#include "Exercise.h"
#include "hackerrank_common.h"

#pragma once
class PrepKitsDay2 : public Exercise
{
public:

	PrepKitsDay2() {
		exercises.push_back([this]() { exLonelyInteger(); });
		exercises.push_back([this]() { exDiagonalDifference(); });
		exercises.push_back([this]() { exCountingSort1(); });
		exercises.push_back([this]() { exTestFlipMatrix(); });
	}

private:
	void exLonelyInteger();
	int lonelyinteger(std::vector<int> a);

	void exDiagonalDifference();
	int diagonalDifference(std::vector<std::vector<int>> arr);

	void exCountingSort1();
	std::vector<int> countingSort(std::vector<int> arr);	
	
	void exTestFlipMatrix();
	int flippingMatrix(std::vector<std::vector<int>> matrix);
};

