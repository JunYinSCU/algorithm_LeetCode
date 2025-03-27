/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode.cn/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (61.09%)
 * Likes:    5401
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 2.7M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 * 
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 返回容器可以储存的最大水量。
 * 
 * 说明：你不能倾斜容器。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49 
 * 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [1,1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 * 
 * 
 */

// @lc code=start
#include<climits>
#include<vector>
#include<algorithm>
class Solution {
public:
    //时间复杂度O(n),空间复杂度O(1)
    int maxArea(vector<int>& height) {
        int res = INT_MIN;
        int capacity;
        int left = 0;
        int right = height.size() - 1;

        while(left < right){
            if(height[left] <= height[right]){ //左边界小于右边界，左边界向右移动
                capacity = (right - left) * height[left];
                left++;
            }else{                      //同理，右边界向左移动
                capacity = (right - left) * height[right];
                right--;
            }
            res = max(res,capacity);           
        }

        return res;
    }
};
// @lc code=end

