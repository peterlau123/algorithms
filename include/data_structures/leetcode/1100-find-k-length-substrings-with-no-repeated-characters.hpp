#include "../base/cpp_standard_header.h"
#include <unordered_map>

//https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/description/?envType=study-plan-v2&envId=premium-algo-100
namespace leetcode_1100{
    class Solution {
        public:
            int numKLenSubstrNoRepeats(string s, int k) {
                int s_len = s.size();
                //字符串长度小于k
                int ret = 0;
                if(s_len<k){
                    return ret;
                }
                if(k==1){
                    return s_len;
                }
                //字符串长度大于等于k
                std::unordered_map<char,list<int>> occurence;
                int start=0;
                char ch = s[start];
                occurence[ch].push_back(start);//start对应的字符和位置
                for(int i=start+1;i<s_len;i++){
                    ch = s[i];
                    if(occurence.count(ch)){//如果之前ch出现过
                        start= *(occurence[ch].rbegin()) + 1;
                        occurence.erase(ch);
                        occurence[ch].push_back(i);
                    }else{
                        occurence[ch].push_back(i);
                        if(k<=i-start+1){
                            ret++;
                            occurence.erase(s[start]);
                            start++;
                        }
                    }
                }
                return ret;
            }
        };
}