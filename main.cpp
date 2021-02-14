//
//  main.cpp
//  proj2
//
//  Created by Jonathan Sanchez on 2/27/20.
//  Copyright © 2020 Jonathan Sanchez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include "bfsSearch.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    
    string line;
    int value;
    Node* structArray[50];
    for (int i=0; i<50; i++) {
        structArray[i] = new Node;
    }
    
    ifstream myFile ("data2.txt");
    if(myFile.is_open())
    {
        cout << "Success opening file, here is the data: " << endl;
        int nodeNum = 0;
        int j = 0;
        while (getline(myFile, line))
        {
            j = 0;
            stringstream ss(line);
            
            ss>>value;
            structArray[nodeNum]->data = value;
            while (ss>>value)
            {
                structArray[nodeNum]->childArray[j] = value;
                j++;
            }
            cout << endl;
            cout << line << endl;
            structArray[nodeNum]->childSize=j;
            nodeNum++;
        }
        myFile.close();
        cout << "*-------------------------*" << endl;

        for (int i=0; i<nodeNum; i++) {
            for (int y=0; y<structArray[i]->childSize; y++) {
                for (int z=0; z<
                     nodeNum; z++) {
                    if(structArray[i]->childArray[y] == structArray[z]->data)
                    {
                        structArray[i]->child[y] = structArray[z];
                    }
                }
                
            }
        }
        
        bfs(structArray);
        ofstream outFile;
        outFile.open("out2.txt");
        for (int i=0; i<nodeNum; i++) {
            if (structArray[i]->visit == 0) {
                cout << "Result after performing BFS: Graph is not connected." << endl << endl;
                outFile << "Graph is not connected.";
                return 0;
            }
        }
        cout << "Result after performing BFS: Graph is connected." << endl << endl;
        outFile << "Graph is connected.";
    	}
    return 0;
}
