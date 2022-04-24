/*  node.c
 *
 *  Created on: 23 Apr 2022
 *      Author: im-somnus  */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "tree.h"

void init(Tree *tree)
{
	*tree = NULL;
}

Tree createNode(Tree *tree, char *name, double lat, double lon, Tree left, Tree right)
{
	Tree ptrNew = (Tree) malloc(sizeof(struct node));

	ptrNew->name = (char*) malloc(sizeof(name));
	strcpy(ptrNew->name, name);

	ptrNew->lon = lon;
	ptrNew->lat = lat;
	ptrNew->left = left;
	ptrNew->right = right;

	return ptrNew;
}

void createTree(Tree *tree, char *new, double lat, double lon)
{
	Tree newNode = createNode(tree, new, lat, lon, NULL, NULL);

	if (*tree == NULL)
	{
		*tree = newNode;
	}
	else
	{
		Tree current = *tree;

		if (strcmp(new, current->name) < 0) // left
		{
			if (current->left == NULL)
			{
				current->left = newNode;
			}
			else
			{
				createTree(&current->left, new, lat, lon);
			}
		}
		else if (strcmp(new, current->name) >= 0) // right
		{
			if (current->right == NULL)
			{
				current->right = newNode;
			}
			else
			{
				createTree(&current->right, new, lat, lon);
			}
		}
	}
}

void showTree(Tree tree)
{
	if (tree != NULL)
	{
		if (tree->left != NULL)
		{
			showTree(tree->left);
		}

		if (tree != NULL)
		{
			printf("\t[%s %.4lf %.4lf]\n", tree->name, tree->lat, tree->lon);
		}

		if (tree->right != NULL)
		{
			showTree(tree->right);
		}
	}
	else
	{
		printf("Empty Tree.\n");
	}
}

void destroyTree(Tree *tree)
{
	if (*tree != NULL)
	{
 		if ((*tree)->left != NULL)
		{
			destroyTree(&(*tree)->left);
		}

		if ((*tree)->right != NULL)
		{
			destroyTree(&(*tree)->right);
		}

		if (*tree != NULL)
		{
			(*tree)->left = NULL;
			(*tree)->right= NULL;

			free((*tree)->name);
			free(*tree);
		}
	}
	*tree = NULL;
}
