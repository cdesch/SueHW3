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
    cout << "Expected Result: \t" << expectedResult << endl;
    
    BigInteger* myBigNum = new BigInteger(firstNum);
    string  myNum = myBigNum->add(secondNum);
    
    cout << "Actual Result: \t\t" <<  myNum << endl <<endl;
}

void subtractionTestCase(string firstNum, string secondNum, string expectedResult){
    
    cout << "Testing Subtraction: " << firstNum << " - " << secondNum << endl;
    cout << "Expected Result: \t" << expectedResult << endl;
    
    BigInteger* myBigNum = new BigInteger(firstNum);
    string  myNum = myBigNum->subtract(secondNum);
    
    cout << "Actual Result: \t\t" <<  myNum << endl <<endl;
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
    
    //2.4 add two numbers of differeing lengths
    additionTestCase("1678","154387","156065");
    
    //2.5 add two long numbers of differeing lengths
    additionTestCase("738492738409274019284726474038262019362543059573630183749505846264849374","9875037634645930237595736253009785730737","738492738409274019284726474038271894400177705503867779485758856050580111");
    
    //2.6 add two long numbers of differeing lengths
    additionTestCase("9875037634645930237595736253009785730737","738492738409274019284726474038262019362543059573630183749505846264849374","738492738409274019284726474038271894400177705503867779485758856050580111");
}

//Test 3:
//Subtract two numbers
void testCaseThree(){
    
    //3.1 Subtract two numbers
    subtractionTestCase("123","321","-198");
    
    //3.2 Subtract two numbers that carry over
    subtractionTestCase("1678","1543","135");
    
    //3.3 Subtract two numbers of differing length
    subtractionTestCase("167832","1543","166289");
    
    //3.4 Subtract two numbers of differeing lengths
    subtractionTestCase("1678","154387","-152709");
    /*
    //3.5 Subtract two long numbers of differeing lengths

    subtractionTestCase("738492738409274019284726474038262019362543059573630183749505846264849374","9875037634645930237595736253009785730737","738492738409274019284726474038252144324908413643392588013252836479118637");
    
    //3.6 Subtract two long numbers of differeing lengths
    subtractionTestCase("9875037634645930237595736253009785730737","738492738409274019284726474038262019362543059573630183749505846264849374","-738492738409274019284726474038252144324908413643392588013252836479118637");
     */
}


void testClassFunctions(){
    BigInteger* myNum = new BigInteger("123");
    myNum->runTests();
}

int main(int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";
    
    //testClassFunctions();
    //testCaseOne();
    //testCaseTwo();
    testCaseThree();
    
    
    
    return 0;
}
