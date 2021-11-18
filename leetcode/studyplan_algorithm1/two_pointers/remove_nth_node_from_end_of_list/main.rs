// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

struct Solution {}

impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut cursor = head.clone().unwrap();
        let mut count: i32 = 0;

        while cursor.next != None {
            count += 1;
            cursor = cursor.next.unwrap();
        }

        let mut n = count - n;

        let mut new_cursor = head.unwrap();

        while n != 0 {
            n -= 1;
            new_cursor = new_cursor.next.unwrap();
        }

        new_cursor.next = new_cursor.next.unwrap().next;

        head
    }
}

fn main() {
    let head = Box::new(ListNode::new(1));
    let mut curr = head;

    for i in 2..6 {
        curr.next = Some(Box::new(ListNode::new(i)));
        curr = curr.next.unwrap();
    }
}

#[cfg(test)]
mod tests {}
