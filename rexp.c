#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "stack.h"

int parseTable[15][50];
char termSymbols[50];
char syncSymbols[15];
char* userInput;//will be equated to nextTerminal and used for part 2(table driven parsing)
STACK driverSt;
STACK* driverStack;//pointer to stack used in part two table driven parsing
char stackPop; //to store the char that are popped out after every pop
TREE tableTree;//holds tree generated after table driver parse in part 2
TREE parseTree; //holds the result of the part one parse
char* nextTerminal;//input array for part 1
int valid = 0;
int pass=1;

/*****PART ONE CODE******/
TREE E() {
    TREE treeC = C();
    if (treeC != FAILED) {
        TREE treeET = ET();
        if (treeET != FAILED) { //if ET hasn't failed and entire input has been read
            return makeNode2('E', treeC, treeET);
        } else {
            return FAILED;
        }
    } else {
        return FAILED;
    }
}

//ONE METHOD FOR EACH GRAMMAR RULE GOES HERE BUT HAS BEEN REMOVED DUE TO UNIVERSITY CS DEPARTMENT's PROJECT GUIDELINE

void runPartOne() {
    parseTree = E(); //starts with E symbol
    if(parseTree==0 || *nextTerminal != 0) { //if null parsetree or entire input hasn't been read
        valid = 0;
        printf("\nPART ONE OUTPUT: Invalid expression - Could not make parse tree! \n");
    } else {
        valid = 1;
        printf("\n\nPART ONE OUTPUT: Successful Recursive Descent Parsing. Below is the PARSE TREE:\n");
        printParseTree(parseTree, -1);
    }
}

/************END OF PART ONE CODE********/





/*************    PART TWO CODE  **********************/

void createTable(){
 termSymbols[0]='|';
 termSymbols[1]='(';
 termSymbols[2]='*';
 termSymbols[3]='.';
 termSymbols[30]=')';
char filler='a';
for(int i=4;i<30;i++){
termSymbols[i]=filler;
filler++;
}

syncSymbols[0]='E';
syncSymbols[1]='F';
syncSymbols[2]='C';
syncSymbols[3]='G';
syncSymbols[4]='S';
syncSymbols[5]='H';
syncSymbols[6]='A';
syncSymbols[7]='X';



for(int i=0;i<=30;i++){
parseTable[0][i]=1;//row for production E
}


//CODE FOR FUTHER TABLE SETUP GOES HERE BUT HAS BEEN REMOVED

int getRow(char syncCategory){
for(int i=0;i<8;i++){
        if(syncSymbols[i]==syncCategory){
            return i;
        }
}
return -99;
}
int getColumn(char terminal){
for(int i=0;i<=30;i++){
        if(termSymbols[i]==terminal){
            return i;
        }
}
return -99;
}

void E1(){

  pop(driverStack, stackPop);
  push('F', driverStack);
  push('C', driverStack);

}

//CODE FOR EVERY OTHER PRODUCTIONS LIKE E1 GOES HERE BUT HAS BEEN REMOVED


void driver(){
 //CODE THAT WILL EXECUTE THE PARSING FOR PART TWO
 //REMOVED DUE TO UNIVERSITY CS DEPARTMENT's PROJECT GUIDELINES
}

/***********END OF PART TWO CODE ***********/

int main() {
nextTerminal = (char*)malloc(sizeof(char)*100); //array of 100 characters
userInput = (char*)malloc(sizeof(char)*100); //array of 100 characters

printf("Please Enter a RegEx input: ");
scanf("%s", nextTerminal);//will use this in part 1
userInput=nextTerminal;//will use this in part 2
//part one parsing
runPartOne();

//part two parsing
createTable();
driver();



}


