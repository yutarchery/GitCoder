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
ll l[20];

int solve(int num) {
  bool plus[n] = {};
  for (int i = 0; i < n; i++) {
    if (num % 2 == 1) {
      plus[i] = true;
    }
    num /= 2;
  }

  int ans = 0;
  ll now = 0;
  for (int i = 0; i < n; i++) {
    ll next = now;
    if (plus[i]) {
      next += l[i];
    } else {
      next -= l[i];
    }

    if (now >= 0 && next < 0) {
      ans++;
    } else if (now < 0 && next >= 0) {
      ans++;
    }
    now = next;
  }

  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    ans = max(ans, solve(i));
  }
  cout << ans << '\n';

  return 0;
}
