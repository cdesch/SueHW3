//
//  BigInteger.h
//  SueHW3
//
//  Created by cj on 9/25/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

//
//  BigInteger.h
//  SueHW3
//
//  Created by cj on 9/25/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

//The .h file will have all the declarations for the class
#ifndef __SueHW3__BigInteger__  //
#define __SueHW3__BigInteger__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

//COPY FROM HERE //
//************************
//    Class BigInteger
//************************

class BigInteger{
private:
    
    vector <int> digits;
    //Private Member Functions//
    int convertCharToInt(char c);
    char convertIntToChar(int i);
    vector <int> convertStringToVector(string ns);
    string convertVectorToString(vector <int> myVector);
    bool isGreaterThan(vector <int> numVector);

public:
    
    BigInteger(); //Default Constructor
    BigInteger(string ns); //Constructor with parameters
    ~BigInteger(); //Deconstructor
    
    //Member functions//
    //Every Function will have the same format
    //<Return type> <name>(<parameters, ...nth>);  // Every function declaration
    //<Return type> <name>(<parameters, ...nth>){}  // Every function Implementation
    void print();
    int getDigit(int index);

    string add(string number);
    string subtract(string number);
    string multiply(string number);
    string divide(string number);
    void increment();
    void decrement();
    vector <int> reverseVector(vector<int> digits);

    //Setters//
    void setDigitsValue(string number); //TODO
    
    //Getters//
    long getSize();
    
    //Tests//
    void runTests();
    void testConvertVectorToString();
};

//COPY TO HERE //

#endif /* defined(__SueHW3__BigInteger__) */