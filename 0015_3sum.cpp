#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() - 2 ; i++){
            if (nums[i] > 0){
                break;
            }
            int j = i + 1, k = nums.size() - 1;
            while(j < k){   // 双指针向中间移动,
                int s = nums[j] + nums[k];
                if (s > -nums[i]){  
                    // 需要的数比较大,只能把大的那边缩小,也就是右边
                    --k;
                }else if (s < -nums[i]){
                    // 同上
                    ++j;
                }else{
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while(nums[i] == nums[i+1] && i < (nums.size() - 1)){
                        i++;
                    }
                    do{
                        ++j;
                    }while(nums[j-1] == nums[j] && j < k);
                    do{
                        --k;
                    }while(nums[k+1] == nums[k] && k > i);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution solu;
    vector<int> aa = {-1,-1,0,0,1,1};
    // solu.threeSum(aa);
    // aa = {-1,-1,0,0,2};
    // solu.threeSum(aa);    
    aa = {0,0,0,0};
    solu.threeSum(aa);
    cout << "x" <<endl;
}