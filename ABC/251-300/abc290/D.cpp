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

ll gcd(ll a, ll b) {
  if (a < b) {
    return gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int t;
ll n, d, k;

void solve() {
  ll g = gcd(n, d);
  cout << ((k - 1) * d + (k - 1) / (n / g)) % n << endl;

  return;
}

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> d >> k;
    solve();
  }

  return 0;
}