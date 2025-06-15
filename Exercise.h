#include <functional>
#include <vector>

#pragma once

// Interface for all exercises
class Exercise
{
public:
	
	void runExercise(const int exNum) {
		if (exNum <= exercises.size())
			exercises[exNum-1]();
	}

protected:

	std::vector<std::function<void()>> exercises;
};

