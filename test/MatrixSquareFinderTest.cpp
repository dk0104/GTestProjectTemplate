//
// Created by toor on 7/18/18.
// More examples https://github.com/google/googletest/blob/master/googletest/samples/sample7_unittest.cc
//

#include "gtest/gtest.h"
#include <matrixSquareFinder.hpp>

using ::testing::TestWithParam;
using ::testing::ValuesIn;

using namespace std;
using ::testing::TestWithParam;
using ::testing::Bool;
using ::testing::Values;
using ::testing::Combine;


struct MatrixTestChunk
{
    MatrixTestChunk(std::vector<std::vector<char>> input, int result):
        xItem(input),
        expectedResult(result)
    {
    }

    std::vector<std::vector<char>> xItem;
    int expectedResult;
};

typedef MatrixTestChunk* TestInput[];

auto chunk1 = new MatrixTestChunk({
                                      {'1', '0', '1', '1', '1'},
                                      {'1', '0', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '0', '0', '1', '0'},
                                      {'1', '0', '0', '1', '0'}
                                  },0);

auto chunk2 = new MatrixTestChunk({
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'0', '0', '0', '1', '0'},
                                      {'0', '0', '0', '1', '0'}
                                  },0);

auto chunk3 = new MatrixTestChunk({
                                      {'1', '1', '0', '1', '1'},
                                      {'1', '1', '0', '0', '0'},
                                      {'1', '1', '0', '1', '1'},
                                      {'0', '0', '0', '1', '0'},
                                      {'0', '0', '0', '1', '0'}
                                  },0);


TestInput positiveInput{chunk1,chunk2,chunk3};

class MatrixFieldTest: public  TestWithParam<MatrixTestChunk*>{
public:
    ~MatrixFieldTest(){
        if(testInput!= nullptr){
            delete testInput;
        }
    }
    virtual void SetUp(){
        std::cout << "SetUp" << std::endl;
        squareFinder = new MatrixSquareFinder();
        testInput = GetParam();
        std::cout << "MAtrix sqare finder" << std::endl;
    }
    virtual void TearDown(){
    }
protected:
    MatrixTestChunk* testInput;
    MatrixSquareFinder* squareFinder;
};

TEST_P(MatrixFieldTest,MatrixSquareFinder_ValidInput_ValidOutput){

    if(testInput!= nullptr){
        auto result = squareFinder->SquareNumber(testInput->xItem);
        EXPECT_EQ(testInput->expectedResult,result);
    }
}

INSTANTIATE_TEST_CASE_P(PositiveTestInput,
                        MatrixFieldTest,
                        ::testing::ValuesIn(positiveInput));
