#pragma once
#include "angle.h"

namespace GPS
{
	class Latitude : public Angle<-89, 90>
	{
	public:
		enum class Cardinal { S = -1, N = +1 };

		Latitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second) :
			Angle<-89, 90>((cardinal == Cardinal::S ? -1 : 1) * degree, minute, second)
		{
		}

		bool operator< ( Latitude const& rhs) const
		{
			return get_total_() < rhs.get_total_();
		}
	};
}
