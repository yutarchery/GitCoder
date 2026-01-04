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

int n;
int a[int(2e5 + 5)], b[int(2e5 + 5)];
Pii p[int(2e5 + 5)];

int ans[int(2e5 + 5)];
set<int> st[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    p[i] = {a[i], b[i]};
  }
  sort(p + 1, p + n + 1);

  p[0] = {-1, -1};
  queue<int> que;

  for (int i = 1; i <= n; i++) {
    if (p[i].first != p[i - 1].first) {
      while (!que.empty()) {
        int q = que.front();
        que.pop();
        st[ans[q]].insert(p[q].second);
      }
    }

    int ok = 0, ng = n + 1;
    while (ng - ok > 1) {
      int now = (ok + ng) / 2;
      if (st[now].empty()) {
        ng = now;
        continue;
      }

      auto iter = st[now].begin();
      if ((*iter) < p[i].second) {
        ok = now;
      } else {
        ng = now;
      }
    }

    ans[i] = ok + 1;
    que.push(i);
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, ans[i]);
  }
  cout << res << endl;

  return 0;
}
