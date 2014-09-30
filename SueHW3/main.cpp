//
//  main.cpp
//  Lab 3 working version
//
//  Created by Susan Chang on 9/25/14.
//
//

#include <iostream>
#include <string>
#include "BigInteger.h"


using namespace std;
    
int main(int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";
    string operation, quit;
    string firstInt, secondInt;
    bigInteger* numOne, *numTwo, *result;
    
    while(true){
        //INITIAL USER INPUT
        cout << "**********\n Please enter First INTEGER: ";
        cin >> firstInt;
        cout << "\n What mathematical operation would you like to perform? (A=Addition, S=Subtration, M=Multiplication, F=Factorial, I=Increment, D=Division) ";
        cin >> operation;
        if(operation != "F" && operation!="f"){  //if operation desired isn't factorial, we want a second number
            cout << "\n Please enter Second INTEGER: ";
            cin >> secondInt;
            numTwo = bigInteger(secondInt);
        }
        numOne = bigInteger(firstInt);
        
        //OPERATIONS
        if(operation=="A" || operation=="a"){ //Addition
            result = addAny(numOne,numTwo);
            cout << "\n The SUM of " << firstInt << " and " << secondInt << " is "; result; cout << ".\n" ;
        }
        else if(operation=="S" || operation=="s"){ //Subtraction
            result = subtractAny(numOne,numTwo);
            cout << "\n The DIFFERENCE of " << firstInt << " and " << secondInt << " is "; result; cout << ".\n" ;
        }
        else if(operation=="M" || operation=="m"){ //Multiplication
            result = multiplyAny(numOne,numTwo);
            cout << "\n The PRODUCT of " << firstInt << " and " << secondInt << " is "; result; cout << ".\n" ;
        }
        else if(operation=="F" || operation=="f"){ //Factorial
            result = factorialAny(numOne);
            if(result != NULL){
                cout << "\n The FACTORIAL of " << firstInt << " is "; result; cout << ".\n" ;
            }
            else
                cout << "\n The FACTORIAL of " << firstInt << " could not be computed.\n";
        }
        else if(operation=="I" || operation=="i"){ //Increment
            result = incrementAny(numOne,numTwo);
            cout << "\n The INCREMENT of " << firstInt << " by " << secondInt << " is "; result; cout << ".\n" ;
        }
        else if(operation=="D" || operation=="d"){ //Division
            result = divideAny(numOne,numTwo);
            if(result != NULL){
                
                cout << "\n The DIVISION of " << firstInt << " and " << secondInt << " is "; result; cout << ".\n" ;
            }
            else
                cout << "\n The DIVISION of " << firstInt << " and " << secondInt << " could not be computed.\n";
        }
        else {//if input isn't valid
            cout << "\nNot a valid input. Try again.\n";
            continue;
        }
        cout << "\n Would you like to quit? (Y or N) ";
        cin >> quit;
        
        if(quit=="Y" || quit=="y") //To quit program
            exit(1);
        cout << endl;
    }
    
    return 0;
}
