#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    // for all intervals[i]
    //     for all intervals[j].left >= intervals[i].right
    //         find min( intervals[j].left )
    //         return j
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<int> ans;
        ans.reserve(intervals.size());

        // map will sort by key automatically
        // map <left , index in intervals>
        map<int, int> m;

        for (int i = 0; i < intervals.size(); ++i)
        {
            m.insert(pair<int, int>(intervals[i].front(), i));
        }

        for (int i = 0; i < intervals.size(); ++i)
        {
            // map.lower_bound(input) return iterator it
            // input <= it.key
            // it == map.end() if input > map.last.key
            auto it = m.lower_bound(intervals[i].back());
            if (it == m.end())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(it->second);
            }
        }

        return ans;
    }
};