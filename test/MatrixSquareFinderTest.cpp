//
// Created by toor on 7/18/18.
//

#include "gtest/gtest.h"
#include <matrixSquareFinder.hpp>

using namespace std;

class MatrixTable{
public:
    virtual MatrixTable(vector<vector<char>>& inputVector,int result);
    virtual ~MatrixTable();
    virtual vector<vector<char>>* GetTable();
    virtual int GetExpectedResult();
};

class PrecompMatrixTable: public MatrixTable{
public:
    PrecompMatrixTable(vector<vector<char>>& input,int result);
    vector<vector<char>> *GetTable() override {
        return table;
    }

    int GetExpectedResult() override {
        return MatrixTable::GetExpectedResult();
    }

protected:
    vector<vector<char>> table;

};

typedef MatrixTable* CreateMatrixTable();


class MatrixSquareFinderTest : public ::testing::TestWithParam<CreateMatrixTable*>
{
public:
    virtual ~MatrixSquareFinderTest(){
        delete  squareField;
    }
    virtual void SetUp(){
        squareField = (*GetParam())();
    }
    virtual void TearDown(){
        delete squareField;
        squareField = NULL;
    }
protected:
    MatrixTable* squareField;
};

TEST_P(MatrixSquareFinderTest,RetunFalseForNonMatchingSquares){
    

}

INSTANTIATE_TEST_CASE_P(InvalidFieldsTest,MatrixSquareFinderTest,Values());