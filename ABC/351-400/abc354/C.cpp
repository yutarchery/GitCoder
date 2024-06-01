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

int n, a[int(2e5 + 5)], c[int(2e5 + 5)];
Pii pa[int(2e5 + 5)];
priority_queue<Pii> que;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> c[i];
    pa[i] = {a[i], i};
  }
  sort(pa + 1, pa + n + 1);

  for (int i = 1; i <= n; i++) {
    int now = pa[i].second;
    que.push({c[now], now});

    while (!que.empty()) {
      Pii q = que.top();
      if (c[now] < q.first) {
        que.pop();
      } else {
        break;
      }
    }
  }
  vector<int> ans;
  while (!que.empty()) {
    Pii q = que.top();
    que.pop();
    ans.push_back(q.second);
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
