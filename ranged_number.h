#pragma once

template <class Number, Number lowerLimit, Number upperLimit>
class ranged_number 
{
public:
	// operators and methods to make the class behave
	// just like an actual number, with the addition of
	// restricting the range.	
	ranged_number(Number number) :
	number(std::clamp(number, lowerLimit, number, upperLimit))
	{
	};

	void operator+ (const ranged_number& other) {  this.number += other.number; }
	void operator- (const ranged_number& other) { this.number -= other.number; }

	void operator* (const ranged_number& other) { this.number * other.number; }	
	void operator/ (const ranged_number& other) { this.number / other.number; }
	void operator% (const ranged_number& other) { this.number % other.number; }

	ranged_number& operator++ () { return ++this.number; }
	ranged_number& operator-- () { return --this.number; }
	
	
	bool operator== (const ranged_number& other) { return this.number == other.number; }
	bool operator!= (const ranged_number& other) { return this.number != other.number; }
	bool operator> (const ranged_number& other) { return this.number > other.number; }
	bool operator< (const ranged_number& other) { return this.number < other.number; }
	bool operator>= (const ranged_number& other) { return this.number >= other.number; }
	bool operator<= (const ranged_number& other) { return this.number <= other.number; }


private:
	Number number;
};