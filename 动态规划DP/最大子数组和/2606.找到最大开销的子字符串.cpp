/*
 * @lc app=leetcode.cn id=2606 lang=cpp
 *
 * [2606] 找到最大开销的子字符串
 *
 * https://leetcode.cn/problems/find-the-substring-with-maximum-cost/description/
 *
 * algorithms
 * Medium (62.73%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    17.7K
 * Total Submissions: 28K
 * Testcase Example:  '"adaa"\n"d"\n[-1000]'
 *
 * 给你一个字符串 s ，一个字符 互不相同 的字符串 chars 和一个长度与 chars 相同的整数数组 vals 。
 * 
 * 子字符串的开销 是一个子字符串中所有字符对应价值之和。空字符串的开销是 0 。
 * 
 * 字符的价值 定义如下：
 * 
 * 
 * 如果字符不在字符串 chars 中，那么它的价值是它在字母表中的位置（下标从 1 开始）。
 * 
 * 
 * 比方说，'a' 的价值为 1 ，'b' 的价值为 2 ，以此类推，'z' 的价值为 26 。
 * 
 * 
 * 否则，如果这个字符在 chars 中的位置为 i ，那么它的价值就是 vals[i] 。
 * 
 * 
 * 请你返回字符串 s 的所有子字符串中的最大开销。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "adaa", chars = "d", vals = [-1000]
 * 输出：2
 * 解释：字符 "a" 和 "d" 的价值分别为 1 和 -1000 。
 * 最大开销子字符串是 "aa" ，它的开销为 1 + 1 = 2 。
 * 2 是最大开销。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "abc", chars = "abc", vals = [-1,-1,-1]
 * 输出：0
 * 解释：字符 "a" ，"b" 和 "c" 的价值分别为 -1 ，-1 和 -1 。
 * 最大开销子字符串是 "" ，它的开销为 0 。
 * 0 是最大开销。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只包含小写英文字母。
 * 1 <= chars.length <= 26
 * chars 只包含小写英文字母，且 互不相同 。
 * vals.length == chars.length
 * -1000 <= vals[i] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    //     if(s.empty()) return 0;

    //     vector<int> cost(26,0); //初始化cost数组
    //     for(int i = 0; i < 26; i++){
    //         cost[i] = i + 1;
    //     }
    //     for(int i = 0; i < chars.size(); i++){       
    //         cost[chars[i] - 'a'] = vals[i];
    //     }

    //     vector<int> prefix(s.size() + 1, 0);
    //     for(int i = 0; i < s.size(); i++){  //计算前缀和
    //         prefix[i+1] = prefix[i] + cost[s[i] - 'a'];
    //     }

    //     int maxCost = cost[s[0] - 'a']; //最大开销初始化为第一个字符的开销
    //     int minPrefix = 0;  //前缀和最小值
    //     for(int i = 1; i <= s.size(); i++){
    //         maxCost = max(maxCost, prefix[i] - minPrefix);  //更新最大开销
    //         minPrefix = min(minPrefix, prefix[i]); //更新前缀和最小值
    //     }

    //     return maxCost < 0 ? 0 : maxCost;   //由于空字符串的开销为0，如果最大开销小于0，则返回0
    // }

    //方法二：动态规划
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        if(s.empty()) return 0;

        vector<int> cost(26,0); //初始化cost数组
        for(int i = 0; i < 26; i++){
            cost[i] = i + 1;
        }
        for(int i = 0; i < chars.size(); i++){       
            cost[chars[i] - 'a'] = vals[i];
        }

        vector<int> dp(s.size()+1);
        dp[0] = 0;
        int maxCost = cost[s[0] - 'a']; //最大开销初始化为第一个字符的开销
        for(int i = 1; i <= s.size(); i++){
            dp[i] = max(cost[s[i-1] - 'a'], dp[i-1] + cost[s[i-1] - 'a']);
            maxCost = max(maxCost, dp[i]);  //更新最大开销
        }

        return maxCost < 0 ? 0 : maxCost;   //由于空字符串的开销为0，如果最大开销小于0，则返回0
    }
};
// @lc code=end

