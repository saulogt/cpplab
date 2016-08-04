//
//  BST.hpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-04.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>
#include <iterator>

template <typename T>
class BST {
    
    class Node {
        friend BST;
        Node* greater;
        Node* less;
        
        T value;
        
        Node(const T& v) : greater(nullptr), less(nullptr), value(v){
            

        }
        
        ~Node(){
            delete greater;
            delete less;
        }
        
        T* find(const T& v){
            if (v > value){
                if (greater != nullptr){
                    return greater->find(v);
                }
            } else if (v < value) {
                if (less != nullptr){
                    return less->find(v);
                }
            } else {
                return &value;
            }
            return nullptr;
        }
        
    };
    
    Node* root;
    
    Node* add(const T& v, Node* root){
        if (root == nullptr){
            return new Node(v);
        } else {
            if (v > root->value)
                root->greater = add(v, root->greater);
            else if (v < root->value){
                root->less = add(v, root->less);
            }
            
            return root;
        }
    }
    
public:
    BST() : root(nullptr){
        
    }
    
    BST(std::iterator<std::forward_iterator_tag, T> start, std::iterator<std::forward_iterator_tag, T> end) : root(nullptr){
        
        for (auto s = start; s != end; ++s){
            add(*s);
        }
    }
    
    void add(const T& value){
        root = add(value, root);
    }
    
    const T* find(const T& val) const{
        
        if (root == nullptr){
            return nullptr;
        }
        return root->find(val);
    }
            
};

#endif /* BST_hpp */
