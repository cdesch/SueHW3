//
//  main.cpp
//  Lab 3 working version
//
//  Created by Susan Chang on 9/25/14.
//
//

#include <iostream>
#include <string>
#include <vector>
#include "BigInteger.h"


using namespace std;

//Test 1:
//Store a number in BigIntger Object via String and print it.
void testCaseOne(){
    
    BigInteger* myBigNum = new BigInteger("123");
    myBigNum->print();
    
}

void additionTestCase(string firstNum, string secondNum, string expectedResult){
    
    cout << "Testing Addition: " << firstNum << " + " << secondNum << endl;
    cout << "Expected Result: " << expectedResult << endl;
    
    BigInteger* myBigNum = new BigInteger(firstNum);
    string  myNum = myBigNum->add(secondNum);

    
    cout << "Actual Result: " <<  myNum << endl;
}


//Test 2:
// Add two numbers
void testCaseTwo(){
    
    
    //2.1 Add two numbers
    additionTestCase("123","321","444");
    
    //2.2 add two numbers that carry over
    additionTestCase("1678","1543","3221");
    
    //2.3 add two numbers of differing length
    additionTestCase("167832","1543","169375");
    
    /*
     BigInteger* myNextBigNum3 = new BigInteger("1678");
     myNextBigNum3->print();
     myNum = myNextBigNum3->add("154387");
     cout << myNum << endl;
     
     */
    
}

void testClassFunctions(){
    BigInteger* myNum = new BigInteger("123");
    myNum->runTests();
}



int main(int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";
    
    testClassFunctions();
    testCaseOne();
    testCaseTwo();
    
    
    /*
     
     string operation, quit;
     string firstInt, secondInt;
     BigInteger* numOne, *numTwo, *result;
     
     while(true){
     //INITIAL USER INPUT
     cout << "**********\n Please enter First INTEGER: ";
     cin >> firstInt;
     cout << "\n What mathematical operation would you like to perform? (A=Addition, S=Subtration, M=Multiplication, F=Factorial, I=Increment, D=Division) ";
     cin >> operation;
     if(operation != "F" && operation!="f"){  //if operation desired isn't factorial, we want a second number
     cout << "\n Please enter Second INTEGER: ";
     cin >> secondInt;
     numTwo = BigInteger(secondInt);
     }
     numOne = BigInteger(firstInt);
     
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
     */
    
    return 0;
}
