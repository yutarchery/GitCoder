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

int n, w, q;
ll x[int(2e5 + 5)], y[int(2e5 + 5)], t[int(2e5 + 5)], a[int(2e5 + 5)];

vector<Pli> locs[int(2e5 + 5)];
ll ans[int(2e5 + 5)];

int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];

    locs[x[i]].push_back({y[i], i});
  }

  int min_size = 1e9;
  for (int i = 1; i <= w; i++) {
    min_size = min(min_size, int(locs[i].size()));

    if (!locs[i].empty()) {
      sort(locs[i].begin(), locs[i].end());
    }
  }

  fill(ans, ans + n + 1, 1e16);
  ll last_ans = 0;
  for (int j = 1; j <= min_size; j++) {
    ll now_ans = last_ans + 1;
    for (int i = 1; i <= w; i++) {
      now_ans = max(now_ans, locs[i][j - 1].first);
    }

    last_ans = now_ans;
    for (int i = 1; i <= w; i++) {
      ans[locs[i][j - 1].second] = last_ans;
    }
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t[i] >> a[i];

    if (ans[a[i]] > t[i]) {
      Yes();
    } else {
      No();
    }
  }

  return 0;
}
