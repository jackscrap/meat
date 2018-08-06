#include "vec3.h"

namespace sparky {
	namespace math {
		vec3::vec3(float& x, float& y, float& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const vec3& other) {
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& vec3::sub(const vec3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		vec3& vec3::mult(const vec3& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		vec3& vec3::div(const vec3& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}


		vec3 operator +(vec3 left, const vec3& right) {
			return left.add(right);
		}

		vec3 operator -(vec3 left, const vec3& right) {
			return left.sub(right);
		}

		vec3 operator *(vec3 left, const vec3& right) {
			return left.mult(right);
		}

		vec3 operator /(vec3 left, const vec3& right) {
			return left.div(right);
		}


		vec3& vec3::operator +=(const vec3& other) {
			return add(other);
		}

		vec3& vec3::operator -=(const vec3& other) {
			return sub(other);
		}

		vec3& vec3::operator *=(const vec3& other) {
			return mult(other);
		}

		vec3& vec3::operator /=(const vec3& other) {
			return div(other);
		}


		bool vec3::operator ==(const vec3& other) {
			return x == other.x && y == other.y && y == other.y;
		}

		bool vec3::operator !=(const vec3& other) {
			return !(*this == other);
		}


		std::ostream& operator<<(std::ostream& stream, const vec3& vec) {
			stream << "vec3: (" << vec.x << ", " << vec.y << ", " << vec.x << ")";

			return stream;
		}
	}
}
