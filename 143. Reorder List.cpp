#include <stack>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Genius Merge Function
// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3430/discuss/45003/A-concise-O(n)-time-O(1)-in-place-solution

// time complexity: O(n)
// space complexity: O(n)
class Solution
{
public:
    void reorderList(ListNode *head)
    {

        // 0~2 nodes
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            return;
        }
        if (head->next->next == nullptr)
        {
            return;
        }
        ListNode *ptr1 = head;
        ListNode *ptr2 = head->next;

        // find mid: O(n)
        while (ptr2 != nullptr && ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }

        // ptr1=head; ptr2=mid->next
        ptr2 = ptr1->next;
        ptr1->next = nullptr;
        ptr1 = head;

        // push firsthalf(ptr1 to ptr2.previous) to queue: O(n)
        queue<ListNode *> q;
        while (ptr1 != nullptr)
        {
            ListNode *nextPtr = ptr1->next;
            q.push(ptr1);
            ptr1 = nextPtr;
        }

        // push secondhalf(ptr2 to end) to stack: O(n)
        stack<ListNode *> s;
        while (ptr2 != nullptr)
        {
            ListNode *nextPtr = ptr2->next;
            s.push(ptr2);
            ptr2 = nextPtr;
        }

        // merge: O(n)
        // q.front -> s.top -> q.front -> ...
        ListNode *curr = q.front();
        q.pop();
        while (!(q.empty() || s.empty()))
        {
            ptr1 = s.top();
            ptr2 = q.front();
            curr->next = ptr1;
            ptr1->next = ptr2;
            curr = ptr2;
            q.pop();
            s.pop();
        }
        // check whether s is empty
        if (!s.empty())
        {
            ptr1 = s.top();
            curr->next = ptr1;
            curr = curr->next;
            s.pop();
        }
        curr->next = nullptr;
        return;
    }
};