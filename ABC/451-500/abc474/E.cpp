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
ll a[int(2e5 + 5)], b[int(2e5 + 5)];
Pli diff_idx[int(2e5 + 5)];

bool bought[int(2e5 + 5)];

ll solve() {
  cin >> n;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    ans += a[i];
    diff_idx[i] = {a[i] - b[i], i};
  }
  sort(a + 1, a + n + 1);
  sort(diff_idx + 1, diff_idx + n + 1, greater<Pli>());

  int rest = n;
  for (int i = 1; i <= n; i++) {
    if (rest >= 2) {
      ans -= diff_idx[i].first;
      rest -= 2;
    } else {
      if (diff_idx[i].first >= a[1] * (2 - rest)) {
        ans = ans + a[1] * (2 - rest) - diff_idx[i].first;
        rest = 0;
      } else {
        break;
      }
    }
  }

  return ans;
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
