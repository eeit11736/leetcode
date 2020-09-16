#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
class trieNode
{
public:
    // using unorderedmap may be faster
    // < previous letter , pointer to previous letter >
    vector<pair<char, trieNode *>> pairs;
    // is the first letter of a word
    bool front;

    trieNode(){};
    trieNode(bool isFront) : front(isFront){};

    trieNode *FindLetterPointer(char letter)
    {
        for (auto p : pairs)
        {
            if (p.first == letter)
            {
                return p.second;
            }
        }
        return nullptr;
    }
};

class StreamChecker
{
public:
    trieNode *curr;
    trieNode *dummyHead;
    int maxWordLength;
    deque<char> queries;

    StreamChecker(vector<string> &words)
    {
        maxWordLength = 0;
        curr = dummyHead = new trieNode(false);
        for (string word : words)
        {
            curr = dummyHead;
            if (word.length() > maxWordLength)
            {
                maxWordLength = word.length();
            }

            // the key to the problem
            reverse(word.begin(), word.end());

            for (int i = 0; i < word.length(); ++i)
            {
                char letter = word[i];
                trieNode *ptr = curr->FindLetterPointer(letter);

                bool front = (i == word.length() - 1);
                if (ptr == nullptr)
                {
                    trieNode *newPtr = new trieNode(front);
                    curr->pairs.push_back(make_pair(letter, newPtr));
                    curr = newPtr;
                }
                else
                {
                    curr = ptr;

                    // break under situation such as "aaaaaabb" after "aabb"
                    if (curr->front == true)
                    {
                        break;
                    }

                    // set front=true under situation such as "abb" after "aabb"
                    if (front == true)
                    {
                        curr->front = true;
                    }
                }
            }
        }
    }

    bool query(char letter)
    {
        queries.push_back(letter);
        curr = dummyHead;

        int findCount = 1;
        while (findCount <= maxWordLength && findCount <= queries.size())
        {

            // find the letter is front or not from the latest input
            curr = curr->FindLetterPointer(queries[queries.size() - findCount]);

            if (curr == nullptr)
            {
                return false;
            }

            if (curr->front)
            {
                return true;
            }
            ++findCount;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */