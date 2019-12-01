//
// Created by toor on 7/13/18.
//

#include "HouseRobberyMemoization.hpp"
#include "HouseRobberySimple.h"
#include "gtest/gtest.h"
using namespace std;

class HouseRobberyTest : public  ::testing::Test
{
public:
    HouseRobberyTest(): Test(){
        mpHouseRobberyMemoization = new HouseRobberyMemoization();
        mpHouseRobberySimple = new HouseRobberySimple();
    }
    virtual ~HouseRobberyTest(){
        delete mpHouseRobberyMemoization;
        delete mpHouseRobberySimple;
    }
protected:
    HouseRobberyMemoization* mpHouseRobberyMemoization;
    HouseRobberySimple* mpHouseRobberySimple;

};

TEST_F(HouseRobberyTest, simpleTest){
vector<int> testVector = {1,4,3,8};
int result = mpHouseRobberyMemoization->Robber(testVector);
int resultSimple =mpHouseRobberySimple->HouseRobber(testVector);
EXPECT_EQ(result,12);
}

TEST_F(HouseRobberyTest, simpleTest2) {
vector<int> testVector = {1, 4, 3, 8, 16, 1, 1, 100};
int result = mpHouseRobberyMemoization->Robber(testVector);
EXPECT_EQ(result, 120);
}

