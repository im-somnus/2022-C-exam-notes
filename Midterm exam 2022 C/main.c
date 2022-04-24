/*  main.c
 *
 *  Created on: 23 Apr 2022
 *      Author: im-somnus  */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <math.h>

#include "./src/main.h"

int main()
{
	// Initializing the data structure
	Tree tree;
	init(&tree);

	// Read and populating the tree
	read("read.txt", &tree);
	printf("Showing tree..\n");
	showTree(tree);
	printf("\n");

	// Output the data structure into a binary file
	printf("Writing binary file..");
	write("out.bin", tree);
	printf("Done\n\n");

	// Finding the closest country
	printf("Closest country is: %s\n", closestCountry(tree, 1.2, 4.0)); // argentina
	printf("Closest country is: %s\n", closestCountry(tree, 1.1, 3.0)); // britain
	printf("Closest country is: %s\n", closestCountry(tree, 1.3, 5.0)); // china
	printf("Closest country is: %s\n", closestCountry(tree, 1.0, 2.0)); // denmark
	printf("Closest country is: %s\n", closestCountry(tree, 1.6, 8.0)); // egypt
	printf("Closest country is: %s\n", closestCountry(tree, 1.7, 9.0)); // france
	printf("Closest country is: %s\n", closestCountry(tree, 1.8, 10.0)); // germanye
	printf("Closest country is: %s\n", closestCountry(tree, 1.9, 11.0)); // haiti
	printf("Closest country is: %s\n", closestCountry(tree, 1.4, 6.0)); // indonesia
	printf("Closest country is: %s\n", closestCountry(tree, 2.0, 12.0)); // yemen
	printf("Closest country is: %s\n\n", closestCountry(tree, 1.5, 7.0)); // zimbawe

	// Destroying the data structure
	printf("Destroying tree..");
	destroyTree(&tree);
	printf("Done\n");

	printf("Showing tree..");
	showTree(tree);

	exit(0);
}

double calcDistance(double cityLat, double cityLon, double misilLat, double misilLon)
{
	return sqrt(pow((misilLat - cityLat), 2) + pow((misilLon - cityLon), 2));
}

double searchCity(Tree tree, Tree *closest, double misilLat, double misilLon)
{
	*closest = tree;
	Tree left, right;

	double currentDistance = calcDistance((*closest)->lat, (*closest)->lon, misilLat, misilLon);
	double leftDistance, rightDistance;

	if (tree->left != NULL)
	{
		leftDistance = searchCity(tree->left, &left, misilLat, misilLon);

		if (leftDistance < currentDistance)
		{
			currentDistance = leftDistance;
			*closest = left;
		}
	}
	if (tree->right != NULL)
	{
		rightDistance = searchCity(tree->right, &right, misilLat, misilLon);

		if (rightDistance < currentDistance)
		{
			currentDistance = rightDistance;
			*closest = right;
		}
	}

	return currentDistance;
}

char* closestCountry(Tree tree, double misilLat, double misilLon)
{
	Tree closest;

	if (tree != NULL)
	{
		searchCity(tree, &closest, misilLat, misilLon);
	}

	return closest->name;
}

void read(char *filename, Tree *tree)
{
	FILE *fin;

	if ((fin = fopen(filename, "rt")) == NULL)
	{
		perror("Error when reading myfile.txt");
		return;
	}

	int done = 0;

	while (!done)
	{
		char city[50];
		double lat;
		double lon;

		if (fscanf(fin, "%s %lf %lf", city, &lat, &lon) == 3)
		{
			createTree(tree, city, lat, lon);
		}

		if (feof(fin))
		{
			done = 1;
		}
	}

	fclose(fin);
}

void writer(FILE *fout, Tree tree)
{
	if (tree != NULL)
	{
		if (tree->left != NULL)
		{
			writer(fout, tree->left);
		}

		if (tree != NULL)
		{
			int nameLength = 1 + strlen(tree->name);

			// <nameLength><name><lat><lon>
			fwrite(&nameLength, sizeof(nameLength), 1, fout);
			fwrite(&tree->name, sizeof(char), nameLength, fout);
			fwrite(&tree->lat, sizeof(double), 1, fout);
			fwrite(&tree->lon, sizeof(double), 1, fout);
		}

		if (tree->right != NULL)
		{
			writer(fout, tree->right);
		}
	}
}

void write(char *filename, Tree tree)
{
	FILE *fout;

	if ((fout = fopen(filename, "wb")) == NULL)
	{
		perror("Error when creating out.bin");
	}

	writer(fout, tree);
	fclose(fout);
}

