/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
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
    int totalFruit(vector<int>& fruits) {
        int res  = 0;
        int left = 0;
        unordered_map<int,int> window;//用哈希表记录窗口中的水果种类
        for(int right = 0;right < fruits.size();right++){
            window[fruits[right]]++; //更新水果种类数量

            while(window.size() > 2){ //窗口中水果种类大于2时，缩小窗口
                window[fruits[left]]--;
                if(window[fruits[left]] == 0){ //如果窗口中的水果种类数量为0，删除该水果;原因：如果窗口中的水果种类数量为0，那么窗口中的水果种类就会减少一个
                    window.erase(fruits[left]);
                }
                left++;
            }
            res = max(res,right - left + 1);//更新结果

        }

        return res;

    }
};
// @lc code=end

