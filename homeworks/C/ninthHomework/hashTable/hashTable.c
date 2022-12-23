#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "hashTable.h"

typedef struct HashTable {
    int size;
    int amountOfElements;
    float fillFactor;
    List** cells;
} HashTable;

 ErrorCode createCells(HashTable* table) {
    table->cells = malloc(table->size * sizeof(List*));
     if (table->cells == NULL) {
        return memoryAllocationError;
    }
    for (int i = 0; i < table->size; ++i) {
        table->cells[i] = createList();
        if (table->cells[i] == NULL) {
            return memoryAllocationError;
        }
    }
    return ok;
}

HashTable* createHashTable(void) {
    HashTable* hashTable = malloc(sizeof(hashTable));
    if (hashTable == NULL) {
        return NULL;
    }
    hashTable->size = 2;
    hashTable->amountOfElements = 0;
    hashTable->fillFactor = 0.0;
    if (createCells(hashTable) != ok) {
        return NULL;
    }
    return hashTable;
}

int hashFunction(char* string, int size) {
    int result = 0;
    int stringLength = strlen(string);
    for (int i = 0; i < stringLength; ++i) {
        result = (result + string[i]) % size; //*i try
    }
    return result;
}

ErrorCode add(HashTable* hashTable, char* string) {
    const int hashFunctionResult = hashFunction(string, hashTable->size);
    const int listLengthBeforeAdd = getLength(hashTable->cells[hashFunctionResult]);
    if (push(hashTable->cells[hashFunctionResult], string) != ok) {
        return memoryAllocationError;
    }
    if (getLength(hashTable->cells[hashFunctionResult]) != listLengthBeforeAdd) {
        ++(hashTable->amountOfElements);
        hashTable->fillFactor = 1.0 * hashTable->amountOfElements / hashTable->size;
    }
    return ok;
}

List* tempList(HashTable* table) {
    List* temp = createList();
    if (temp == NULL) {
        return NULL;
    }
    for (int i = 0; i < table->size; ++i) {
        while (!isEmpty(table->cells[i])) {
            char* string = getValueFromHead(table->cells[i]);
            push(temp, string);
            deleteHead(table->cells[i]);
        }
        deleteList(table->cells[i]);
    }
    return temp;
}

void deleteCells(HashTable* hashtable) {

    for (int i = 0; i < hashtable->size; ++i) {
        deleteList(&(hashtable->cells[i]));
    }
    deleteList(hashtable->cells);
}

ErrorCode increaseTable(HashTable* hashTable) {
    List* previouslyAddedStrings = tempList(hashTable);
    if (previouslyAddedStrings == NULL) {
        return memoryAllocationError;
    }
    deleteCells(hashTable);
    hashTable->size *= 2;
    hashTable->amountOfElements = 0;
    createCells(hashTable);
    while (!isEmpty(previouslyAddedStrings)) {
        char* string = getValueFromHead(previouslyAddedStrings);
        add(hashTable, string);
        deleteHead(previouslyAddedStrings);
    }
    deleteList(previouslyAddedStrings);
    return ok;
}

ErrorCode addValue(HashTable* hashTable, char* string) {
    if (add(hashTable, string) != ok) {
        return memoryAllocationError;
    }
    if (hashTable->fillFactor > 0.9) {
        if (increaseTable(hashTable) != ok) {
            return memoryAllocationError;
        }
    }
    return ok;
}
