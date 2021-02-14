//
//  bfsSearch.cpp
//  proj2
//
//  Created by Jonathan Sanchez on 2/27/20.
//  Copyright © 2020 Jonathan Sanchez. All rights reserved.
//
#include "bfsSearch.hpp"

void bfs(Node* nodes[])
{
    queue<Node*> myQueue;
    myQueue.push(nodes[1]);
    nodes[1]->visit=1;
    while (myQueue.size() > 0) {
        Node* x=myQueue.front();
        myQueue.pop();
        for (int i=0; i<x->childSize; i++) {
            if (x->child[i]->visit == 0) {
                x->child[i]->visit=1;
                myQueue.push(x->child[i]);
            }
        }
    }
}


