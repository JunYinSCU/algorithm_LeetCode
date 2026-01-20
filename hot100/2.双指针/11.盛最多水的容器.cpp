/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode.cn/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (61.71%)
 * Likes:    5782
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 3.2M
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
class Solution {
public:
// 相向双指针

// 容量 = len * height
    int maxArea(vector<int>& height) {
        int n = height.size();

        int left = 0, right = n-1;
        int res = 0, capacity = 0;

        while(right > left){
            int len = right -left;

            int h = min(height[right],height[left]);

            res = max(res,len * h);

            //始终去挪动高度较小的板子
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        //  while(right > left){
        //     int len = right -left;

        //     if(height[right] > height[left]){
        //         capacity = len * height[left];
        //         if(capacity > res){
        //             res = capacity;                   
        //         }
        //         //始终去挪动高度较小的板子
        //         left++;
        //     }else{
        //         capacity = len * height[right];
        //         if(capacity > res){
        //             res = capacity;    
        //         }
        //         //始终去挪动高度较小的板子
        //         right--;
        //     }

        // }

        return res;
    }
};
// @lc code=end

