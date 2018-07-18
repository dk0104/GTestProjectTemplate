#include "HouseRobberyMemoization.hpp"


int HouseRobberyMemoization::Robber(vector<int> slot) {
	map<vector<int>, int> memo;
	return CalculateMemorized(slot, memo);
}

int HouseRobberyMemoization::CalculateMemorized(vector<int> slot, map<vector<int>, int> memo) {
	if (memo.count(slot))
		return memo[slot];
	if (slot.size() == 1) {
		memo.emplace(slot, slot[0]);
		return memo[slot];
	}
	if (slot.size() == 2) {
		memo.emplace(slot, max(slot[0], slot[1]));
		return memo[slot];
	}

	vector<int> calcSlot2(slot.begin() + 2, slot.end());
	int secondResult = slot[0] + CalculateMemorized(calcSlot2, memo);

	vector<int> calcSlot(slot.begin() + 1, slot.end());
	int firstResult = CalculateMemorized(calcSlot, memo);

	memo[slot] = max(firstResult, secondResult);
	return memo[slot];
}