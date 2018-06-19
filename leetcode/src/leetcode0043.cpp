// leetcode043.cpp
//
// Multiply Strings
// 	Given two numbers represented as strings, return multiplication of the numbers as a string.
//  Note: The numbers can be arbitrarily large and are non-negative.

#include <string>
#include <vector>
#include <iostream>
#include <thread.h>
using namespace std;

#define N 110

class Solution {
public:
    void char_to_int(string number, int array[])
    {
        size_t count = number.size();
        for(size_t index = 0 ; index < count; ++index)
        {
            array[count - index - 1] = (number.at(index) - '0');
        }
    }
    
	string multiply(string num1, string num2)
    {
        int a[N], b[N], c[N * 2];
        int i = 0, j = 0;
        memset(a, 0, sizeof(int) * N);
        memset(b, 0, sizeof(int) * N);
        char_to_int(num1, a);
        char_to_int(num2, b);
        
        memset(c, 0, sizeof(int) * N * 2);
        
        //两个数字的每一位都彼此相乘
        for(i = 0 ; i < N ; ++i)
        {
            for(j = 0 ; j < N ; ++j)
            {
                c[i + j] += a[i] * b[j];
            }
        }
        
        //处理进位关系，9 * 9 = 81，所以最高进一位
        for(i = 0 ; i < 2 * N - 1 ; ++i)
        {
            c[i + 1] += c[i] /10;
            c[i] = c[i] % 10;
        }
        
        //越过不需要的位
        j = 2 * N - 1;
        while(c[j] == 0 && j > 0)
            --j;
        
        //组成返回值
        string str;
        for (i = j; i >= 0; --i)
        {
            str.push_back((char)(c[i] + '0'));
        }
        return str;
	}
};

//更简洁的，减小空间复杂度，减小了不必要的运算的版本
class Solution1
{
public:
    string multiply(string num1, string num2)
    {
        size_t len1 = num1.length(), len2 = num2.length();
        vector<int> temp(len1 + len2, 0);
        for (int i = 0; i < len1; ++i) {
            int d1 = num1[i] - '0';
            for (int j = 0; j < len2; ++j) {
                int d2 = num2[j] - '0';
                temp[i + j + 1] += d1 * d2;
            }
        }
        
        for (auto ritr = temp.rbegin(); ritr != prev(temp.rend()); ++ritr)
        {
            *next(ritr) += *ritr / 10;
            *ritr %= 10;
        }
        
        string res;
        res.reserve(temp.size());
        std::transform(temp.cbegin(), temp.cend(), back_inserter(res), [](int d) { return d + '0'; });
        
        size_t positionNonZero = res.find_first_not_of('0');
        if(positionNonZero != string::npos)
        {
            return res.substr(positionNonZero);
        }
        return "0";
    }
};

int main()
{
    Solution1 s;
    
    string str = s.multiply("0", "0");
    
    
    
    string str1 = "12345";
    string str2;
    string str3 = "12345";
    
    std::transform(str1.cbegin(), str1.cend(), back_inserter(str2), [](char a){return a + 1;});
    
    cout << str2 << endl;
    
    str2.clear();
    
    std::transform(str1.cbegin(), str1.cend(), str3.cbegin(), back_inserter(str2), [](char a, char b){return a + b;});
    
    cout << str2 << endl;
    
    
	return 0;
}
