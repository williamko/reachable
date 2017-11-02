//
//  reachability.cpp
//  COSC 2430 Project 4
//
//  Created by William Ko on 11/15/16.
//  Copyright © 2016 Will Ko. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include "ArgumentManager.h"
#include "stack.h"
#include "hash.h"

using namespace std;

int* arrayA;
int* arrayDFS;
int lengthA;
int commentsInA;

int dfsCount;

int zeroCounter;

string filenameE;
string labelFile;

bool emptyFile;

//
int arrayDFSCounter;
string* arrayLabel;
int lengthLabel;
int commentsInLabel;

// From array.h
int* matrixC;
int CLength;

//int cost[10][10];
//int i,j,k,n,top,v;
//int stack[10];
//int visit[10];
//int visited[10];

void readLabelFile(string inputFile) {
    cout << "*** READING LABEL FILE***" << endl;
    
    // Prompt user for the Matrix input file name
    ifstream myFile;
    myFile.open(inputFile.c_str());
    
    // While the input file name is incorrect, prompt the user for a correct input file name
    while (myFile.fail()) {
        cout << "Error with file. Please use a valid file.";
        cin >> inputFile;
        myFile.open(inputFile.c_str());
    }
    
    if (myFile.peek() == std::ifstream::traits_type::eof()){
        emptyFile = true;
    } else {
        emptyFile = false;
    }
    
    int rows = 0;
    int columns = 0;
    
    int a = 0;
    int b = 0;
    
    int lineCounter = 0;
    int comments = 0;
    
    // CHECK: Reject input matrices with errors producing an empty file
    string line;
    while (getline(myFile, line)) {
        if (line[0] == '#' || line[0] == ' ' || line.empty()) { // Skip comments found in input file
            cout << "Comment found, skipping.." << endl;
            comments++;
            continue;
        } else {
            lineCounter++;
        }
    }
    
    // Skip comments
    for (int i = 0; i < comments; i++) {
        getline(myFile,line);
    }
    
    for (int i = 0; i < lineCounter; i++) {
        
        myFile >> a;
        myFile >> b;
        
        // Find number of rows in matrix
        if (a > rows) {
            rows = a;
        }
        
        // Find number of columns in matrix
        if (b > columns) {
            columns = b;
        }
    }
    
    // CHECK: Output an error if there is no matrix in the input file
    if (lineCounter == 0) {
        cout << "Error: Input file has no entries." << endl;
    }
    
    if (inputFile == labelFile) {
        lengthLabel = lineCounter * 2;
        cout << "lengthLabel is: " << lengthLabel << endl;
    }
    // Close file
    myFile.close();
    
    
}

void storeLabelFile(string inputFile) {
    cout << "*** STORING LABEL FILE***" << endl;
    
    int length;
    int comments;
    
    arrayLabel = new string[lengthLabel];
    length = lengthLabel;
    comments = commentsInLabel;
    
    // Prompt user for the Matrix input file name
    ifstream myFile(inputFile.c_str());
    
    string line;
    
    for (int i = 0; i < comments; i++) {
        getline(myFile,line);
    }
    
    for (int i = 0; i < length; i++) {
        myFile >> arrayLabel[i];
    }
    
    cout << "Vertex-ID and Label is: " << endl;
    for (int i = 0; i < length; i+=2) {
        cout << arrayLabel[i] << " " << arrayLabel[i+1] << endl;
    }
    
    cout << "ArrayLabel[0] = " << arrayLabel[0] << endl;

    
    // Close file
    myFile.close();
    
}
class Graph {
    
    int vertices;
    
    list<int> *adj;
    void helper(int v, bool visited[]);
    
public:
    
    Graph(int vertices);
    
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int vertices) {
    
    cout << "GOOD LUCK: Graph::Graph(int vertices) " << endl;

    this -> vertices = vertices;
    
    adj = new list<int>[vertices];
    
}

void Graph::addEdge(int i, int j) {
    cout << "GOOD LUCK: void Graph::addEdge(int i, int j) { " << endl;

    adj[i].push_back(j);
}

void Graph::helper(int v, bool visited[]) {

    visited[v] = true; // Node has now been visited
    
    arrayDFS[arrayDFSCounter] = v;
    arrayDFSCounter++;
    
    list<int>::iterator i;
    
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        
        if (!visited[*i]) {
            helper(*i, visited);
        }
    }
}

void Graph::DFS(int v) {
    
    cout << "void Graph::DFS(int v) {" << endl;

    // None of the vertices have been visited
    
    bool *visited = new bool[vertices];
    
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }
    
    helper(v, visited);
}

void readMatrix(string inputFile) {
    cout << "*** READING ***" << endl;

    // Prompt user for the Matrix input file name
    ifstream myFile;
    myFile.open(inputFile.c_str());
    
    // While the input file name is incorrect, prompt the user for a correct input file name
    while (myFile.fail()) {
        cout << "Error with file. Please use a valid file.";
        cin >> inputFile;
        myFile.open(inputFile.c_str());
    }
    
    if (myFile.peek() == std::ifstream::traits_type::eof()){
        emptyFile = true;
    } else {
        emptyFile = false;
    }
    
    int rows = 0;
    int columns = 0;
    
    int a = 0;
    int b = 0;
    
    int lineCounter = 0;
    int comments = 0;
    
    // CHECK: Reject input matrices with errors producing an empty file
    string line;
    while (getline(myFile, line)) {
        if (line[0] == '#' || line[0] == ' ' || line.empty()) { // Skip comments found in input file
            cout << "Comment found, skipping.." << endl;
            comments++;
            continue;
        } else {
            lineCounter++;
        }
    }
    
    // Skip comments
    for (int i = 0; i < comments; i++) {
        getline(myFile,line);
    }
    
    for (int i = 0; i < lineCounter; i++) {
        
        myFile >> a;
        // cout << "HERES THE a: " << a << endl;
        myFile >> b;
        
        // Find number of rows in matrix
        if (a > rows) {
            rows = a;
        }
        
        // Find number of columns in matrix
        if (b > columns) {
            columns = b;
        }
    }
    
    // CHECK: Output an error if there is no matrix in the input file
    if (lineCounter == 0) {
        cout << "Error: Input file has no entries." << endl;
    }
    
    if (inputFile == filenameE) {
        lengthA = lineCounter * 3;
        cout << "lengthA is: " << lengthA << endl;
    }
    
    // Close file
    myFile.close();
    
}

void storeMatrix(string inputFile) {
    cout << "*** STORING ***" << endl;
    
    int length;
    int comments;
    
    arrayA = new int[lengthA];
    length = lengthA;
    comments = commentsInA;
    
    // Prompt user for the Matrix input file name
    ifstream myFile(inputFile.c_str());
    
    string line;
    
    for (int i = 0; i < comments; i++) {
        getline(myFile,line);
    }
    
    for (int i = 0; i < length; i++) {
        myFile >> arrayA[i];
    }
    
    cout << "Adjaceny matrix E is: " << endl;
    for (int i = 0; i < length; i+=3) {
        cout << arrayA[i] << " " << arrayA[i+1] << " " << arrayA[i+2] << endl;
    }
    
    cout << "ArrayA[0] = " << arrayA[0] << endl;

    // Close file
    myFile.close();

}

void deleteRowsWithZeroEntries (int* matrix, int length) {
    // Delete rows with zero entries
    for (int i = 0; i < length; i++) {
        if (matrix[i] == 0) {
            // Iterate through the remaining elements, stopping one before the end.
            for (int j = i; j < length; j++) {
                
                // Overwrite the current element with the next.
                // This effectively deletes the item to delete, and moves everything else down one.
                matrix[j] = matrix[j + 1];
            }
            
            // Reduce the array size by 1
            length--;
        }
    }

    cout << "Deleting rows with zero entries" << endl;
    
    // TEST OUTPUT
    for (int i = 0; i < length; i++) {
        cout << "Matrix is now: " << matrix[i] << endl;
    }
    
}

void sortMatrix(int* matrix, int length) {
    cout << "*** SORTING ***" << endl;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length-1; j++) {
            if ((matrix[i] < matrix[j])) {
                swap(matrix[i], matrix[j]);
            }
        }
    }
    
    arrayDFS = matrix;
    
}

int zeroCount(int* matrix, int length) {
    int zCount = 0;
    
    for (int i = 0; i < length; i++) {
        if (matrix[i] == 0) {
            zCount++;
        }
    }
    
    return zCount;
}

int main(int argc, char * argv[]) {
    
    ArgumentManager am(argc, argv);

    string result = am.get("result");
    string dfs = am.get("dfs");
    
    // Uncomment for submission
//     string fileNameforAdjacencyMatrixE = am.get("E");
//     string source = am.get("source");
//     string k = am.get("k");x
//    string labels = am.get("labels");

    // Uncomment for Testing
    string fileNameforAdjacencyMatrixE = "01.txt";
    string source = "1";
    string labels = "01lbl.txt";
    dfs = "recursive";
    
    filenameE = fileNameforAdjacencyMatrixE.c_str();
    labelFile = labels.c_str();
    
    // Read adjacency matrix E
    readMatrix(fileNameforAdjacencyMatrixE);
    
    // Store adjacency matrix E
    storeMatrix(fileNameforAdjacencyMatrixE.c_str());
    
//    readLabelFile(labelFile);
//    storeLabelFile(labelFile);
//    
//    HashMap();
//    HashMap table;
//    
//    for (int i = 0; i < lengthLabel; i += 2) {
//        string id = arrayLabel[i];
//        string label = arrayLabel[i+1];
//        
//        table.put(std::stoi(id), label);
//
//    }
    
    // Find max value
    int max = arrayA[lengthA-2];
    cout << "max value is: " << max << endl;
    dfsCount = 0;
    arrayDFS = new int[max];
    arrayDFSCounter = 0;
    
    // Output to file
    string outputLine;
    
    // UNCOMMENT FOR SUBMISSION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//     ofstream outputFile(result.c_str());
    ofstream outputFile("result.txt");
    
    if (labels == "") { // No label file given
        
        Graph g(lengthA);
        
        for (int i = 0; i <= lengthA; i += 3) {
            g.addEdge(arrayA[i], arrayA[i+1]);
        }
        
        g.DFS(std::stoi(source));
        
        // Sort arrayDFS by vertex-id in ascending order
        sortMatrix(arrayDFS, arrayDFSCounter);
        
        if (outputFile.is_open()) {
            for (int i = 0; i < arrayDFSCounter; i++) {
                
                outputFile << arrayDFS[i] << endl;
                
            }
        }
        outputFile.close();
        
    } else { // Label file given
        
        readLabelFile(labelFile);
        storeLabelFile(labelFile);

        HashMap();
        HashMap table;
        
        
        for (int i = 0; i < lengthLabel; i += 2) {
            string id = arrayLabel[i];
            string label = arrayLabel[i+1];
            
            table.put(std::stoi(id), label);
            
        }
        
        if (dfs == "recursive") {

            Graph g(lengthA);
            
 

            for (int i = 0; i < lengthA; i += 3) {
                g.addEdge(arrayA[i], arrayA[i+1]);

            }
            

            g.DFS(std::stoi(source));
            

            // Sort arrayDFS by vertex-id in ascending order
            sortMatrix(arrayDFS, arrayDFSCounter);
            
            // Output to file
            string outputLine;
            
            if (outputFile.is_open()) {
                for (int i = 0; i < arrayDFSCounter; i++) {
                    
                    outputFile << arrayDFS[i] << " " << table.get(arrayDFS[i]) << endl;
                    
                }
            }
            outputFile.close();
            
        } else if (dfs == "no") {
            Graph g(lengthA);
            
            for (int i = 0; i < lengthA; i += 3) {
                g.addEdge(arrayA[i], arrayA[i+1]);
            }
            
            g.DFS(std::stoi(source));
            
            // Sort arrayDFS by vertex-id in ascending order
            sortMatrix(arrayDFS, arrayDFSCounter);
            
            // Output to file
            string outputLine;
            
            if (outputFile.is_open()) {
                for (int i = 0; i < arrayDFSCounter; i++) {
                    
                    outputFile << arrayDFS[i] << " " << table.get(arrayDFS[i]) << endl;
                    
                }
            }
            outputFile.close();
             mtive") {
            Graph g(lengthA);
            
            for (int i = 0; i < lengthA; i += 3) {
                g.addEdge(arrayA[i], arrayA[i+1]);
            }
            
            g.DFS(std::stoi(source));
            
            // Sort arrayDFS by vertex-id in ascending order
            sortMatrix(arrayDFS, arrayDFSCounter);
            
            // Output to file
            string outputLine;
            
            if (outputFile.is_open()) {
                for (int i = 0; i < arrayDFSCounter; i++) {
                    
                    outputFile << arrayDFS[i] << " " << table.get(arrayDFS[i]) << endl;
                    
                }
            }
            outputFile.close();
        }
        
    }

}
