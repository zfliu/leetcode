#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int num2 = 0;
        while(num2 < x){
            num2 = num2 * 10 + x % 10;
            x /= 10;
        }

        return num2 == x || (num2 / 10) == x;
    }
};
// @lc code=end

int main()
{
    Solution solu;
    cout << solu.isPalindrome(1) <<endl;
    cout << solu.isPalindrome(10) <<endl;
    cout << solu.isPalindrome(101) <<endl;
    cout << solu.isPalindrome(1234) << endl;
    cout << solu.isPalindrome(1234321) << endl;
    cout << solu.isPalindrome(1234321) << endl;
    cout << "HelloWorld" << endl;
}