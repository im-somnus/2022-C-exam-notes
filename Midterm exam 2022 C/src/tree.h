/*  node.h
 *
 *  Created on: 23 Apr 2022
 *      Author: im-somnus  */

#ifndef NODE_NODE_H_
#define NODE_NODE_H_

typedef struct node *Tree;
struct node
{
	char *name;
    double lat, lon;
    Tree left, right;
} Node;

void init(Tree *tree);
void createTree(Tree *tree, char *name, double lat, double lon);
void showTree(Tree tree);
void destroyTree(Tree *tree);

#endif
