#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        
        for (int i = 0 ; i < str.size() ; i++){
            
            if (!isNumber(str[i])){
                break;
            }
            if (isOverflow(1,2)){
                return result > 0 ? 
            }
            
        }
        return result;
    }
    bool isOverflow(int32_t x, int32_t y){
        int32_t z = x + y;
        if(x > 0 && y > 0 && z < 0)
            return true;  
        if(x < 0 && y < 0 && z > 0)
            return true;
        return false;
    }
    bool isNumber(char ch){
        return ch >= '0' && ch <= '9';
    }
};
// @lc code=end

int main()
{

}
