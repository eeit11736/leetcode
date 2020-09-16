#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        map<int, string> m = {{3, "Fizz"}, {5, "Buzz"}};

        vector<string> ans;
        ans.reserve(n);
        for (int i = 1; i < n + 1; ++i)
        {
            string str = "";
            for (auto p : m)
            {
                if (i % p.first == 0)
                {
                    str += p.second;
                }
            }
            if (str.empty())
            {
                str += to_string(i);
            }
            ans.push_back(str);
        }
        return ans;
    }
};