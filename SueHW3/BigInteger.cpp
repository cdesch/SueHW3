//
//  BigInteger.cpp
//  SueHW3
//
//  Created by cj on 9/25/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "BigInteger.h"

//COPY FROM HERE //

//Constructor with parameters
BigInteger::BigInteger(string ns){
    for(int i=0; i < ns.size(); i++){
        // cout << ns[i] << endl;
        char myDigit = ns[i];
        int myTempInt = convertCharToInt(myDigit);
        //cout << myDigit <<"-" << myTempInt << endl;
        digits.push_back(myTempInt);
    }
}

//Deconstructor
BigInteger::~BigInteger(){
}

//My Simple char to int converter via ASCII indexs
int BigInteger::convertCharToInt(char c){
    int myTempInt = (int)c;
    if(myTempInt < 48 || myTempInt > 57) return -1; //Error checking
    return myTempInt - 48;
}

vector <int> BigInteger::convertStringToVector(string ns){
    vector <int> myVector;
    myVector = atoi(ns.c_str());
    return ns.push_back(myVector());
}


vector <BigInteger> reverseVector(vector<BigInteger> digits){
    vector <BigInteger> reverseVector;
    for (int j = int(digits.size() - 1); j >= 0; j--){
        reverseVector.push_back(digits[j]);
    }
    return reverseVector;
}

//Member Functions ??????????
// Print, Add, Subtract, Multiply, Divide, Factorial, Increment
void BigInteger::print(){ //Prints out digits of BigInteger
    
    for (int i  = 0; i < digits.size(); i++){
        cout << digits[i];
    }
    cout << endl;
    
    /*
     if(negative && (getSize()==1 && get(1)==0)==false) //If negative, prints out '-' for nonzero numbers
     cout << "-";
     for(int i=size-1; i>=0; i--){
     cout << digits[i];
     }
     */
}

//get a digit at a given index
int BigInteger::getDigit(int index){  //Returns digit of BigInteger at index, according to the array of string stored backward
    if(index < 0 || index >= digits.size()){  //Index is invalid
        return -1;
    }
    return digits[index];
}

string BigInteger::add(string number){
    
    //vector <int> whatever = convertStringToVector(number);
    vector <int> numVector = convertStringToVector(number);
    int carry=0;
    for(int i = digits.size(); i >= 0; i--){
        int sum = number[i] + digits[i] + carry;
        if(sum >= 10){
            carry = (sum/10)%10;
            sum=sum-10;
            number[i]=sum;
        }
    }
    cout << "number " << number << endl;
    
    //For Debugging -- Print the vectors.
    
    //convert the final vector to a string and return.
    
    return number;
}


//Getters
long BigInteger::getSize(){
    return digits.size();
}

/*
 bigInteger* addAny(bigInteger* a, bigInteger* b){  //Return a+b, with regard to signs
 return 0;
 }
 bigInteger* subtractAny(bigInteger* a, bigInteger* b){  //Return a-b, with regard to signs
 return 0;
 }
 bigInteger* multiplyAny(bigInteger* a, bigInteger* b){  //Return a*b, with regard to signs
 return 0;
 }
 bigInteger* divideAny(bigInteger* a, bigInteger* b){  //Return a/b, with regard to signs
 return 0;
 }
 bigInteger* factorialAny(bigInteger* a, bigInteger* b){  //Return a!, with regard to signs
 return 0;
 }
 bigInteger* incrementAny(bigInteger* a, bigInteger* b){  //Return a+increment, with regard to signs
 return 0;
 }
 */

/*
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
 */
