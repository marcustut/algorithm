from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next


# Time Complexity: O(n)
# Space Complexity: O(1)
def reverseList(head: Optional[ListNode]) -> Optional[ListNode]:
    prev, curr = None, head
    while curr:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
    return prev


if __name__ == "__main__":
    head = ListNode(5, ListNode(4, ListNode(3, ListNode(2, ListNode(1)))))
    reversed = reverseList(head)

    while reversed != None:
        print(reversed.val)
        reversed = reversed.next
