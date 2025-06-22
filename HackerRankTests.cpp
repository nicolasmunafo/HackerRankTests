// HackerRankTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PrepKeysDay1.h"
#include "prepkitsday2.h"
#include "prepkitsday3.h"
#include "Exercise.h"
#include <algorithm>

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */



int main()
{
	std::vector<Exercise*> exercisesVec;
	PrepKeysDay1* prepKeysDay1 = new PrepKeysDay1();
	PrepKitsDay2* prepKitsDay2 = new PrepKitsDay2();
	PrepKitsDay3* prepKitsDay3 = new PrepKitsDay3();

	exercisesVec.push_back(prepKeysDay1);
	exercisesVec.push_back(prepKitsDay2);
	exercisesVec.push_back(prepKitsDay3);

	int exNum = 0, exDay=1;
	std::cout << "Day num: "; std::cin >> exDay;
	std::cout << "Exercise num: "; std::cin >> exNum;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears leftover newline

	exercisesVec[exDay - 1]->runExercise(exNum);


	delete(prepKeysDay1);
	delete(prepKitsDay2);
	delete(prepKitsDay3);
}