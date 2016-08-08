//
//  q1_3.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-05.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "q1_3.hpp"


#include <assert.h>

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


void usePercent20(string& s, int sz){
    int nspaces = 0;
    string perc20 = "%20";
    
    for (int i = 0; i < sz; ++i){
        if (s[i] == ' ') {
            nspaces++;
        }
    }
    

    
    int finalsize = sz + (nspaces * 3);
    assert(s.size() >= finalsize);
    
    int lastbreak = sz;
    
    for (int i = sz-1; i >= 0; --i){
        if (s[i] == ' '){
            
            copy(&s[i], &s[lastbreak], &s[i + (nspaces * 3) - nspaces]);
            lastbreak = i;
            --nspaces;
            copy(perc20.begin(), perc20.end(), &s[i + (nspaces * 3) - nspaces]);
        }
    }
    
}


void testq1_3(){
    string s("a b c          ");
    usePercent20(s, 5);
    
    cout << "new s: " << s << endl;
    
    string s2("abc def ddd rrr eee zzz                            ");
    usePercent20(s2, 23);
    
    cout << "new s: " << s2 << endl;
}
