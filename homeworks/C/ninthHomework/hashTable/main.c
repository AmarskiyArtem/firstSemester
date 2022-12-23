#include <stdio.h>

#include "list.h"
#include "hashTable.h"


void main() {
    HashTable* hashTable = createHashTable();
    if (hashTable == NULL) {
        return;
    }
    addValue(hashTable, "fff");
    addValue(hashTable, "aab");
    addValue (hashTable, "zzz");
    addValue(hashTable, "fgf");
    addValue(hashTable, "aab");
    addValue(hashTable, "zzf");
    addValue(hashTable, "fff");
    addValue(hashTable, "aab");
    addValue(hashTable, "zbz");
}