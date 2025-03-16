/*
 * @lc app=leetcode.cn id=3090 lang=cpp
 *
 * [3090] 每个字符最多出现两次的最长子字符串
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        int left = 0;
        unordered_map<char,int> window;//用哈希表记录窗口中的字符种类
        for(int right = 0;right < s.size();right++){
            window[s[right]]++;
            while(window[s[right]] > 2){
                window[s[left]]--;
                left++;
            }
            res = max(res,right - left + 1);
        }
        return res;
    }
};
// @lc code=end

