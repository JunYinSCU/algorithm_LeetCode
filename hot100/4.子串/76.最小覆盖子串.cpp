/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (48.72%)
 * Likes:    3466
 * Dislikes: 0
 * Total Accepted:    971K
 * Total Submissions: 2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t
 * 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。
 * 
 * 测试用例保证答案唯一。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 O(m + n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
public:
    
    // string minWindow(string s, string t) {
    //     int m = s.size();
    //     int n = t.size();
    //     string res = "";
    //     // 如果长度比t小，直接返回空字符串
    //     if(m < n) return res;
    
    //     // 用于统计每个字符串中字符出现的次数
    //     int t_cnt[128]{};
    //     int s_cnt[128]{};
    
    //     for(int i = 0; i < n; i++){
    //         t_cnt[t[i]]++;
    //     }
    
    //     int left = 0;
    //     int ans_left = 0,ans_right=0;
    //     int min_len = INT_MAX;
    //     for(int right = 0; right < m; right++){
    //         // 右指针进入统计
    //         s_cnt[s[right]]++;
    //         // 如果完成覆盖
    //         while(is_covered(s_cnt,t_cnt) && left <= right){
    //             int len = right - left + 1;//记录长度
    
    //             if(len < min_len){  //更新最小值
    //                 min_len = len;
    //                 ans_left = left;
    //             }
    //             // 左边界移出，寻找最小子串
    //             s_cnt[s[left]]--;
    //             left++;
    //         }
            
    //     }
    
    //     res = min_len == INT_MAX ? "" : s.substr(ans_left,min_len);
    //     return res;
    // }

    // bool is_covered(int s_cnt[], int t_cnt[]) {
    //     for(int i = 'A';i <= 'Z';i++){
    //         if(s_cnt[i] < t_cnt[i]){
    //             return false;
    //         }
    //     }

    //     for(int i = 'a';i <= 'z';i++){
    //         if(s_cnt[i] < t_cnt[i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    //优化方案，维护一个整数变量 count(计数器),用来记录“还差多少个字符才凑齐”
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m < n) return "";

        // need[c] > 0 : 表示还需要 c 字符
        // need[c] < 0 : 表示 c 字符多余了
        // need[c] == 0 : 刚好凑齐
        vector<int> need(128,0);
        //遍历记账
        for(char c : t) need[c]++;

        int need_cnt = n; //记录还需要多少个字符

        int left = 0;
        int ans_left = 0;
        int min_len = INT_MAX;

        for(int right = 0; right < m; right++){
            if(need[s[right]] > 0){ //如果>0说明是目前还需要的字符，则减少
                need_cnt--;
            }
            need[s[right]]--;   //无论是否是我们需要的，都将数组记录减少

            while(need_cnt == 0){   //循环判断是否覆盖，寻找最小字符串
                // 先判断是否更新结果
                int len = right - left + 1;
                if(len < min_len){  //更新最小记录
                    min_len = len;
                    ans_left = left;
                }
                // 出窗口，如果出窗口的字符是我们需要的且=0
                // 则说明出窗口后我们差字符了，需要计算器+1
                if(need[s[left]] == 0){
                    need_cnt++;
                }

                need[s[left]]++;
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(ans_left, min_len);
    }
};
// @lc code=end

