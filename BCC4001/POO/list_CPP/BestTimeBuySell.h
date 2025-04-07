#include <vector>
using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int min = __INT_MAX__;
            int max = 0;

            for(int price: prices){
                if (price < min){
                    min = price;
                }
                else if (price - min > max){
                    max = price - min;
                }
            }
            return max;
        }
    };