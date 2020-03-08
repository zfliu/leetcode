#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        
        map<char, int> substr;

        int max = 0;
        for (int i = 0, j = 0 ; j < s.length() ; j++){
            if (substr.find(s[j]) != substr.end()){
                i = std::max(substr[s[j]], i);
            }
            substr[s[j]] = j + 1;
            max = std::max(max, j - i  + 1);
        }

        return max;        
    
    }

    int lengthOfLongestSubstring2(string s) {

        set<char> substr;

        int i = 0, j = 0, n = s.length();
        int max = 0;

        while(i < n && j < n){

            if (substr.count(s[j]) < 1){
                // 不存在
                substr.insert(s[j++]);
                if (substr.size() > max){
                    max = substr.size();
                }
            }else{
                substr.erase(s[i++]);
            }

        }
        return max;
    }
};

int main()
{  
    Solution solu;
    //cout << solu.lengthOfLongestSubstring("abcabcbb") << endl;
    //cout << solu.lengthOfLongestSubstring("pwwkew") << endl;
    cout << solu.lengthOfLongestSubstring(" ") << endl;
}