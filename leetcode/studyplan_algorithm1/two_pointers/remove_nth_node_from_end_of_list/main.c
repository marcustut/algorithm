#include <stddef.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *cursor = head;
    int count = 0;

    while (cursor->next != NULL)
    {
        count++;
        cursor = cursor->next;
    }

    n = count - n;

    if (count == 0)
    {
        head->next = NULL;
        return head;
    }

    if (n < 0)
    {
        head = head->next;
        return head;
    }

    struct ListNode *new_cursor = head;

    while (n != 0)
    {
        n--;
        new_cursor = new_cursor->next;
    }

    new_cursor->next = new_cursor->next->next;

    return head;
}

int main(void)
{
    struct ListNode head = {.val = 1, .next = &(struct ListNode){.val = 2, .next = NULL}};
    removeNthFromEnd(&head, 2);
}