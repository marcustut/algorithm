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

ListNode* middleNode(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

struct testcase {
  ListNode* head;
  ListNode* expected;
};

void test() {
  vector<testcase> testcases{
    (testcase) {new ListNode(1, new ListNode(1, new ListNode(2))), new ListNode(1, new ListNode(2))},
    (testcase) {new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3))))), new ListNode(1, new ListNode(2, new ListNode(3)))},
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
