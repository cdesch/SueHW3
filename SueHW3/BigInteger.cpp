//
//  BigInteger.cpp
//  SueHW3
//
//  Created by cj on 9/25/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "BigInteger.h"



//Constructor with parameters
BigInteger::BigInteger(string ns, long int a, long int b){
    numsize = ns;
    numA = a;
    numb = b;
}

//Deconstructor

BigInteger::~BigInteger(){
}

//Member Functions ??????????
// Print, Add, Subtract, Multiply, Divide, Factorial, Increment


//Setters
void BigInteger::setSize(string ns){
    numsixe = ns;
}

void BigInteger::setNumA(long int a){
    long NumA = a;
}

void BigInteger::setNumB(long int b){
    long NumB = b;
}

//Getters
string BigInteger::getSize(){
    return ;
}

long int BigInteger::getNumA(){
    return NumA;
}

long int BigInteger::getNumB(){
    return NumB;
}


vector <BigInteger> digitVector(vector<BigInteger> numdigit){
    vector <BigInteger> digitVector;
    for (int j = 0; j<= int(numsize.size()); j++){
        digitVector.push_back(numdigit[j]);
    }
    return digitVector;
}

int BigInteger::getSize(){ //Returns number of digits in BigInteger
    return size;
}

int BigInteger::getcapSize(){ //Returns number of digits that BigInteger can potentially hold
    return capSize;
}

void BigInteger::print(){ //Prints out digits of BigInteger
    if(negative && (getSize()==1 && get(1)==0)==false) //If negative, prints out '-' for nonzero numbers
        cout << "-";
    for(int i=size-1; i>=0; i--){
        cout << digits[i];
    }
}

int BigInteger::get(int index){  //Returns digit of BigInteger at index, according to the array of string stored backward
    if(index<0 || index >= size){  //Index is invalid
        return -1;
    }
    return (digits[index]-'0');
}
void BigInteger::pushBack(string number){ //Adding string input to next free spot in digits array
    if(number<'0' || number>'9'){   //If string number isn't a single digit between 0 and 9.
        return;
    }
    if(size>=capSize)
        resize();
    digits[size] = number;
    size++;
}
void BigInteger::pushBack(int number){ //Adding int to next free spot in digits array
    if(number>=10){       //More than two digits
        cout << "\n ERROR in pushBack because number istoo big to push back.\n";
        return;
    }
    if(number<0){ //if a negative number
        cout << "\n ERROR in pushBack since push back a negative number: " << number << ".\n";
        return;
    }
    if(number%1!=0){ //if not an int
        cout << "\n ERROR in pushBack since unable to push back a double.\n";
        return;
    }
    
    if(size>=capSize){ //Digits capSize needs to increase in order to hold more
        resize();
    }
    if(number<=9){ //Checking valid digit
        digits[size] = '0' + number;
    }
    size++;
}
