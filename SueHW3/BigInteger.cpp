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


//TODO: Description
//Returns true if 'number' is greater than digits
//returns false if digits is greater than 'number'
bool BigInteger::isGreaterThan(string number){
    
    
    //TODO: Implement
    bool result;
    
    //YOUR CODE GOES HERE to SET RESULT AS TRUE OR FALSE
    
    
    //If one array has greater size -- If Digits is longer 'number' return false
    //if else -If Digits is shorter 'number' return true
    //else -  the vectors are of equal length.
        //Loop the numbers
        //[6,7,4]
        //[6,4,2]
        //first past -  compare 6 to 6 -
                //if statement- if they are equal, compare next
                //if  Digits is greater than 'number' return false
                //If Digits is less 'number' return true
    
    
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

//TODO: Description
string BigInteger::add(string number){
    
    vector <int> numVector = convertStringToVector(number);
    
    //Add numVector and Digits together to by each element to get a result.
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

//TODO: Description
string BigInteger::subtract(string number){
    
    vector <int> numVector = convertStringToVector(number);
    
    //Subtract numVector and Digits by each element to get a result.
    
    int maxindex=0;
    int index=0;
    int diffNum=0;
    int flag=0;
    
    if(digits.size() < numVector.size()){
        index = int(numVector.size()-1);
        maxindex = int(numVector.size() - digits.size());
        flag=1;
    }
    if(digits.size() > numVector.size()){
        index = int(digits.size()-1);
        maxindex = int(digits.size() - numVector.size());
    }
    if(digits.size() == numVector.size()){
        index = int(digits.size()-1);
        maxindex = int(digits.size() - numVector.size());
        //Do a do loop and add then compare
    }
    
    //TODO: do the comparision, return error if negative
    //if(isGreaterThan(number)) return "Error, negative result pending."; //Return error
    
    if(digits[maxindex] < numVector[maxindex]) flag=1;
    
    cout << "INDEX = " << index << " maxindex = " <<maxindex << endl;
    
    for(int i = index; i >= maxindex;){
        cout << " digits " << digits[i] << "numVector= "<< numVector[i] << endl;
        if(digits[i] < numVector[i]){
            digits[i] = digits[i] + 10;
            digits[i-1] = digits[i - 1] - 1;
        }
        diffNum = int(digits[i] - numVector[i]);
        digits[i] = diffNum;
        cout << "DIFFNUM " << diffNum << endl;
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


//TODO: Description
string BigInteger::multiply(string number){
    
    //convert the final vector to a string and return.

    //TODO: implement
    return number;
    
}
//TODO: Description
string BigInteger:: divide(string number){
    //convert the final vector to a string and return.
    
    //TODO: implement
    return number;
}
//TODO: Description
void BigInteger:: increment(){
    
    //TODO: implement
    //string myNewNum = add("1");
    //digits = convertStringToVector(myNewNum);
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

