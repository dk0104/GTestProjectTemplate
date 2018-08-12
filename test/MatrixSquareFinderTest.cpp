//
// Created by toor on 7/18/18.
//

#include "gtest/gtest.h"
#include <matrixSquareFinder.hpp>

using namespace std;
using ::testing::TestWithParam;
using ::testing::Bool;
using ::testing::Values;
using ::testing::Combine;


struct MatrixTestChunk
{
    MatrixTestChunk(vector<vector<char>> vector): mMatrixItem(vector){

    }

    vector<vector<char>>& mMatrixItem;
};

typedef MatrixTestChunk TestInput[];


TestInput positiveInput={
        MatrixTestChunk(
        {
            {'1', '0', '1', '1', '1'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'},
            {'1', '0', '0', '1', '0'}}
        ),
        MatrixTestChunk(
        {
            {'1', '0', '1', '1', '1'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '1', '1', '1'},
            {'1', '0', '1', '1', '1'}}
        ),
        MatrixTestChunk(
        {
            {'1', '1', '1', '0', '1'},
            {'1', '1', '1', '0', '1'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '1', '0', '0'}}
        ),
};

