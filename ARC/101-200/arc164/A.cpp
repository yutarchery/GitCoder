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

ll pows[40];

bool solve(ll n, ll k) {
  ll cnt = 0, rest = n;
  for (int i = 39; i >= 0; i--) {
    cnt += rest / pows[i];
    rest %= pows[i];
  }

  if (cnt <= k && (k - cnt) % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int t;
  cin >> t;

  pows[0] = 1;
  for (int i = 1; i < 40; i++) {
    pows[i] = pows[i - 1] * 3;
  }

  while (t--) {
    ll n, k;
    cin >> n >> k;
    solve(n, k) ? Yes() : No();
  }

  return 0;
}
