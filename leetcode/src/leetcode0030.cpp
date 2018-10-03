// leetcode030.cpp
//
/********************************************************************************** 
* 
* You are given a string, S, and a list of words, L, that are all of the same length. 
* Find all starting indices of substring(s) in S that is a concatenation of each word 
* in L exactly once and without any intervening characters.
* 
* For example, given:
* S: "barfoothefoobarman"
* L: ["foo", "bar"]
* 
* You should return the indices: [0,9].
* (order does not matter).
* 
*               
**********************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> result;
        if ( s.size()<=0 || words.size() <=0 ){
            return result;
        }
        
        map<string,int> expect;
        size_t max_length = 0;
        for (size_t index = 0; index < words.size(); ++index)
        {
            max_length += words[index].length();
            if (expect.find(words[index]) == expect.end())
            {
                expect[words[index]] = 1;
            }else{
                expect[words[index]] += 1;
            }
        }
        
        size_t string_length = s.length();
        size_t word_length = words[0].length();

        if(string_length < max_length)
        {
            return result;
        }

        for (int i = 0; i <= string_length - max_length; ++i)
        {
            map<string,int> actual;
            for (int j = i; j < i + max_length; j += word_length)
            {
                string substr = s.substr(j,word_length);
                if (expect.find(substr) != expect.end())
                {
                    if (actual.find(substr) != actual.end())
                    {
                        actual[substr] += 1;
                    }else{
                        actual[substr] =  1;
                    }
                }else{
                    actual.clear();
                    break;
                }
            }
            
            if (actual.size() == expect.size())
            {
                bool bSame = true;
                map<string,int>::iterator it = expect.begin();
                for (;it != expect.end(); it++)
                {
                    if(it->second != actual[it->first])
                    {
                        bSame = false;
                    }
                }
                if (bSame)
                {
                    result.push_back(i);
                }
            }
        }
        
        return result;
    }
};


int main()
{
    Solution s;

	{
		string str = "barfoothefoobarman";
		vector<string> l;
		l.push_back("bar");
		l.push_back("foo");
		
		vector<int> indics = s.findSubstring(str, l);
		for(int i=0; i<indics.size(); i++){
			cout << indics[i] << " ";
		}
		cout << endl;
	}

	{
		string str = "barfoobarfoothefoobarman";
		vector<string> l;
		l.push_back("foo");
		l.push_back("bar");
		l.push_back("foo");
		
		vector<int> indics = s.findSubstring(str, l);
		for(int i=0; i<indics.size(); i++){
			cout << indics[i] << " ";
		}
		cout << endl;
	}

	{
		string str = "a";
		vector<string> l;
		l.push_back("a");
		l.push_back("a");
		
		vector<int> indics = s.findSubstring(str, l);
		for(int i=0; i<indics.size(); i++){
			cout << indics[i] << " ";
		}
		cout << endl;
	}

	{
		string str = "a";
		vector<string> l;
		l.push_back("a");
		
		vector<int> indics = s.findSubstring(str, l);
		for(int i=0; i<indics.size(); i++){
			cout << indics[i] << " ";
		}
		cout << endl;
	}
    
    return 0;
}
