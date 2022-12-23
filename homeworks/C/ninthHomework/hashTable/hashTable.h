#pragma once

typedef struct HashTable HashTable;

HashTable* createHashTable(void);

ErrorCode addValue(HashTable* hashTable, char* string);

