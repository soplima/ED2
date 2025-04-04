#include <iostream>
using namespace std;

class Solution {
    private:
        void lower(string &s){
            for (char &c : s){
                c = tolower(c);
            }
        }
        
        string cleanString(string s){
            string result = "";
            for(char c : s){
                if(isalnum(c)){
                result += c;
                }
            }
            return result; 
        } 

    public:
        bool isPalindrome(string s) {
            s = cleanString(s);
            lower(s);

            if(s.empty()){
                return true;
            }

            int left = 0, right = s.size()-1;
            while(left<right){
                if(s[left] != s[right]){
                    return  false;
                }
                left ++;
                right --;
            }

            return true;
        }
    };