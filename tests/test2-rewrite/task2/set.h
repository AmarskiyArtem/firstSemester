#pragma once
#include <stdbool.h>

typedef struct Set Set;

//������� "���������" �����
Set* createSet();

//"�������������" ���� 
void unionSet(Set* set, int firstValue, int secondValue);

//������� ���
void makeSet(Set* set, int value);

//��������, �������� �� ���� �������������� ������ ����
bool isTheSameSet(Set* set, int firstValue, int secondValue);

//������� "���������" �����
void deleteSet(Set* set);