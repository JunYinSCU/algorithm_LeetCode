/*
 * @lc app=leetcode.cn id=1685 lang=cpp
 *
 * [1685] 有序数组中差绝对值之和
 *
 * https://leetcode.cn/problems/sum-of-absolute-differences-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (69.20%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    12.5K
 * Total Submissions: 18K
 * Testcase Example:  '[2,3,5]'
 *
 * 给你一个 非递减 有序整数数组 nums 。
 * 
 * 请你建立并返回一个整数数组 result，它跟 nums 长度相同，且result[i] 等于 nums[i] 与数组中所有其他元素差的绝对值之和。
 * 
 * 换句话说， result[i] 等于 sum(|nums[i]-nums[j]|) ，其中 0  且 j != i （下标从 0 开始）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,5]
 * 输出：[4,3,5]
 * 解释：假设数组下标从 0 开始，那么
 * result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4，
 * result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3，
 * result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,4,6,8,10]
 * 输出：[24,15,13,15,21]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(n)
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> pre(n + 1);
        pre[0] = 0;
        for(int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + nums[i];
        }

        //[0,i-1]的和为pre[i] - pre[0]
        //[i+1,n-1]的和为pre[n] - pre[i+1]
        for(int i = 0; i < n; i++){
            ans[i] = nums[i] * i - (pre[i] - pre[0]) + pre[n] - pre[i+1] - nums[i] * (n - i - 1);
        }

        return ans;
    }
};
// @lc code=end

