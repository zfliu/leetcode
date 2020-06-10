#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0){
            return "";
        }

        for (int i = 0 ; i < strs[0].length() ; i++){
            char c = strs[0][i];
            for (int j = 1 ;  j < strs.size() ; j++){
                if (i > strs[j].length() || strs[j][i] != c){
                    return strs[0].substr(0, i);
                }
            }
        }
        // 当全部比较完必定是第0个的长度
        return strs[0];
    }
};
// @lc code=end

int main()
{
    vector<string> strs;
    // strs.push_back("abcedf");
    // strs.push_back("abce");
    // strs.push_back("abcd");
    // strs.push_back("abcdeeeee");
    strs.push_back("a");
    strs.push_back("a");
    strs.push_back("a");

    Solution solu;
    cout << solu.longestCommonPrefix(strs) <<endl;
    cout << endl;
}
