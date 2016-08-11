//
//  movesemantics.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-09.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include <vector>
#include <string>
#include "movesemantics.hpp"

using namespace std;

///TODO: Incomplete


void testMove(){
    
    vector<string> ss1 = {"aaa", "sssddd"};
    ss1.push_back("abc");
    ss1.emplace_back("sssss");
    ss1.push_back("iii");
    ss1.push_back("wer");
    
    vector<string> ss2;
    ss2.push_back("xxxxxx");
    ss2.push_back("yyyyyyyy");
    
    ss2 = std::move(ss1);
    
    string s("Ssssssssssss");
    
    
    
}