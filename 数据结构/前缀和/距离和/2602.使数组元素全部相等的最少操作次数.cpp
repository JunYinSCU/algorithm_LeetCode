/*
 * @lc app=leetcode.cn id=2602 lang=cpp
 *
 * [2602] 使数组元素全部相等的最少操作次数
 *
 * https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/description/
 *
 * algorithms
 * Medium (39.18%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    12.3K
 * Total Submissions: 31K
 * Testcase Example:  '[3,1,6,8]\n[1,5]'
 *
 * 给你一个正整数数组 nums 。
 * 
 * 同时给你一个长度为 m 的整数数组 queries 。第 i 个查询中，你需要将 nums 中所有元素变成 queries[i] 。你可以执行以下操作
 * 任意 次：
 * 
 * 
 * 将数组里一个元素 增大 或者 减小 1 。
 * 
 * 
 * 请你返回一个长度为 m 的数组 answer ，其中 answer[i]是将 nums 中所有元素变成 queries[i] 的 最少 操作次数。
 * 
 * 注意，每次查询后，数组变回最开始的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [3,1,6,8], queries = [1,5]
 * 输出：[14,10]
 * 解释：第一个查询，我们可以执行以下操作：
 * - 将 nums[0] 减小 2 次，nums = [1,1,6,8] 。
 * - 将 nums[2] 减小 5 次，nums = [1,1,1,8] 。
 * - 将 nums[3] 减小 7 次，nums = [1,1,1,1] 。
 * 第一个查询的总操作次数为 2 + 5 + 7 = 14 。
 * 第二个查询，我们可以执行以下操作：
 * - 将 nums[0] 增大 2 次，nums = [5,1,6,8] 。
 * - 将 nums[1] 增大 4 次，nums = [5,5,6,8] 。
 * - 将 nums[2] 减小 1 次，nums = [5,5,5,8] 。
 * - 将 nums[3] 减小 3 次，nums = [5,5,5,5] 。
 * 第二个查询的总操作次数为 2 + 4 + 1 + 3 = 10 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [2,9,6,3], queries = [10]
 * 输出：[20]
 * 解释：我们可以将数组中所有元素都增大到 10 ，总操作次数为 8 + 1 + 4 + 7 = 20 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * m == queries.length
 * 1 <= n, m <= 10^5
 * 1 <= nums[i], queries[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(mlogn + nlogn)
    //空间复杂度O(n)
    /* 如果采用双重循环计算步数会导致超时
        用一个数组存储排序后的nums的前缀和 ，二分查找第一个>=当前数的元素
        对于<当前数的元素,步数 = 当前数 * index - 前缀和pre[index]
        对于>=当前数的元素，步数 = 前缀和为pre[n] - pre[index] - 当前数 * (n - index)
    */
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> pre(n + 1);
        pre[0] = 0;
        for(int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        int m = queries.size();
        vector<long long> ans(m);
        for(int i = 0; i < m; i++){
            //对于<当前数的元素,前缀和pre[index] - pre[0]       [0,index - 1]
            //对于>=当前数的元素，前缀和为pre[n] - pre[index]    [index,n - 1]
            int index = lowerBound(nums, queries[i]);
            long long leftCost = (long long)queries[i] * index - pre[index];
            long long rightCost = (pre[n] - pre[index]) - (long long)queries[i] * (n - index);
            ans[i] = leftCost + rightCost;
        }

        return ans;
        
    }

    int lowerBound(vector<int>& n, int num){
        int left = 0;
        int right = n.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(n[mid] < num){   //小于目标值，说明应该在mid的右边，更新左指针
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;
    }
};
// @lc code=end

