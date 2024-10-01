#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

class Solution
{
public:
    // 954.二倍数对数组
    bool canReorderDoubled(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            map[arr[i]]++; // 哈希表词频统计
        }
        if (map[0] % 2 != 0)
        {
            return false; // 判断一下0出现的次数，如果为奇数那么一定不满足
        }
        vector<int> keycnt(n);
        for (auto &[x, _] : map)
        {
            // 遍历键值对中的键
            keycnt.push_back(x);
        }
        // 对键按绝对值大小排序
        sort(keycnt.begin(), keycnt.end(), [&](int a, int b)
             { return abs(a) < abs(b); });
        // 在 C++ 中，如果键(例如8)不存在于 unordered_map<int, int> cnt 中，cnt[8] 会自动插入一个键为 8 且值为 0 的新元素
        for (int key : keycnt)
        {
            if (map[2 * key] < map[key])
            {
                return false;
            }
            map[2 * key] -= map[key];
        }
        return true;
    }

    // 969.煎饼排序
    vector<int> pancakeSort(vector<int> &arr)
    {
        // 每次找到最大的数然后把他放到最后,下次寻找排除最后一个数
        vector<int> ans;
        int n = arr.size();
        for (int i = n; i > 1; i--)
        {
            int idx = max_element(arr.begin(), arr.begin() + i) - arr.begin(); // 得到最大元素的下标
            if (idx == i - 1)
            {
                continue;
            }
            // reverse与max_element的范围都是[first,last)
            reverse(arr.begin(), arr.begin() + idx + 1);
            reverse(arr.begin(), arr.begin() + i);
            ans.push_back(idx + 1);
            ans.push_back(i);
        }
        return ans;
    }

    // 1833.雪糕的最大数量(自己AC)
    int maxIceCream(vector<int> &costs, int coins)
    {
        vector<int> cnt(100001, 0);
        int n = costs.size();
        for (int i = 0; i < n; i++)
        {
            cnt[costs[i]]++;
        }
        int num = 0, j = 0;
        int max_num = *max_element(costs.begin(), costs.end());
        for (int i = 0; i <= max_num; i++)
        {
            while (cnt[i] != 0 && coins - i >= 0)
            {
                num++;
                coins -= i;
                cnt[i]--;
            }
        }
        return num;
    }

    // 1834.单线程
    using PII = pair<int, int>;
    using LL = long long;
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<int> ans;
        vector<int> idx(n);              // 存储索引
        iota(idx.begin(), idx.end(), 0); // 生成0 1 2 ... n-1的数组
        // 对tasks排序,原数组没动排序的是其索引，按照何时开始从小到大
        sort(idx.begin(), idx.end(), [&](int a, int b)
             { return tasks[a][0] < tasks[b][0]; });
        // 创建小顶堆
        priority_queue<PII, vector<PII>, greater<PII>> q;
        int p = 0;        // 索引数组idx的指针
        LL totaltime = 0; // 总共消耗的时间
        for (int i = 0; i < n; i++)
        {
            if (q.empty())
            {
                totaltime = max(totaltime, (LL)tasks[idx[p]][0]);
            }
            // 入堆的操作
            while (p < n && tasks[idx[p]][0] < totaltime)
            {
                q.emplace(tasks[idx[p]][1], idx[p]); // 每项任务的执行时间和对应的索引入堆
                p++;
            }
            // 堆顶出来
            auto &&[process, ii] = q.top();
            totaltime += process;
            ans.push_back(ii);
            q.pop();
        }
        return ans;
    }

    // 1838.最高频元素的频数
    // 做的时候没有考虑到窗口的缩小，滑动窗口真没想到啊
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1;
        long total = 0; // 补齐差值总的消耗代价
        for (int r = 1, l = 0; r < n; r++) {
            total += long (nums[r] - nums[r-1]) * (r - l);
            while (total > k) {
                total -= nums[r] - nums[l]; // 缩小窗口
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

    // 2300.咒语和药水的成功对数
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(), potions.end());
        int n = spells.size();
        for (int i = 0; i < n; i++) {
            long long target = (success + spells[i] - 1) / spells[i]; // 向上取整
            int idx = binarysearch(potions, target);
            ans.push_back(potions.size() - idx);
        }
        return ans;
    }
    // 寻找大于等于某个数的最左边界
    int binarysearch(vector<int>&num, long long target) {
        int l = 0, r = num.size() - 1, ans = num.size();
        while (l <= r) {
            int m = (r + l) / 2;
            if (num[m] >= target) {
                ans = m;
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        return ans;
    }


    // 面试题10.02变位词组
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>map;
        // 包含相同字母的字符串的正序排列做key
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            // it迭代器
            ans.emplace_back(it->second);
        }
        return ans;
    }









};
int main()
{

    Solution s;
    vector<int> nums{3,9,6};
    int k = 2;
    int ans = s.maxFrequency(nums, k);
    cout << ans << endl;
    return 0;
}