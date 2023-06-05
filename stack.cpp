/*
Name: Saeid Jalaliani
Coding 05 - Cosc2436
Purpose: design and test a fully functional stack that handles the sample data ADT
 */

// each cpp includes ONLY it's header directly
#include "stack.h"

Stack::Stack(int mainSize){
    
    if (mainSize < 2){
        size = DEFAULTSIZE;
    } else {
        size = mainSize;
    }
    
    top = -1;
    
    stack = new Data*[size]; //stack is a pointer to a pointer, so it needs to point to pointer(s). 
    //we use the keyword new to create a stack of type DATA of pointers, which each point to a data that holds value on line 38
    
}

Stack::~Stack(){
   	
    while(top!=-1){
        delete stack[top--];
    }
     
    delete[] stack;
}

bool Stack::push(int num,string *temp){
     
     bool pushed = false;
   
         
     if(num > 0 && temp->length() > 0 && top < size-1){
     
     
         stack[++top] = new Data;

         stack[top]->id = num;
         stack[top]->information = *temp;
         
         pushed = true;
     }
         
     
     return pushed;
}

bool Stack::pop(Data *temp){
    
    bool popped = false;
    
    if(top > -1){
        temp->id = stack[top]->id;
        temp->information = stack[top]->information;
        
        delete stack[top--];
        popped = true;
    } else {
  		temp->id = -1;
		temp->information ="";
    }
    
    return popped;
}

bool Stack::peek(Data *temp){
	
    bool peeked = false;
	
	if(top > -1){
		
		temp->id = stack[top]->id;
		temp->information = stack[top]->information;
		
		peeked = true;
	}else{
		temp->id = -1;
		temp->information ="";
	}
	
	return peeked;
}

bool Stack::isEmpty(){
    return (top < 0); // condition will be false if top is not -1, and true if -1 
}

int Stack::getSize(){
    
    return size;
}