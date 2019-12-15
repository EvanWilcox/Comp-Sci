
#ifndef FLOW_NETWORK_H
#define FLOW_NETWORK_H

#include <vector>

class FlowNetwork
{

public:
	int src = 0, sink = 0, numVertices = 0;
	//edge capacities, edge flows, vertex neighbors
	std::vector<std::vector<int>> capacities, flows, neighbList;
	std::vector<int> excess, height;

	FlowNetwork(int n, int source, int snk, std::vector<std::vector<int>> &caps);
    void setSrcEnd(int src, int end);
private:
	std::vector<std::vector<int>> buildNeighborList(int n, std::vector<std::vector<int>> &caps);
};


class RectangularVectors
{
public:
	static std::vector<std::vector<int>> RectangularIntVector(int size1, int size2)
	{
		std::vector<std::vector<int>> newVector(size1);
		for (int vector1 = 0; vector1 < size1; vector1++)
		{
			newVector[vector1] = std::vector<int>(size2);
		}

		return newVector;
	}
};


FlowNetwork::FlowNetwork(int n, int source, int snk, std::vector<std::vector<int>> &caps)
{
	numVertices = n;
	src = source;
	sink = snk;
	capacities = caps;
	flows = RectangularVectors::RectangularIntVector(n, n);
	excess = std::vector<int>(n);
	height = std::vector<int>(n);
	neighbList = buildNeighborList(n, caps);
}

void FlowNetwork::setSrcEnd(int src, int end)
{
    this->src = src;
    this->sink = end;
}

std::vector<std::vector<int>> FlowNetwork::buildNeighborList(int n, std::vector<std::vector<int>> &caps)
{
	std::vector<int> numNeighbs(n); //temp array
	std::vector<std::vector<int>> tempNeighbList(n); //create jagged neighbor array from edge capacities
	//first count number of neighbors for each vertex
	for (int i = 0;i < caps.size();i++)
	{
		for (int j = 0;j < caps[i].size();j++)
		{
			if (caps[i][j] > 0)
			{
				numNeighbs[i]++;
				numNeighbs[j]++;
			}
		}
	}
	//allocate capacities
	for (int i = 0; i < numNeighbs.size();i++)
	{
		tempNeighbList[i] = std::vector<int>(numNeighbs[i]);
	}
	std::vector<int> counter(n); //temp array
	//store neighbors of each vertex
	for (int i = 0;i < caps.size();i++)
	{
		for (int j = 0;j < caps[i].size();j++)
		{
			if (caps[i][j] > 0)
			{
				tempNeighbList[i][counter[i]] = j;
				tempNeighbList[j][counter[j]] = i;
				counter[i]++;
				counter[j]++;
			}
		}
	}
	return tempNeighbList;
}

#endif