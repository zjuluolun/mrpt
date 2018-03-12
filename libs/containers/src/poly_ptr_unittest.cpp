/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2018, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */

#include <mrpt/containers/deepcopy_ptr.h>
#include <mrpt/core/common.h>  // TODO
MRPT_TODO("Re-enable when mrpt-poses is ported!");
#if 0

#include <mrpt/poses/CPose2D.h>
#include <gtest/gtest.h>

using namespace mrpt;
using namespace std;

TEST(copy_ptr, SimpleOps)
{
	mrpt::utils::copy_ptr<int> ptr1;
	EXPECT_FALSE(ptr1);

	ptr1.reset(new int());
	EXPECT_TRUE(ptr1);

	*ptr1 = 123;
	EXPECT_TRUE(*ptr1 == 123);

	{
		mrpt::utils::copy_ptr<int> ptr2 = ptr1;
		EXPECT_TRUE(*ptr1 == *ptr2);

		(*ptr2)++;
		EXPECT_FALSE(*ptr1 == *ptr2);
	}
	{
		mrpt::utils::copy_ptr<int> ptr2;
		ptr2 = ptr1;
		EXPECT_TRUE(*ptr1 == *ptr2);

		(*ptr2)++;
		EXPECT_FALSE(*ptr1 == *ptr2);
	}
}

TEST(copy_ptr, StlContainer)
{
	using str2d_ptr = mrpt::utils::copy_ptr<std::pair<std::string, int>>;

	str2d_ptr ptr;
	EXPECT_FALSE(ptr);

	std::vector<str2d_ptr> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(str2d_ptr(new str2d_ptr::value_type));
		v[i]->first = "xxx";
		v[i]->second = i;
	}

	str2d_ptr v3 = v[3];
	EXPECT_TRUE(v3->second == 3);
	v3->second++;

	EXPECT_TRUE(v3->second == 4);
	EXPECT_TRUE(v[3]->second == 3);
}

TEST(poly_ptr, SimpleOps)
{
	mrpt::utils::poly_ptr<mrpt::poses::CPose2D> ptr1;
	EXPECT_FALSE(ptr1);

	ptr1.reset(new mrpt::poses::CPose2D());
	EXPECT_TRUE(ptr1);

	ptr1->x(123.0);
	EXPECT_NEAR(ptr1->x(), 123.0, 1e-9);

	{
		mrpt::utils::poly_ptr<mrpt::poses::CPose2D> ptr2 = ptr1;
		EXPECT_TRUE(*ptr1 == *ptr2);

		ptr2->x_incr(1.0);
		EXPECT_FALSE(*ptr1 == *ptr2);
	}
	{
		mrpt::utils::poly_ptr<mrpt::poses::CPose2D> ptr2;
		ptr2 = ptr1;
		EXPECT_TRUE(*ptr1 == *ptr2);

		ptr2->x_incr(1.0);
		EXPECT_FALSE(*ptr1 == *ptr2);
	}
}

TEST(poly_ptr, StlContainer)
{
	using str2d_ptr = mrpt::utils::poly_ptr<mrpt::poses::CPose2D>;

	str2d_ptr ptr;
	EXPECT_FALSE(ptr);

	std::vector<str2d_ptr> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(str2d_ptr(new str2d_ptr::value_type));
		v[i]->x(i);
	}

	str2d_ptr v3 = v[3];
	EXPECT_NEAR(v3->x(), 3.0, 1e-9);
	v3->x_incr(1.0);

	EXPECT_NEAR(v3->x(), 4.0, 1e-9);
	EXPECT_NEAR(v[3]->x(), 3.0, 1e-9);
}
#endif
