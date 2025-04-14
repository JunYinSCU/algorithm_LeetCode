/*
 * @lc app=leetcode.cn id=2909 lang=cpp
 *
 * [2909] 元素和最小的山形三元组 II
 *
 * https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-ii/description/
 *
 * algorithms
 * Medium (55.80%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 20.1K
 * Testcase Example:  '[8,6,1,5,3]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 * 
 * 如果下标三元组 (i, j, k) 满足下述全部条件，则认为它是一个 山形三元组 ：
 * 
 * 
 * i < j < k
 * nums[i] < nums[j] 且 nums[k] < nums[j]
 * 
 * 
 * 请你找出 nums 中 元素和最小 的山形三元组，并返回其 元素和 。如果不存在满足条件的三元组，返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [8,6,1,5,3]
 * 输出：9
 * 解释：三元组 (2, 3, 4) 是一个元素和等于 9 的山形三元组，因为： 
 * - 2 < 3 < 4
 * - nums[2] < nums[3] 且 nums[4] < nums[3]
 * 这个三元组的元素和等于 nums[2] + nums[3] + nums[4] = 9 。可以证明不存在元素和小于 9 的山形三元组。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,4,8,7,10,2]
 * 输出：13
 * 解释：三元组 (1, 3, 5) 是一个元素和等于 13 的山形三元组，因为： 
 * - 1 < 3 < 5 
 * - nums[1] < nums[3] 且 nums[5] < nums[3]
 * 这个三元组的元素和等于 nums[1] + nums[3] + nums[5] = 13 。可以证明不存在元素和小于 13 的山形三元组。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [6,5,4,3,4,5]
 * 输出：-1
 * 解释：可以证明 nums 中不存在山形三元组。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //方法一：该用前缀和后缀记录最小值
    int minimumSum(vector<int>& nums) {
        int mountainSum = INT_MAX;
        int n = nums.size();

        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            suf[i] = min(suf[i+1], nums[i]);
        }

        for(int i = 1; i < n - 1; i++){
            pre[i] = min(pre[i-1], nums[i]);
            if(pre[i-1] < nums[i] && suf[i+1] < nums[i])
                mountainSum = min(mountainSum, pre[i-1] + nums[i] + suf[i+1]);
        }
        
        return mountainSum == INT_MAX ? -1 : mountainSum;
    }
    //方法二：暴力寻找当前位置前后最小值，容易超时
    int minimumSum(vector<int>& nums) {
        int mountainSum = INT_MAX;
        
        
        for(int i = 1; i < nums.size()-1; i++){
            int leftMin = nums[i];
            for(int j = 0; j < i; j++){
                if(nums[j] < leftMin){
                    leftMin = nums[j];
                }
            }
            int rightMin = nums[i];
            for(int k = i+1; k < nums.size(); k++){
                if(nums[k] < rightMin){
                    rightMin = nums[k];
                }
            }
            if(leftMin < nums[i] && rightMin < nums[i]){
                mountainSum = min(mountainSum, leftMin + nums[i] + rightMin);
            }
        }

        return mountainSum == INT_MAX ? -1 : mountainSum;
    }
};
// @lc code=end

