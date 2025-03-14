/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;

        unordered_map<char, int> window; //用 哈希表来记录每个字符出现的次数

        for(int right = 0; right < s.size(); right++){
            char c =s[right];
            window[c]++;//将字符出现字数加1
            while(window[c]>1){ //如果出现次数大于1，说明有重复字符，一直循环，直到没有重复字符
                window[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);//结果取最大值
            
        }

        return res;
    }
};

// @lc code=end

