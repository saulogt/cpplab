//
//  q1_2.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-05.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "q1_2.hpp"

#include <assert.h>

#include <string>
#include <map>
#include <unordered_map>

using namespace std;

bool isPermutation(const string & s1, const string& s2){
    
    if (s1.size() != s2.size()){
        return false;
    }
    
    map<char, int> chars;
    
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        
        auto found = chars.find(*it);
        if (found == chars.end()){
            chars.insert(pair<char, int>(*it, 1));
        }
        else {
            (*found).second++;
        }
    }
    
    for (auto it = s2.begin(); it != s2.end(); ++it){
        auto found = chars.find(*it);
        if (found == chars.end())
            return false;
        
        if ((*found).second == 1){
            chars.erase(found);
        }
        else {
            (*found).second--;
        }
    }
    
    
    return chars.size() == 0;
    
    
}

void testQ1_2() {
    
    assert(isPermutation("abcdee", "ecdeba"));
    
    
    assert(isPermutation("abcde", "ecdba"));
    assert(!isPermutation("abcdes", "ecdba"));
    
    assert(isPermutation("aba", "baa"));
    
}


