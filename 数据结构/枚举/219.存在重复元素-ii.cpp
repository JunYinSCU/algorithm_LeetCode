/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode.cn/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (49.22%)
 * Likes:    787
 * Dislikes: 0
 * Total Accepted:    386.5K
 * Total Submissions: 783K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且
 * abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,1], k = 3
 * 输出：true
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,0,1,1], k = 1
 * 输出：true
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,3,1,2,3], k = 2
 * 输出：false
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(n)，空间复杂度O(n)
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;   //记录数值和下标
        for(int i = 0; i < nums.size(); i++){
            if(m.count(nums[i]) && i - m[nums[i]] <= k){
                return true;
            }else{
                m[nums[i]] = i;
            }
        }
        return false;
    }
};
// @lc code=end

