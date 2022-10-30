#pragma once
#include "cycleList.h"

typedef struct Node {
    int value;
    Node* next;
} Node;

typedef struct CycleList {
    Node* head;
} CycleList;