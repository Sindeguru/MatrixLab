#include <../gtest/gtest.h>
#include "MyVector.h"

TEST(Vector, create_vector)
{
	ASSERT_NO_THROW(Vector<int> v1);

}


TEST(Vector, create_empty_vector)
{
	SUCCEED(Vector<int> v1);
}

TEST(Vector, single_element_vector)
{
	Vector<int>v1(1,0);
	EXPECT_EQ(0, v1.GetElem(0));
	EXPECT_EQ(1, v1.GetLength());
}

TEST(Vector, set_elem_in_position)
{
	Vector<int> v1(3, 3);
	v1.SetElem(2, 9);
	EXPECT_EQ(3, v1.GetElem(1));
	EXPECT_EQ(9, v1.GetElem(2));
}

TEST(Vector, throw_if_try_set_elem_with_more_index_when_in_vector)
{
	Vector<int> v(1,9);
	ASSERT_ANY_THROW(v.SetElem(2, 3));
}

TEST(Vector, create_vector_use_other_vector)
{
	Vector<int> v1(3, 3);
	Vector<int>v2(3,3);
	EXPECT_EQ(1, v2==v1);
}

TEST(Vector, create_vector_use_massiv)
{
	int* a;
	a = new int[3];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	Vector<int> v(3);
	v.SetElem(0, a[0]);
	v.SetElem(1, a[1]);
	v.SetElem(2, a[2]);
	EXPECT_EQ(v.GetElem(0), a[0]);
	EXPECT_EQ(v.GetElem(1), a[1]);
	EXPECT_EQ(v.GetElem(2), a[2]);
}

TEST(Vector, vector_plus_vector_and_plus_equal)
{
	Vector<int> v1(4, 3), v2(3, 4), v3(3, 7);
	v1.SetElem(2, 10);
	v3.SetElem(2, 14);
	EXPECT_EQ((v1 + v2) == v3,1);
	v1 += v2;
	EXPECT_EQ(v1== v3, 1);
}

TEST(Vector, vector_minus_vector_and_minus_equal)
{
	Vector<int> v1(4, 5), v2(3, 3), v3(3, 2);
	v1.SetElem(2, 10);
	v3.SetElem(2, 7);
	EXPECT_EQ((v1 - v2) == v3, 1);
	v1 -= v2;
	EXPECT_EQ(v1 == v3, 1);
}

TEST(Vector, multiplication_of_vectors)
{
	Vector<int> v1(4, 5), v2(3, 3), v3(3, 15);
	v1.SetElem(2, 8);
	v3.SetElem(2, 24);
	EXPECT_EQ((v1 * v2) == v3, 1);
}

TEST(Vector, division_of_vectors)
{
	Vector<int> v1(4, 15), v2(3, 3), v3(3, 5);
	v1.SetElem(2, 24);
	v3.SetElem(2, 8);
	EXPECT_EQ((v1 / v2) == v3, 1);
}

TEST(Vector, not_equal)
{
	Vector<int> v1(4, 15), v2(3, 3), v3(4, 3);
	EXPECT_EQ(v1 == v2, 0);
	EXPECT_EQ(v2 == v3, 0);
}

TEST(Vector, assignet_vector_to_vector)
{
	Vector<int> v1(4, 15), v2(3, 3);
	v1 = v2;
	EXPECT_EQ(v1 == v2, 1);
}

TEST(Vector, get_elem_used_index)
{
	Vector<int> v1(3, 7);
	v1.SetElem(2, 13);
	EXPECT_EQ(v1.GetElem(2), 13);
}
