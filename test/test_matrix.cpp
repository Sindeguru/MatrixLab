#include <../gtest/gtest.h>
#include "Matrix.h"


TEST(TMatrix, can_create_matrix)
{
  ASSERT_NO_THROW(TMatrix<int> A(3));
}

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix<int> m(5);
  TMatrix<int>m1(5);
  EXPECT_EQ(m==m1,1);
}


TEST(TMatrix, can_get_size)
{
  TMatrix<int> m(10);
  EXPECT_EQ(m.GetLength(), 10);
}
