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

ll n, a, b, p, q, r, s;

bool check1(ll i, ll j) {
  ll ki = i - a, kj = j - b;
  if (ki != kj) {
    return false;
  }

  if (max(1 - a, 1 - b) <= ki && ki <= min(n - a, n - b)) {
    return true;
  } else {
    return false;
  }
}

bool check2(ll i, ll j) {
  ll ki = i - a, kj = b - j;
  if (ki != kj) {
    return false;
  }

  if (max(1 - a, b - n) <= ki && ki <= min(n - a, b - 1)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  cin >> n >> a >> b;
  cin >> p >> q >> r >> s;

  for (ll i = p; i <= q; i++) {
    for (ll j = r; j <= s; j++) {
      if (check1(i, j) || check2(i, j)) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << endl;
  }

  return 0;
}
