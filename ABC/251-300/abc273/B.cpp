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

ll x;
int k;

ll my_round(ll x, ll num) {
  ll r1 = (x / num) * num, r2 = ((x / num) + 1) * num;

  if ((r2 - x) <= (x - r1)) {
    return r2;
  } else {
    return r1;
  }
}

int main() {
  cin >> x >> k;
  ll num = 1;
  for (int i = 1; i <= k; i++) {
    num *= 10;
    x = my_round(x, num);
  }
  cout << x << endl;

  return 0;
}
