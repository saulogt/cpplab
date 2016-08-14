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

class MovableObject{
    
    string data;
public:
    
    MovableObject(){
        
    }
    
    MovableObject(const string& s): data(s){
        
        printf("constructor\n");
    }
    
    MovableObject(const MovableObject& other)
    :data(other.data){
            printf("copy\n");
    }
    
    MovableObject(MovableObject&& other)
    :data(move(other.data)){
        printf("move\n");
        
    }
    
    MovableObject& operator = (MovableObject&& other){
        swap(data, other.data);
        return *this;
    }
    
    MovableObject& operator = (const MovableObject& other){
        data= other.data;
        return *this;
    }
    
    friend void swap(MovableObject& lhs, MovableObject& rhs) throw() {
        MovableObject temp(move(lhs));
        lhs = move(rhs);
        rhs = move(temp);
    }
    
};

MovableObject getMovable(const string& s){
    MovableObject m(s);
    
    printf("m = %p\n", &m);
    
    return m;
    
}

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
    
    MovableObject m1(move(getMovable("First call")));
        printf("m1 = %p\n", &m1);
    
    MovableObject m1_5;
    swap(m1_5, m1);
    
    m1 = getMovable("Second call");
        printf("new m1 = %p\n", &m1);
    
    
    
    
    
}
