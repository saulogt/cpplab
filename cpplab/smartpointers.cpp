//
//  smartpointers.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-09.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include <string>

#include "smartpointers.hpp"


////Incomplete

using namespace std;

class Teste{
    string sss;
    
public:
    Teste(const string& that)
    :sss(that){
        
    }
};


void testeSmartpointers(){
    
    auto s = make_shared<Teste>("teste");
    
    
}