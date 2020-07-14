#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {

        stack<char> check;
        map<char, char> m = {{')','('}, {']','['}, {'}','{'}};
        for (int i = 0 , len = s.size() ; i < len ; i++){
            char c = s[i];
            if (m.find(c) == m.end()){
                check.push(c);
            }else{
                if (!check.empty() && check.top() == m[c]){
                    check.pop();
                }else{
                    return false;
                }
            }
        }
        if (!check.empty()){
            return false;
        }
        return true;
    }
};
// @lc code=end


int main()
{
    Solution solu;
    cout << solu.isValid("{}{}{}") <<endl;
    cout << solu.isValid("({}){}{}") <<endl;
    cout << solu.isValid("({)}){}{}") <<endl;
}