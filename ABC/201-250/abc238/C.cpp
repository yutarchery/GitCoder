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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

ll n, ans;

ll myPow(ll a, ll x) {
  if (x == 0) {
    return 1;
  } else if (x % 2 == 0) {
    return myPow(a * a % mod2, x / 2);
  } else {
    return myPow(a * a % mod2, x / 2) * a % mod2;
  }
}

int add(ll min, ll max) {
  ll l = (max - min + 1) % mod2;
  ll sum = l * (l + 1) % mod2;
  ans += sum * myPow(2, mod2 - 2) % mod2;
  ans %= mod2;

  return 0;
}

int main() {
  cin >> n;

  ll digit = 1;
  while (digit <= n) {
    add(digit, min(digit * 10 - 1, n));
    digit *= 10;
  }
  cout << ans << endl;

  return 0;
}