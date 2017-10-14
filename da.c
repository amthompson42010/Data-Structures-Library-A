/**
 * @author: Alexander Mark Thompson
 * @title: CS 201 -- Fall 2017 -- Project 0 -- Dynamic Array File
 * @descirption: Public Interface of functions to perform on a dynamic array.
 */

#include "da.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct da {
  void (*display)(FILE *, void*);
  int size;
  int filledIndices;
  void **array;
};

/****************************** Public Interface ********************************/

/**
 * Function to create/initialize a new dynamic array.
 * display -> the display function for the dynamic array.
 */
DA *newDA(void (*d)(FILE *, void *)) {
  assert( sizeof(DA) != 0 );

  DA *arr = malloc( sizeof(DA) );

  arr->array = malloc( 1 * sizeof(void*) );
  arr->display = d;
  arr->size = 1;
  arr->filledIndices = 0;

  return arr;
}

/**
 * Function to insert into the dynamic array.
 * items -> the dynamic array
 * value -> value to be inserted
 */
void insertDA(DA *items, void *value) {
  assert(sizeof(void*) * items->size * 2 != 0);

  if ( items->filledIndices < items->size ) {
    items->array[items->filledIndices] = value;
    items->filledIndices += 1;
  }

  else {

    items->array = realloc( items->array, 2 * items->size * sizeof(void*) );

    items->array[items->filledIndices] = value;

    items->size *= 2;
    items->filledIndices += 1;
  }

  return;
}

/**
 * Function to remove a value out of the dynamic array.
 * If the ratio of size and capacity are less than or equal
 * to 25% then the array is shrunken by half.
 * items -> the dynamic array
 */
void *removeDA(DA *items) {
  assert(items->filledIndices > 0);

  void *tmp = items->array[items->filledIndices-1];
  items->array[items->filledIndices-1] = NULL;
  items->filledIndices -= 1;

  if (items->filledIndices < items->size * .25) {
    items->array = realloc( items->array, (items->size/2) * sizeof(void*) );
    items->size /= 2;
  }

  return tmp;
}

/**
 * Function to join to dynamic arrays.
 * recipient -> dynamic array to be merged into
 * donor -> dynamic array to be merged into the recipient
 */
void unionDA(DA *recipient, DA *donor) {
  int i;
  for (i = 0; i < donor->filledIndices; i++) {
    insertDA(recipient, donor->array[i]);
  }

  donor->array = realloc( donor->array, sizeof(void*) );
  donor->size = 1;
  donor->filledIndices = 0;
}

/**
 * Function to a value at a particular index in the dynamic array.
 * items -> the dynamic array
 * index -> index to be found in the dynamic array
 */
void *getDA(DA *items, int index) {
  assert(index >= 0 && index < items->filledIndices);
  return items->array[index];
}

/**
 * Function to set a particular index to a specific value in the
 * dynamic array.
 * items -> the dynamic array
 * index -> the index to be found in the dynamic array
 * value -> the value to be inserted into the value at the given 
 *          index in the dynamic array
 */
void *setDA(DA *items, int index, void *value) {
  assert(index >= 0 && index <= items->filledIndices);

  void *replacedVal;

  if (index == items->filledIndices) {
    insertDA(items, value);
    replacedVal = NULL;
  }
  else {
    replacedVal = items->array[index];
    items->array[index] = value;
  }

  return replacedVal;
}

/**
 * Function to return a shrunken version of the current dynamic 
 * array. If capacity is greater than the size that means that
 * there is extra space in the array. This function is used
 * to take away that extra space.
 * items -> the dynamic array
 */
void **extractDA(DA *items) {
  if (items->filledIndices == 0) {
    return 0;
  }
   assert( items->filledIndices * sizeof(void*) != 0 );

   void **newArr = malloc( items->size * sizeof(void *));
   int i;
   for (i = 0; i < items->size; i++) {
    newArr[i] = items->array[i];
   }

   items->array = realloc( items->array, items->filledIndices * sizeof(void*) );
   items->array = realloc( items->array, sizeof(void*) );
   items->size = 1;
   items->filledIndices = 0;

   return newArr;
}

/**
 * Function to get the size of the dynamic array.
 * items -> the dynamic array.
 */
int sizeDA(DA *items) {
  return items->filledIndices;
}

/**
 * Function to print out the dynamic array in a brackets, and the array's
 * size to the right in brackets.
 * fp -> the file pointer to print the array to
 * items -> the dynamic array
 */
void visualizeDA(FILE *fp, DA *items) {
  int remaining = items->size - items->filledIndices;

  fprintf(fp, "[");

  if (items->filledIndices != 0) {
    int i;
    for (i = 0; i < items->filledIndices; i++) {
      items->display(fp, items->array[i]);
      if (i != items->filledIndices - 1) { fprintf(fp, ","); }
    }
  }

  fprintf(fp, "]");

  fprintf(fp, "[%d]", remaining);
}

/**
 * Function to display the dynamic array, but not the size of the array.
 * fp -> the file pointer to print the array to
 * items -> the dynamic array
 */
void displayDA(FILE *fp, DA *items) {
  fprintf(fp, "[");

  if (items->filledIndices != 0) {
    int i;
    for (i = 0; i < items->filledIndices; i++) {
      items->display(fp, items->array[i]);
      if (i != items->filledIndices - 1) { fprintf(fp, ","); }
    }
  }

  fprintf(fp, "]");
}