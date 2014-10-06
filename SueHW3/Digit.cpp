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
Digit::Digit(int aDigit){
    this->value = aDigit;
}
//Deconstructor
Digit::~Digit(){
}

//Member Functions


/* Name: Print
 * Description:	Prints the current value of digit
 */
void Digit::print(){
    std::cout << this->value ;//<< "\n";
}

//TODO: Description with pre/post conditions
bool Digit::isGreaterThan(Digit* d){
    if(this->value > d->getValue()){
        return true;
    }else{
        return false;
    }
}

//TODO: Description with pre/post conditions
bool Digit::isEqualTo(Digit* d){
    if(this->value == d->getValue()){
        return true;
    }else{
        return false;
    }
}

//TODO: Description with pre/post conditions
bool Digit::isLessThan(Digit* d){
    if(this->value < d->getValue()){
        return true;
    }else{
        return false;
    }
}


//Setters//
/* Name: setValue
 * Description:	sets value using the passed parameter
 * Modifies:	     modifies the current value of the private variable 'value'
 * Pre-Condition:         the passed parameter must be a positive integer
   Post-Condition:  'value' is now set to a new value
 */
void Digit::setValue(int v){
    this->value = v;
}

//Getters//
int Digit::getValue(){
    return this->value;
}