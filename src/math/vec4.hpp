#pragma once

#include <iostream>

namespace sparky {
	namespace math {
		struct vec4 {
			float x,
						y,
						z,
						w;

			/* vec4() = default; */
			vec4(float& x, float& y, float& z, float& w);

			vec4& add(const vec4& other);
			vec4& sub(const vec4& other);
			vec4& mult(const vec4& other);
			vec4& div(const vec4& other);

			friend vec4 operator +(vec4 left, const vec4& right);
			friend vec4 operator -(vec4 left, const vec4& right);
			friend vec4 operator *(vec4 left, const vec4& right);
			friend vec4 operator /(vec4 left, const vec4& right);

			bool operator ==(const vec4& other);
			bool operator !=(const vec4& other);

			vec4& operator +=(const vec4& other);
			vec4& operator -=(const vec4& other);
			vec4& operator *=(const vec4& other);
			vec4& operator /=(const vec4& other);

			/* friend std::ostream& operator<<(std::ostream& stream, const vec4& vec); */
		};
	}
}
