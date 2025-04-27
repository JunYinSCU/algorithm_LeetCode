/*
 * @lc app=leetcode.cn id=3170 lang=cpp
 *
 * [3170] 删除星号以后字典序最小的字符串
 *
 * https://leetcode.cn/problems/lexicographically-minimum-string-after-removing-stars/description/
 *
 * algorithms
 * Medium (40.46%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 17.2K
 * Testcase Example:  '"aaba*"'
 *
 * 给你一个字符串 s 。它可能包含任意数量的 '*' 字符。你的任务是删除所有的 '*' 字符。
 * 
 * 当字符串还存在至少一个 '*' 字符时，你可以执行以下操作：
 * 
 * 
 * 删除最左边的 '*' 字符，同时删除该星号字符左边一个字典序 最小 的字符。如果有多个字典序最小的字符，你可以删除它们中的任意一个。
 * 
 * 
 * 请你返回删除所有 '*' 字符以后，剩余字符连接而成的 字典序最小 的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aaba*"
 * 
 * 输出："aab"
 * 
 * 解释：
 * 
 * 删除 '*' 号和它左边的其中一个 'a' 字符。如果我们选择删除 s[3] ，s 字典序最小。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abc"
 * 
 * 输出："abc"
 * 
 * 解释：
 * 
 * 字符串中没有 '*' 字符。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 只含有小写英文字母和 '*' 字符。
 * 输入保证操作可以删除所有的 '*' 字符。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string clearStars(string s) {
        stack<int> st[26];//用26个栈分别记录每个字母的下标
        for(int i = 0; i < s.size();i++){
            if(s[i] == '*'){    //如果遇到星号，则选择最小的不为空的栈，弹出下标
                for(int j = 0; j < 26; j++){
                    if(!st[j].empty()){
                        st[j].pop();
                        break;
                    }
                }
            }else{
                st[s[i] - 'a'].push(i);
            }
        }

        string ans(s.size(), ' ');  // 初始化为字符串的大小
        for(int i = 0; i < 26; i++) {
            while(!st[i].empty()) {
                int index = st[i].top();  // 获取栈顶的索引
                st[i].pop();
                ans[index] = s[index];  // 填充对应的字符
            }
        }
        ans.erase(remove(ans.begin(), ans.end(), ' '), ans.end());  // 删除空格
        return ans;
    }
};
// @lc code=end

