//
//  async_stuff.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-11.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "async_stuff.hpp"

#include <cassert>
#include <random>
#include <future>
#include <vector>

#include <functional>
#include <iostream>

using namespace std;


void test_future(){
    int n = 100;
    
    
    
    auto f = async(std::launch::any, [](int val){
        
        auto start = clock();
        
        vector<int> is;
        for (int i = 0; i < val ; i++){
            
            is.push_back(random());
        }
        
        sort(is.begin(), is.end());
        
        cout << "run time: " << clock() - start << endl;
        
        return is.size();
        
    }, n);
    
    f.wait();
    assert( f.get() == n );

}


void test_async_stuff(){

    test_future();
    
    
    
    
}