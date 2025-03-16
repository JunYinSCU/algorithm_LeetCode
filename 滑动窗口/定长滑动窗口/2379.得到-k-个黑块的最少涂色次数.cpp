/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //求字符串的长度
        int min_recolors = k; 
        int left = 0;
        int W_num = 0;
        //窗口大小为固定的k
        for(int right = 0; right < blocks.size(); right++)
        {
            //只需要找出窗口未k时，白色块的最小值
            if(right < k-1)
            {
                if(blocks[right] == 'W')
                {
                    W_num++;
                }
                continue;
            }

            if(blocks[right] == 'W')
            {
                W_num++;
            }
            //更新
            min_recolors = min(W_num, min_recolors);

            if(blocks[left] == 'W')
            {
                W_num--;               
            }   
            left++;     
        }
        return min_recolors;
    }
};
// @lc code=end

