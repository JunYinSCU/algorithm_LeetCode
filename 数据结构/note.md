# 常见数据结构

## 枚举技巧

1. 枚举右，维护左
   * 对于**双变量**问题，例如两数之和 ai+aj=t，可以枚举右边的 aj，转换成单变量问题，也就是在 aj左边找是否有 ai=t−aj，这可以用哈希表维护。
    ```
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x : nums) { // x = nums[j]
            ans += cnt[x]++;
        }
        return ans;
    }
    ```