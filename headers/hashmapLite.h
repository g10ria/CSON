#ifndef hashmapLite_h

#define hashmapLite_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./hashfunctions.h"

struct entry;

void initializeMap();

void addEntry(struct entry *ent);

char *get(char *key);

void put(char *key, char *value);

#endif