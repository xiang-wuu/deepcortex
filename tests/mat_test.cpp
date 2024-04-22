#include <gtest/gtest.h>
#include "mat.h"

class MatrixTest : public ::testing::Test {
protected:
    Matrix A{3, 3};
    Matrix B{3, 3};
    Matrix C{3, 3};

    void SetUp() override {
        A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
        A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;
        A(2, 0) = 7; A(2, 1) = 8; A(2, 2) = 9;

        B(0, 0) = 10; B(0, 1) = 11; B(0, 2) = 12;
        B(1, 0) = 13; B(1, 1) = 14; B(1, 2) = 15;
        B(2, 0) = 16; B(2, 1) = 17; B(2, 2) = 18;

        C(0, 0) = 0; C(0, 1) = 0; C(0, 2) = 0;
        C(1, 0) = 0; C(1, 1) = 0; C(1, 2) = 0;
        C(2, 0) = 0; C(2, 1) = 0; C(2, 2) = 0;
    }
};

TEST_F(MatrixTest, Addition) {
    C = A + B;
    C.print();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(C(i, j), A(i, j) + B(i, j));
        }
    }
}

TEST_F(MatrixTest, Substraction) {
    C = A - B;
    C.print();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(C(i, j), A(i, j) - B(i, j));
        }
    }
}

TEST_F(MatrixTest, Multiplication) {
    C = A * B;
    C.print();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            EXPECT_EQ(C(i, j), A(i, j) * B(i, j));
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}