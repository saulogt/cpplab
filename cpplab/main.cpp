//
//  main.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-02.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include <assert.h>
#include <iostream>
#include "BST.hpp"
#include "mergesortedarrays.hpp"


void testBST(){
    vector<int> v = {3,4200,5,6,400,3,5,54,7,3,8,4,10,60,3,99,123};
    BST<int> bst;
    
    for (auto val: v) {
        bst.add(val);
    }
    
    assert(*bst.find(5) == 5 );
    assert(*bst.find(6) == 6 );
    assert(*bst.find(7) == 7 );
    assert(bst.find(5555) == nullptr );
    assert(*bst.find(123) == 123 );
    
    

}

void testMergeSortedArray(){
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
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    testMergeSortedArray();
    
    testBST();
    
 
        
    return 0;
}
