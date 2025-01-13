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
  }
  return my_gcd(b, a % b);
}

void solve(ll a, ll b, ll g) {
  double ans = 1;
  ans *= a / g;
  ans *= b;

  if (ans > 3e18) {
    cout << "Large" << endl;
    return;
  }

  if (a / g * b <= ll(1e18)) {
    cout << a / g * b << endl;
  } else {
    cout << "Large" << endl;
  }

  return;
}

int main() {
  ll a, b;
  cin >> a >> b;

  ll g = my_gcd(a, b);
  solve(a, b, g);

  return 0;
}
