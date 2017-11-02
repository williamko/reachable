William Ko
1092928
COSC 2430
HW 4

This program finds reachable vertices using iteration of vector-matrix multiplications and DFS. Outputs the vertex-id and the corresponding label from the hash table (if applicable) to the output text file.

While testing the large test cases, I encountered an issue that would cause my program to continue running without ceasing. However, I was able to fix the issue by adjusting the hash table size and was able to successfully pass the large test cases.


reachability.cpp uses the ArgumentManager.h class to parse command line arguments.

