/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */

// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        //空间复杂度O(n)
        //时间复杂度O(n)
        int res = 0;
        int left = 0;

        unordered_map<int, int> mp;//记录每个元素出现的次数

        for(int right = 0;right < nums.size();right++){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){//如果添加的元素个数超过k，移动左端点直至满足条件
                mp[nums[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }

        return res;
    }

};
// @lc code=end

