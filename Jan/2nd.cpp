class Solution
{
public:
    vector<int> vowelStrings(vector<string> &words,
                             vector<vector<int>> &queries)
    {
        vector<int> count;
        vector<int> result;
        for (string s : words)
        {
            if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' ||
                 s[0] == 'u') &&
                (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' ||
                 s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' ||
                 s[s.size() - 1] == 'u'))
            {
                count.push_back(1);
            }
            else
            {
                count.push_back(0);
            }
        }
        for (int i = 1; i < count.size(); i++)
        {
            count[i] = count[i - 1] + count[i];
        }
        cout << endl;
        for (int n : count)
        {
            cout << n << " ";
        }
        cout << endl;
        for (vector<int> slot : queries)
        {
            int left = slot[0];
            int right = slot[1];
            cout << left << right << endl;
            int totalCount = count[right] - (left == 0 ? 0 : count[left - 1]);
            result.push_back(totalCount);
        }
        return result;
    }
};