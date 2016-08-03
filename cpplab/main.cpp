//
//  main.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-02.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include <iostream>

#include "mergesortedarrays.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    try {
    
    mergesortedarray m;
    
    vector<int> v1 = {1, 2, 3, 4, 10};
    vector<int> v2 = {6, 7, 8, 9};
    
    
    m.doTheStuff(v1, v2);
    
    cout << &v1;
    
    }
    catch (exception& e){
        cout << "Exceptions occured: " << e.what() << endl;;
    }
        
    return 0;
}
