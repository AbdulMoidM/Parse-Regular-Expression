#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#ifndef STACK_H_
#define STACK_H_
#define MAX 500



typedef struct {
char A[MAX];
int top;
}STACK ;

void clear(STACK *pS);
bool isEmpty(STACK *pS);
bool isFull(STACK *pS);
bool pop(STACK *pS, char px);
bool push(char x, STACK *pS);
char seeTop(STACK *pS);




#endif
