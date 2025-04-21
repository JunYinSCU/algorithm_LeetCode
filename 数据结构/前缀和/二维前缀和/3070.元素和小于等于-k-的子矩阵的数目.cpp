/*
 * @lc app=leetcode.cn id=3070 lang=cpp
 *
 * [3070] 元素和小于等于 k 的子矩阵的数目
 *
 * https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/
 *
 * algorithms
 * Medium (61.66%)
 * Likes:    7
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 12.6K
 * Testcase Example:  '[[7,6,3],[6,6,1]]\n18'
 *
 * 给你一个下标从 0 开始的整数矩阵 grid 和一个整数 k。
 * 
 * 返回包含 grid 左上角元素、元素和小于或等于 k 的 子矩阵的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[7,6,3],[6,6,1]], k = 18
 * 输出：4
 * 解释：如上图所示，只有 4 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 18 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
 * 输出：6
 * 解释：如上图所示，只有 6 个子矩阵满足：包含 grid 的左上角元素，并且元素和小于或等于 20 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length 
 * n == grid[i].length
 * 1 <= n, m <= 1000 
 * 0 <= grid[i][j] <= 1000
 * 1 <= k <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        vector<vector<int>> sum(n+1,vector<int>(m+1,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + grid[i][j];
                if(sum[i+1][j+1] <= k){
                    res++;
                }
                // if(sum[i+1][j+1] - sum[0][j+1] - sum[i+1][0] + sum[0][0] <= k){
                //     res++;
                // }
            }
        }

        
        return res;
    }
};
// @lc code=end  

