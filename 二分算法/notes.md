# 二分算法

## 二分查找
1. 对于需要知道相同数字出现的次数和下标时，可以用
   ```
   unordered_map<int, vector<int>> pos;#key用于存储值，value用于存储下标
   ```
   由于在插入时是按照下标的顺序插入的，所以后续可以不用再对value的vector进行排序  
   **例题** :2080、3488

## 二分答案
* 二分答案，顾名思义就是对答案进行二分，即题目求的是什么就对什么进行二分。注意以下字眼：**非负整数数组**、**非空** 和 **连续**。就可以想到用二分查找法，查找一个有范围的整数。
* 最重要的一点就是挖掘数组的单调性，如果不具备单调性则无法使用二分算法。如果具有单调性，则根据此来编写check函数来辅助二分。
* 对于二分答案题，最重要的就是check函数，用于判断当前答案是否满足条件，通过check函数来进行二分
* 其次，确定二分的区间也很重要，即确定left和right的取值

### 求最小值
1. 求最小：check(mid) == true 时更新 right = mid - 1，反之更新 left = mid + 1，最后返回 left。
   

### 求最大值
1. 求最大：check(mid) == true 时更新 left = mid + 1，反之更新 right = mid - 1，最后返回 right

