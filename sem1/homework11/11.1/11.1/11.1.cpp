﻿#include "pch.h"
#include "Seek.h"
#include <iostream>
#include <string>
#include <locale>
#include <assert.h>

void test()
{
	std::string testMainString = "abcabdabcabe";
	std::string testSample = "abcabe";
	assert(algorithmKMP(testMainString, testSample) == 6);
	std::string testAbcString = "abcabc";
	std::string testSampleAbc = "abc";
	assert(algorithmKMP(testAbcString, testSampleAbc) == 1);
	std::string testKkkString = "kkkkkkk";
	std::string testAString = "aaa";
	assert(algorithmKMP(testKkkString, testAString) == 0);
	std::cout << "Тест пройден:)" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	test();
	std::cout << "Введите строку, в которой будет осуществляться поиск:" << std::endl;
	std::string mainString = "";
	std::cin >> mainString;
	std::cout << "Введите образец для поиска:" << std::endl;
	std::string sample = "";
	std::cin >> sample;

	if (algorithmKMP(mainString, sample) == 0)
	{
		std::cout << "Нет совпадений между строками!:(" << std::endl;
		return -1;
	}
	std::cout << "Первый индекс вхождения образца в строку: " << algorithmKMP(mainString, sample) << std::endl;
	return 0;
}