class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        vector<long long> pre(nums.begin(), nums.end());
        vector<long long> suf(nums.begin(), nums.end());
        int count = 0;
        for (int i = 1; i < pre.size(); i++)
        {
            pre[i] = pre[i] + pre[i - 1];
        }
        for (int i = suf.size() - 2; i >= 0; i--)
        {
            suf[i] = suf[i] + suf[i + 1];
        }
        for (int i = 0; i < pre.size() - 1; i++)
        {
            if (pre[i] >= suf[i + 1])
            {
                count++;
            }
        }
        return count;
    }
};