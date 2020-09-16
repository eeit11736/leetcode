// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

#include <stdlib.h>
using namespace std;
int rand7()
{
    return rand() % 7 + 1;
}

class Solution
{
public:
    int rand10()
    {
        // initial thought
        // return (rand7()+rand7()+.....)%10
        // not uniformly random unless call many many times

        // view the discuss after an hour

        // to reduce times call rand7()
        // make function like ax+y; x=[0,6], y=[0,6]
        // a=?
        // a=7 to make sure 7x+y -> [0,48] be 1-1 onto
        // and we need [0,9]
        // [0,39]%10 can make uniformly random on [0,9]
        // roll again 7x+y if we get [40,48]

        int rand = 7 * (rand7() - 1) + (rand7() - 1);
        if (rand < 40)
        {
            return rand % 10 + 1;
        }
        else
        {
            return rand10();
        }
    }
};