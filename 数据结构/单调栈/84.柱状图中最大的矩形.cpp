/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode.cn/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (47.05%)
 * Likes:    2945
 * Dislikes: 0
 * Total Accepted:    538.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入： heights = [2,4]
 * 输出： 4
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //对于一个柱子，他所可以形成的最大面积取决于其两边高度小于自身的距离
        //因此遍历每个柱子，求出其可以形成的最大矩形面积，最后选出整体面积最大值
        int n = heights.size();
        stack<int> s; //存储下标
        vector<int> left(n,-1); //left[i]表示第i个柱子左边最近的小于自身高度的下标

        for(int i = 0; i < n; i++){ //遍历数组，求出每个的left值
            while(!s.empty() && heights[i] <= heights[s.top()]) //需要找小的，所以遇到大的值就出栈
            {
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top();
            }
            s.push(i);
        }

        while(!s.empty()){  //清空栈
            s.pop();
        }

        vector<int> right(n,n);
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[i] <= heights[s.top()])
            {
                right[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++){         
            int m = (right[i]-left[i]-1)*heights[i];
            if(m > res){
                res = m;
            }
        }

        return res;
    }
};
// @lc code=end

