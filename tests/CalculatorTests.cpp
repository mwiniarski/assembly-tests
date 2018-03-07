//
// Created by Michael Winiarski on 05/03/2018.
//

#include <gtest/gtest.h>
#include <Calculator.h>

TEST(Calculator, init) {
    Calculator c;
    c.add(14, 6);
    ASSERT_EQ(c.getResult(), 20);
}