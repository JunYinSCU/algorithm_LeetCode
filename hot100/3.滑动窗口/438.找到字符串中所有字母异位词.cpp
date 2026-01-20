/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (54.57%)
 * Likes:    1840
 * Dislikes: 0
 * Total Accepted:    901.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "cbaebabacd", p = "abc"
 * 输出: [0,6]
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "abab", p = "ab"
 * 输出: [0,1,2]
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s 和 p 仅包含小写字母
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size();
        int m = p.size();

        if(n < m) return res;

        //利用vector代替哈希表，节省空间
        vector<int> p_count(26,0);
        vector<int> window_count(26,0);

        for(int i = 0; i < m; i++){
            p_count[p[i]-'a']++;
            //初始化p_count时也可以把滑动窗口的初始统计也做了
            window_count[s[i]-'a']++;
        }

        // 先判断这个初始统计里是否有异位词
        if(p_count == window_count)
            res.push_back(0);
        
        // 这里r初始化为下一个字母
        for(int r = m,l = 0; r < n; r++){
            // 下一个字母进入统计
            window_count[s[r]-'a']++;
            // 左指针字母移除统计
            window_count[s[l]-'a']--;
            // 固定指针，所以左指针也要移动
            l++;
            // 判断现在是否是异位词
            if(p_count == window_count){
                res.push_back(l);
            }            
        }

        return res;
    }

    // vector<int> findAnagrams(string s, string p) {
    //     int l = 0;
    //     vector<int> res;
    //     int n = s.size();
    //     int m = p.size();
    //     if(n < m) return res;

    //     sort(p.begin(),p.end());

    //     for(int r = m-1; r < n; r++){
    //         string str = s.substr(l,m);
    //         //由于每次循环都需要进行sort排序，导致超时
    //         //对于这种不考虑字符串顺序的比较，可以用哈希表拆分成单个字母
    //         // 只需要判断字母个数是否一致，即可得出是否异位词
    //         if(isAnagram(str,p)){
    //             res.push_back(l);
    //         }
    //         l++;

    //     }
    //     return res;

    // }


    // bool isAnagram(string target,string pattern){
    //     sort(target.begin(),target.end());
    //     //sort函数时间复杂度O(nlogn)
    //     if(target == pattern)
    //         return true;
    //     return false;
    // }

    
};
// @lc code=end

