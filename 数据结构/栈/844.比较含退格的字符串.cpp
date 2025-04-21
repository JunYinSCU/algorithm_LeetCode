/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 *
 * https://leetcode.cn/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (48.00%)
 * Likes:    814
 * Dislikes: 0
 * Total Accepted:    283K
 * Total Submissions: 589.4K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
 * 
 * 注意：如果对空文本输入退格字符，文本继续为空。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ab#c", t = "ad#c"
 * 输出：true
 * 解释：s 和 t 都会变成 "ac"。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "ab##", t = "c#d#"
 * 输出：true
 * 解释：s 和 t 都会变成 ""。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a#c", t = "b"
 * 输出：false
 * 解释：s 会变成 "c"，但 t 仍然是 "b"。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length, t.length <= 200
 * s 和 t 只含有小写字母以及字符 '#'
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
//方法一：栈
    // bool backspaceCompare(string s, string t) {
    //     stack<char> s1, s2;
    //     for(char& c : s ){
    //         if(!s1.empty()){
    //             if(c == '#') s1.pop();
    //             else s1.push(c);
    //         }else{
    //             if(c != '#') s1.push(c);
    //         }

    //     }

    //     for(char& c : t ){
    //         if(!s2.empty()){
    //             if(c == '#') s2.pop();
    //             else s2.push(c);
    //         }else{
    //             if(c != '#') s2.push(c);
    //         }
    //     }
    //     if(s1.size() != s2.size()) return false;
    //     while(!s1.empty()){
    //         if(s1.top() != s2.top()) return false;
    //         s1.pop();
    //         s2.pop();
    //     }
    //     return true;
    // }

    //方法二：双序列双指针：
    bool backspaceCompare(string s, string t) {
        int p1 = s.size() - 1, p2 = t.size() - 1;
        
        while(p1 >= 0 || p2 >= 0){
            int skipS = 0,skipT = 0;
            while(p1 >= 0){
                if (s[p1] == '#') {
                    skipS++;
                    p1--;
                } else if (skipS > 0) {
                    skipS--;
                    p1--;
                } else {
                    break;
                }
            }

            while(p2 >= 0){
                if (t[p2] == '#') {
                    skipT++;
                    p2--;
                } else if (skipT > 0) {
                    skipT--;
                    p2--;
                } else {
                    break;
                }
            }

            if (p1 >= 0 && p2 >= 0) {
                if (s[p1] != t[p2]) return false;
            }else {
                // 如果只有一个指针越界，说明长度不同
                if (p1 >= 0 || p2 >= 0) return false;
            }

            p1--;
            p2--;
        }

        return true;

    }
};
// @lc code=end

