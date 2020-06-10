#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int cur = getValue(s[0]);
        for (int i = 1 ; i < s.length() + 1 ; i++){
            int next = getValue(s[i]);
            if (cur >= next){
                ans += cur;
            }else{
                ans -= cur;
            }
            cur = next;
        }
        return ans;
    }
    
    int getValue(char c){
        switch (c){
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0;
        }
    }
};
// @lc code=end

int main()
{
    Solution solu;
    cout << solu.romanToInt("CDXII") <<endl;
    cout << endl;
}

