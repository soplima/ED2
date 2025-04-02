#include <iostream>
using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            if(needle.empty()){
                return 0;
            }
            int nLen = needle.size();
            int hLen = haystack.size();

            for(int i = 0; i<= hLen - nLen; i++){
                if(haystack.substr(i, nLen) == needle){
                    return i;
                }
            }
            return -1;
        }
    };