//
// Created by toor on 8/11/18.
//

#ifndef GTESTPROJECTTEMPLATE_UNSORTSRUFF_HPP
#define GTESTPROJECTTEMPLATE_UNSORTSRUFF_HPP

#include <map>

class UnsortStuff {

public:
    UnsortStuff();
    void ToggleMap();
    void Run(int count);
    std::map<int,int> testMap;

private:
    int iterator;
};

#endif //GTESTPROJECTTEMPLATE_UNSORTSRUFF_HPP
