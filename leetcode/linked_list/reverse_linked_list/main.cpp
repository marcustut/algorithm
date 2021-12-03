#include <stack>
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    ListNode head = ListNode(1);
    ListNode *curr = &head;
    for (int i = 2; i <= 5; i++)
    {
        ListNode next = ListNode(i);
        curr->next = &next;
        curr = curr->next;
    }

    reverseList(&head);
}
