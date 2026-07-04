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

ll a[10];

ll solve() {
  vector<int> elems;
  for (int i = 1; i <= 9; i++) {
    cin >> a[i];

    if (a[i] >= 1) {
      elems.emplace_back(i);
    }
  }

  if (a[5] <= 1) {
    if (elems.size() <= 1 || elems.size() >= 3) {
      return 0;
    }

    if (elems[0] + elems[1] == 10) {
      return 1;
    } else {
      return 0;
    }
  }

  ll cnt = 0;
  for (int i = 1; i <= 9; i++) {
    if (i == 5) {
      continue;
    }
    cnt += a[i];
  }

  return max(0ll, (a[5] - 1) - cnt);
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
