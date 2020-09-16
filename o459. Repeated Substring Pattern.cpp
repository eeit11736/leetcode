#include <string>
using namespace std;
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // initial idea: int  len=strlen(input)
        // for all p make len%p==0
        //     let q=len/p;
        //     bool check = s[0~q-1]==s[q~2*q-1]==...==s[(p-1)*q~p*q-1]
        //     if(check==true)return true
    }
};