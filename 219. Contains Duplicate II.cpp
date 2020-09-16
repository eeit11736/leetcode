#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        //initial idea: get currentValue and check distance in unordered_map <value,last_index>
        //another idea: using hashtable and store only last k value by erase
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.find(nums[i]) != m.end())
            {
                if (i - m[nums[i]] <= k)
                {
                    return true;
                }
            }
            m[nums[i]] = i;
        }
        return false;
    }
};