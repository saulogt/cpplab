//
//  MyGraph.cpp
//  cpplab
//
//  Created by Saulo Tauil on 2016-08-13.
//  Copyright © 2016 Saulo Tauil. All rights reserved.
//

#include "MyGraph.hpp"


void testGraph(){
    MyGraph<string> g;
    
    g.addNode("a", {"b"});
    g.addNode("c", {"a"});
    g.addNode("b", {});
    
}