/**
 * @file 1.18.merge.k.sorted.lists
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  ListNode *m2(ListNode *a, ListNode *b) {
    ListNode *d = new ListNode(0), *c = d;
    while (a && b) {
      int x = a->val, y = b->val;
      if (x < y) c->next = new ListNode(x), a = a->next;
      else
        c->next = new ListNode(y), b = b->next;
      c = c->next;
    }
    if (a) c->next = a;
    else if (b)
      c->next = b;

    return d->next;
  }

 public:
  ListNode *mergeKLists(vector<ListNode *> &l) {
    if (l.empty()) return 0;
    int n = l.size(), j = 0;

    while (n > 1) {
      for (int i = 0; i + 1 < n; i += 2) {
        l[j++] = m2(l[i], l[i + 1]);
      }
      if (n & 1) l[j++] = l[n - 1];
      n = j, j = 0;
    }

    return l[0];
  }
};