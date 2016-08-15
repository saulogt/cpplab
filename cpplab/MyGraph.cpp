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

void visit(MyGraphNode<string>* g){
    g->Marked = true;
    cout << g->getObj() << endl;
}

int BFS(MyGraphNode<string>* g){
    
    queue<MyGraphNode<string>*> q;
    q.push(g);
    
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        
        visit(curr);
        
        auto links = curr->getLinks();
        for (auto l: links){
            if (!l->Marked){
                q.push(l);
            }
        }
        
    }
    return 0;
}

void testGraph(){
    MyGraph<string> g;
    
    g.addNode("a", {"b", "c"});
    g.addNode("c", {"a"});
    g.addNode("b", {});
    
    auto r = g.getRoot();
    
    BFS(r);
    
    
}

