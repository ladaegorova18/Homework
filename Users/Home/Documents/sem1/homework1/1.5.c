#include <stdio.h>
#include <string.h>
int main() {
    printf("Enter a string:\n");
    char str[100];
    scanf("%s", str);
    int k = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == '(')
            k++;
        if(str[i] == ')')
            k--;
        if(k < 0) {
            printf("false"); /*��������� ����������� ������ �� ������ ����� �����*/
            return 0;
        }
    }
    if(k == 0) {
        printf("true");
    } else {
        printf("false");
    }
    /*��������� ��������� ����������� � ����������� ������*/
    return 0;
}
