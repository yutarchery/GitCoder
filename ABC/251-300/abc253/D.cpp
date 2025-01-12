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

ll my_gcd(ll a, ll b) {
  if (a < b) {
    swap(a, b);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

ll my_lcm(ll a, ll b) {
  ll g = my_gcd(a, b);
  return (a / g) * b;
}

ll n, a, b, ans;

int main() {
  cin >> n >> a >> b;
  ans = (1 + n) * n / 2;

  if (a <= n) {
    ans -= (a + (n / a) * a) * (n / a) / 2;
  }
  if (b <= n) {
    ans -= (b + (n / b) * b) * (n / b) / 2;
  }

  ll l = my_lcm(a, b);
  if (l <= n) {
    ans += (l + (n / l) * l) * (n / l) / 2;
  }
  cout << ans << endl;

  return 0;
}
