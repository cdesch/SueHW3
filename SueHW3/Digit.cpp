//
//  Digit.cpp
//  SueHW3
//
//  Created by cj on 10/6/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "Digit.h"

//Default Constructor
Digit::Digit(){
    this->value = 0;
}
//Constructor with param
Digit::Digit(int digit){
    this->value = digit;
}
//Deconstructor
Digit::~Digit(){
}

//Member Functions


/* Name: Print
 * Description:	Prints the current value of digit
 */
void Digit::print(){
    cout << this->value << endl;
}

//Setters//
/* Name: setValue
 * Description:	sets value using the passed parameter
 * Modifies:	modifies the current value of the private variable value
 * Pre:         the passed parameter must be a positive integer
 */
void Digit::setValue(int v){
    this->value = v;
}

//Getters//
int Digit::getValue(){
    return this->value;
}