class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> exist(51, 0);
        vector<int> result;
        for (int i = 0; i < A.size(); i++)
        {
            int res = 0;
            if (A[i] == B[i])
            {
                res += 1;
            }
            else
            {
                if (exist[A[i]] == 1)
                {
                    res += 1;
                }
                if (exist[B[i]] == 1)
                {
                    res += 1;
                }
            }
            exist[A[i]] = 1;
            exist[B[i]] = 1;
            res = i > 0 ? res + result[result.size() - 1] : res + 0;
            result.push_back(res);
        }
        return result;
    }
};