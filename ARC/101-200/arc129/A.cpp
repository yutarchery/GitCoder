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

ll n, l, r, digit[61];

ll solve(ll num) {
  ll ans = 0;
  for (int i = 0; i <= 60; i++) {
    if ((n & digit[i]) > 0) {
      if (num >= digit[i]) {
        ans += min(digit[i] * 2 - 1, num) - digit[i] + 1;
      }
    }
  }

  return ans;
}

int main() {
  cin >> n >> l >> r;

  digit[60] = 1;
  for (int i = 59; i >= 0; i--) {
    digit[i] = digit[i + 1] * 2;
  }

  cout << solve(r) - solve(l - 1) << endl;

  return 0;
}
