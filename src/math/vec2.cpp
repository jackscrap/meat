#include "vec2.h"

namespace sparky {
	namespace math {
		vec2::vec2(float& x, float& y) {
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other) {
			x += other.x;
			y += other.y;

			return *this;
		}

		vec2& vec2::sub(const vec2& other) {
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& vec2::mult(const vec2& other) {
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2& vec2::div(const vec2& other) {
			x /= other.x;
			y /= other.y;

			return *this;
		}


		vec2 operator +(vec2 left, const vec2& right) {
			return left.add(right);
		}

		vec2 operator -(vec2 left, const vec2& right) {
			return left.sub(right);
		}

		vec2 operator *(vec2 left, const vec2& right) {
			return left.mult(right);
		}

		vec2 operator /(vec2 left, const vec2& right) {
			return left.div(right);
		}


		vec2& vec2::operator +=(const vec2& other) {
			return add(other);
		}

		vec2& vec2::operator -=(const vec2& other) {
			return sub(other);
		}

		vec2& vec2::operator *=(const vec2& other) {
			return mult(other);
		}

		vec2& vec2::operator /=(const vec2& other) {
			return div(other);
		}


		bool vec2::operator ==(const vec2& other) {
			return x == other.x && y == other.y;
		}

		bool vec2::operator !=(const vec2& other) {
			return !(*this == other);
		}


		std::ostream& operator<<(std::ostream& stream, const vec2& vec) {
			stream << "vec2: (" << vec.x << ", " << vec.y << ")";

			return stream;
		}
	}
}
