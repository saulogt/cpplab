//
//  q1_5.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-08.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "q1_5.hpp"
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;


class OneDifference {
    
    const string& s1;
    const string& s2;
    
    
    bool checkInsert(){
        auto bigger = s1.size() > s2.size() ? s1 : s2;
        auto smaller = s2.size() < s1.size() ? s2 : s1;
        
        auto itb = bigger.begin();
        auto its = smaller.begin();
        
        bool differenceFound = false;
        
        while (itb != bigger.end() && its != smaller.end()){
            if (*itb != *its){
                if (differenceFound){
                    return false;
                }
                
                itb++;
                differenceFound = true;
            }
            else {
                itb++;
                its++;
            }
        }
        
        return true;
    }
    
    bool checkReplace(){
        
        bool foundDiff = false;
        
        for (auto it1 = s1.begin(), it2 = s2.begin() ; it1 != s1.end() && it2 != s2.end() ; ++it1, ++it2){
            if (*it1 != *it2){
                if (foundDiff){
                    return false;
                }
                
                foundDiff = true;
            }
        }
        
        return true;
    }
    
public:
    OneDifference(const string& s1, const string& s2)
    : s1(s1),  s2(s2){
        
    }
    
    bool check(){
        auto sz1 = s1.size();
        auto sz2 = s2.size();
        
        if (std::abs(static_cast<int>(sz1) - static_cast<int>(sz2)) > 1){
            return false;
        }
        
        if (sz1 != sz2){
            return checkInsert();
        
        } else {
            return checkReplace();
        }
        

    }
    
    
    
};


bool oneEditAway(const string& s1, const string& s2){
    
    OneDifference checker(s1, s2);
    return checker.check();
}



void testq1_5(){
    assert(oneEditAway("pale", "pale"));
    assert(oneEditAway("pale", "pala"));
    assert(oneEditAway("ple", "pale"));
    assert(oneEditAway("paler", "pale"));
    assert(!oneEditAway("pela", "pale"));
    assert(!oneEditAway("palee", "pwle"));
    
}