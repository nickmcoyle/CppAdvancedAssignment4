#pragma once

#include "SizedWord.h"
#include <type_traits>

template <class Number, Number lowerLimit, Number upperLimit>
class ranged_number 
{
public:
	ranged_number() :
	number(0)
	{
	};
	
	ranged_number(Number number) :
	number(std::clamp(number, lowerLimit, upperLimit))		
	{		
	};

	ranged_number(const ranged_number&) = default;
	ranged_number(ranged_number &&) = default;
	ranged_number& operator=(const ranged_number&) = default;
	ranged_number& operator=(ranged_number&&) = default;
	~ranged_number() = default;

	const int& getNumber() const { return this->number; };
	void setNumber(const int& value) { this->number = std::clamp(value, static_cast<int>(lowerLimit), static_cast<int>(upperLimit)); };
	
	const Binary::Byte& getByte() const { return static_cast<Binary::Byte>(number); };
		
	ranged_number operator+(const ranged_number& rhs) { setNumber(this->number + rhs.number); return *this; };
	ranged_number& operator- (const ranged_number& rhs) { setNumber(this->number - rhs.number); return *this; };
	ranged_number& operator* (const ranged_number& rhs) { setNumber(this->number * rhs.number); return *this; };
	ranged_number& operator/ (const ranged_number& rhs) { setNumber(this->number / rhs.number); return *this; };	
	ranged_number& operator++() { this->setNumber(++number); return *this; }; //prefix
	ranged_number operator++(int unused) { return *this; }; //postfix
	ranged_number& operator--() { this->setNumber(--number); return *this; }; //prefix
	ranged_number operator--(int unused) { return *this; };
	ranged_number& operator+=(const ranged_number& rhs) 
	{ 
		this->setNumber(this->number + rhs.number); 
		return *this; 
	};
	ranged_number& operator-=(const ranged_number& rhs) 
	{
		this->setNumber(this->number - rhs.number); 
		return *this;
	};

	bool operator==(const ranged_number& rhs) const { return this->number == rhs->number; };
	friend bool operator==(int x, const ranged_number& rhs) { return x == int(rhs.number); };
	bool operator!=(const ranged_number& rhs) const { return !this==rhs; };

	friend std::ostream& operator<< (std::ostream &out, const ranged_number& number)
	{
		out << number.number;
		return out;
	}

private:
	static_assert(std::is_integral_v<Number>, "Integral Type required for template creation of base type");

	Number number;	
};