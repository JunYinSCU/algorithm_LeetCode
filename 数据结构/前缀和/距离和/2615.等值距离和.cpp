/*
 * @lc app=leetcode.cn id=2615 lang=cpp
 *
 * [2615] 等值距离和
 *
 * https://leetcode.cn/problems/sum-of-distances/description/
 *
 * algorithms
 * Medium (40.24%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    8.7K
 * Total Submissions: 21.4K
 * Testcase Example:  '[1,3,1,1,2]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。现有一个长度等于 nums.length 的数组 arr 。对于满足 nums[j] ==
 * nums[i] 且 j != i 的所有 j ，arr[i] 等于所有 |i - j| 之和。如果不存在这样的 j ，则令 arr[i] 等于 0 。
 * 
 * 返回数组 arr 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,1,1,2]
 * 输出：[5,0,3,4,0]
 * 解释：
 * i = 0 ，nums[0] == nums[2] 且 nums[0] == nums[3] 。因此，arr[0] = |0 - 2| + |0 -
 * 3| = 5 。 
 * i = 1 ，arr[1] = 0 因为不存在值等于 3 的其他下标。
 * i = 2 ，nums[2] == nums[0] 且 nums[2] == nums[3] 。因此，arr[2] = |2 - 0| + |2 -
 * 3| = 3 。
 * i = 3 ，nums[3] == nums[0] 且 nums[3] == nums[2] 。因此，arr[3] = |3 - 0| + |3 -
 * 2| = 4 。 
 * i = 4 ，arr[4] = 0 因为不存在值等于 2 的其他下标。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,5,3]
 * 输出：[0,0,0]
 * 解释：因为 nums 中的元素互不相同，对于所有 i ，都有 arr[i] = 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n,0);
        unordered_map<int,vector<long long>> mp;    //记录每个数的下标
        
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto& [k,v] : mp){
            int m = v.size();

            对于每个索引数组，求前缀和
            vector<long long> pre(m+1);
            pre[0] = 0;
            for(int i = 1; i <= m; i++){
                pre[i] = pre[i-1] + v[i-1];
            }
            //通过前缀和来完成计算
            for(int i = 0; i < m; i++){
                ans[v[i]] = v[i] * i - (pre[i] - pre[0]) + (pre[m] - pre[i+1])- v[i] * (m-i-1);
            }

            //暴力求解容易超时
            // for(int i = 0; i < m; i++){
            //     for(int j = 0; j < m; j++){
            //         ans[v[i]] += abs(v[i] - v[j]);
            //     }
            // }

        }
        return ans;
    }
};
// @lc code=end

