// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut cursor = head.clone().unwrap();
        let mut count: usize = 0;

        while cursor.next != None {
            count += 1;
            cursor = cursor.next.unwrap();
        }

        let mut mid = if count % 2 == 0 {
            count / 2
        } else {
            (count / 2) + 1
        };

        let mut new_cursor = head.unwrap();

        while mid != 0 {
            mid -= 1;
            new_cursor = new_cursor.next.unwrap();
        }

        Some(new_cursor)
    }
}
