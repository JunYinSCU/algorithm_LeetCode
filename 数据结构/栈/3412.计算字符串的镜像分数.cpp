/*
 * @lc app=leetcode.cn id=3412 lang=cpp
 *
 * [3412] 计算字符串的镜像分数
 *
 * https://leetcode.cn/problems/find-mirror-score-of-a-string/description/
 *
 * algorithms
 * Medium (43.93%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 8.1K
 * Testcase Example:  '"aczzx"'
 *
 * 给你一个字符串 s。
 * 
 * 英文字母中每个字母的 镜像 定义为反转字母表之后对应位置上的字母。例如，'a' 的镜像是 'z'，'y' 的镜像是 'b'。
 * 
 * 最初，字符串 s 中的所有字符都 未标记 。
 * 
 * 字符串 s 的初始分数为 0 ，你需要对其执行以下过程：
 * 
 * 
 * 从左到右遍历字符串。
 * 对于每个下标 i ，找到距离最近的 未标记 下标 j，下标 j 需要满足 j < i 且 s[j] 是 s[i] 的镜像。然后 标记 下标 i 和
 * j，总分加上 i - j 的值。
 * 如果对于下标 i，不存在满足条件的下标 j，则跳过该下标，继续处理下一个下标，不需要进行标记。
 * 
 * 
 * 返回最终的总分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入： s = "aczzx"
 * 
 * 输出： 5
 * 
 * 解释：
 * 
 * 
 * i = 0。没有符合条件的下标 j，跳过。
 * i = 1。没有符合条件的下标 j，跳过。
 * i = 2。距离最近的符合条件的下标是 j = 0，因此标记下标 0 和 2，然后将总分加上 2 - 0 = 2 。
 * i = 3。没有符合条件的下标 j，跳过。
 * i = 4。距离最近的符合条件的下标是 j = 1，因此标记下标 1 和 4，然后将总分加上 4 - 1 = 3 。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入： s = "abcdef"
 * 
 * 输出： 0
 * 
 * 解释：
 * 
 * 对于每个下标 i，都不存在满足条件的下标 j。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s 仅由小写英文字母组成。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    long long calculateScore(string s) {
        long long res = 0;
        stack<int> st[26];//用26个栈记录每个字母的下标
        for(int i = 0; i < s.size(); i++){
            int index = s[i] - 'a';
            int mirrorIndex = 25 - index;

            if(st[mirrorIndex].empty()){    //如果当前字母的镜像字母的栈为空，则将当前字母的下标压入对应的栈中
                st[index].push(i);
            }else{  //否则表示存在镜像字母，出栈计算分数
                int j = st[mirrorIndex].top();
                st[mirrorIndex].pop();
                res += i - j;              
            }

        }

        return res;
    }
};
// @lc code=end

