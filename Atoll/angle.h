#pragma once
#include "range.h"

namespace GPS
{
	template<int min, int max>
	class Angle
	{
		static_assert(min < max);

	private:
		using base_degree_type = int;
		using base_minute_type = unsigned;
		using base_second_type = unsigned;

	protected:
		using degree_type = Range<base_degree_type, min, max>;
		using minute_type = Range<base_minute_type, 0, 60>;
		using second_type = Range<base_second_type, 0, 60>;
	
	private:
		degree_type const degree_;
		minute_type const minute_;
		second_type const second_;
		double const total_{ degree_ + minute_ / 60.0 + second_ / 3600.0 };

	public:
		Angle(const degree_type degree, const minute_type minute, const second_type second) : 
			degree_{degree},
			minute_{minute},
			second_{second}
		{
		}

		double get_total_() const noexcept
		{
			return total_;
		}
	};
}