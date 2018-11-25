﻿#include <cstdio>
#include "pch.h"
#include <stdio.h>
#include <locale>
#include <assert.h>
const int SIZE = 32;
using namespace std;

bool *conversion(long int number)
{
    unsigned bit = 1 << 31;
    bool *binaryNumber = new bool[SIZE]{};
    for (int j = 0; j < SIZE; j++)
    {
        binaryNumber[j] = ((number & bit) ? 1 : 0);
        bit = bit >> 1;
    }
    return binaryNumber;
}

bool *sum(bool* first, bool* second)
{
    bool *result = new bool[SIZE]{0};
    for (int i = SIZE - 1; i > -1; i--)
    {
        if ((first[i]) || (second[i]))
        {
            if (first[i] == second[i])
            {
               result[i - 1] = 1;
            }
            else
            {
                if (result[i] == 1)
                {
                    result[i] = 0;
                    result[i - 1] = 1;
                }
                else
                {
                    result[i] = 1;
                }
            }
        }
    }
    return result;
}

int binaryToDecimal(bool* binNumber)
{
    long int decimalNumber = 0;
    int addition = 1;
    for (int i = SIZE - 1; i > -1; i--)
    {
        if (binNumber[i] == 1)
        {
            decimalNumber += addition;
        }
        addition *= 2;
    }
    return decimalNumber;
}

bool *decimalToBin(long int number)
{
	return conversion(number);  
}

void printing(bool *binaryNumber)
{
    int j = 0;
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", binaryNumber[i]);
        j++;
        if (j == 8)
        {
            printf(" ");
            j = 0;
        }
    }
}

void test()
{
    long int numberOne = 1;
    long int maxNumberMinusOne = (1 << 31) - 2;
    bool *oneToBinary = decimalToBin(numberOne);
    bool *maxToBinary = decimalToBin(maxNumberMinusOne);
    long int result = binaryToDecimal(sum(oneToBinary, maxToBinary));
    assert(result == (1 << 31) - 1);
    long int negativeOne = -1;
    long int negativeMaxPlusOne = ((1 << 31) - 1) * (-1);
    bool *negOneToBinary = decimalToBin(negativeOne);
    bool *negMaxToBinary = decimalToBin(negativeMaxPlusOne);
    long int resultOfNegative = binaryToDecimal(sum(negOneToBinary, negMaxToBinary));
    assert(resultOfNegative == (1 << 31) * (-1));
    printf("Test passed\n");
	delete[] oneToBinary;
	delete[] maxToBinary;
	delete[] negOneToBinary;
	delete[] negMaxToBinary;
	delete[] sum(negOneToBinary, negMaxToBinary);
	delete[] sum(oneToBinary, maxToBinary);
}

int main()
{
    test();
    setlocale(LC_ALL, "Russian");
    int theFirstNumber = 0;
    int theSecondNumber = 0;
    printf("Введите числа в десятичной системе счисления:\n");
    scanf("%d %d", &theFirstNumber, &theSecondNumber);
    bool *firstBinary = new bool[SIZE];
    bool *secondBinary = new bool[SIZE];
    firstBinary = decimalToBin(theFirstNumber);
    secondBinary = decimalToBin(theSecondNumber);
    printf("В двоичной системе:\n");
    printing(firstBinary);
    printf("\n");
    printing(secondBinary);
    printf("\n");
    printf("Сумма в двоичной системе счисления:\n");
    printing(sum(firstBinary, secondBinary));
    printf("\nЧисла в десятичной системе счисления:\n%d\n%d\nСумма в десятичной системе счисления: %d\n", binaryToDecimal(firstBinary), binaryToDecimal(secondBinary), binaryToDecimal(firstBinary) + binaryToDecimal(secondBinary));
    delete[] firstBinary;
    delete[] secondBinary;
	delete[] sum(firstBinary, secondBinary);
    return 0;
}
