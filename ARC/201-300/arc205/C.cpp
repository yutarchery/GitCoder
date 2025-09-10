#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, s[int(2e5 + 5)], t[int(2e5 + 5)];

Pii ps[int(2e5 + 5)], pt[int(2e5 + 5)];

queue<int> que;
set<Pii> s_rest;
vector<int> ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> t[i];
    ps[i] = {s[i], i};
    s_rest.insert(ps[i]);

    pt[i] = {t[i], i};
  }
  sort(ps + 1, ps + n + 1);
  sort(pt + 1, pt + n + 1);

  for (int i = 1; i <= n; i++) {
    if (ps[i].second != pt[i].second) {
      No();
      return 0;
    }
  }

  s_rest.insert({0, 0});
  ps[0] = {0, 0};
  s_rest.insert({1e9 + 5, 0});
  ps[n + 1] = {int(1e9 + 5), 0};

  for (int i = 1; i <= n; i++) {
    int idx = ps[i].second;

    if (ps[i - 1].first < t[idx] && t[idx] < ps[i + 1].first) {
      que.push(idx);
    }
  }

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    auto iter = s_rest.find({s[q], q});
    if (iter == s_rest.end()) {
      continue;
    }

    auto before_iter = iter, after_iter = iter;
    before_iter--;
    after_iter++;

    if ((*before_iter).first < t[q] && t[q] < (*after_iter).first) {
      ans.push_back(q);
      s_rest.erase(iter);

      if ((*before_iter).second >= 1) {
        que.push((*before_iter).second);
      }
      if ((*after_iter).second >= 1) {
        que.push((*after_iter).second);
      }
    }
  }

  Yes();
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
