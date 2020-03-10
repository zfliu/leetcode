#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()){
            return "";
        }
        int maxLeft = 0;
        int maxRight = 0;
        for (int i = 0; i < s.length() ; i++){
            int max1 = search(s, i, i);
            int max2 = search(s, i, i + 1);
            
            int max = std::max(max1, max2);
            if (max > maxRight - maxLeft){
                maxLeft = i - (max - 1) / 2;
                maxRight = maxLeft + max;
            }
        }
        return s.substr(maxLeft, maxRight - maxLeft);
    }
    
    int search(string &s, int centerLeft, int centerRight){
        while(centerLeft >= 0 && centerRight <= s.length() && s[centerLeft] == s[centerRight]){
            centerLeft--;
            centerRight++;
        }
        return centerRight - centerLeft - 1;
    }
};

int main(){
    Solution solu;
    cout << solu.longestPalindrome("a") <<endl;
    cout << solu.longestPalindrome("abccb") << endl;
    cout << solu.longestPalindrome("abcacb") << endl;
    cout << solu.longestPalindrome("abbbbbbzzbccb") << endl;
    cout << solu.longestPalindrome("babad") << endl;
}