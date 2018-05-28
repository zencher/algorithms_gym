//
//  leetcode0168.cpp
//  leetcode
//
//  Created by zencher on 2018/5/28.
//  Copyright © 2018年 zencher. All rights reserved.
//

#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string convertToTitle(int n)
    {
        stack<char> s;
        while (n > 0) {
            --n;
            s.push('A' + (n%26));
            n /= 26;
        }
        
        string ret;
        while (!s.empty()) {
            ret.push_back(s.top());
            s.pop();
        }
        return ret;
    }

};


int main()
{
    Solution s;
    
    string str = s.convertToTitle(27);
    cout << str;
    
    return 0;
}
