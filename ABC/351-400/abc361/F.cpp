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

ll n, ans = 1;
map<ll, bool> visited;

bool is_prime(ll num) {
  if (num == 1) {
    return false;
  }
  for (ll i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a, n / 2);
  } else {
    return a * my_pow(a, n - 1);
  }
}

int main() {
  cin >> n;

  for (ll i = 2; i <= 60; i++) {
    ll l = 1, r = pow(10, double(18) / double(i)) + 1;

    while (r - l > 1) {
      ll mid = (l + r) / 2;
      ll p = my_pow(mid, i);

      if (p <= n) {
        l = mid;
      } else {
        r = mid;
      }
    }

    if (l == 1) {
      continue;
    }
    if (is_prime(i)) {
      ans += l - 1;
    } else {
      for (int j = 2; j <= i; j++) {
        if (!is_prime(j)) {
          continue;
        }
        for (int k = j + 1; j * k <= i; k++) {
          if (!is_prime(k)) {
            continue;
          }
          if (j * k == i) {
            ans -= l - 1;
          }

          if (i % (j * k) == 0 && is_prime(i / (j * k)) && k < i / (j * k)) {
            ans += l - 1;
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
