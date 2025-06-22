#include "Exercise.h"
#include "hackerrank_common.h"

#pragma once
class PrepKitsDay3 : public Exercise
{
public:

	PrepKitsDay3() {
		exercises.push_back([this]() { exZigZagSequence(); });
		exercises.push_back([this]() { exTowerBreakers(); });
		exercises.push_back([this]() { exCaesarCipher(); });
	}

private:
	void exZigZagSequence();
	void findZigZagSequence(std::vector<int> a, int n);

	void exTowerBreakers();
	int towerBreakers(int n, int m);
	int findMaxDivisor(int num);

	void exCaesarCipher();
	std::string caesarCipher(std::string s, int k);
};

