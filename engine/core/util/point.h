/***************************************************************************
 *   Copyright (C) 2005-2007 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef FIFE_VIDEO_POINT_H
#define FIFE_VIDEO_POINT_H

// Standard C++ library includes
#include <iostream>

// Platform specific includes
#include "fife_math.h"
#include "fife_stdint.h"

// 3rd party library includes

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder

namespace FIFE {

	/** A 2D Point
	 *
	 * This is a small helper class to aid in 2d vector arithmetics.
	 * @see Rect
	 */
	template <typename T> class PointType2D {
	public:
		/** The X coordinate.
		 */
		T x;

		/** The Y coordinate
		 */
		T y;

		/** Constructor
		 *
		 * Creates a with 0 as default values.
		 */
		explicit PointType2D(T _x = 0, T _y = 0): x(_x), y(_y) {
		}

		/** Vector addition
		 */
		PointType2D<T> operator+(const PointType2D<T>& p) const {
			return PointType2D<T>(x + p.x, y + p.y);
		}

		/** Vector substraction
		 */
		PointType2D<T> operator-(const PointType2D<T>& p) const {
			return PointType2D<T>(x - p.x, y - p.y);
		}

		/** Vector inplace addition
		 */
		PointType2D<T>& operator+=(const PointType2D<T>& p) {
			x += p.x;
			y += p.y;
			return *this;
		}

		/** Vector inplace substraction
		 */
		PointType2D<T>& operator-=(const PointType2D<T>& p) {
			x -= p.x;
			y -= p.y;
			return *this;
		}

		/** Scalar multiplication with an integer value
		 */
		PointType2D<T> operator*(const long& i) const {
			return PointType2D<T>(x * i, y * i);
		}

		/** Scalar division with an integer value
		 */
		PointType2D<T> operator/(const long& i) const {
			return PointType2D<T>(x / i, y / i);
		}

		/** Equality comparision
		 */
		bool operator==(const PointType2D<T>& p) const {
			return x == p.x && y == p.y;
		}

		/** Equality comparision
		 */
		bool operator!=(const PointType2D<T>& p) const {
			return !(x == p.x && y == p.y);
		}

		/** Return length
		 */
		T length() const {
			double sq;
			sq = x*x + y*y;
			return static_cast<T>(sqrt(sq));
		}
	};

	/** Print coords of the Point to a stream
	 */
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const PointType2D<T>& p) {
		return os << "(" << p.x << "," << p.y << ")";
	}

	typedef PointType2D<int> Point;
	typedef PointType2D<int> IntPoint;
	typedef PointType2D<double> DoublePoint;
	typedef PointType2D<int> IntPoint2D;
	typedef PointType2D<double> DoublePoint2D;



	/** A 3D Point
	 *
	 * This is a small helper class to aid in 3d vector arithmetics.
	 * @see Rect
	 */
	template <typename T> class PointType3D {
	public:
		/** The X coordinate.
		 */
		T x;

		/** The Y coordinate
		 */
		T y;

		/** The Z coordinate.
		 */
		T z;

		/** Constructor
		 *
		 * Creates a with 0 as default values.
		 */
		explicit PointType3D(T _x = 0, T _y = 0, T _z = 0): x(_x), y(_y), z(_z) {
		}

		/** Vector addition
		 */
		PointType3D<T> operator+(const PointType3D<T>& p) const {
			return PointType3D<T>(x + p.x, y + p.y, z + p.z);
		}

		/** Vector substraction
		 */
		PointType3D<T> operator-(const PointType3D<T>& p) const {
			return PointType3D<T>(x - p.x, y - p.y, z - p.z);
		}

		/** Vector inplace addition
		 */
		PointType3D<T>& operator+=(const PointType3D<T>& p) {
			x += p.x;
			y += p.y;
			z += p.z;
			return *this;
		}

		/** Vector inplace substraction
		 */
		PointType3D<T>& operator-=(const PointType3D<T>& p) {
			x -= p.x;
			y -= p.y;
			z -= p.z;
			return *this;
		}

		/** Scalar multiplication with an integer value
		 */
		PointType3D<T> operator*(const long& i) const {
			return PointType3D<T>(x * i, y * i, z * i);
		}

		/** Scalar division with an integer value
		 */
		PointType3D<T> operator/(const long& i) const {
			return PointType3D<T>(x / i, y / i, z / i);
		}

		/** Equality comparision
		 */
		bool operator==(const PointType3D<T>& p) const {
			return x == p.x && y == p.y && z == p.z;
		}

		/** Equality comparision
		 */
		bool operator!=(const PointType3D<T>& p) const {
			return !(x == p.x && y == p.y && z == p.z);
		}

		/** Return length
		 */
		T length() const {
			double sq;
			sq = (x*x + y*y);
			sq = sq*sq + z*z;
			return static_cast<T>(sqrt(sq));
		}
	};

	/** Print coords of the Point to a stream
	 */
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const PointType3D<T>& p) {
		return os << "(" << p.x << "," << p.y << "," << p.z << ")";
	}

	typedef PointType3D<int> Point3D;
	typedef PointType3D<int> IntPoint3D;
	typedef PointType3D<double> DoublePoint3D;
}

#endif
