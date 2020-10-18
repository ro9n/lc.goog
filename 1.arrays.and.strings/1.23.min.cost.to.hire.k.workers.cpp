/**
 * @file 1.23.min.cost.to.hire.k.workers
 * @author Touhid Alam <taz.touhid@gmail.com>
 *
 * @date Saturday October 17 2020
 *
 * @brief 
 */

#include <bits/stdc++.h>

using namespace std;

const double INF = 1e15;

class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    int n = wage.size();
    vector<int> worker;
    for (int i = 0; i < n; ++i) worker.push_back(i);
    sort(worker.begin(), worker.end(), [&](int a, int b) {
      // return wage[a] / quality[a] < wage[b] / quality[b];
      return wage[a] * quality[b] < wage[b] * quality[a];  // simplifying equation for comparison of ints
    });

    double sum = 0.f, best = INF;
    priority_queue<int> q;  // max heap to eject higher quality workers
    // The key insight is to iterate over the ratio. Let's say we hire workers with a ratio R or lower.
    // Then, we would want to know the K workers with the lowest quality, and the sum of that quality.
    for (auto w : worker) {
      // 2
      while (q.size() >= K) sum -= q.top(), q.pop();
      // 1
      sum += 1.f * quality[w];
      q.push(quality[w]);
      if (q.size() == K) best = min(best, (double)sum * wage[w] / quality[w]);
    }

    return best;
  }
  // // TLE
  // double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
  //   int n = w.size();
  //   double best = INT_MAX;
  //   priority_queue<double> r;  // rates queue
  //   vector<double> mnr(n, 0);  // asking rates which is min

  //   for (int i = 0; i < n; ++i) {
  //     mnr[i] = (double)w[i] / q[i];
  //     r.push(-mnr[i]);
  //   }

  //   while (!r.empty()) {
  //     double rate = -r.top();
  //     r.pop();
  //     priority_queue<double> qq;

  //     for (int i = 0; i < n; ++i) {
  //       if (mnr[i] > rate) continue;
  //       else
  //         qq.push(-q[i] * rate);
  //     }
  //     if (qq.size() < K) continue;
  //     else {
  //       double current = 0;
  //       for (int i = 0; i < K; ++i) current += -qq.top(), qq.pop();
  //       best = min(best, current);
  //     }
  //   }

  //   return best;
  // }
};