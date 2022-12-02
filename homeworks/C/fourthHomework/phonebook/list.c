#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

#define MAX_SIZE 256

typedef struct Node {
    char name[MAX_SIZE];
    char number[MAX_SIZE];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList(void) {
    List* list = malloc(sizeof(list));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

bool isEmpty(List* list) {
    return list->head == NULL;
}

void deleteList(List* list) {
    while (!isEmpty(list)) {
        Node* currentHead = list->head;
        list->head = list->head->next;
        free(currentHead);
    }
    free(list);
}

int readFromFile(char* fileName, List* list) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return -1;
    }
    char name[MAX_SIZE] = { 0 };
    char number[MAX_SIZE] = { 0 };
    bool isContinue = true;
    while (true) {
        if (fscanf_s(file, "%s%s", name, MAX_SIZE, number, MAX_SIZE) == EOF) {
            break;
        }
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return -1;
        }
        strcpy(newNode->name, name);
        strcpy(newNode->number, number);
        newNode->next = list->head;
        list->head = newNode;
    }
    fclose(file);
    return 0;
}

int printList(List* list) {
    if (isEmpty(list)) {
        return -1;
    }
    Node* node = list->head;
    while (node != NULL) {
        printf("%s %s\n", node->name, node->number);
        node = node->next;
    }
    return 0;
}

int add(List* list, char* name, char* number) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    strcpy(newNode->name, name);
    strcpy(newNode->number, number);
    newNode->next = list->head;
    list->head = newNode;
    return 0;
}

int saveToFile(char* fileName, List* list) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        return -1;
    }
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        fprintf(file, "%s %s\n", currentNode->name, currentNode->number);
        currentNode = currentNode->next;
    }
    fclose(file);
    return 0;
}

char* findByName(List* list, char* name) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        if (strcmp(name, currentNode->name) == 0) {
            return currentNode->number;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

char* findByNumber(List* list, char* number) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        if (strcmp(number, currentNode->number) == 0) {
            return currentNode->name;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

bool listTests(void) {
    List* testList = createList();
    if (testList == NULL) {
        return false;
    }
    if (add(testList, "aa", "456") != 0) {
        deleteList(testList);
        return false;
    }
    if (strcmp(testList->head->name, "aa") != 0 || strcmp(testList->head->number, "456") != 0) {
        deleteList(testList);
        return false;
    }
    if (add(testList, "bb", "123") != 0) {
        deleteList(testList);
        return false;
    }
    if (strcmp(testList->head->name, "bb") != 0 || strcmp(testList->head->number, "123") != 0) {
        deleteList(testList);
        return false;
    }
    deleteList(testList);
    return true;
}

bool testsPhoneBookFunctions(void) {
    List* testList = createList();
    if (testList == NULL) {
        return false;
    }
    char testName[] = "aa";
    char testNumber[] = "456";
    if (add(testList, &testName[0], &testNumber[0]) != 0) {
        deleteList(testList);
        return false;
    }
    strcpy(testName, "bb");
    strcpy(testNumber, "123");
    if (add(testList, &testName[0], &testNumber[0]) != 0) {
        deleteList(testList);
        return false;
    }
    char* result = NULL;
    char* testSearchByNameTrue = "aa";
    result = findByName(testList, testSearchByNameTrue);
    if (result == NULL || strcmp(result, testList->head->next->number) != 0) {
        deleteList(testList);
        return false;
    }
    char* testSearchByNameFalse = "ab";
    result = findByName(testList, testSearchByNameFalse);
    if (result != NULL) {
        deleteList(testList);
        return false;
    }
    char* testSearchByNumberTrue = "123";
    result = findByNumber(testList, testSearchByNumberTrue);
    if (result == NULL || strcmp(result, testList->head->name) != 0) {
        deleteList(testList);
        return false;
    }
    char* testSearchByNumberFalse = "5342758";
    result = findByNumber(testList, testSearchByNumberFalse);
    if (result != NULL) {
        deleteList(testList);
        return false;
    }
    deleteList(testList);
    return true;
}

bool readFromFileTest(void) {
    List* list = createList();
    if (list == NULL) {
        return false;
    }
    if (readFromFile("test.txt", list) != 0) {
        deleteList(list);
        return false;
    }
    return strcmp(list->head->name, "second") == 0 && strcmp(list->head->next->name, "firstName") == 0 &&
        strcmp(list->head->number, "9900") == 0 && strcmp(list->head->next->number, "8800") == 0 &&
        list->head->next->next == NULL;
}

bool tests(void) {
    return listTests() && testsPhoneBookFunctions() && readFromFileTest();
}