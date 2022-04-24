/*  main.h
 *
 *  Created on: 23 Apr 2022
 *      Author: im-somnus  */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

double calcDistance(double cityLat, double cityLon, double misilLat, double misilLon);
double searchCity(Tree tree, Tree *closest, double misilLat, double misilLon);
char* closestCountry(Tree tree, double misilLat, double misilLon);
void read(char *filename, Tree *tree);
void writer(FILE *fout, Tree tree);
void write(char *filename, Tree tree);

#endif
