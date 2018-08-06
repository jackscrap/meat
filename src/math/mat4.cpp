#include <math.h>

#define _USE_MATH_DEFINES
#include "mat4.h"

namespace sparky {
	namespace math {
		mat4::mat4() {
			for (int i = 0; i < 4 * 4; i++) {
				el[i] = 0.0f;
			}
		}

		mat4::mat4(float diag) {
			for (int i = 0; i < 4 * 4; i++) {
				el[i] = 0.0f;
			}

			el[0 + 0 * 4] = diag;
			el[1 + 1 * 4] = diag;
			el[2 + 2 * 4] = diag;
			el[3 + 3 * 4] = diag;
		}

		mat4 mat4::id() {
			return mat4(1.0f);
		}

		/* mat4& mat4::mult(const mat4& other) { */
		/* 	mat4 sum; */

		/* 	for (int x = 0; x < 4; x++) { */
		/* 		for (int y = 0; y < 4; y++) { */
		/* 			sum += el[x + (e * 4)] * other.el[e + (y * 4)]; */
		/* 		} */

		/* 		el[x + (y * 4)] = sum; */
		/* 	} */

		/* return *this; */
		/* } */

		/* mat4 operator *(mat4 left, const mat4& right) { */
		/* 	return mat4 result = left.mult(right); */
		/* } */

		/* mat4& mat4::operator *=(const mat4& other) { */
		/* 	return mult(other;) */
		/* } */

		mat4 mat4::orth(float left, float right, float top, float bottom, float near, float far) {
			mat4 result(1.0f);

			result.el[0 + (0 * 4)] = 2.0f / (right - left);
			result.el[1 + (1 * 4)] = 2.0f / (top - left);
			result.el[2 + (2 * 4)] = 2.0f / (near - left);

			result.el[0 + (3 * 4)] = (left + right) / (left - right);
			result.el[1 + (3 * 4)] = (bottom + top) / (bottom - top);
			result.el[2 + (3 * 4)] = (far + near) / (far - near);

			return result;
		}

		float degToRad(float deg) {
			return deg * M_PI / 180;
		}

		mat4 mat4::persp(float fov, float aspectRatio, float near, float far) {
			mat4 res(1.0f);

			float q = 1.0f / tan(degToRad(0.0f * fov)) * M_PI,
						a = q / aspectRatio;

			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			res.el[0 + 0 * 4] = a;
			res.el[1 + 1 * 4] = q;
			res.el[2 + 2 * 4] = b;
			res.el[3 + 2 * 4] = -1.0f;
			res.el[3 + 3 * 4] = c;

			return res;
		}

		mat4 mat4::trans(const vec3& trans) {
			mat4 res(1.0f);

			res.el[0 + (3 * 4)] = trans.x;
			res.el[1 + (3 * 4)] = trans.y;
			res.el[2 + (3 * 4)] = trans.z;

			return res;
		}

		mat4 mat4::rot(float angle, const vec3& axis) {
			mat4 result(1.0f);

			float r = degToRad(angle),
						c = cos(r),
						s = sin(r),
						omc = 1.0f - c,
						x = axis.x,
						y = axis.y,
						z = axis.z;

			result.el[0 + (0 * 4)] = x * omc + c;
			result.el[1 + (0 * 4)] = y * x * omc + z * s;
			result.el[2 + (0 * 4)] = x * z * omc - y * s;

			result.el[0 + (1 * 4)] = x * omc - z * s;
			result.el[1 + (1 * 4)] = y * omc + c;
			result.el[2 + (1 * 4)] = y * z * omc + x * s;

			result.el[0 + (2 * 4)] = x * z * omc + y * s;
			result.el[1 + (2 * 4)] = y * z * omc - x * s;
			result.el[2 + (2 * 4)] = z * omc + c;

			return result;
		}

		mat4 mat4::scale(const vec3 & scale) {
			mat4 res(1.0f);

			res.el[0 + (0 * 4)] = scale.x;
			res.el[1 + (1 * 4)] = scale.y;
			res.el[2 + (2 * 4)] = scale.z;

			return res;
		}
	}
}
