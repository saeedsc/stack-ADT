/*
Name: Saeid Jalaliani
Coding 05 - Cosc2436
Purpose: design and test a fully functional stack that handles the sample data ADT
 */

#ifndef STACK_H
#define STACK_H

/*
 * there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#define DEFAULTSIZE 10
 
class Stack {

public:

	Stack(int);
	~Stack();
	
	bool push(int, string*);
	bool pop(Data*);
	bool peek(Data*);
	bool isEmpty();
    int getSize();
    
private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need.
    // do not modify them or add any other attributes
    int top;
    int size;
    Data **stack;
    // notice stack is a pointer to a pointer. That means if you do
    // a single array allocation, you will get an array of pointers
};

#endif //STACK_H
