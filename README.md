# Parsing-Program

NOTE: Due to the University of Rochester Computer Science Department's project guidelines, I cannot display the solution for this project publicly. Therefore I have commented out many crucial
parts of the code in rexp.c, which is the file that contains the methods for the parsing. 

For this project, we created a Console Application in C to parse Regular Expressions using Recursive Descent(Part One) and Table-Driven Parsing(Part Two).

Collborators:Sufian Mushtaq, Moazzam Salman

To compile we typed: gcc -std=c99 -Wall -Werror rexp.c stack.c tree.c (will not work with this repository because I commented out code inside rexp.c)

The program outputs whether the expression typed by the user, is a valid Regular Expression or not. Part 1 stands for Recursive Descent Parsing, and Part 2 stands for Table Driven Parsing. Both Parts will always the same output, as they are just two different methods of doing the same thing. 


How we did Part 1:
Parse tree representation and functions (files, struct names, important functions): tree.c, tree.h
Recursive-descent parsing functions: E(), ET(), C(), CT(), S(), ST(), A(), X()  (each function is made for one grammar rule)
Function that starts a recursive-descent parse: runPartOne()


How we did Part 2:
Parsing table representation and functions (files, struct names, main functions):stack.c, stack.h, int parseTable[][], tree.c, tree.h
Function that creates the parsing table for your grammar of regular expressions: createTable()
Function that uses a parsing table to perform a table-driven parse: driver()
Helper functions are used for part2 in the form of one function for each synctactic category. They just pop the top of the stack
and push their production into stack, depending on what production the parse table contains for a given input character and synctactic category.




