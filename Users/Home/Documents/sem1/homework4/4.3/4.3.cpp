#include <stdio.h>
#include <stdlib.h>
#include <clocale>
#include <string.h>
#include <ctype.h>
#include "options.h"
#include <windows.h>

void options(int key, PersonalData *phonebook)
{
    switch(key)
    {
    case 1:
        addingData(phonebook);
        break;
    case 2:
        printData(phonebook);
        break;
    case 3:
        seekingByName(phonebook);
        break;
    case 4:
        seekingByPhone(phonebook);
        break;
    case 5:
        saveToFile(phonebook);
        break;
    }
}

int mainMenu(PersonalData *phonebook)
{
    int key = 1;
    printf("����� ����������! ��� ���������� ����������. �� ������ ��������� �������, ����������� � ���. �������:\n1, ����� �������� ������;\n2, ����� ������� ��� ������ �� �����;\n3, ����� ����� ������� �� �����;\n4, ����� ����� ��� �� ��������;\n5, ����� ��������� ������� ������ � ����;\n0, ����� �����.\n");
    scanf("%d", &key);
    if (key == 0)
    {
        printf("�� ��������!");
        return 0;
    }
    options(key, phonebook);
    mainMenu(phonebook);
}

void test(PersonalData *phonebook)
{
    for (int i = 1; i < 5; i++)
    {
        options(i, phonebook);
    }
}

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    FILE *file = fopen("C:\\phonebook.txt", "a+");
    personalData *phonebook = (personalData*) malloc(MAX * sizeof(personalData));
    int line = 0;
    while (!feof(file))
    {
        char *buffername = new char[MAX];
        char *bufferphonenumber = new char[MAX];
        int readBytes = fscanf(file, "%s %s", buffername, bufferphonenumber);
        if (readBytes < 0)
        {
            break;
        }
        phonebook[line].name = buffername;
        phonebook[line].phoneNumber = bufferphonenumber;
        line++;
    }
    fclose(file);
    for (int i = line; i < MAX; i++)
    {
        phonebook[i].name = "*������ ���*";
        phonebook[i].phoneNumber = "*������ ����� ��������*";
    }
    mainMenu(phonebook);
    return EXIT_SUCCESS;
}
