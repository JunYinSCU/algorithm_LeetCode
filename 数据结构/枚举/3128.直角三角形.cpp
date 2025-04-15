/*
 * @lc app=leetcode.cn id=3128 lang=cpp
 *
 * [3128] 直角三角形
 *
 * https://leetcode.cn/problems/right-triangles/description/
 *
 * algorithms
 * Medium (66.65%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    23.5K
 * Total Submissions: 35.3K
 * Testcase Example:  '[[0,1,0],[0,1,1],[0,1,0]]'
 *
 * 给你一个二维 boolean 矩阵 grid 。
 * 
 * 如果 grid 的 3 个元素的集合中，一个元素与另一个元素在 同一行，并且与第三个元素在 同一列，则该集合是一个 直角三角形。3 个元素 不必
 * 彼此相邻。
 * 
 * 请你返回使用 grid 中的 3 个元素可以构建的 直角三角形 数目，且满足 3 个元素值 都 为 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 
 * 0
 * 1
 * 0
 * 
 * 
 * 0
 * 1
 * 1
 * 
 * 
 * 0
 * 1
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 0
 * 1
 * 0
 * 
 * 
 * 0
 * 1
 * 1
 * 
 * 
 * 0
 * 1
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 输入：grid = [[0,1,0],[0,1,1],[0,1,0]]
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 有 2 个值为 1 的直角三角形。注意蓝色的那个 没有 组成直角三角形，因为 3 个元素在同一列。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 
 * 1
 * 0
 * 0
 * 0
 * 
 * 
 * 0
 * 1
 * 0
 * 1
 * 
 * 
 * 1
 * 0
 * 0
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 输入：grid = [[1,0,0,0],[0,1,0,1],[1,0,0,0]]
 * 
 * 输出：0
 * 
 * 解释：
 * 
 * 没有值为 1 的直角三角形。注意蓝色的那个 没有 组成直角三角形。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 
 * 
 * 1
 * 0
 * 1
 * 
 * 
 * 1
 * 0
 * 0
 * 
 * 
 * 1
 * 0
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 1
 * 0
 * 1
 * 
 * 
 * 1
 * 0
 * 0
 * 
 * 
 * 1
 * 0
 * 0
 * 
 * 
 * 
 * 
 * 
 * 
 * 输入：grid = [[1,0,1],[1,0,0],[1,0,0]]
 * 
 * 输出：2
 * 
 * 解释：
 * 
 * 有两个值为 1 的直角三角形。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length <= 1000
 * 1 <= grid[i].length <= 1000
 * 0 <= grid[i][j] <= 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        vector<int> row(grid.size(), 0);
        long long res = 0;

        for(int i = 0; i < grid.size(); i++) {  //统计每行有多少个1
            for(int j = 0; j < grid[i].size(); j++) {
                row[i] += grid[i][j];
            }
        }

        for(int i = 0; i < grid[0].size(); i++) {
            int column = 0;
            for(int j = 0; j < grid.size(); j++) {  //统计每列有多少个1
                column += grid[j][i];              
            }
            //遍历每个元素和统计每列有多少个1可以放在一起进行
            for(int j = 0; j < grid.size(); j++) {  //遍历每个元素，可以构成三角形的个数就是该行该列除本身外1的个数的乘积
                if(grid[j][i] == 1) {
                    res += (row[j] - 1) * (column - 1);
                }
            }
            
        }
        return res;
    }
};
// @lc code=end

