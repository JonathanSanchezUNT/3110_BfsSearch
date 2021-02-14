//
//  bfsSearch.hpp
//  proj2
//
//  Created by Jonathan Sanchez on 2/27/20.
//  Copyright © 2020 Jonathan Sanchez. All rights reserved.
//
#ifndef bfsSearch_hpp
#define bfsSearch_hpp

#include <stdio.h>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Node
{
public:
    int data = 0;
    Node *child[50];
    int childSize = 0;
    int childArray[50] = {0};
    int visit = 0;
};


void bfs(Node* node[]);
#endif /* bfsSearch_hpp */
