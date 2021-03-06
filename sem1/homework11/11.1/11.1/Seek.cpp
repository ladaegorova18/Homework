﻿#include "pch.h"
#include "Seek.h"
#include <fstream>

int* prefixFunction(std::string const &str, int len)
{
	int *index = new int[len] {0};
	for (int i = 0; i < len - 1; i++)
	{
		if (str[i + 1] == str[index[i]])
		{
			index[i + 1] = index[i] + 1;
		}
		else
		{
			index[i + 1] = 0;
		}
	}
	return index;
}

int algorithmKMP(std::ifstream &file, std::string const &sample)
{
	int sampleLen = sample.length();
	int equalIndex = 0;
	int *index = prefixFunction(sample, sampleLen);
	int i = 0;
	char temp = ' ';
	file >> temp;
	while (!file.eof())
	{
		if ((temp == sample[equalIndex]) || (equalIndex == 0))
		{
			if (temp == sample[equalIndex])
			{
				equalIndex++;
			}
			file >> temp;
			i++;
		}
		else
		{
			equalIndex = index[equalIndex - 1];
		}
		if (equalIndex == sampleLen)
		{
			delete[] index;
			return i - equalIndex + 1;
		}
	}
	delete[] index;
	return equalIndex;
}