#include "Exercise.h"
#include "hackerrank_common.h"

#pragma once
class PrepKeysDay1 : public Exercise
{
public:

	PrepKeysDay1() {
		exercises.push_back([this]() { exPlusMinus(); });
		exercises.push_back([this]() { exMiniMaxSum(); });
		exercises.push_back([this]() { exTimeConversion(); });
	}

private:
	void exPlusMinus();
	void plusMinus(std::vector<int> arr);

	void exMiniMaxSum();
	void miniMaxSum(std::vector<int> arr);	
	
	void exTimeConversion();
	std::string timeConversion(std::string s);
};

