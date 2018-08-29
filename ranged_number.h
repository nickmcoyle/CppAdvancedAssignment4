#pragma once

template <class Number, Number lowerLimit, Number upperLimit>
class ranged_number 
{
public:
	// operators and methods to make the class behave
	// just like an actual number, with the addition of
	// restricting the range.
	//std::clamp();
	ranged_number(Number number) :
	number(std::clamp(number, lowerLimit, number, upperLimit))
	{
	};

private:
	Number number;
};