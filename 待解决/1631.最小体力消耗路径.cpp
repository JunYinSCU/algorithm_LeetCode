/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 *
 * https://leetcode.cn/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (53.27%)
 * Likes:    547
 * Dislikes: 0
 * Total Accepted:    71.1K
 * Total Submissions: 133.4K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子
 * (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从
 * 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
 * 
 * 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
 * 
 * 请你返回从左上角走到右下角的最小 体力消耗值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
 * 输出：2
 * 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
 * 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
 * 输出：1
 * 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * 输出：0
 * 解释：上图所示路径不需要消耗任何体力。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * rows == heights.length
 * columns == heights[i].length
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int left = 0, right = 999999;
        
        
        while(left <= right) {
            int mid = left + (right - left) / 2; // 中间值
            if (check(heights, mid)) {
                right = mid - 1; // 能够到达终点，尝试更小的差值
            } else {
                left = mid + 1; // 无法到达终点，增大差值
            }
        }
        return left; // 最小的体力消耗值
    }

    bool check(vector<vector<int>>& heights, int maxDiff) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        // 四个方向
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            // 到达终点
            if (x == rows - 1 && y == cols - 1) {
                return true;
            }
            // 扫描四个方向
            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY]) {
                    // 判断是否符合当前的最大差值
                    if (abs(heights[newX][newY] - heights[x][y]) <= maxDiff) {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
        }
        // 没有路径到达终点
        return false;
    }
};
// @lc code=end

