#pragma once
#define MAX 100

typedef struct PersonalData
{
    char* name = "9";
    char* phoneNumber = "8";
} personalData;

void skipToMenu()
{
    printf("������� � ������� ����;\n\n");
}

void addingData(PersonalData *phonebook)
{
    printf("����� �� ������ ��������� ������. ����� ����� � ������� ����, ������� 0, ��� ������� ����� ������, ������� �� ������ �� ��������.\n");
    int id = 0;
    scanf("%d", &id);
    id--;
    while (id > -1)
    {
        printf("%s %s\n", phonebook[id].name, phonebook[id].phoneNumber);
        printf("����� �������� ���, ������� 1, ����� �������� ����� ��������, ������� 2\n");
        int key = -1;
        scanf("%d", &key);
        char *newdata = new char[MAX]{};
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
        id--;
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
    char *nametoseek = new char[MAX]{};
    scanf("%s", nametoseek);
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
        else if (!(strcmp(phonebook[i].name, nametoseek)))
        {
            printf("����� �������� �������� %s: %s\n", phonebook[i].name, phonebook[i].phoneNumber);
            isSomeone = true;
        }
    }
    skipToMenu();
}

void seekingByPhone(PersonalData *phonebook)
{
    printf("��� ����� �� ������ ��������. ������� �����:\n");
    char *numbertoseek = new char[MAX]{};
    scanf("%s", numbertoseek);
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
        else if (!strcmp(phonebook[i].phoneNumber, numbertoseek))
        {
            printf("��� �������� %s: %s\n", phonebook[i].phoneNumber, phonebook[i].name);
            isNumber = true;
        }
    }
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
