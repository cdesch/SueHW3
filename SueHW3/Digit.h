//
//  Digit.h
//  SueHW3
//
//  Created by cj on 10/6/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#ifndef __SueHW3__Digit__
#define __SueHW3__Digit__

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

class Digit{
    
private:
    
    int value;
public:
    Digit();
    Digit(int digit);
    ~Digit();
    
    //Member Functions
    void print();
    bool isGreaterThan(Digit* d);
    bool isEqualTo(Digit* d);
    bool isLessThan(Digit* d);
    //Setters//
    void setValue(int v);
    
    //Getters//
    int getValue();
    
};

#endif /* defined(__SueHW3__Digit__) */
