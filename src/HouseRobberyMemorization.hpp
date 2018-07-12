#pragma once

#include <vector>
#include <map>

using namespace std;
class HouseRobberyMemoization {
public:
	int Robber(vector<int> slot);

	int CalculateMemorized(vector<int> slot, map<vector<int>, int> memo);
};

