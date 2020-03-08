#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0x80000000){
            return 0;
        }
        
        int s = -1;
        if (x < 0){
            x = -x;
            s = 1;
        }

        int r = 0;
        while (x){
            int d = x % 10;
            x /= 10;
            r *= 10;
            r += d;
        }

        return r * s;
    }
};

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
