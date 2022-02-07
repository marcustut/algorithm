#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
  ListNode* curr = head;

  // exit when pointing at NULL
  while (curr != nullptr) {
    // [next elem is not NULL] and [curr elem is equals to next elem]
    while (curr->next != nullptr && curr->val == curr->next->val) {
      curr->next = curr->next->next;
    }
    // move to next elem
    curr = curr->next;
  }

  return head;
}

struct testcase {
  ListNode* head;
  ListNode* expected;
};

void test() {
  vector<testcase> testcases{
    // [1,1,2] [1,2]
    (testcase) {new ListNode(1, new ListNode(1, new ListNode(2))), new ListNode(1, new ListNode(2))}, 
    // [1,1,2,3,3] [1,2,3]
    (testcase) {new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3))))), new ListNode(1, new ListNode(2, new ListNode(3)))},
    // [1,1,1] [1]
    (testcase) {new ListNode(1, new ListNode(1, new ListNode(1))), new ListNode(1)}, 
  };
  for (int i = 0; i < testcases.size(); i++) {
    ListNode* result = deleteDuplicates(testcases[i].head);
    while (result != NULL) {
      assert(testcases[i].expected->val == result->val);
      result = result->next;
      testcases[i].expected = testcases[i].expected->next;
    }
    cout << "test" << i + 1 << ": PASSED\n";
  }
}

int main() {
  test();
}

