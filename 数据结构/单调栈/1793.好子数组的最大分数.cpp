/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 *
 * [1793] 好子数组的最大分数
 *
 * https://leetcode.cn/problems/maximum-score-of-a-good-subarray/description/
 *
 * algorithms
 * Hard (56.33%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 50.4K
 * Testcase Example:  '[1,4,3,7,4,5]\n3'
 *
 * 给你一个整数数组 nums （下标从 0 开始）和一个整数 k 。
 * 
 * 一个子数组 (i, j) 的 分数 定义为 min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1)
 * 。一个 好 子数组的两个端点下标需要满足 i <= k <= j 。
 * 
 * 请你返回 好 子数组的最大可能 分数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [1,4,3,7,4,5], k = 3
 * 输出：15
 * 解释：最优子数组的左右端点下标是 (1, 5) ，分数为 min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,5,4,5,4,1,1,1], k = 0
 * 输出：20
 * 解释：最优子数组的左右端点下标是 (0, 4) ，分数为 min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 2 * 10^4
 * 0 <= k < nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
//类似84题求柱状图最大面积
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> s;
        vector<int> left(n,-1);//left数组记录index=i处值的左边第一个小于自身的下标

        for(int i = 0; i < n; i++){
            while(!s.empty() && nums[i] <= nums[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top();
            }
                
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        vector<int> right(n,n);//right数组记录index=i处值的右边第一个小于自身的下标
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && nums[i] <= nums[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                right[i] = s.top();
            }
            s.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int r = right[i];
            int l = left[i];
            int score = nums[i] * (r - l - 1);
            //对在这区间范围内的答案进行更新
            if(i<k && r>k){
                ans = max(ans,score);
            }
        }

        return ans;
    }
};
// @lc code=end

