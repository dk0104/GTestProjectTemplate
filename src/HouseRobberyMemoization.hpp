/*
 * A robber enters a colony of houses numbered from 1 to n.
 * Every house has a number printed on the top of it.
 * That number is the amount of money inside that house.
 * However, there is one constraint.
 * If the robber robs the i-th house, he can't rob house no i-1 and house no i+1.
 * How can the robber maximise his robbery?
 */
#pragma once

#include <vector>
#include <map>

using namespace std;

class HouseRobberyMemoization {
public:
    int Robber(vector<int> slot);

    int CalculateMemorized(vector<int> slot, map<vector<int>, int> memo);
};

