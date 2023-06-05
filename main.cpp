/*
Name: Saeid Jalaliani
Coding 05 - Cosc2436
Purpose: design and test a fully functional stack that handles the sample data ADT
 */

#include "main.h"

int main(int argc, char **argv) {
    // here for the rand_string() function
    // if you don't use it, get rid of this
    srand(time(NULL));
    
    int stackSize = 0;
    int input;
    int tempNum, tempNum2, tempNum3;
    string strTemp;
    Data package;
    bool check;
    
    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;
    
    
    if (argc==2){
        input = std::atoi(argv[1]);
        if(input < 2){
            cout << "Stack size must be at least 2, and a positive integer." << endl;
        } else {
            
            stackSize = input;
            Stack myStack(stackSize);
            
            if(myStack.isEmpty()){
                cout << "stack is currently empty, beginning test:" << endl << endl;
            }

            cout << "Stack size is: " << myStack.getSize() << endl << endl;
            
            
        for(int i = 0; i < stackSize; i++){
            
            tempNum = rand()%30-3; // sometimes we want to send an invalid num
            tempNum2 = rand()%3+1; // randomly peeking as we push
        
            rand_string(&strTemp);
        
            check = myStack.push(tempNum, &strTemp);
            
            if(tempNum2 == 2){
                
                myStack.peek(&package);
                
                cout << "peeking the top of the stack at this time: " << package.id << ": " << package.information << endl;
            }
            
            cout << "Filling stack ..." << endl << endl;
            
            if (check) {
                cout << "pushed " << tempNum << ": " << strTemp << " successfully." << endl;
            } else {
                cout << "could not push element " << i+1 <<": " << tempNum << " to the stack, invalid entry. " << endl;
            }
        
     } 
     
        tempNum = rand()%(TESTSIZE/2)-1;
     
     for(int i =0; i<tempNum; i++ ){
         
         if(!(myStack.push(5, &strTemp))){
             cout << "could not push more elements onto the stack, overflow reached." << endl << endl;
         }
     }
     
     for(int i = 0; i < stackSize+(tempNum); i++){
         
         check = myStack.pop(&package);
         
         if (check) {
             cout << i+1 << ": " << package.id << " " << package.information << endl;
         } else {
             cout << "could not pop anymore. Underflow!" << endl;
         }
     }


             check = myStack.peek(&package);
        
        if(!check){
            cout << "Stack is empty, cannot peek! underflow. " << endl;
        } else {
            cout << "peeking the top of the stack at this time: " << package.id << ": " << package.information << endl; 
        } 
        
   for(int i = 0; i < NUM_TESTS; i++){
	
	tempNum = rand()%6 + 1;
	tempNum2 = rand()%number_test_cases;
    tempNum3 = rand()%30-3;
 
	
	cout << "random tests number " << i+1 << endl << endl;
	
	switch(tempNum){
		case 1:
		case 2: 
			for(int i=0; i < tempNum2; i++ ){
				
			rand_string(&strTemp);
		
			if(!myStack.push(tempNum3+i, &strTemp)){
 
			cout << "Stack overflow reached!" << endl;
			}else{
				cout << "successfully pushed." << endl;
			}
				
		}
		break;
		case 3:
		case 4:
			for(int i=0; i<tempNum2;i++){
				myStack.pop(&package);
				if(package.id == -1){
				cout << "stack underflow!" << endl;
			}else{
				cout << package.id << " - " << package.information << endl;
			}
		}
		break;
		case 5:
			myStack.peek(&package);
			if(package.id > 0 && package.information.length()>0){
				cout << "Peeking at stack ID: " << package.id << " - info: " << package.information << endl;
			}else{
				cout <<"invalid data" << endl;
			}
		break;
		case 6: 
			if(myStack.isEmpty()){
				cout << "stack is empty (in swtich statement)" << endl;
			}else{
				cout << "stack is not empty (in swtich statement)" << endl;
			}
		break;
	}
}

        }     
        
        
    } else if (argc == 1) {
        cout << "You must enter a number for stack size, following a space bar after the program name. " << endl;
    } else if (argc > 2){
        cout << "Please enter only one number after the program name." << endl;
    }

    
    
    return 0;
}
