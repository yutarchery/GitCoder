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

int n, q;
ll a[int(1e5 + 5)], sum_a[int(1e5 + 5)], sum_b[int(1e5 + 5)];
ll l, r;

ll idxes[int(1e5 + 5)];

ll solve(ll num) {
  int ok = 0, ng = n + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (idxes[mid] <= num) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  ll ans = sum_b[ok], rest = num - idxes[ok];
  ans += sum_a[rest];
  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum_a[i] = sum_a[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    sum_b[i] = sum_b[i - 1] + sum_a[i];
  }

  for (ll i = 1; i <= n; i++) {
    idxes[i] = idxes[i - 1] + i;
  }

  while (q--) {
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << '\n';
  }

  return 0;
}
