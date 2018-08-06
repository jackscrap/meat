#include <iostream>

namespace sparky {
	namespace math {
		struct vec2 {
			float x,
						y;

			vec2();
			vec2(float& x, float& y);

			vec2& add(const vec2& other);
			vec2& sub(const vec2& other);
			vec2& mult(const vec2& other);
			vec2& div(const vec2& other);

			friend vec2 operator +(vec2 left, const vec2& right);
			friend vec2 operator -(vec2 left, const vec2& right);
			friend vec2 operator *(vec2 left, const vec2& right);
			friend vec2 operator /(vec2 left, const vec2& right);

			bool operator ==(const vec2& other);
			bool operator !=(const vec2& other);

			vec2& operator +=(const vec2& other);
			vec2& operator -=(const vec2& other);
			vec2& operator *=(const vec2& other);
			vec2& operator /=(const vec2& other);

			/* friend std::ostream& operator<<(std::ostream& stream, const vec2& vec); */
		};
	}
}
