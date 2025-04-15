/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 *
 * https://leetcode.cn/problems/plates-between-candles/description/
 *
 * algorithms
 * Medium (44.32%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    38.5K
 * Total Submissions: 86.9K
 * Testcase Example:  '"**|**|***|"\n[[2,5],[5,9]]'
 *
 * 给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子
 * ，'|' 表示一支 蜡烛 。
 * 
 * 同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串
 * s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在
 * 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。
 * 
 * 
 * 比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2
 * ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
 * 
 * 
 * 请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 输入：s = "**|**|***|", queries = [[2,5],[5,9]]
 * 输出：[2,3]
 * 解释：
 * - queries[0] 有两个盘子在蜡烛之间。
 * - queries[1] 有三个盘子在蜡烛之间。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 
 * 输入：s = "***|**|*****|**||**|*", queries =
 * [[1,17],[4,5],[14,17],[5,11],[15,16]]
 * 输出：[9,0,0,0,0]
 * 解释：
 * - queries[0] 有 9 个盘子在蜡烛之间。
 * - 另一个查询没有盘子在蜡烛之间。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= s.length <= 10^5
 * s 只包含字符 '*' 和 '|' 。
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= lefti <= righti < s.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //这道题本质上也是求区间元素和，但需要弄清楚需要找的是哪个范围的区间和
    //这里通过寻找原始范围内，最近的两个蜡烛的位置，确定为要求区间和的范围
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> ans(queries.size());

        vector<int> pre(n+1,0);
        pre[0] = 0;
        for(int i = 0; i < n; i++){         //统计盘子前缀和
            pre[i+1] = pre[i] + (s[i] == '*' ? 1 : 0);
        }

        vector<int> leftCandle(n,-1);
        vector<int> rightCandle(n,-1);
        int leftIndex = -1;
        for(int i = 0; i < n; i++){     //当前盘子左边最近蜡烛的位置
            if(s[i] == '|')
                leftIndex = i;
            leftCandle[i] = leftIndex;
        }
        int rightIndex = -1;
        for(int i = n-1; i >= 0; i--){   //当前盘子右侧最近蜡烛位置    
            if(s[i] == '|')
                rightIndex = i;
                rightCandle[i] = rightIndex;
        }

        for(int i = 0;i < queries.size();i++){
            int right = leftCandle[queries[i][1]];
            int left = rightCandle[queries[i][0]];
            
            // if(left != -1 && right != -1 && left < right)             
            //     ans[i] = pre[right+1] - pre[left];
            // else
            //     ans[i] = 0;
            if(left == -1 || right == -1 || left >= right)
                ans[i] = 0;
            else
                ans[i] = pre[right+1] - pre[left];

        }
        return ans;
    }
};
// @lc code=end

