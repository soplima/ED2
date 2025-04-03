#include <cmath>

class Solution {
    public:
        int mySqrt(int x) {
            if(x < 2){
                return x;
            }
            int y = x;
            int z = y + (x / y ) / 2;
            return std::floor(std::sqrt(x));
        }
    };