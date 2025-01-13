class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> freq(26, 0);
        int result = 0;
        for (char ch : s)
        {
            freq[ch - 'a']++;
        }
        for (int n : freq)
        {
            if (n > 0)
            {
                if (n % 2 == 0)
                {
                    result += 2;
                }
                else
                {
                    result++;
                }
            }
        }
        return result;
    }
};