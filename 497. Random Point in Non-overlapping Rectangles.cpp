#include <vector>
#include <stdlib.h>
using namespace std;

class Solution
{
public:
    int rectCount;
    // sumOfPointCount[i] stores pointCount from rect[0] to rect[i]
    vector<int> sumOfPointCount;
    // totalPointCount stores pointCount from all rects
    int totalPointCount;

    // pair< x1,x2 > and < y1,y2 >
    vector<pair<int, int>> vx;
    vector<pair<int, int>> vy;

    Solution(vector<vector<int>> &rects)
    {
        rectCount = rects.size();
        sumOfPointCount.clear();
        sumOfPointCount.reserve(rectCount);
        totalPointCount = 0;

        vx.reserve(rectCount);
        vy.reserve(rectCount);
        for (auto rect : rects)
        {
            int x1 = rect[0];
            int y1 = rect[1];
            int x2 = rect[2];
            int y2 = rect[3];
            vx.push_back(make_pair(x1, x2));
            vy.push_back(make_pair(y1, y2));

            // pointCount=1 when x2==x1, y2==y1
            int pointCount = (x2 - x1 + 1) * (y2 - y1 + 1);
            totalPointCount += pointCount;
            sumOfPointCount.push_back(totalPointCount);
        }
        return;
    }

    vector<int> pick()
    {

        int randInt = rand() % totalPointCount;
        int selectRect;
        for (selectRect = 0; selectRect < rectCount; ++selectRect)
        {
            if (sumOfPointCount[selectRect] > randInt)
            {
                break;
            }
        }

        int x1 = vx[selectRect].first;
        int x2 = vx[selectRect].second;
        int y1 = vy[selectRect].first;
        int y2 = vy[selectRect].second;

        int x = x1 + rand() % (x2 - x1 + 1);
        int y = y1 + rand() % (y2 - y1 + 1);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */