/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.73%)
 * Likes:    2725
 * Dislikes: 0
 * Total Accepted:    700.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
 * 
 * 子数组是数组中元素的连续非空序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 时间复杂度O(n)
    // 空间复杂度O(n)
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size() + 1);
        pre[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            pre[i+1] = pre[i] + nums[i];
        }

        unordered_map<int, int> mp;
        int ans = 0;

        // 区间[i,j]的和为pre[j+1] - pre[i]
        // 所以求的目标为pre[j+1] - pre[i] = k
        // 变形得到pre[j+1] - k = pre[i]
        // 所以只需要遍历nums，统计pre[j+1] - k出现的次数即可

        for(int i = 0; i < pre.size(); i++){
            if(mp.count(pre[i] - k)){
                ans += mp[pre[i] - k];
            }
            mp[pre[i]]++;
        }

        return ans;
    }
};
// @lc code=end

