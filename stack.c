//code from FOCs 308, 309
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#define MAX 500
char seeTop(STACK *pS){
    return (pS->A[(pS->top)]);
}
void clear(STACK *pS){
pS->top = -1;
}
bool isEmpty(STACK *pS)
{
return (pS->top < 0);
}
bool isFull(STACK *pS)
{
return (pS->top >= MAX-1);
}
bool pop(STACK *pS, char px)
{
if (isEmpty(pS))
return false;
else {
px = pS->A[(pS->top)--];
return true;
}
}
bool push(char x, STACK *pS)
{
if (isFull(pS))
return false;
else {
pS->A[++(pS->top)] = x;
return true;
}
}
