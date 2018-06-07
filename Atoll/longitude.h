#pragma once
#include "angle.h"

namespace GPS
{
	class Longitude : public Angle<-180, 180>
	{
	public:
		enum class Cardinal { W = -1, E = +1 };

		Longitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second) :
			Angle<-180, 180>((cardinal == Cardinal::W ? -1 : 1) * degree, minute, second)
		{
		}

		bool operator< (Longitude const& rhs) const
		{
			return get_total_() < rhs.get_total_();
		}
	};
}
