#pragma once

template<typename T, T min, T max>
class Range 
{
private:
	using value_type = T;

	value_type const value_;

public:
	Range(value_type const value) :
		value_{value}
	{
		//static_assert(value <= max && value >= min);
	}

	value_type get_value_() const noexcept
	{
		return value_;
	}

	operator int() const noexcept { return value_; }
};