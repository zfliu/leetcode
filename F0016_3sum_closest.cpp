#include <algorithm>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min = 10000000;
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() - 2 ; i++){
            if (i != 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while(j < k){   // 双指针向中间移动,
                int s = nums[i] + nums[j] + nums[k];
                if (abs(s - target) < abs(min - target)){
                    min = s;
                }
                if (s > target){  
                    // 需要的数比较大,只能把大的那边缩小,也就是右边
                    --k;
                }else if (s < target){
                    // 同上
                    ++j;
                }else{
                    return target;
                }
            }
        }
        return min;
    }
};
// @lc code=end

