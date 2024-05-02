#include <iostream>
#include <vector>
#include <string>

using namespace std; 


// EACH SLOT HAS 2 COMPONENTS. STATUS, AND VALUE. 

// never used, tombstone, occupied
// table starts with 26 never used slots a-z. 
// length of key at most 10. Hash func uses last character. 


// Search: if key matches, then its been found. If never used, or tombstone, move onto next slot. 
//         Need to wrap around if its the last one. 

// Insertion: Check that key DOES NOT exist. If it exists, do nothing. 
//            Take last char as as key. If not used/tombstone, put key there. Try 
//            nxet slot if occupied. 

// Deletion: Search for it. Find key and change slot status to tombstone. 
// vector<string> getInput() {

// }
vector<string> getInput() {
    // tokenise and get input
}

struct Entry {
    string key; // Single letter
    string status; // Never Used, Occupied, Tombstone
    Entry() {
        key = "";
        status = "Never Used";
    }
};

class hashTable {
    private:
        vector<Entry> hTable; // Vector of Entries. 
    public:        
        // Initialise the hash table, with 26 "never used" entries
        hashTable() {
            for(int i = 0; i < 26; i++) {
                hTable.push_back(Entry());
            }
        }

        // Take word in. Use last letter. Convert letter to hash table index. 
        int hash(string key) {
            char lastChar = key.back(); // access last char. 
            return (lastChar - 'a')  % 26; 
        }

        // Start at the hashed entry. Then keep looking, and eventually wrap around. Do this 26 times.
        int Search(string key) {
            int targetIndex = hash(key);
            int maxIterations = 26 - hash(key);

            for(int i = 0; i < 26; i++) {
                // To be found, it must be marked occupied, and the keys must match. 
                if((hTable[targetIndex].key == key) && (hTable[targetIndex].status == "Occupied")) {
                    return targetIndex; 
                } else {
                    targetIndex = (targetIndex + 1) % 26; // to wrap around properly. 
                }
            }

            // If it's looked through 26 entries, then it doesn't exist, or it's been deleted.
            // Therefore, return false.  
            return -1; 
        }

        void Insert(string key) {
            // If it exists, return. 
            if(Search(key) != -1) {
                return;
            }

            int targetIndex = hash(key); // position in hash table, where you intend to store the key.  
            // Similar wrap around technique, to Search() function. 
            for(int i = 0; i < 26; i++) {
                if((hTable[targetIndex].status == "Never Used") || (hTable[targetIndex].status == "Tombstone")) {
                    hTable[targetIndex].key = key; 
                    hTable[targetIndex].status = "Occupied";
                    return;
                } 
                // If it's occupied, increase the index. Eventually wrap around. 
                if(hTable[targetIndex].status == "Occupied") {
                    targetIndex = (targetIndex + 1) % 26;  
                } 
            }
        }

        void Delete(string key) {
            int deletionTarget = Search(key);
            // If it does exist. 
            if(deletionTarget != -1) {
                hTable[deletionTarget].status == "Tombstone";
            }   

            return;
        }

        void printTable() {
            for(int i = 0; i < 26; i++) {
                // Entry must exist. 
                if(hTable[i].status == "Occupied") {
                    if(i == 25) {
                        // print with no space.
                        cout << hTable[i].key;
                    } else {
                        // print with space. 
                        cout << hTable[i].key << " ";
                    }
                }
            }
        }
};

int main(void) {
    // Execute instructions that are received, from getInput. 
    vector<string> fullInstructions = getInput(); 
    hashTable ht();
    
    size_t instructionCount = fullInstructions.size(); 
    for(int i = 0; i < instructionCount; i++) {
        
    }
    // Print the table. 
    return 0;
}