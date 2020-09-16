#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

// ToDo: replace line2 with std::max_element(itFirst,itLast)
// std::max_element returns an iterator in the range [first,last)

class Solution
{
public:
     // timeComplexity: O(n^2)
     // spaceComplexity: O(n)
     // this run on worse case: 2n-2 times reverse
     vector<int> pancakeSort(vector<int> &A)
     {

          // key function : std::reverse(itFront,itLast);
          //     iterator itFront=vec[front];
          //     iterator itLast=vec[last];
          //     reverse between [itFront,itLast)  i.e. from vec[front] to vec[last-1]

          // 1 IsSort? line2: return ;
          // 2 let i=unSortMaxVal
          // 3 find i in A
          // 4 put i to A[0]
          // 5 put i to A[i-1]
          // 6 go to line1

          if (A.empty() || A.size() == 1)
          {
               return {};
          }

          vector<int> ans;
          ans.reserve(2 * A.size() - 2);

          // Reduce time in find index
          int lastSortVal = A.size();

          while (true)
          {
               if (IsSort(A, lastSortVal))
               {
                    break;
               }
               else
               {

                    int i = UnSortMaxVal(A, lastSortVal);
                    int indexOfI = distance(A.begin(), find(A.begin(), A.begin() + lastSortVal, i));

                    // if(indexOfI==0) reverse A[0,1) ;
                    // and ans will push_back extra "1"
                    reverse(A.begin(), A.begin() + indexOfI + 1);
                    ans.push_back(indexOfI + 1);

                    reverse(A.begin(), A.begin() + i);
                    ans.push_back(i);

                    lastSortVal = i;
               }
          }
          return ans;
     }

     bool IsSort(vector<int> &A, int lastSortVal)
     {
          for (int i = lastSortVal; i > 0; --i)
          {
               if (i != A[i - 1])
               {
                    return false;
               }
          }
          return true;
     }

     int UnSortMaxVal(vector<int> &A, int lastSortVal)
     {
          for (int i = lastSortVal; i > 0; --i)
          {
               if (i != A[i - 1])
               {
                    return i;
               }
          }
          return -1;
     }
};
