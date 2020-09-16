#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {

        deque<int> ans;
        for (auto i : A)
        {
            if (i % 2 == 0)
            {
                ans.push_front(i);
            }
            else
            {
                ans.push_back(i);
            }
        }
        vector<int> vec(ans.begin(), ans.end());
        return vec;
    }
};