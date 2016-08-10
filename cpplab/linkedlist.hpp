//
//  linkedlist.hpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-09.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#ifndef linkedlist_hpp
#define linkedlist_hpp

#include <stdio.h>
template<typename T>
class linkedlist {
    
    class Node {
   
    public:
        
        
        Node* next;
        T value;
   
        Node()
        : next( nullptr){
            
        }
        
        ~Node(){
            delete next;
        }
        
    };
    
    Node* root;
    Node* last;
public:
    linkedlist()
    : root(nullptr), last(nullptr){
        
    }
    
    ~linkedlist(){
        delete root;
    }
    
    void clear(){
        delete root; root = nullptr;
    }
    
    void add(const T& val){
        auto node = new Node();
        if (last){
            last->next = node;
            last = node;
        }
        else {
            root = last = node;
        }
    }
    
    
    
};

#endif /* linkedlist_hpp */
