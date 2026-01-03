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

ll calc_digit(ll num) {
  ll digit = 0;
  while (num > 0) {
    digit++;
    num /= 10;
  }
  return digit;
}

ll my_pow(ll a, ll n) {
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= a;
  }
  return ans;
}

int n;
ll a[int(2e5 + 5)];
Pll d_a[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d_a[i] = {calc_digit(a[i]), a[i]};
  }
  sort(d_a + 1, d_a + n + 1, greater<Pll>());

  ll ans1 = d_a[1].second * my_pow(10, d_a[2].first) + d_a[2].second;
  ll ans2 = d_a[2].second * my_pow(10, d_a[1].first) + d_a[1].second;
  cout << max(ans1, ans2) << endl;

  return 0;
}
