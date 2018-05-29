//
//  leetcode0169.cpp
//
//  Created by zencher on 2018/5/29.
//  Copyright © 2018年 zencher. All rights reserved.
//
//  Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//  You may assume that the array is non-empty and the majority element always exist in the array.
//
//  Example 1:
//
//  Input: [3,2,3]
//  Output: 3
//  Example 2:
//
//  Input: [2,2,1,1,1,2,2]
//  Output: 2

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max = 0, key = 0;
        map<int,int> amap;
        map<int, int>::iterator itr;
        for (size_t index = 0; index < nums.size(); ++index ) {
            itr = amap.find(nums[index]);
            if(itr == amap.end())
            {
                amap[nums[index]] = 1;
                if (max == 0) {
                    max = 1;
                    key = nums[index];
                }
            }else{
                itr->second++;
                if(itr->second > max) {
                    max = itr->second;
                    key = itr->first;
                }
            }
        }
        return key;
    }
};

int main()
{
    Solution s;
    
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(4);
    
    int ret = s.majorityElement(arr);
    cout << ret;
    
    return 0;
}
