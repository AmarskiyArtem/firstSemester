#pragma once
#include <stdbool.h>

typedef struct List List;

//���������� ��������� �� ������ ������, NULL, ���� �������� � ���������� ������
List* createList(void);

//������� ������
void deleteList(List* list);

//��������� ������� � ������, ���������� 0, ���� �������, -1 - � ��������� ������ (�������� � ���������� ������)
int push(List* list, int value);

//������� ������ �� �����
void printList(List* list);

//��������� ������ �� �������������� 
bool isSymmetric(List* list);