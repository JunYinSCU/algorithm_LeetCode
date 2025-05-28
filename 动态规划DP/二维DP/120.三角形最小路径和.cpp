/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode.cn/problems/triangle/description/
 *
 * algorithms
 * Medium (69.28%)
 * Likes:    1445
 * Dislikes: 0
 * Total Accepted:    421.4K
 * Total Submissions: 607.1K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形 triangle ，找出自顶向下的最小路径和。
 * 
 * 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1
 * 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * 输出：11
 * 解释：如下面简图所示：
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：triangle = [[-10]]
 * 输出：-10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //方法一：动态规划
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int m = triangle.size();
    //     int n = triangle[m-1].size();
    //     if(m == 1) return triangle[0][0];

    //     vector<vector<int>> dp(m,vector<int>(n,0));
    //     dp[0][0] = triangle[0][0];

    //     for(int i = 1; i < m; i++){
    //         //处理第一个元素
    //         dp[i][0] = dp[i - 1][0] + triangle[i][0];
    //         //处理中间元素
    //         for(int j = 1; j < triangle[i-1].size(); j++){  
    //             dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];  
    //         }
    //         //处理最后一位元素
    //         dp[i][triangle[i-1].size()] = dp[i-1][triangle[i-1].size()-1] + triangle[i][triangle[i-1].size()];
    //     }

    //     int res = INT_MAX;
    //     //寻找最后一排的最小值
    //     for(int i = 0; i < triangle[m-1].size(); i++){
    //         if(dp[m-1][i] < res)
    //             res = dp[m-1][i];
    //     }

    //     return res;
    // }

    //方法二：空间优化，使用长度为m的数组
    // int minimumTotal(vector<vector<int>>& triangle){
    //     int m = triangle.size();
    //     //初始化dp数组为三角形最后一排元素
    //     vector<int> dp = triangle[m-1];

    //     //从底到顶更新最小路径
    //     //从倒数第二排开始倒序更新
    //     for(int i = m - 2; i >= 0; i--){
    //         for(int j = 0; j <= i; j++){    //第i行有i+1个元素
    //             //新的路径长度等于下一排的相邻最小元素+当前开销
    //             dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
    //         }
    //     }

    //     //返回到达三角形顶的开销
    //     return dp[0];
    // }

    //方法三：空间优化，原地修改
    int minimumTotal(vector<vector<int>>& triangle){
        int m = triangle.size();
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};
// @lc code=end

