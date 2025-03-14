/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <algorithm>
class Solution {
public:
//因为原数组不是排好序的，所以不能用双指针法
//可以用哈希表，遍历数组，将数组元素和下标存入哈希表，然后遍历数组，查找target-nums[i]是否在哈希表中
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

