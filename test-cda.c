#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "integer.h"
#include "real.h"
#include "string.h"
extern long random(void);
extern void srandom(unsigned int seed);

int
main(void)
    {
    printf("CDA tester: 1,4\n");
    printf("you can retrieve this test with:\n");
    printf("wget beastie.cs.ua.edu/cs201/testing/0/cda-test-1-4.c\n");
    printf("\noutput:\n\n");
    CDA *d = newCDA(displayINTEGER);
    void *p = 0;
    printf("inserting items into array d\n");
    insertCDAback(d,newINTEGER(102));
    insertCDAfront(d,newINTEGER(468));
    insertCDAback(d,newINTEGER(448));
    insertCDAfront(d,newINTEGER(595));
    insertCDAback(d,newINTEGER(466));
    insertCDAfront(d,newINTEGER(949));
    insertCDAfront(d,newINTEGER(465));
    insertCDAfront(d,newINTEGER(106));
    insertCDAfront(d,newINTEGER(109));
    insertCDAback(d,newINTEGER(341));
    insertCDAback(d,newINTEGER(131));
    insertCDAfront(d,newINTEGER(217));
    insertCDAfront(d,newINTEGER(787));
    insertCDAfront(d,newINTEGER(685));
    insertCDAback(d,newINTEGER(98));
    insertCDAfront(d,newINTEGER(928));
    insertCDAfront(d,newINTEGER(900));
    insertCDAback(d,newINTEGER(323));
    insertCDAfront(d,newINTEGER(901));
    insertCDAfront(d,newINTEGER(338));
    insertCDAback(d,newINTEGER(316));
    insertCDAback(d,newINTEGER(555));
    insertCDAback(d,newINTEGER(922));
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing all but one item from array d\n");
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing the last item from array d\n");
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("inserting one item into array d\n");
    insertCDAfront(d,newINTEGER(598));
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("removing that item\n");
    p = removeCDAback(d);
    printf("array d: ");
    visualizeCDA(stdout,d);
    printf("\n");
    printf("looking at the last element removed\n");
    printf("last element removed: ");
    displayINTEGER(stdout,p);
    printf("\n");
    return 0;
    }