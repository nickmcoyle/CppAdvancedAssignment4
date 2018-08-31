#pragma once

#include "SizedWord.h"

template <class Number, Number lowerLimit, Number upperLimit>
class ranged_number 
{
public:
	ranged_number() :
		number(0)
	{
	};

	ranged_number(Number number) :
	number(std::clamp(number, lowerLimit, number, upperLimit))	
	{
	};

	ranged_number(const ranged_number&) = default;
	ranged_number(ranged_number &&) = default;

	ranged_number& operator=(const ranged_number&) = default;
	ranged_number& operator=(ranged_number&&) = default;

	~ranged_number() = default;

	const int& getNumber() const { return number; };
	const Binary::Byte& getByte() const { return static_cast<Binary::Byte>(number); };
		
	const ranged_number& operator+ (const ranged_number& other) { return this.number += other.number; };
	const ranged_number& operator- (const ranged_number& other) { return this.number -= other.number; };
	const ranged_number& operator* (const ranged_number& other) { return this.number * other.number; };
	const ranged_number& operator/ (const ranged_number& other) { return this.number / other.number; };
	const ranged_number& operator% (const ranged_number& other) { return this.number % other.number; };
	
	void operator++ () {};
	void operator-- () {};

	const ranged_number& operator= (const ranged_number& rhs) { return this.number = rhs.number; };
	const ranged_number& operator= (const ranged_number&& rhs) { return this.number = rhs.number; };

	const ranged_number& operator+= (const ranged_number& rhs) { return this.number += rhs.number; };
	const ranged_number& operator-= (const ranged_number& rhs) { return this.number -= rhs.number; };

	bool operator== (const ranged_number& rhs) { return this.number == rhs.number; };
	bool operator!= (const ranged_number& rhs) { return !this==rhs; };

private:
	Number number;	
};