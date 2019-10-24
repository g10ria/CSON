#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_KEY_LENGTH 2048
#define MAX_VALUE_LENGTH 2048

#include "./hashfunctions.c"


int allocatedSlots = 8;    // allocate some number of initial slots
int numEntries = 0;        // number of entries

unsigned long int (*hash)(char *key) = &identity;

union value
{
   char * string;
   double number;
   int boolean;
};

typedef struct
{
   char key[MAX_KEY_LENGTH];
   char type;
   union value * val;
   int level; // not in use

} entry;

entry **map; // array of pointers to entries

int entrysize = sizeof(entry);

void initialize()
{
   map = malloc(entrysize * allocatedSlots);
}

void addEntry(entry ent)
{
   if (numEntries==allocatedSlots)
   {
      allocatedSlots *=2;
   } // space allocation not written
   
   unsigned long int address = hash(ent.key);

   map[address] = &ent;

   numEntries++;
}

entry getEntry(int index)
{
   return *map[index];
}

union value getValue(unsigned long int index)
{
   return *((*map[index]).val);
}

char *getString(char * key)
{
   unsigned long int address = hash(key);
   return getValue(address).string;
}

double getNumber(char *key)
{
   unsigned long int address = hash(key);
   return getValue(address).number;
}

int getBoolean(char *key)
{
   unsigned long int address = hash(key);
   return getValue(address).boolean;
}

void main()
{
   initialize();

   // make test entries
   entry e1;
   e1.type = 'c';
   union value valtemp;
   valtemp.number = 3;
   e1.val = &valtemp;
   addEntry(e1);

   double val3 = getNumber("adslfj"); // doesn't matter because hash function not written yet

   printf("%lf\n", val3);


   free(map);
   return;
}

/**
 * s: string
 * d: number
 * b: boolean
 */ 