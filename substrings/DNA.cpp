#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> result;
        unordered_set<string> store;
        unordered_map<string, int> mp;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        { // O(N)
            string temp;
            for (int j = i; j < i + 10 && j < n; ++j)
            {
                temp += s[j];
            }
            if (mp.find(temp) != mp.end())
            { // O(N)
                mp[temp] += 1;
                if (mp[temp] == 2)
                {
                    result.push_back(temp);
                }
            }
            else
            {
                mp.insert({temp, 1});
            }
        }
        return result;
    }
};