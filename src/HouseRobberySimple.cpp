//
// Created by toor on 12/2/19.
//

#include <vector>
#include "HouseRobberySimple.h"

int HouseRobberySimple::HouseRobber(std::vector<int> nums) {
    int nb = 0;
    int ob = 0;
    int take = 0;
    for(auto num: nums)
    {
        take = ob+num;
        ob=nb;
        nb=take>ob?take:ob;
    }
}
