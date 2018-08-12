//
// Created by toor on 8/11/18.
//

#include <iostream>
#include "unsortSruff.hpp"


UnsortStuff::UnsortStuff():iterator(99)
{
    testMap[1]=44;
    testMap[4]=55;
    testMap[6]=88;
    testMap[8]=99;
    testMap[12]=22;
}

void UnsortStuff::ToggleMap()
{
    if(iterator==99)
    {
        iterator = testMap.begin()->first;
    } else {
        std::map<int, int>::iterator it = testMap.find(iterator);
        it++;
        if (it != testMap.end()) {
            iterator = it->first;
        } else {
            iterator = testMap.begin()->first;
        }
    }
}

void UnsortStuff::Run(int count)
{
    while(count > 0){
        ToggleMap();
        std::cout << "Iterator : " << iterator << std::endl;
        count --;
    }

}