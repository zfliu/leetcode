#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // 1. 如果temp = rev * 10 + pop 导致溢出,那么一定又 rev >= INTMAX / 10
        // 2. 如果 rev > INTMAX / 10, 那么temp = rev * 10 + pop 一定会溢出
        // 3. 如果 rev == INTMAX / 10, 那么只要 pop > 7, temp = rev * 10 + pop 就会溢出
        int INT_MAX = 0x7fffffff, INT_MIN = 0x80000000;
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) 
                return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) 
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
    int reverse2(int x) {
        // 如果y = y * 10 + x % 10溢出，则 y>=214748364
        // 当y=214748364时，输入的值只能为：1463847412，此时不溢出
        // 即：y > 214748364 || y < -214748364 必定溢出
        int y = 0;
        while (x != 0) {
            if (y > 214748364 || y < -214748364) {
                return 0;
            }
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return y;
    }
};
// @lc code=end

int main()
{
	Solution solu;
    //cout << 0x80000000 << ":" << solu.reverse(0x80000000) << endl;
    //cout << 123 << ":" << solu.reverse(123) << endl;
    //cout << -123 << ":" << solu.reverse(-123) << endl;
    //cout << (int)0xFFFFFFFF << ":" << solu.reverse(0xFFFFFFFF) << endl;
    cout << (int)0x7FFFFFFF << ":" << solu.reverse(0x7FFFFFFF) << endl;
    return 0;
}
