#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "options.h"

void skipToMenu()
{
	printf("������� � ������� ����;\n\n");
}

int scanningNumber()
{
	int id = 0;
	scanf("%d", &id);
	return id;
}

char* scanningString()
{
	char* stringToScan = new char[MAX] {};
	scanf("%s", stringToScan);
	return stringToScan;
}

void adding(PersonalData *phonebook, int id)
{
	while (id != 0)
	{
		id--;
		printf("%s %s\n", phonebook[id].name, phonebook[id].phoneNumber);
		printf("����� �������� ���, ������� 1, ����� �������� ����� ��������, ������� 2\n");
		int key = -1;
		scanf("%d", &key);
		char *newData = new char[MAX] {};
		printf("������� ���������:\n");
		scanf("%s", newData);
		if (key == 1)
		{
			phonebook[id].name = newData;
		}
		else if (key == 2)
		{
			phonebook[id].phoneNumber = newData;
		}
		printf("������ ��������. ���� ������ ����������, ������� ����� ������, ������� �� ������ �� ��������. ��� ������ ������� 0.\n");
		id = scanningNumber();
	}
}

void addingData(PersonalData *phonebook)
{
	printf("����� �� ������ ��������� ������. ����� ����� � ������� ����, ������� 0, ��� ������� ����� ������, ������� �� ������ �� ��������.\n");
	int id = scanningNumber();
	adding(phonebook, id);
	skipToMenu();
}

void printData(PersonalData *phonebook)
{
	printf("���������� ����� ������ �������� ���:\n");
	for (int j = 0; j < MAX; j++)
	{
		if ((phonebook[j].name != NULL) || (phonebook[j].phoneNumber != NULL))
		{
			printf("%d. %s\t%s\n", j + 1, phonebook[j].name, phonebook[j].phoneNumber);
		}
	}
	skipToMenu();
}

void seekingNameFunction(PersonalData *phonebook, char* nameToSeek)
{
	bool isSomeone = false;
	for (int i = 0; i <= MAX; i++)
	{
		if (i == MAX)
		{
			if (!isSomeone)
			{
				printf("������� � ����� ������ �� ������;\n");
			}
			break;
		}
		else if (!(strcmp(phonebook[i].name, nameToSeek)))
		{
			printf("����� �������� �������� %s: %s\n", phonebook[i].name, phonebook[i].phoneNumber);
			isSomeone = true;
		}
	}
}

void seekingByName(PersonalData *phonebook)
{
	printf("��� ����� �� �����. ������� ���:\n");
	char *nameToSeek = new char[MAX] {};
	nameToSeek = scanningString();
	seekingNameFunction(phonebook, nameToSeek);
	delete[] nameToSeek;
	skipToMenu();
}

void seekingByPhone(PersonalData *phonebook)
{
	printf("��� ����� �� ������ ��������. ������� �����:\n");
	char *numberToSeek = new char[MAX] {};
	scanf("%s", numberToSeek);
	bool isNumber = false;
	for (int i = 0; i <= MAX; i++)
	{
		if (i == MAX)
		{
			if (!isNumber)
			{
				printf("������� � ����� ������� �������� �� ������;\n");
			}
			break;
		}
		else if (!strcmp(phonebook[i].phoneNumber, numberToSeek))
		{
			printf("��� �������� %s: %s\n", phonebook[i].phoneNumber, phonebook[i].name);
			isNumber = true;
		}
	}
	delete[] numberToSeek;
	skipToMenu();
}

void saveToFile(PersonalData *phonebook)
{
	FILE *file = fopen("phonebook.txt", "w");
	for (int i = 0; i < MAX; i++)
	{
		fprintf(file, "%s\t%s\n", phonebook[i].name, phonebook[i].phoneNumber);
	}
	fclose(file);
	printf("������ ���������!\n");
}

void options(int key, PersonalData *phonebook)
{
	switch (key)
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

void mainText()
{
	printf("����� ����������! ��� ���������� ����������. �� ������ ��������� �������, ����������� � ���. �������:\n");
	printf("1, ����� �������� ������;\n");
	printf("2, ����� ������� ��� ������ �� �����;\n");
	printf("3, ����� ����� ������� �� �����;\n");
	printf("4, ����� ����� ��� �� ��������;\n");
	printf("5, ����� ��������� ������� ������ � ����;\n");
	printf("0, ����� �����.\n");
}

void mainMenu(PersonalData *phonebook)
{
	int key = 1;
	mainText();
	scanf("%d", &key);
	while (key != 0)
	{
		options(key, phonebook);
		mainText();
		scanf("%d", &key);
	}
	printf("�� ��������!");
}

void test()
{
	FILE *file = fopen("phonebook.txt", "r");
	PersonalData *testPhoneBook = new PersonalData[MAX];
	bool testPassed = false;
	int line = 0;
	if (!file)
	{
		printf("File not found!");
		return;
	}
	while (!feof(file))
	{
		char *bufferName = new char[MAX];
		char *bufferPhoneNumber = new char[MAX];
		int readBytes = fscanf(file, "%s %s", bufferName, bufferPhoneNumber);
		if (readBytes < 0)
		{
			delete[] bufferName;
			delete[] bufferPhoneNumber;
			break;
		}
		testPhoneBook[line].name = bufferName;
		testPhoneBook[line].phoneNumber = bufferPhoneNumber;
		line++;
	}
	fclose(file);

	delete[] testPhoneBook;
	printf("Test passed\n");
}