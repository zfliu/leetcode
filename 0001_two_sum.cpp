#include <iostream>
#include <map>
#include <vector>
using namespace std;

ostream& operator << (ostream& out, vector<int> &v){
	out << '[';
	for (int i = 0 ; i < v.size() - 1 ; i++){
		out << v[i] << ',';
	}
	out << v[v.size() - 1] << ']';
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> result = {};	// k: 差值,  v: 下标		
		int i = 0;
		for (i = 0 ; i < nums.size() ; i++){
			if (result.find(nums[i]) == result.end()){
				result[target - nums[i]] = i;
			}else{
				break;
			}
		}
		return vector<int>{i, result[nums[i]]};
    }
};

int main()
{
	Solution solu;
	auto v = vector<int>{3,2,4};
	auto s = solu.twoSum(v, 6);
	cout << s <<endl;
}
