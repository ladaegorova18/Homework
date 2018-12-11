#include "pch.h"
#include "Graph.h"
#include <vector>
#include <iostream>

void Map::war()
{
	size_t count = 0;
	while (count < mark.size())
	{
		for (size_t i = 0; i < kingdoms.size(); i++) // новое королевство
		{ 
			int min = INF;
			int newCity = 0;
			for (size_t tempCity = 0; tempCity < kingdoms[i].size(); tempCity++) // новый город в королевстве
			{
				for (size_t j = 0; j < mark.size(); j++) // все города, связанные с ним
				{
					if ((roads[kingdoms[i][tempCity]][j] < min) && (!mark[j]))
					{
						min = roads[kingdoms[i][tempCity]][j];
						newCity = j;
					}
				}
			}
			kingdoms[i].push_back(newCity);
			mark[newCity] = 1;
		}
		count++;
	}
}

void printing(std::vector<std::vector<int>> kingdoms)
{
	for (size_t i = 0; i < kingdoms.size(); i++)
	{
		std::cout << i + 1 << " королевству принадлежат города: " << std::endl;
		for (size_t j = 0; j < kingdoms[i].size(); j++)
		{
			if (kingdoms[i][j] != 0)
			{
				std::cout << kingdoms[i][j] << " ";
			}
		}
		std::cout << "\n";
	}
}
