#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while(l < r){
            int m = min(height[l],height[r]) * (r - l);
            ans = max(ans, m);
            if (height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    
}

