/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (64.98%)
 * Likes:    5615
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.9M
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
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //时间复杂度O(n) 空间复杂度O(n)
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int pre[n], suf[n];

        pre[0] = height[0];
        for (int i = 1; i < n; i++) { //获得前缀最大值，表示当前位置左边的最大高度
            pre[i] = max(pre[i - 1], height[i]);
        }

        suf[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) { //获得后缀最大值，表示当前位置右边的最大高度
            suf[i] = max(suf[i + 1], height[i]);
        }
        for(int i = 0;i < n;i++) {
            ans +=min(pre[i],suf[i]) - height[i]; //当前位置能接的雨水等于左右两边最大高度的较小值减去当前高度
        }

        return ans;
    }
};
// @lc code=end

