//
//  hash.h
//  COSC 2430 Project 4
//
//  Created by William Ko on 11/20/16.
//  Copyright © 2016 Will Ko. All rights reserved.
//

class HashTable {

private:
    int key;
    string value;

public:
    HashTable(int key, string value) {
        this->key = key;
        this->value = value;
    }

int getKey() {
    return key;
}

string getValue() {
    return value;
}
};

const int TABLE_SIZE = 10000;
class HashMap {

private:
    HashTable **table;
public:

    HashMap() {
        table = new HashTable*[TABLE_SIZE];
        
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }
    
    string get(int key) {
        int hash = (key % TABLE_SIZE);
        
        while (table[hash] != NULL && table[hash]->getKey() != key) {
            hash = (hash + 1) % TABLE_SIZE; // mod
        }
        
        if (table[hash] == NULL) {
            return "";
        } else {
            return table[hash]->getValue();
        }
    }
    
    void put(int key, string value) {
        int hash = (key % TABLE_SIZE);
        
        while (table[hash] != NULL && table[hash]->getKey() != key) {
            hash = (hash + 1) % TABLE_SIZE;
        }
        
        if (table[hash] != NULL) {
            delete table[hash];
        }
        
        table[hash] = new HashTable(key, value);
    }
    
    // Deconstructor
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL) {
                delete table[i];
            }
        }
        
        delete[] table;
    }
};
