#include "pch.h"
#include "Graph.h"
#include <iterator>
#include <queue>
const int INF = 1000000000;

void addNode(Graph &graph, int dist, int i, int j)
{
	graph.branches[i].push_back(std::make_pair(j, dist));
}

void algorithmPrima(Graph &graph)
{
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	for (int i = 0; i < graph.vert; ++i)
	{
		graph.parent[i] = -1;
		graph.key[i] = INF;
	}
	std::vector<bool> included{ false };
	included.resize(graph.vert);
	int current = 0; 
	pq.push(std::make_pair(0, current));
	graph.key[current] = 0;
	while (!pq.empty())
	{
		int currVert = pq.top().second;
		pq.pop(); // ����� ������� � ��������, ��� ��� ���� � MST
		included[currVert] = true;
		for (auto it = graph.branches[currVert].begin(); it != graph.branches[currVert].end(); ++it)
		{
			int v = it->first;
			int dist = it->second;
			if ((!included[v]) && (dist < graph.key[v]))
			{
				graph.key[v] = dist;
				pq.push(std::make_pair(graph.key[v], v));
				graph.parent[v] = currVert;
			}
		}
	}
}

void deleteGraph(Graph &graph)
{
	for (int i = 0; i < graph.vert; ++i)
	{
		graph.branches[i].clear();
	}
	graph.branches.clear();
	graph.parent.clear();
	graph.key.clear();
}

void printResult(Graph graph)
{
	for (int i = 1; i < graph.vert; ++i)
	{
		std::cout << graph.parent[i] << " " << i << " " << graph.key[i] << std::endl;
	}
}