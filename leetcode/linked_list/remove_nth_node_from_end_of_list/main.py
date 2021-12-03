from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def removeNthFromEnd(head: Optional[ListNode], n: int) -> Optional[ListNode]:
    if head.next == None:
        return None

    slow = fast = head

    for _ in range(n+1):
        fast = fast.next

    while fast:
        fast = fast.next
        slow = slow.next

    slow.next = slow.next.next

    return head


if __name__ == '__main__':
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    head2 = ListNode(1)
    head3 = ListNode(1, ListNode(2))
    new = removeNthFromEnd(head3, 1)

    while new:
        print(new.val)
        new = new.next
