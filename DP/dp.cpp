#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
    // 198.��ҽ���
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[0] = nums[0];
            }else if (i == 1) {
                dp[1] = max(dp[0],nums[1]);
            }else {
                dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            }
        }
        return dp[n-1];
    }
    // �Ľ���״ѹDP
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int first,second;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                first = nums[0];
            }else if (i == 1) {
                second = max(first,nums[1]);
            }else {
                int temp = second;
                second = max(first + nums[i],second);
                first = temp;
            }
        }
        return second;
    }
    
    // �ҵ�͵�����ļ��ҷ���
    // const��������vector����������ؼ�����ζ��vector������ݲ��ɱ��޸�
    vector<int> calculateIND(const vector<int>& FF, const vector<int>& M) {
    vector<int> IND;
    int ind = -1;
    // �ҵ���һ����������������
    // find����������ָ���һ��ƥ��Ԫ�صĵ�������autoΪc++���Զ�ʶ������
    // ��δ�ҵ��򷵻ظ���������������
    auto it = find(FF.begin(), FF.end(), FF.back());
    if (it != FF.end()) {
        ind = distance(FF.begin(), it); // distance���ڼ�������������֮��ľ��������ɵ������õ�����
        IND.push_back(ind);
    }
    // ѭ������ֱ����������
    while (ind >= 0 && FF[ind] > M[ind]) {
        it = find(FF.begin(), FF.end(), FF[ind] - M[ind]);
        if (it != FF.end()) {
            ind = distance(FF.begin(), it);
            IND.push_back(ind);
        } else {
            break; // ����Ҳ���ƥ�������˳�
        }
    }
    // ��ת���
    reverse(IND.begin(), IND.end());
    return IND;
}







};