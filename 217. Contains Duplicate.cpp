#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // initial ideas:push each element to hashtable and check duplicate
        // from discuss:
        //   ideaA: sort(nums) and check nums[i]==nums[i+1]
        //   ideaB: compare size of hashtable and originalVec
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};