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
    // 954.������������
    bool canReorderDoubled(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            map[arr[i]]++; // ��ϣ���Ƶͳ��
        }
        if (map[0] % 2 != 0)
        {
            return false; // �ж�һ��0���ֵĴ��������Ϊ������ôһ��������
        }
        vector<int> keycnt(n);
        for (auto &[x, _] : map)
        {
            // ������ֵ���еļ�
            keycnt.push_back(x);
        }
        // �Լ�������ֵ��С����
        sort(keycnt.begin(), keycnt.end(), [&](int a, int b)
             { return abs(a) < abs(b); });
        // �� C++ �У������(����8)�������� unordered_map<int, int> cnt �У�cnt[8] ���Զ�����һ����Ϊ 8 ��ֵΪ 0 ����Ԫ��
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

    // 969.�������
    vector<int> pancakeSort(vector<int> &arr)
    {
        // ÿ���ҵ�������Ȼ������ŵ����,�´�Ѱ���ų����һ����
        vector<int> ans;
        int n = arr.size();
        for (int i = n; i > 1; i--)
        {
            int idx = max_element(arr.begin(), arr.begin() + i) - arr.begin(); // �õ����Ԫ�ص��±�
            if (idx == i - 1)
            {
                continue;
            }
            // reverse��max_element�ķ�Χ����[first,last)
            reverse(arr.begin(), arr.begin() + idx + 1);
            reverse(arr.begin(), arr.begin() + i);
            ans.push_back(idx + 1);
            ans.push_back(i);
        }
        return ans;
    }

    // 1833.ѩ����������(�Լ�AC)
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

    // 1834.���߳�
    using PII = pair<int, int>;
    using LL = long long;
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<int> ans;
        vector<int> idx(n);              // �洢����
        iota(idx.begin(), idx.end(), 0); // ����0 1 2 ... n-1������
        // ��tasks����,ԭ����û��������������������պ�ʱ��ʼ��С����
        sort(idx.begin(), idx.end(), [&](int a, int b)
             { return tasks[a][0] < tasks[b][0]; });
        // ����С����
        priority_queue<PII, vector<PII>, greater<PII>> q;
        int p = 0;        // ��������idx��ָ��
        LL totaltime = 0; // �ܹ����ĵ�ʱ��
        for (int i = 0; i < n; i++)
        {
            if (q.empty())
            {
                totaltime = max(totaltime, (LL)tasks[idx[p]][0]);
            }
            // ��ѵĲ���
            while (p < n && tasks[idx[p]][0] < totaltime)
            {
                q.emplace(tasks[idx[p]][1], idx[p]); // ÿ�������ִ��ʱ��Ͷ�Ӧ���������
                p++;
            }
            // �Ѷ�����
            auto &&[process, ii] = q.top();
            totaltime += process;
            ans.push_back(ii);
            q.pop();
        }
        return ans;
    }

    // 1838.���ƵԪ�ص�Ƶ��
    // ����ʱ��û�п��ǵ����ڵ���С������������û�뵽��
    int maxFrequency(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1;
        long total = 0; // �����ֵ�ܵ����Ĵ���
        for (int r = 1, l = 0; r < n; r++) {
            total += long (nums[r] - nums[r-1]) * (r - l);
            while (total > k) {
                total -= nums[r] - nums[l]; // ��С����
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }

    // 2300.�����ҩˮ�ĳɹ�����
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(), potions.end());
        int n = spells.size();
        for (int i = 0; i < n; i++) {
            long long target = (success + spells[i] - 1) / spells[i]; // ����ȡ��
            int idx = binarysearch(potions, target);
            ans.push_back(potions.size() - idx);
        }
        return ans;
    }
    // Ѱ�Ҵ��ڵ���ĳ����������߽�
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


    // ������10.02��λ����
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>map;
        // ������ͬ��ĸ���ַ���������������key
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].emplace_back(str);
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            // it������
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