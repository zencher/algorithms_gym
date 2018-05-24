//  leetcode0190.cpp
//
//  Created by zencher on 16/4/27.
//  Copyright © 2016年 zencher. All rights reserved.
//

#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t count = sizeof(n) * 8;
        for(uint32_t i = 1; i < count; ++i)
        {
            ret += n & 1;
            ret = ret << 1;
            n = n >> 1;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    s.reverseBits(1);
    return 0;
}
