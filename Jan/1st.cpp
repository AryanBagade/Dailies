class Solution
{
public:
    int maxScore(string s)
    {
        int count0 = 0;
        int count1 = 0;
        int maxi = 0;
        for (char i : s)
        {
            count1 = count1 + (i - '0');
        }
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '0')
            {
                count0++;
            }
            else
            {
                count1--;
            }
            maxi = max(maxi, count0 + count1);
        }
        return maxi;
    }
};