//
//  Utility.cpp
//  SueHW3
//
//  Created by cj on 10/6/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#include "Utility.hpp"

namespace utility{
    void function1()
    {
        //code
    }
    
    //Simple char to int converter via ASCII indexs
    int convertCharToInt(char c){
        int myTempInt = (int)c;
        if(myTempInt < 48 || myTempInt > 57) {
            std::cout << "Error: Not an integer!\n";
            return -1; //Error checking
        }
        return myTempInt - 48;
    }
    
    //Simple int to char converter via ASCII indexes
    char convertIntToChar(int i){
        char c;
        c = (char)i;
        return c + 48;
    }

}