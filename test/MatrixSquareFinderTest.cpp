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
    MatrixTestChunk(std::vector<std::vector<char> > vector, int result):
        mMatrixItem(vector),
        expectedResult(result)
    {
    }

    std::vector<std::vector<char> >& mMatrixItem;
    int expectedResult;
};

typedef MatrixTestChunk* TestInput[];

auto chunk1 = new MatrixTestChunk({
                                      {'1', '0', '1', '1', '1'},
                                      {'1', '0', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '0', '0', '1', '0'},
                                      {'1', '0', '0', '1', '0'}
                                  },1);

auto chunk2 = new MatrixTestChunk({
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'1', '1', '1', '1', '1'},
                                      {'0', '0', '0', '1', '0'},
                                      {'0', '0', '0', '1', '0'}
                                  },1);

auto chunk3 = new MatrixTestChunk({
                                      {'1', '1', '0', '1', '1'},
                                      {'1', '1', '0', '0', '0'},
                                      {'1', '1', '0', '1', '1'},
                                      {'0', '0', '0', '1', '0'},
                                      {'0', '0', '0', '1', '0'}
                                  },1);
TestInput positiveInput{chunk1,chunk2,chunk3};

class MatrixFieldTest: public  TestWithParam<MatrixTestChunk*>{
public:
    ~MatrixFieldTest(){
        delete testInput;

    }
    virtual void SetUp(){
        std::cout << "SetUp" << std::endl;
        squareFinder = new MatrixSquareFinder();
        std::cout << "MAtrix sqare finder" << std::endl;
    }
    virtual void TearDown(){
        delete squareFinder;
    }
protected:
    MatrixTestChunk* testInput;
    MatrixSquareFinder* squareFinder;
};

TEST_P(MatrixFieldTest,MatrixSquareFinder_ValidInput_ValidOutput){
    auto testInput = GetParam();
    int result = squareFinder->SquareNumber(testInput->mMatrixItem);
    EXPECT_EQ(testInput->expectedResult,result);
}

INSTANTIATE_TEST_CASE_P(PositiveTestInput,
                        MatrixFieldTest,
                        ::testing::ValuesIn(positiveInput));
