#pragma once

void addingData(PersonalData *phonebook)
{
    printf("����� �� ������ ��������� ������. ����� ����� � ������� ����, ������� 0, ��� ������� ����� ������, ������� �� ������ �� ��������.\n");
    int id = -1;
    scanf("%d", &id);
    while (id != 0)
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
        else if (key == 0)
        {
            phonebook[id].phoneNumber = newdata;
        }
        printf("������ ��������. ���� ������ ����������, ������� ����� ������, ������� �� ������ �� ��������. ��� ������ ������� 0.\n");
        addingData(phonebook);
    }
    mainMenu(phonebook);
}

void printData(PersonalData *phonebook)
{
    printf("���������� ����� ������ �������� ���:\n");
    for (int j = 0; j < MAX; j++)
    {
        printf("%s\t%s\n", phonebook[j].name, phonebook[j].phoneNumber);
    }
    printf("������� � ������� ����;\n");
}

void seekingByName(PersonalData *phonebook)
{
    printf("��� ����� �� �����. ������� ���:\n");
    char *nametoseek = new char[MAX]{};
    scanf("%s", nametoseek);
    printf("%s", nametoseek);
    for (int i = 0; i < MAX; i++)
    {
        if (phonebook[i].name == nametoseek)
        {
            printf("����� �������� �������� %s: %s", phonebook[i].name, phonebook[i].phoneNumber);
        }
    }
}

void seekingByPhone(PersonalData *phonebook)
{
    printf("��� ����� �� ������ ��������. ������� �����:\n");
    char *numbertoseek = new char[MAX]{};
    scanf("%s", numbertoseek);
    for (int i = 0; i < MAX; i++)
    {
        if (phonebook[i].phoneNumber == numbertoseek)
        {
            printf("��� �������� %s: %s", phonebook[i].phoneNumber, phonebook[i].name);
        }
    }
}

void saveToFile(PersonalData *phonebook)
{
    FILE *file = fopen("C:\\phonebook.txt", "w");
    for (int i = 0; i < MAX; i++)
    {
        fprintf(file, "%s\t%s\n", phonebook[i].name, phonebook[i].phoneNumber);
    }
    fclose(file);
    printf("������ ���������!");
}
