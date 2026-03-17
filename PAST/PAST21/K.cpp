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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
ll a[int(2e5 + 5)], b[int(2e5 + 5)], c[int(2e5 + 5)], d[int(2e5 + 5)],
    e[int(2e5 + 5)];

Pll d_b[int(2e5 + 5)], bd_b[int(2e5 + 5)];

int ans[int(2e5 + 5)];

// d_b[idx] <= {d_val, b_val} になる最大の idx を返す
int search_d(ll d_val, ll b_val) {
  int ok = 0, ng = n + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;

    if (d_b[mid].first < d_val) {
      ok = mid;
    } else if (d_b[mid].first == d_val && d_b[mid].second <= b_val) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return ok;
}

// bd_b[idx] <= {bd_val, b_val} になる最大の idx を返す
int search_bd(ll bd_val, ll b_val) {
  int ok = 0, ng = n + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;

    if (bd_b[mid].first < bd_val) {
      ok = mid;
    } else if (bd_b[mid].first == bd_val && bd_b[mid].second <= b_val) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return ok;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> e[i];
  }

  d_b[0] = {-1e16, 0};
  bd_b[0] = {-1e16, 0};
  for (int i = 1; i <= n; i++) {
    d_b[i] = {d[i], b[i]};
    bd_b[i] = {b[i] - d[i], b[i]};
  }
  sort(d_b + 1, d_b + n + 1);
  sort(bd_b + 1, bd_b + n + 1);

  d_b[n + 1] = {1e16, 0};
  bd_b[n + 1] = {1e16, 0};

  for (int i = 1; i <= n; i++) {
    ans[i] +=
        search_d(a[i] - e[i], a[i] + c[i]) - search_d(a[i] - e[i] - 1, 1e16);
    ans[i] +=
        search_bd(c[i] + e[i] + 1, -1e16) - search_bd(c[i] + e[i], a[i] + c[i]);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
