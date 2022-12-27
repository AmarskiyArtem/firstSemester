#pragma once

typedef struct HashTable HashTable;

HashTable* createHashTable(void);

ErrorCode addValue(HashTable* hashTable, char* string);

int fillFactor(HashTable* hashTable);

int maxListLength(HashTable* table);

float averageListLength(HashTable* table);

void deleteHashTable(HashTable* hashTable);

