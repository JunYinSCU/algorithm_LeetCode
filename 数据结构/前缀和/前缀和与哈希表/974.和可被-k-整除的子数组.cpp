/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 *
 * https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/
 *
 * algorithms
 * Medium (49.28%)
 * Likes:    545
 * Dislikes: 0
 * Total Accepted:    74.9K
 * Total Submissions: 151.8K
 * Testcase Example:  '[4,5,0,-2,-3,1]\n5'
 *
 * 给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的非空 子数组 的数目。
 * 
 * 子数组 是数组中 连续 的部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,0,-2,-3,1], k = 5
 * 输出：7
 * 解释：
 * 有 7 个子数组满足其元素之和可被 k = 5 整除：
 * [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2,
 * -3]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [5], k = 9
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -10^4 <= nums[i] <= 10^4
 * 2 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(k)
    int subarraysDivByK(vector<int>& nums, int k) {
        //区间和为:pre[j+1] - pre[i]
        //转换为pre[j+1] % k == pre[i] % k
        int n = nums.size();
        vector<int> pre(n+1);
        pre[0] =  0;
        for(int i = 0; i < n; i++){
            pre[i+1] = pre[i]+nums[i];
        }

        unordered_map<int,int> cnt;
        int res = 0;
        for(int i = 0; i < n+1; i++){
            //确保余数始终为正数
            int key = (pre[i] % k + k) % k;
            if(cnt.count(key)){
                res += cnt[key];
            }
            cnt[key]++;
        }

        return res;
    }
};
// @lc code=end

