//
//  BigInteger.h
//  SueHW3
//
//  Created by cj on 9/25/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#ifndef __SueHW3__BigInteger__
#define __SueHW3__BigInteger__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//************************
//    Class BigInteger
//************************

class BigInteger{
private:
    string numsize;
    long int numA;
    long int numb;
    
public:
    BigInteger(string ns, long int a, long int b); //Constructor with parameters
    ~BigInteger(); //Deconstructor
    
    //Setters
    void setSize(string ns);
    void setNumA(long int a);
    void setNumB(long int b);
    
    //Getters
    string getSize();
    long int getNumA();
    long int getNumB();
    
};



#endif /* defined(__SueHW3__BigInteger__) */
