#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <assert.h>
using namespace std;

int INT_MAX = 0x7fffffff;
int INT_MIN = 0x80000000;

/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        bool positive = true;   // 符号为正
        int ans = 0;
        
        int i = 0;
        // 先找到起点
        for (i = 0 ; i < str.size() ; i++){
            if (str[i] == ' '){
                continue;
            }else if (str[i] == '-'){
                positive = false;
                i++;
                break;
            }else if (str[i] == '+' || isNumber(str[i])){
                positive = true;
                if (!isNumber(str[i])){
                    i++;
                }
                break;
            }else{
                return 0;
            }
        }
        // 开始解析数字
        for (; i < str.size() ; i++){
            if (!isNumber(str[i])){
                break;
            }
            int num = str[i] - '0';
            if (isOverflow(ans, num, positive)){  // 溢出返回最大值
                if (positive){
                    return INT_MAX;
                }else{
                    return INT_MIN;
                }
            }
            ans = ans * 10 + num;
        }
        if (!positive){
            ans = -ans;
        }
        return ans;
    }
    bool isOverflow(int rev, int pop, bool positive){
        assert(rev >= 0);
        assert(pop >= 0);
        if (rev < 214748364){
            return false;
        }else if (rev == 214748364 && pop <= 7){
            return false;
        }else{
            return true;
        }
        return true;
    }
    bool isNumber(char ch){
        return ch >= '0' && ch <= '9';
    }
};
// @lc code=end

int main()
{
    Solution solu;
    //cout << solu.myAtoi("  -100") << endl;
    //cout << solu.myAtoi("  -1001    xxxx") << endl;
    //cout << solu.myAtoi("   2147483647    xxxx") << endl;
    //cout << solu.myAtoi("   -2147483648    xxxx") << endl;
    cout << solu.myAtoi("-2147483648") << endl;

    cout << endl;
    cout << endl;
}
