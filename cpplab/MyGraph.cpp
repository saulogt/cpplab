//
//  MyGraph.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-13.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "MyGraph.hpp"
#include <queue>
#include <iostream>

bool visit(MyGraphNode<string>* g, const string& target){
    g->Marked = true;
    cout << g->getObj() << endl;
    return (g->getObj() == target);
}

class PathNode{
    MyGraphNode<string>* node;
    shared_ptr<PathNode> parent;
public:
    PathNode() = delete;
    
    PathNode(shared_ptr<PathNode> parent, MyGraphNode<string>* node)
    : parent(parent), node(node){
        
    }
    
    MyGraphNode<string>* getNode(){
        return node;
    }
    shared_ptr<PathNode> getParent(){
        return parent;
    }
    
    ~PathNode(){
        //cout << "destroy path node" << endl;
    }
    
};

int BFS(MyGraphNode<string>* g){
    
    queue<shared_ptr<PathNode> > q;
    q.push(make_shared<PathNode>(nullptr, g));
    
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        
        if (visit(curr->getNode(), "i")){
            auto temp = curr;
            while (temp != nullptr) {
                cout << temp->getNode()->getObj() << " <- ";
                temp = temp->getParent();
            }
            cout << endl;
            //break;
        }
        
        auto links = curr->getNode()->getLinks();
        for (auto l: links){
            if (!l->Marked){
                q.push(make_shared<PathNode>(curr, l));
                
            }
        }
        
    }
    return 0;
}

void testGraph(){
    MyGraph<string> g;
    
    g.addNode("a", {"b", "c"});
    g.addNode("c", {"a", "f"});
    g.addNode("b", {});
    g.addNode("e", {"g", "h"});
    g.addNode("f", {"e"});
    g.addNode("g", {"h", "i", "j"});
    
    
    auto r = g.getRoot();
    
    BFS(r);
    
    
}

