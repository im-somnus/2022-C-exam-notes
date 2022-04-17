/*  nfv.c
 *
 *  Created on: 15 Apr 2022
 *      Author: ed  */

#include "nfv.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

void init(LFramework *ptrFrame, int size, int initCpu)
{
	*ptrFrame = NULL;

	int frameworkCount = 0;
	while (frameworkCount < size)
	{
		LFramework ptrNewFramework = (LFramework) malloc(sizeof(struct NodeFramework));

		ptrNewFramework->availCpu = initCpu;
		ptrNewFramework->vnfs = NULL;
		ptrNewFramework->next = *ptrFrame;
		*ptrFrame = ptrNewFramework;

		frameworkCount++;
	}
}

void store(LFramework frame, char *filename)
{
	if (frame != NULL)
	{
		FILE *fout;

		if ((fout = fopen(filename, "wb")) == NULL)
		{
			char a[] = "Error opening the file: ";
			strcat(a, filename);
			perror(a);
		}
		else
		{
			while (frame != NULL)
			{
				LVnf ptrCurrentNode = frame->vnfs;

				while (ptrCurrentNode != NULL)
				{
					unsigned lengthOfID = strlen(ptrCurrentNode->id);

					fwrite(&lengthOfID, sizeof(lengthOfID), 1, fout);
					fwrite(ptrCurrentNode->id, sizeof(char), lengthOfID, fout);
					fwrite(&(ptrCurrentNode->cpu), sizeof(int), 1, fout);

					ptrCurrentNode = ptrCurrentNode->next;
				}

				frame = frame->next;
			}
		}

		fclose(fout);
	}
}

int deployVNF(LFramework frame, char *vnfId, int cpu)
{
	while (frame != NULL && frame->availCpu < cpu)
	{
		frame = frame->next;
	}

	if (frame != NULL) // We found it
	{
		LVnf ptrCurrentNode = (LVnf) malloc(sizeof(struct NodeVnf));

		strcpy(ptrCurrentNode->id, vnfId);
		ptrCurrentNode->cpu = cpu;
		ptrCurrentNode->next = frame->vnfs;

		frame->vnfs = ptrCurrentNode;
		frame->availCpu -= cpu;
	}

	return frame == NULL ? 0 : 1;
}

void releaseVNF(LFramework frame, char *vnfId)
{
	int found = 0;

	while (!found && frame != NULL)
	{
		LVnf ptrCurrentNode = frame->vnfs;
		LVnf ptrPreviousNode = NULL;

		while (!found && ptrCurrentNode != NULL)
		{
			if (!strcmp(ptrCurrentNode->id, vnfId))
			{
				found = 1;
				ptrPreviousNode->next = ptrCurrentNode->next;
				frame->availCpu += ptrCurrentNode->cpu;
				free(ptrCurrentNode);
			}

			ptrPreviousNode = ptrCurrentNode;
			ptrCurrentNode = ptrCurrentNode->next;
		}

		frame = frame->next;
	}
}

void destroyFramework(LFramework *ptrFrame)
{
	if (*ptrFrame != NULL)
	{
		LVnf ptrCurrentNode = (*ptrFrame)->vnfs;

		while (*ptrFrame != NULL)
		{
			while (ptrCurrentNode != NULL)
			{
				LVnf ptrAuxNode = ptrCurrentNode;
				ptrCurrentNode = ptrCurrentNode->next;
				free(ptrAuxNode);
			}

			(*ptrFrame)->vnfs = NULL;

			LFramework ptrAuxFramework = (*ptrFrame);
			(*ptrFrame) = (*ptrFrame)->next;
			free(ptrAuxFramework);
		}

		ptrFrame = NULL;
	}
}

void showFramework(LFramework frame)
{
	if (frame != NULL)
	{
		printf("\n[Framework]\n");
		int frameworkCount = 0;
		while (frame != NULL) // We print the whole DS
		{
			printf("\t[Node %d][%d]->", frameworkCount, frame->availCpu);
			LVnf ptrCurrentNode = frame->vnfs;

			if (ptrCurrentNode != NULL)
			{
				while (ptrCurrentNode != NULL)
				{
					printf("(%s|%d)", ptrCurrentNode->id, ptrCurrentNode->cpu);

					if (ptrCurrentNode->next != NULL)
					{
						printf("->");
					}

					ptrCurrentNode = ptrCurrentNode->next;
				}
			}
			else if (ptrCurrentNode == NULL && INFRA_NODES < 6) // < 6 avoids cluttering the screen.
			{
				for (int i = 0; i < INFRA_NODES - 1; ++i)
				{
					printf("()->");
				}

				printf("()");
			}

			printf("\n");

			frameworkCount++;
			frame = frame->next;
		}
		printf("[/Framework]\n\n");
	}
	else
	{
		printf("Framework is empty.\n");
	}
}

