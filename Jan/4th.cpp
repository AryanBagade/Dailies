class Solution
{
public:
    int countUnique(string &s, int first, int last)
    {
        int count = 0;
        unordered_set<char> exists;
        for (int i = first + 1; i < last; i++)
        {
            if (exists.find(s[i]) == exists.end())
            {
                count++;
                exists.insert(s[i]);
            }
        }
        return count;
    }
    int countPalindromicSubsequence(string s)
    {
        vector<vector<int>> position(26, vector<int>(2, -1));
        unordered_set<char> done;
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (position[s[i] - 'a'][0] == -1)
            {
                position[s[i] - 'a'][0] = i;
                position[s[i] - 'a'][1] = i;
            }
            else
            {
                position[s[i] - 'a'][1] = i;
            }
        }
        for (char ch : s)
        {
            if (done.find(ch) == done.end())
            {
                int unique = countUnique(s, position[ch - 'a'][0],
                                         position[ch - 'a'][1]);
                result = result + unique;
                done.insert(ch);
            }
        }
        return result;
    }
};