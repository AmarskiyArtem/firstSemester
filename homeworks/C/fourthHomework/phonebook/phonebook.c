#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#define maxStringLength 200
#define storageSize 100

int currentStorageSize(FILE* file) {
    int result = 0;
    char temp[storageSize] = { 0 };
    while (fgets(temp, maxStringLength, file) != NULL) {
        ++result;
    }
    fseek(file, 0, SEEK_SET);
    return result;
}

void printStorage(FILE* file) {
    int size = currentStorageSize(file);
    if (size == 0) {
        printf("Записи отсутствуют\n");
        return;
    }
    char record[storageSize] = { 0 };

    for (int i = 0; i < size; ++i)
    {
        fgets(record, maxStringLength, file);
        printf("%s", record);
    }
    fseek(file, 0, SEEK_SET);
}
void printListOfActions(void) {
    printf("--------------------------------------\n"
        "0 - выйти\n"
        "1 - добавить запись(имя и телефон)\n"
        "2 - распечатать все имеющиеся записи\n"
        "3 - найти телефон по имени\n"
        "4 - найти имя по телефону\n"
        "5 - сохранить текущие данные в файл\n"
        "--------------------------------------\n");
}

char *addRecord(int currentRecord) {
    char  *buffer = calloc(maxStringLength, sizeof(char));
    if (buffer == NULL) {
        printf("Memory panicc :(");
        return 0;
    }
    printf("Введите телефон и имя: \n");
    buffer[0] = getchar();
    fgets(buffer, storageSize, stdin);
    return buffer;
}

void savingRecords(FILE* file, char* data[], int amountOfUnsavedRecords) {
    if (amountOfUnsavedRecords == 0) {
        printf("Сохранять нечего :(\n");
        return;
    }
    fseek(file, 0, SEEK_END);
    for (int i = 0; i < amountOfUnsavedRecords; ++i) {
        fputs(data[i], file);
        data[i] = 0;
    }
    fseek(file, 0, SEEK_SET);
    printf("Изменения добавлены\n");
}

void search(FILE* file, char searchingSymbols[maxStringLength]) {
    int size = currentStorageSize(file);
    bool wasFound = false;
    char record[storageSize] = { 0 };
    for (int i = 0; i < size; ++i)
    {
        fgets(record, maxStringLength, file);
        if (strstr(record, searchingSymbols) != NULL) {
            wasFound = true;
            printf("%s\n", record);
        }
    }
    if (!wasFound) {
        printf("Ничего не найдено\n");
    }
    fseek(file, 0, SEEK_SET);
}

void main() {
    setlocale(LC_ALL, "RU");
    FILE* file = fopen("storage.txt", "a+");
    if (file == NULL) {
        printf("Проблемы с файлом");
        return;
    }

    char *data[storageSize] = { 0 };
    int currentRecordNumber = 0;
    bool isContinue = true;
    while (isContinue) {
        int currentAction = 0;
        printf("Введите действие (999 - справка)\n");
        scanf_s("%d", &currentAction);
        switch (currentAction) {
        case 0:
        {
            isContinue = false;
            break;
        }
        case 1:
        {
            data[currentRecordNumber] = addRecord(currentRecordNumber);
            ++currentRecordNumber;
            break;
        }
        case 2:
        {
            printStorage(file);
            break;
        }
        case 3:
        {
            printf("Введите имя:\n");
            char name[maxStringLength] = { 0 };
            scanf_s("%100s", name, (unsigned)sizeof(name));
            search(file, name);
            break;
        }
        case 4:
        {
            printf("Введите номер:\n");
            char phoneNumber[maxStringLength] = { 0 };
            scanf_s("%100s", phoneNumber, (unsigned)sizeof(phoneNumber));
            search(file, phoneNumber);
            break;
        }
        case 5:
        {
            savingRecords(file, data, currentRecordNumber);
            break;
        }
        case 999:
        {
            printListOfActions();
            break;
        }
        default:
            printf("Неверный формат ввода\n");
            break;
        }
    }
}