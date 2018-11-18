#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale>
#include <string.h>

const int MAX = 100;

struct PersonalData
{
	const char *name = " ";
	const char *phoneNumber = " ";
};

void skipToMenu()
{
	printf("������� � ������� ����;\n\n");
}

void addingData(PersonalData *phonebook)
{
	printf("����� �� ������ ��������� ������. ����� ����� � ������� ����, ������� 0, ��� ������� ����� ������, ������� �� ������ �� ��������.\n");
	int id = 0;
	scanf("%d", &id);
	while (id != 0)
	{
	    id--;
		printf("%s %s\n", phonebook[id].name, phonebook[id].phoneNumber);
		printf("����� �������� ���, ������� 1, ����� �������� ����� ��������, ������� 2\n");
		int key = -1;
		scanf("%d", &key);
		char *newdata = new char[MAX] {};
		printf("������� ���������:\n");
		scanf("%s", newdata);
		if (key == 1)
		{
			phonebook[id].name = newdata;
		}
		else if (key == 2)
		{
			phonebook[id].phoneNumber = newdata;
		}
		printf("������ ��������. ���� ������ ����������, ������� ����� ������, ������� �� ������ �� ��������. ��� ������ ������� 0.\n");
		scanf("%d", &id);
	}
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

void seekingByName(PersonalData *phonebook)
{
	printf("��� ����� �� �����. ������� ���:\n");
	char *nameToSeek = new char[MAX] {};
	scanf("%s", nameToSeek);
	bool isSomeone;
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
	delete[] nameToSeek;
	skipToMenu();
}

void seekingByPhone(PersonalData *phonebook)
{
	printf("��� ����� �� ������ ��������. ������� �����:\n");
	char *numberToSeek = new char[MAX] {};
	scanf("%s", numberToSeek);
	bool isNumber;
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
    printf("����� ����������! ��� ���������� ����������. �� ������ ��������� �������, ����������� � ���. �������:\n1, ����� �������� ������;\n");
	printf("2, ����� ������� ��� ������ �� �����;\n3, ����� ����� ������� �� �����;\n4, ����� ����� ��� �� ��������;\n");
	printf("5, ����� ��������� ������� ������ � ����;\n0, ����� �����.\n");
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

void test(PersonalData *phonebook)
{
	for (int i = 1; i < 5; i++)
	{
		options(i, phonebook);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE *file = fopen("phonebook.txt", "a+");
	PersonalData *phonebook = new PersonalData[MAX];
	int line = 0;
	while (!feof(file))
	{
		char *bufferName = new char[MAX];
		char *bufferPhoneNumber = new char[MAX];
		int readBytes = fscanf(file, "%s %s", bufferName, bufferPhoneNumber);
		if (readBytes < 0)
		{
			break;
		}
		phonebook[line].name = bufferName;
		phonebook[line].phoneNumber = bufferPhoneNumber;
		line++;
	}
	fclose(file);
	for (int i = line; i < MAX; i++)
	{
		phonebook[i].name = "*������ ���*";
		phonebook[i].phoneNumber = "*������ ����� ��������*";
	}
	/*test(phonebook);*/
	mainMenu(phonebook);
	delete[] phonebook;
	return EXIT_SUCCESS;
}
