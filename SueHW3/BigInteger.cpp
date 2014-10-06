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
    myDigits = convertStringToVector2(ns);
    //TODO: ->
}
//Deconstructor
BigInteger::~BigInteger(){
    //Remove all of the objects in the array;
    for (int i = 0; i < this->myDigits.size(); i++ ){
        delete myDigits[i];
    }
}


//Description: This converts a string into a vector. It converts all chars to integers in the process.
vector <int> BigInteger::convertStringToVector(string ns){
    vector <int> myVector;
    for(int i=0; i < ns.size(); i++){
        char myDigit = ns[i];
        int myTempInt = utility::convertCharToInt(myDigit);
        myVector.push_back(myTempInt); //Pushes myTempInt into the vector named myVector
    }
    return myVector;
}

vector <Digit*> BigInteger::convertStringToVector2(string ns){
    vector <Digit*> myVector;
    for(int i=0; i < ns.size(); i++){
        char myChar = ns[i];
        int myTempInt = utility::convertCharToInt(myChar);
        Digit* myDigit = new Digit(myTempInt);
        myVector.push_back(myDigit); //Pushes myTempInt into the vector named myVector
    }
    return myVector;
}


//Description: This converts a vector into a string.  It converts all integers to chars in the process.
string BigInteger::convertVectorToString(vector <int> myVector){
    string ns;
    for(int i=0; i < myVector.size(); i++){
        int myChar = myVector[i];
        char myTempChar = utility::convertIntToChar(myChar);
        ns.push_back(myTempChar);
    }
    return ns;
}


//Description: This converts a vector into a string.  It converts all integers to chars in the process.
string BigInteger::convertVectorToString(vector <Digit*> myVector){
    string ns;
    for(int i=0; i < myVector.size(); i++){
        int myChar = myVector[i]->getValue();
        char myTempChar = utility::convertIntToChar(myChar);
        ns.push_back(myTempChar);
    }
    return ns;
}


/*
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
*/

//Does a comparison of two vectors to determine which has a greater value
//Returns true if 'number' is greater than digits
//returns false if digits is greater than 'number'
bool BigInteger::isGreaterThan(vector <Digit*> numVector){
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
    
    if(myDigits.size() < numVector.size()){
        result = true;
        return result;
    }else if(myDigits.size() > numVector.size()){
        result = false;
        return result;
    }
    
    if(myDigits.size() == numVector.size()){
        for(int i = 0; i < myDigits.size();i++){
            
            cout << i << " i " << myDigits.size() << endl;
            if(myDigits[i]->getValue() > numVector[i]->getValue()){
                result = false;
                return result;
            }else if(myDigits[i]->getValue()  < numVector[i]->getValue() ) {
                //cout << "i = " << i << " digits[i] " << myDigits[i]->getValue() << " number[i] " << numVector[i]->getValue() << endl;
                //cout << "GOT HERE"<< endl;
                result = true;
                return result;
            }
            //else continue;
        }
    }
    return result;
}

vector<Digit*> BigInteger::removeLeadingZeros(vector<Digit*> myDigitVector){
    for (int i = 0; i < myDigitVector.size(); i++){
        
        if(myDigitVector[i]->getValue() == 0){
            //remove that leading 0;
            myDigitVector.erase(myDigitVector.begin()+0);
        }else{
            return myDigitVector;
        }
    }
    return myDigitVector;
}


/*
//Description: Reverses the digits in the vector.
vector <int> BigInteger::reverseVector(vector<int> digits){
    vector <int> reverseVector;
    for (int j = (int)(digits.size() - 1); j >= 0; j--){
        reverseVector.push_back(digits[j]);
    }
    return reverseVector;
}*/

//Description: Reverses the digits in the vector.
vector <Digit*> BigInteger::reverseVector(vector<Digit*> digits){
    vector <Digit*> reverseVector;
    for (int j = (int)(myDigits.size() - 1); j >= 0; j--){
        reverseVector.push_back(myDigits[j]);
    }
    return reverseVector;
}

// Print, Add, Subtract, Multiply, Divide, Factorial, Increment
void BigInteger::print(){ //Prints out digits of BigInteger
    
    for (int i  = 0; i < myDigits.size(); i++){
        cout << myDigits[i]->getValue();
    }
    cout << endl;
}

//get a digit at a given index
int BigInteger::getDigit(int index){  //Returns digit of BigInteger at index, according to the array of string stored backward
    if(index < 0 || index >= myDigits.size()){  //Index is invalid
        return -1;
    }
    return myDigits[index]->getValue();
}
/*
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
    

    //convert the final vector to a string and return.
    return number;
}
*/


void BigInteger::add(BigInteger* number){
    
    vector <Digit*> numVector = number->getVector();
    int carry=0;
    int newIndex, index;
    int sumNum=0;
    index = int(myDigits.size()-1);
    newIndex = abs(int(myDigits.size() - numVector.size()));
    
    //If myDigits is less than, store numbers in numVector
    //Fixme: Don't change numVectors numbers
    if(myDigits.size() <= numVector.size()){
        index = int(numVector.size()-1);
        for(int i = index; i >= newIndex; i--){
            sumNum = numVector[i]->getValue() + myDigits[i-newIndex]->getValue() + carry;
            if(sumNum >= 10){
                carry = (sumNum/10) % 10;
                sumNum=sumNum-10;
            }
            else{
                carry = 0;
            }
            numVector[i]->setValue(sumNum);
        }
        if(carry==1) {
            numVector[newIndex-1]->setValue(numVector[newIndex-1]->getValue()+1);
        }
        
        myDigits = numVector;

    }else if(myDigits.size() > numVector.size()){
        for(int i = int(myDigits.size()-1); i >= newIndex; i--){
            sumNum = numVector[i-newIndex]->getValue() + myDigits[i]->getValue() + carry;
            if(sumNum >= 10){
                carry = (sumNum/10) % 10;
                sumNum=sumNum-10;
            }
            else{
                carry = 0;
            }
            myDigits[i]->setValue(sumNum);
        }
        //
        if(carry==1){
            myDigits[newIndex-1]->setValue(myDigits[newIndex-1]->getValue()+1);
        }
    }

}
/*
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
    

    //convert the final vector to a string and return.
    if(number[0] == '0') number[0] = ' ';
    return number;
}
*/

void BigInteger::subtract(BigInteger* number){
    
    vector <Digit*> numVector = number->getVector();
    //Subtract numVector from Digits by each element to get a result.
    
    int maxindex=0;
    int index=0;
    int diffNum=0;
    
    if(isGreaterThan(numVector)) {
        cout << "Error, negative result." << endl; //Return error
        return;
    }
    
    index = int(myDigits.size()-1);
    maxindex = int(myDigits.size() - numVector.size());
    
    for(int i = index; i >= maxindex;){
        if(myDigits[i]->getValue() < numVector[i-maxindex]->getValue()){
            myDigits[i]->setValue(myDigits[i]->getValue() + 10);
            myDigits[i-1]->setValue( myDigits[i-1]->getValue()-1);
        }
        diffNum = int(myDigits[i]->getValue() - numVector[i-maxindex]->getValue());
        myDigits[i]->setValue(diffNum);
        i=i-1;
    }
    
    //Remove Leading zeros
    this->myDigits = removeLeadingZeros(this->myDigits);
    

}

// two numbers and returning the resultant vector to a string
string BigInteger::multiply(string number){
    
    vector <int> numVector = convertStringToVector(number);
    
    int index, index2, maxindex, flag, carry, i, j, vecSum;
    flag = 0;
    carry = 0;
    vecSum=0;
    
    if(digits[0] < 0 || numVector[0] < 0) return "Error, negative number."; //Return error
    index = int(digits.size()-1);
    index2 = int(numVector.size()-1);
    maxindex = abs(int(digits.size() - numVector.size()));
    
    if(index >= index2) flag = 0;
    if(index < index2) flag = 1;
    cout << " flag is " << flag << endl;
    cout << "index = " << index << " index2 = " << index2 << " maxindex " << maxindex <<endl;
    if(flag == 0){
        for(i = index2; i >=0;i--){
            for(j= index; j>=0;j--){
                cout << "digits[i] " << digits[i] <<  "numVector[i] " << numVector[i] <<endl;
                digits[i] = int((digits[j]*numVector[i]) + carry);
                
                if(int(digits[i]) >= 10){
                    carry = int((digits[i]/10)%10);
                    digits[i] = int(digits[i] - carry*10);
                    vecSum = vecSum+digits[i];
                }
                
                cout << i << " digits carry " << carry << endl;
                carry = 0;
            }
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



void BigInteger::multiply(BigInteger* number){

}

//TODO: Description
string BigInteger::divide(string number){
    //convert the final vector to a string and return.
    
    //TODO: implement
    return number;
}

void BigInteger::divide(BigInteger* number){}

//Increment the number by 1
//Fixme: add
void BigInteger::increment(){
//    string myNewNum = add("1");
//    digits = convertStringToVector(myNewNum);
    
}

//decrement the number by 1
//Fixme: subtract
void BigInteger::decrement(){
//    string myNewNum = subtract("1");
//    digits = convertStringToVector(myNewNum);
    
}

//Getters
long BigInteger::getSize(){
    return this->myDigits.size();
}

//TODO: Description pre/post
vector <Digit*> BigInteger::getVector(){
    return this->myDigits;
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

