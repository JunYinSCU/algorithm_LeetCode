/*
 * @lc app=leetcode.cn id=1552 lang=cpp
 *
 * [1552] 两球之间的磁力
 *
 * https://leetcode.cn/problems/magnetic-force-between-two-balls/description/
 *
 * algorithms
 * Medium (64.24%)
 * Likes:    222
 * Dislikes: 0
 * Total Accepted:    35.7K
 * Total Submissions: 55.5K
 * Testcase Example:  '[1,2,3,4,7]\n3'
 *
 * 在代号为 C-137 的地球上，Rick 发现如果他将两个球放在他新发明的篮子里，它们之间会形成特殊形式的磁力。Rick 有 n 个空的篮子，第 i
 * 个篮子的位置在 position[i] ，Morty 想把 m 个球放到这些篮子里，使得任意两球间 最小磁力 最大。
 * 
 * 已知两个球如果分别位于 x 和 y ，那么它们之间的磁力为 |x - y| 。
 * 
 * 给你一个整数数组 position 和一个整数 m ，请你返回最大化的最小磁力。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：position = [1,2,3,4,7], m = 3
 * 输出：3
 * 解释：将 3 个球分别放入位于 1，4 和 7 的三个篮子，两球间的磁力分别为 [3, 3, 6]。最小磁力为 3 。我们没办法让最小磁力大于 3
 * 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：position = [5,4,3,2,1,1000000000], m = 2
 * 输出：999999999
 * 解释：我们使用位于 1 和 1000000000 的篮子时最小磁力最大。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == position.length
 * 2 <= n <= 10^5
 * 1 <= position[i] <= 10^9
 * 所有 position 中的整数 互不相同 。
 * 2 <= m <= position.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    //时间复杂度O(nlogn)
    //空间复杂度O(1)
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int left = 1;
        int right = position[n-1] - position[0];

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(position,m,mid)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }

    bool check(vector<int>& position, int m, int min){
        int n = position.size();
        int last =  position[0];
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(position[i]-last>=min){  //如果当前位置比前一个球的位置>=min，则可以放球
                cnt++;
                last=position[i];   //更新球的位置
            }
        }
        return cnt >= m;    //判断是否有m个满足的位置
    }
};
// @lc code=end

