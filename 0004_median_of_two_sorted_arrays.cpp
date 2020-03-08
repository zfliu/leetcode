#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid1 = (nums1.size() + nums2.size() + 1) / 2;   // top mid1
        int mid2 = (nums2.size() + nums2.size() + 2) / 2;   // top mid2

        int total = getKth(nums1, 0, nums1.size() -1, nums2, 0 , nums2.size() -1, mid1)
            + getKth(nums1, 0, nums1.size() -1, nums2, 0 , nums2.size() -1, mid2);
        return total * 1.0 / 2; 
    }

    int getKth(vector<int> &nums1, int begin1, int end1, vector<int> &nums2, int begin2, int end2, int k)
    {
        if (nums2.size() > nums1.size()){
            // 保证入参的nums1一定是比较长的那一个
            getKth(nums2, begin2, end2, nums1, begin1, end1, k);
        }
        if (end2 - begin2 <= 0){
            // 剩下一个数组,那么topK自然在剩下的数组里面选
            return nums1[begin1 + k - 1];
        }
        if (k == 1){
            // 最后一个数了,但是两个数组都还在
            return std::min(nums1[begin1], nums2[begin2]);
        }

        int len1 = end1 - begin1;
        int len2 = end2 - begin2;

        int i = begin1 + std::min(len1, k / 2 + 1) - 1;
        int j = begin2 + std::min(len2, k / 2 + 1) - 1;

        if (nums1[i] < nums2[j]){

        }else{

        }

    }
};

int main()
{

}