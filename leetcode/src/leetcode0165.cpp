/* 165. Compare Version Numbers

Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
 
Note:
Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class SolutionLeetcode0165 {
public:
    int compareVersion(string version1, string version2) {
        vector<string> result1 = split(version1, '.');
        vector<string> result2 = split(version2, '.');
        if (result1.size() > result2.size()) {
            size_t count = result1.size() - result2.size();
            for (size_t i = 0; i < count; i++) {
                result2.push_back("0");
            }
        }
        if (result2.size() > result1.size()) {
            size_t count = result2.size() - result1.size();
            for (size_t i = 0; i < count; i++) {
                result1.push_back("0");
            }
        }
        for (size_t i = 0; i < result1.size(); i++) {
            if (stoi(result1[i]) > stoi(result2[i])) {
                return 1;
            } else if (stoi(result2[i]) > stoi(result1[i])) {
                return -1;
            }
        }
        return 0;
    }

private:
    vector<string> split(string str, char ch) {
        vector<string> result;
        string temp;
        for (size_t i = 0; i < str.size(); i++) {
            if (str[i] != ch) {
                temp.push_back(str[i]);
            } else {
                if (temp.size() != 0) {
                    result.push_back(temp);
                    temp.clear();
                }
            }
        }
        if (temp.size() != 0) {
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};

int main()
{
    SolutionLeetcode0165 s;
    cout << "1.0.1 compare 1.1 result : " << s.compareVersion("1.0.1", "1.1") << endl;
    cout << "1.1.1 compare 1.1 result : " << s.compareVersion("1.1.1", "1.1") << endl;
    cout << "1.1 compare 1.1 result : " << s.compareVersion("1.1", "1.1") << endl;
    cout << "1.1 compare 1.1.1 result : " << s.compareVersion("1.1", "1.1.1") << endl;
    cout << "1.0.1 compare 1 result : " << s.compareVersion("1.0.1", "1") << endl;
    return 0;
}
