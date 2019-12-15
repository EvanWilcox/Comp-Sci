

#ifndef RELABEL_FRONT_H
#define RELABEL_FRONT_H

#include "FlowNetwork.h"
#include <vector>
#define INF 0x3f3f3f3f 

class RelabelToFront
{
private:
	FlowNetwork *fn;

public:
	virtual ~RelabelToFront()
	{
		delete fn;
	}

	RelabelToFront(FlowNetwork *flownetwork);
private:
	int push(FlowNetwork *fn, int from, int to);
	void relabel(FlowNetwork *fn, int target);
	std::vector<int> discharge(FlowNetwork *fn, int target, std::vector<int> &currents);
	/*
	*@return the maximum flow of this RelabelToFront object
	*/
public:
	virtual int getMaxFlow();
private:
	void initialize();
	std::vector<int> moveIndToFrontOfAry(std::vector<int> &list, int targetInd);
};


RelabelToFront::RelabelToFront(FlowNetwork *flownetwork)
{
	fn = flownetwork;
}

int RelabelToFront::push(FlowNetwork *fn, int from, int to)
{
	int flowAmt = std::min(fn->excess[from], fn->capacities[from][to] - fn->flows[from][to]);
	fn->excess[to] += flowAmt;
	fn->flows[from][to] += flowAmt;
	fn->excess[from] -= flowAmt;
	fn->flows[to][from] -= flowAmt;
	return flowAmt;
}

void RelabelToFront::relabel(FlowNetwork *fn, int target)
{
	int minH = INF;
	for (int i = 0; i < fn->neighbList[target].size(); i++)
	{
		int myI = fn->neighbList[target][i];
		if (fn->capacities[target][myI] - fn->flows[target][myI] > 0 && fn->height[myI] >= fn->height[target])
		{
			if (fn->height[myI] < minH)
			{
				minH = fn->height[myI];
			}
		}
	}
	fn->height[target] = minH + 1;
}

std::vector<int> RelabelToFront::discharge(FlowNetwork *fn, int target, std::vector<int> &currents)
{
	//while target vertex of discharge has excess
	while (fn->excess[target] > 0)
	{
		//retrieve the neighbor we are currently inspecting
		int neighbInd = currents[target];
		//ensure that we have not looked through all neighbors
		if (neighbInd >= fn->neighbList[target].size())
		{
			//if we have, then we must relabel and reset our current inspection to the front of the list
			relabel(fn, target);
			currents[target] = 0;
		}
		else
		{
			//otherwise find the id of the neighbor, check if it is a valid push target and push, if not move to next neighbor
			int neighb = fn->neighbList[target][neighbInd];
			int residualCap = fn->capacities[target][neighb] - fn->flows[target][neighb];
			if (residualCap > 0 && fn->height[target] == (fn->height[neighb] + 1))
			{
				push(fn, target, neighb);
			}
			else
			{
				currents[target]++;
			}
		}
	}
	return currents;
}

int RelabelToFront::getMaxFlow()
{
	this->initialize();
	//set up the dischargeList, does not include source or sink
	std::vector<int> dischargeList(fn->numVertices - 2);
	int ind = 0;
	for (int i = 0; i < fn->numVertices; i++)
	{
		if (!(i == fn->src || i == fn->sink))
		{
			dischargeList[ind] = i;
			ind++;
		}
	}
	//each vertex has a current neighbor being inspected
	std::vector<int> currentNeighb(fn->numVertices);
	int curVertInd = 0;
	//if we get to the end then we are finished
	while (curVertInd < dischargeList.size())
	{
		int curVert = dischargeList[curVertInd];
		int curVertH = fn->height[curVert];
		currentNeighb = discharge(fn, curVert, currentNeighb);
		if (fn->height[curVert] > curVertH)
		{ //curVert was relabeled
			dischargeList = moveIndToFrontOfAry(dischargeList, curVertInd);
			curVertInd = 0;
		}
		else
		{
			curVertInd++;
		}
	}
	//solution equals excess at the sink
	return fn->excess[fn->sink];
}

void RelabelToFront::initialize()
{
	fn->height[fn->src] = fn->numVertices; //height of source = |V|
	fn->excess[fn->src] = INF; //temporarily allow source to have infinite excess to utilize push
	int sourceOutflowSum = 0;
	for (int i = 0; i < fn->neighbList[fn->src].size(); i++)
	{
		int vertID = fn->neighbList[fn->src][i];
		sourceOutflowSum += push(fn, fn->src, vertID);
	}
	fn->excess[fn->src] = -sourceOutflowSum;
}

std::vector<int> RelabelToFront::moveIndToFrontOfAry(std::vector<int> &list, int targetInd)
{
	int vertID = list[targetInd];
	for (int i = targetInd; i > 0; i--)
	{
		list[i] = list[i - 1];
	}
	list[0] = vertID;
	return list;
}

#endif