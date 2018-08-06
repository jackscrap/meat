#include "vec4.h"

namespace sparky {
	namespace math {
		vec4::vec4(float& x, float& y, float& z, float& w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::add(const vec4& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		vec4& vec4::sub(const vec4& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w += other.w;

			return *this;
		}

		vec4& vec4::mult(const vec4& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		vec4& vec4::div(const vec4& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			z /= other.z;

			return *this;
		}


		vec4 operator +(vec4 left, const vec4& right) {
			return left.add(right);
		}

		vec4 operator -(vec4 left, const vec4& right) {
			return left.sub(right);
		}

		vec4 operator *(vec4 left, const vec4& right) {
			return left.mult(right);
		}

		vec4 operator /(vec4 left, const vec4& right) {
			return left.div(right);
		}


		vec4& vec4::operator +=(const vec4& other) {
			return add(other);
		}

		vec4& vec4::operator -=(const vec4& other) {
			return sub(other);
		}

		vec4& vec4::operator *=(const vec4& other) {
			return mult(other);
		}

		vec4& vec4::operator /=(const vec4& other) {
			return div(other);
		}


		bool vec4::operator ==(const vec4& other) {
			return x == other.x && y == other.y && y == other.y && w == other.w;
		}

		bool vec4::operator !=(const vec4& other) {
			return !(*this == other);
		}


		std::ostream& operator<<(std::ostream& stream, const vec4& vec) {
			stream << "vec4: (" << vec.x << ", " << vec.y << ", " << vec.x << ", " << vec.w << ")";

			return stream;
		}
	}
}
