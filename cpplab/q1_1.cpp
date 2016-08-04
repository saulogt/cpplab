//
//  q1_1.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-04.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "q1_1.hpp"
#include <assert.h>
#include <string>
#include <unordered_set>

using namespace std;

bool hasUniqueChar(const string& s){
    
    unordered_set<char> ht;
    
    for (auto i = s.begin(); i != s.end(); ++i) {
        if (ht.find(*i) != ht.end()){
            return false;
        }
        ht.insert(*i);
    }
    return true;
    
}

void testQ1_1(){
    
    assert(hasUniqueChar("abcdewerrrrr") == false);
    assert(hasUniqueChar("aaaabcdewerrrrr") == false);
    assert(hasUniqueChar("abcde") == true);
    
    assert(hasUniqueChar("abcdefgh") == true);
    
    
}