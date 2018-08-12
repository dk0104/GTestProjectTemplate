//
// Created by toor on 8/12/18.
//

#include "unsortSruff.hpp"
#include "gtest/gtest.h"

class UnsortStuffTest: public ::testing::Test
{
public:
    UnsortStuffTest():Test(){

    }

protected:
    void  SetUp() override {
        mpUnsortStuff = new UnsortStuff();
    }

    void TearDown() override{
        if(mpUnsortStuff!= nullptr){
            delete  mpUnsortStuff;
        }
    }

    UnsortStuff* mpUnsortStuff;
};

TEST_F(UnsortStuffTest,iteratorTest){
    mpUnsortStuff->Run(100);
}