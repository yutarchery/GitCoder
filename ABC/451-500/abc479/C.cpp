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
ll w, a[25], b[25];

ll ans = 0;

void solve(int idx) {
  ll sum_a = 0, sum_b = 0;
  for (int i = 0; i < n; i++) {
    if (idx % 2 == 1) {
      sum_a += a[i];
      sum_b += b[i];
    }
    idx /= 2;
  }

  if (sum_b <= w) {
    ans = max(ans, sum_a);
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i < (1 << n); i++) {
    solve(i);
  }
  cout << ans << '\n';

  return 0;
}
