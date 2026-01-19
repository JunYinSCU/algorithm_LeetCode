/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (65.88%)
 * Likes:    6053
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.4M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax(n,0);
        vector<int> subMax(n,0);
        preMax[0] = height[0];
        subMax[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            preMax[i] = max(height[i],preMax[i-1]);
        }
        for(int i = n -2;i >= 0; i--){
            subMax[i] = max(height[i],subMax[i+1]);
        }

        int res = 0;

        for(int i = 0; i < n-1; i++){
            res += min(preMax[i],subMax[i]) -height[i];
        }

        return res;
    }
};
// @lc code=end

