/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 *
 * https://leetcode.cn/problems/number-of-good-pairs/description/
 *
 * algorithms
 * Easy (83.28%)
 * Likes:    203
 * Dislikes: 0
 * Total Accepted:    135.4K
 * Total Submissions: 162.6K
 * Testcase Example:  '[1,2,3,1,1,3]'
 *
 * 给你一个整数数组 nums 。
 * 
 * 如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。
 * 
 * 返回好数对的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,2,3,1,1,3]
 * 输出：4
 * 解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,1,1,1]
 * 输出：6
 * 解释：数组中的每组数字都是好数对
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,2,3]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(n),空间复杂度O(n)
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> countMap;
        // 统计每个数字出现的次数
        for(int num : nums) {
            countMap[num]++;
        }

        int goodPairs = 0;

        for(auto& pairCount : countMap) {
            int count = pairCount.second;
            goodPairs += (count * (count - 1)) / 2; // 组合数 C(n, 2) = n * (n - 1) / 2
        }
        return goodPairs;
    }
};
// @lc code=end

