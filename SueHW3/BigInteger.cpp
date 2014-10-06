//
//  BigInteger.cpp
//  SueHW3
//
//  Created by cj on 9/25/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "BigInteger.h"

//COPY FROM HERE //

//Default Constructor
BigInteger::BigInteger(){
    //Empty
}

//Constructor with parameters
BigInteger::BigInteger(string ns){
    digits = convertStringToVector(ns);
    //TODO: ->
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


//Does a comparison of two vectors to determine which has a greater value
//Returns true if 'number' is greater than digits
//returns false if digits is greater than 'number'
bool BigInteger::isGreaterThan(vector <int> numVector){
    bool result;
    //result = false;
    //Compare two vectors
    //If one array has greater size -- If Digits is longer 'number' return false
    //if else -If Digits is shorter 'number' return true
    //else -  the vectors are of equal length.
    //Loop over the digits
    //if statement- if they are equal, compare next
    //if  Digits is greater than 'number' return true
    //If Digits is less 'number' return true
    
    
    
    
    if(digits.size() < numVector.size()){
        result = true;
        return result;
    }else if(digits.size() > numVector.size()){
        result = false;
        return result;
    }
    
    
    if(digits.size() == numVector.size()){
        for(int i = 0; i < digits.size();i++){
            
            cout << i << " i " << digits.size() << endl;
            if(digits[i] > numVector[i]){
                result = false;
                return result;
                
            }else if(digits[i] < numVector[i]) {
                cout << "i = " << i << " digits[i] " << digits[i] << " number[i] " << numVector[i] << endl;
                cout << "GOT HERE"<< endl;
                result = true;
                return result;
            }
            //else continue;
        }
    }
    return result;
}

//Description: Reverses the digits in the vector.
vector <int> BigInteger::reverseVector(vector<int> digits){
    vector <int> reverseVector;
    for (int j = (int)(digits.size() - 1); j >= 0; j--){
        reverseVector.push_back(digits[j]);
    }
    return reverseVector;
}

// Print, Add, Subtract, Multiply, Divide, Factorial, Increment
void BigInteger::print(){ //Prints out digits of BigInteger
    
    for (int i  = 0; i < digits.size(); i++){
        cout << digits[i];
    }
    cout << endl;
}

//get a digit at a given index
int BigInteger::getDigit(int index){  //Returns digit of BigInteger at index, according to the array of string stored backward
    if(index < 0 || index >= digits.size()){  //Index is invalid
        return -1;
    }
    return digits[index];
}

//Add numVector and Digits together to by each element to get a result.
string BigInteger::add(string number){
    
    vector <int> numVector = convertStringToVector(number);
    
    int carry=0;
    int newIndex, index;
    int sumNum=0;
    index = int(digits.size()-1);
    newIndex = abs(int(digits.size()-numVector.size()));
    
    if(digits.size() <= numVector.size()){
        index = int(numVector.size()-1);
        for(int i = index; i >= newIndex; i--){
            sumNum = numVector[i] + digits[i-newIndex] + carry;
            if(sumNum >= 10){
                carry = (sumNum/10) % 10;
                sumNum=sumNum-10;
            }
            else{
                carry = 0;
            }
            numVector[i]=sumNum;
        }
        if(carry==1) numVector[newIndex-1] = numVector[newIndex-1]+1;
        number=convertVectorToString(numVector);
    }
    
    //For Debugging -- Print the vectors.
    /*for (int i =0; i < digits.size(); i++){
     cout << numVector[i];
     }
     */
    
    if(digits.size() > numVector.size()){
        for(int i = int(digits.size()-1); i >= newIndex; i--){
            sumNum = numVector[i-newIndex] + digits[i] + carry;
            if(sumNum >= 10){
                carry = (sumNum/10) % 10;
                sumNum=sumNum-10;
            }
            else{
                carry = 0;
            }
            digits[i]=sumNum;
        }
        if(carry==1) digits[newIndex-1] = digits[newIndex-1]+1;
        number=convertVectorToString(digits);
    }
    
    //For Debugging -- Print the vectors.
    /*for (int i =0; i < digits.size(); i++){
     cout << digits[i];
     }
     cout << endl;
     */
    
    //convert the final vector to a string and return.
    return number;
}

//Subtract two numbers
string BigInteger::subtract(string number){
    
    vector <int> numVector = convertStringToVector(number);
    
    //Subtract numVector from Digits by each element to get a result.
    
    int maxindex=0;
    int index=0;
    int diffNum=0;
    
    if(isGreaterThan(numVector)) return "Error, negative result."; //Return error
    
    index = int(digits.size()-1);
    maxindex = int(digits.size() - numVector.size());
    
    for(int i = index; i >= maxindex;){
        if(digits[i] < numVector[i-maxindex]){
            digits[i] = digits[i] + 10;
            digits[i-1] = digits[i-1]-1;
        }
        diffNum = int(digits[i] - numVector[i-maxindex]);
        digits[i] = diffNum;
        i=i-1;
    }
    number = convertVectorToString(digits);
    //}
    
    //For Debugging -- Print the vectors.
    /*for (int i =0; i < digits.size(); i++){
     cout << numVector[i];
     }
     */
    //convert the final vector to a string and return.
    return number;
}


//TMultiplying two numbers and returning the resultant vector to a string
string BigInteger::multiply(string number){
    
    vector <int> numVector = convertStringToVector(number);
    
    int index, index2, maxindex, flag, carry, i;
    flag = 0;
    carry = 0;
    
    if(digits[0] < 0 || numVector[0] < 0) return "Error, negative number."; //Return error
    index = int(digits.size()-1);
    index2 = int(numVector.size()-1);
    maxindex = abs(int(digits.size() - numVector.size()));
    
    if(index >= index2) flag = 0;
    if(index < index2) flag = 1;
    cout << " flag is " << flag << endl;
    cout << "index = " << index << " index2 = " << index2 << " maxindex " << maxindex <<endl;
    if(flag == 0){
        for(i = index; i >= maxindex;i--){
            
            cout << "digits[i] " << digits[i] <<  "numVector[i] " << numVector[i] <<endl;
            digits[i] = int((digits[i]*numVector[i-maxindex]) + carry);
            
            if(int(digits[i]) >= 10){
                carry = int((digits[i]/10)%10);
                digits[i] = int(digits[i] - carry*10);
            }
            cout << i << " digits carry " << carry << endl;
            carry = 0;
        }
        if(flag == 1){
            for(i = index2; i >= maxindex;)
                numVector[i] = digits[i-maxindex]*numVector[i] + carry;
            cout << "numVector[i] " << numVector[i] << endl;
            if(int(numVector[i]) >=10){
                carry = int((numVector[i]/10)%10);
                numVector[i] = int(numVector[i] - carry*10);
            }
            cout << i << " numVector carry " << carry << endl;
            carry=0;
            i = i - 1;
        }
    }
    
    if(flag == 0) number=convertVectorToString(digits);
    if(flag == 1) number=convertVectorToString(numVector);
    return number;
}

//TODO: Description
string BigInteger:: divide(string number){
    //convert the final vector to a string and return.
    
    //TODO: implement
    return number;
}

//Increment the number by 1
void BigInteger:: increment(){
    string myNewNum = add("1");
    digits = convertStringToVector(myNewNum);
    return;
}

//decrement the number by 1
void BigInteger:: decrement(){
    string myNewNum = subtract("1");
    digits = convertStringToVector(myNewNum);
    return;
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

