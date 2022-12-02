#pragma once
#include <stdbool.h>

typedef struct List List;

//��������� ������ �� ����� � ������, ���������� -1, ���� �� ������� ����� ����, 0 ���� ������ �������
int readFromFile(char* fileName, List* list);

//���������� ��������� �� ������ ������
List* createList(void);

//������� ������
void deleteList(List* list);

//������� ������ � �������
int printList(List* list);

//��������� ������� � ������ ������, ���������� 0 � ������ ������� � ���������� ������
int add(List* list, char* name, char* number);

//��������� ������ �� ������ � ����, ������� ��� ���������, ���������� -1 ���� �� ������� ����� ����, 0 ���� ������ �������
int saveToFile(char* fileName, List* list);

//���������� ��������� �� ������ ��������� ������ � ����������� ������, NULL, ���� ���������� ���
char* findByName(List* list, char* name);

//���������� ��������� �� ������ ��������� ������ � ����������� �������, NULL, ���� ���������� ���
char* findByNumber(List* list, char* number);

//�����...
bool tests(void);