#include <vector>
using namespace std;

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            for(int i = 0; i<nums.size(); i++){
                if(i + 1 < nums.size() && nums[i] == nums[i + 1]){
                    nums.erase(nums.begin() + i);
                    i--; // Adjust index after erasing
                }
            }
            return nums.size();
        }
    };