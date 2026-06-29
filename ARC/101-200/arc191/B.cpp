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

ll n, k;
bool bits[35];

ll solve() {
  fill(bits, bits + 35, false);

  cin >> n >> k;
  int digit_cnt = 0, zero_cnt = 0;
  while (n > 0) {
    if (n % 2 == 0) {
      zero_cnt++;
    }

    bits[digit_cnt] = n % 2;
    n /= 2;
    digit_cnt++;
  }

  if (k > (1ll << zero_cnt)) {
    return -1;
  }

  k--;
  for (int i = 0; i <= digit_cnt - 2; i++) {
    if (bits[i]) {
      continue;
    }

    if (k % 2 == 1) {
      bits[i] = true;
    }
    k /= 2;
  }

  ll ans = 0;
  for (int i = 0; i <= digit_cnt - 1; i++) {
    if (bits[i]) {
      ans += (1ll << i);
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
