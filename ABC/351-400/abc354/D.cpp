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

ll x[2], y[2];

ll sum_1[5] = {0, 2, 3, 3, 4}, sum_2[5] = {0, 1, 3, 4, 4};

ll solve(ll a, ll b) {
  ll x_1 = (a / 4) * sum_1[4] + sum_1[a % 4];
  ll x_2 = (a / 4) * sum_2[4] + sum_2[a % 4];

  return x_1 * ((b + 1) / 2) + x_2 * (b / 2);
}

int main() {
  cin >> x[0] >> y[0] >> x[1] >> y[1];
  for (int i = 0; i < 2; i++) {
    x[i] += ll(2e9);
    y[i] += ll(2e9);
  }

  cout << solve(x[1], y[1]) - solve(x[0], y[1]) - solve(x[1], y[0]) +
              solve(x[0], y[0])
       << endl;

  return 0;
}
