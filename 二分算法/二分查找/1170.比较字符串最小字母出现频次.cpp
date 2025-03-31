/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 *
 * https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/description/
 *
 * algorithms
 * Medium (66.85%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    40.2K
 * Total Submissions: 60.1K
 * Testcase Example:  '["cbd"]\n["zaaaz"]'
 *
 * 定义一个函数 f(s)，统计 s  中（按字典序比较）最小字母的出现频次 ，其中 s 是一个非空字符串。
 * 
 * 例如，若 s = "dcce"，那么 f(s) = 2，因为字典序最小字母是 "c"，它出现了 2 次。
 * 
 * 现在，给你两个字符串数组待查表 queries 和词汇表 words 。对于每次查询 queries[i] ，需统计 words 中满足
 * f(queries[i]) < f(W) 的 词的数目 ，W 表示词汇表 words 中的每个词。
 * 
 * 请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是第 i 次查询的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：queries = ["cbd"], words = ["zaaaz"]
 * 输出：[1]
 * 解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * 输出：[1,2]
 * 解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * queries[i][j]、words[i][j] 都由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(Mlogm+Nlogn)
    //空间复杂度O(m+n+26)
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        int m = words.size();
        vector<int> res(n);
        vector<int> cnt(m); //用于统计word字符串的f值
        for(int i = 0; i < m; i++){
            cnt[i] = f(words[i]);
        }
        sort(cnt.begin(), cnt.end());   //进行排序，便于二分

        for(int i = 0;i < n;i++){
            int min = f(queries[i]);
            res[i] = m - lowerBound(cnt,min+1);
        }

        return res;
    }

    int f(string str){
        int res = 0;
        int cnt[26] = {0};
        int n = str.size();
        if(n == 0)
            return 0;

        for(int i = 0; i < n; i++){
            cnt[str[i] - 'a']++;
        }
        for(int i = 0;i < 26;i++){
            if (cnt[i] > 0) {
                res = cnt[i];
                break;
            }
        }

        return res;
    }

    int lowerBound(vector<int>& nums, int target){
        int left=0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;
    }
};
// @lc code=end

