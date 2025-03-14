/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0;
        int res = 0;
        int cost = 0;//实际花销

        for(int right = 0;right < s.size();right++){
            cost += abs(s[right] - t[right]); //更新花销
            while(cost > maxCost){ //如果花销超过最大花销，就一直循环，直到花销小于最大花销
                cost -= abs(s[left] - t[left]);
                left++;
            }
            res = max(res,right - left + 1);//更新结果
        }

        return res;
    }
};
// @lc code=end

