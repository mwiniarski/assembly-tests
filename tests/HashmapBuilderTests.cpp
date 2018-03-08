//
// Created by Michael Winiarski on 05/03/2018.
//

#include <gtest/gtest.h>
#include <HashmapBuilder.h>
using namespace std;

TEST(HashmapBuilder, init) {
    HashmapBuilder hb(3);
    vector<string> vec = {"ACTGG", "ACGTT", "GGTGT"};
    hb.buildHashmap(vec);
}