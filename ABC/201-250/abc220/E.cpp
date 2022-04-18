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

ll myPow(ll a, ll n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return myPow(a * a % mod2, n / 2);
  } else {
    return a * myPow(a * a % mod2, n / 2) % mod2;
  }
}

ll n, d, ans = 0;

void calc(ll numOfParent, ll depth) {
  ll sum = 0;
  if (d <= depth) {
    sum += myPow(2, d + 1);
  }

  if (depth * 2 >= d) {
    ll maxJ = min(depth, d - 1), minJ = max((ll)1, d - depth);
    sum += myPow(2, d - 1) * (maxJ - minJ + 1);
    sum %= mod2;
  }

  ans += numOfParent * (sum % mod2);
  ans %= mod2;

  return;
}

int main() {
  cin >> n >> d;

  for (int i = 0; i < n; i++) {
    calc(myPow(2, i), n - i - 1);
  }
  cout << ans << endl;

  return 0;
}