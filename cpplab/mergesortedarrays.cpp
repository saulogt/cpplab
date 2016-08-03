//
//  mergesortedarrays.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-02.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "mergesortedarrays.hpp"

class MergeException : public std::runtime_error {
public:
   
    MergeException(const string& msg) : std::runtime_error(msg){
        
    }
    MergeException(const char* msg) : std::runtime_error(msg){
        
    }
};

vector<int>& mergesortedarray::doTheStuff(vector<int> &v1, vector<int> &v2){
    
    v1.reserve(v1.size()+ v2.size());
    
    auto iv1 = v1.begin();
    auto iv2 = v2.begin();
    
    while (iv1 != v1.end() && iv2 != v2.end()){
        if (*iv1 < *iv2){
            ++iv1;
        }
        else {
            v1.insert(iv1++, *iv2);
            ++iv2;
        }
    }
    
    if (iv2 != v2.end()){
        v1.insert(v1.end(), iv2, v2.end());
    }
    
    if (iv2 == v2.end()){
        throw MergeException("error");
    }
    
    return v1;
    
}