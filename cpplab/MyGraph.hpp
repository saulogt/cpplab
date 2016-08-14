//
//  MyGraph.hpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-13.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#ifndef MyGraph_hpp
#define MyGraph_hpp

#include <stdio.h>
#include <list>
#include <unordered_map>
#include <string>

using namespace std;

template <typename T>
class MyGraphNode {
    T obj;
    list<MyGraphNode<T>*> links;
public:
    const T& getObj() const{
        return obj;
    }
    
    MyGraphNode<T>(const T& value)
    :obj(value)
    {
        
    }
    
    void addLink(MyGraphNode<T>* n){
        links.push_back(n);
    }
    
    bool Marked = false;
    
};

template<typename T>
class MyGraph{
    MyGraphNode<T>* root;
    unordered_map<T, MyGraphNode<T> > allNodes;
    
    MyGraphNode<T>* getOrAddNode(const T& l){
        auto found = allNodes.find(l);
        MyGraphNode<T>* newNode;
        if (found == allNodes.end()){
            auto res = allNodes.insert({l, MyGraphNode<T>(l)});
            newNode = &(res.first->second);
        }
        else {
            newNode = &(found->second);
        }
        return newNode;
    }
    
public:
    void addNode(const T& value, const list<T>& links){
        auto newNode = getOrAddNode(value);
        if (root == nullptr){
            root = newNode;
        }
        
        for (auto& l : links){
            
            if (l == value){
                throw std::runtime_error("invalid data");
            }
            
            auto node = getOrAddNode(l);
            newNode->addLink(node);
        }
    }
    
    MyGraphNode<T>* getRoot() {
        return root;
    }
};


void testGraph();

#endif /* MyGraph_hpp */
