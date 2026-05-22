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
ll k, a[int(2e5 + 5)];

bool judge(ll now) {
  ll sum = 0;
  for (ll i = 1; i <= n; i++) {
    if (now <= a[i]) {
      continue;
    }

    sum += (now - a[i] - 1) / i + 1;
    if (sum > k) {
      return false;
    }
  }

  return true;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll ok = 0, ng = ll(4e18);
  while (ng - ok > 1) {
    ll mid = (ng + ok) / 2;

    if (judge(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << ok << '\n';

  return 0;
}
