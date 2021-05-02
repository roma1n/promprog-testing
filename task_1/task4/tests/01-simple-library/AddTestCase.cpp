//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

int AddTestCase::SimpleAdd(int x, int y) {
    int res = Add(x, y);
    return res;
}

TEST_F(AddTestCase, AddTest) {
    EXPECT_EQ(AddTestCase::SimpleAdd(3, 5), 8);
}
