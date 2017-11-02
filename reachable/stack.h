//
//  stack.h
//  COSC 2430 Project 4
//
//  Created by William Ko on 11/20/16.
//  Copyright © 2016 Will Ko. All rights reserved.
//

#include <stack>
#include <vector>
using namespace std;

class stackGraph {
    int V;
    list<int> *adj;
public:
    stackGraph(int V);
    void addEdge(int v, int w);
    void DFS(int s);
};

stackGraph::stackGraph(int V) {
    this -> V = V;
    adj = new list<int>[V];
}

void stackGraph::addEdge(int i, int j) {
    adj[i].push_back(j);
}

void stackGraph::DFS(int s) {
    // Initially mark all verices as not visited
    vector<bool> visited(V, false);
    
    stack<int> stack;
    
    stack.push(s);
    
    while (!stack.empty()) {
        s = stack.top();
        stack.pop();
        
        // Only save the popped s if it has not yet been visted
        if (!visited[s]) {
            cout << s << " ";
            
            //
            
            
            visited[s] = true;
        }
        
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}
