#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid1 = (nums1.size() + nums2.size() + 1) / 2;
        int mid2 = (nums1.size() + nums2.size() + 2) / 2;

        int k1 = getKth(nums1, 0, nums1.size(), nums2, 0 , nums2.size(), mid1);
        int k2 = getKth(nums1, 0, nums1.size(), nums2, 0 , nums2.size(), mid2);
        return (k1 + k2) * 1.0 / 2; 
    }

    int getKth(vector<int> &nums1, int begin1, int end1, vector<int> &nums2, int begin2, int end2, int k)
    {
        int len1 = end1 - begin1;
        int len2 = end2 - begin2;

        if (len2 > len1){
            // 保证入参的nums1一定是比较长的那一个
            return getKth(nums2, begin2, end2, nums1, begin1, end1, k);
        }
        if (len2 <= 0){
            // 剩下一个数组,那么topK自然在剩下的数组里面选
            return nums1[begin1 + k - 1];
        }
        if (k == 1){
            // 最后一个数了,但是两个数组都还在
            return std::min(nums1[begin1], nums2[begin2]);
        }


        int i1 = begin1 + std::min(len1, k / 2) - 1; // 要比较的数的坐标
        int i2 = begin2 + std::min(len2, k / 2) - 1;

        if (nums1[i1] < nums2[i2]){
            return getKth(nums1, i1 + 1, end1, nums2, begin2, end2, k - (i1 - begin1 + 1));
        }else{
            return getKth(nums1, begin1, end1, nums2, i2 + 1, end2, k - (i2 - begin2 + 1));
        }
    }
};

void test_cast(vector<int> v1, vector<int> v2)
{
    Solution solu;
    cout<<solu.findMedianSortedArrays(v1, v2)<<endl;
}

int main()
{
    test_cast({1,2}, {3,4});
    test_cast({1}, {2, 3});
}