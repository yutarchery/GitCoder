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

int n, m;
ll k, x, y, a[int(2e5 + 5)], b[int(2e5 + 5)];

ll sum_a[int(2e5 + 5)], sum_b[int(2e5 + 5)], cnt_b[int(2e5 + 5)];

int solve(int idx) {
  if (y < cnt_b[idx]) {
    return 0;
  }

  ll rest = (x + y * k) - sum_b[idx];
  int ok = 0, ng = n + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (sum_a[mid] <= rest) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok + idx;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> k;
  cin >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    sum_a[i] = sum_a[i - 1] + a[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= m; i++) {
    sum_b[i] = sum_b[i - 1] + b[i];
    cnt_b[i] = cnt_b[i - 1] + (b[i] + k - 1) / k;
  }

  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans = max(ans, solve(i));
  }
  cout << ans << '\n';

  return 0;
}
