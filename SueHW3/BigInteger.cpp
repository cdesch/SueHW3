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
    digits = convertStringToVector(ns);
}

//Deconstructor
BigInteger::~BigInteger(){
}

//Simple char to int converter via ASCII indexs
int BigInteger::convertCharToInt(char c){
    int myTempInt = (int)c;
    if(myTempInt < 48 || myTempInt > 57) return -1; //Error checking
    return myTempInt - 48;
}


//Simple int to char converter via ASCII indexes
char BigInteger::convertIntToChar(int i){
    char c;
    c = (char)i;
    return c + 48;
}

//Description: This converts a string into a vector. It converts all chars to integers in the process.
vector <int> BigInteger::convertStringToVector(string ns){
    vector <int> myVector;
    for(int i=0; i < ns.size(); i++){
        char myDigit = ns[i];
        int myTempInt = convertCharToInt(myDigit);
        myVector.push_back(myTempInt); //Pushes myTempInt into the vector named myVector
    }
    return myVector;
}

//Description: This converts a vector into a string.  It converts all integers to chars in the process.
string BigInteger::convertVectorToString(vector <int> myVector){
    string ns;
    for(int i=0; i < myVector.size(); i++){
        int myChar = myVector[i];
        char myTempChar = convertIntToChar(myChar);
        ns.push_back(myTempChar);
    }
    return ns;
}


//Description: Reverses the digits in the vector.
vector <int> BigInteger::reverseVector(vector<int> digits){
    vector <int> reverseVector;
    for (int j = (int)(digits.size() - 1); j >= 0; j--){
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
    
    vector <int> numVector = convertStringToVector(number);
    
    //Add numVector and Digits together to by each element to get a result.
    int carry=0;
    int index = int(digits.size() - 1);
    if(digits.size() > numVector.size()) index = int(numVector.size()-1);
    cout << "Index " << index << endl;
    for(int i = index; i >= 0; i--){
        int sumNum = numVector[i] + digits[i] + carry;
        if(sumNum >= 10){
            carry = (sumNum/10) % 10;
            sumNum=sumNum-10;
        }
        else{
            carry = 0;
        }
        cout << "sumNum " << sumNum <<endl;
        cout << "carry is " << carry << endl;
        numVector[i]=sumNum;
    }
    
    //For Debugging -- Print the vectors.
    for (int i =0; i < numVector.size(); i++){
        cout << numVector[i];
    }
    cout << endl;
    
    //convert the final vector to a string and return.
    number = convertVectorToString(numVector);
    return number;
}


//Getters
long BigInteger::getSize(){
    return digits.size();
}


//Tests//

void BigInteger::runTests(){
    cout << "Running Class Tests" << endl;
    testConvertVectorToString();
}
void BigInteger::testConvertVectorToString(){
    cout << "**Running " << __PRETTY_FUNCTION__ << endl;
    
    vector <int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    
    string myString = convertVectorToString(myVector);
    
    cout << "Converted String: " << myString << endl;
    
    cout << "**Ended " << __PRETTY_FUNCTION__ << endl;
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
