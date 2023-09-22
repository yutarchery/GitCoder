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

pair<double, double> p[4];

bool solve1() {
  double a = p[0].first, b = p[0].second, c = p[2].first, d = p[2].second;

  double res1 = (b - d) * p[1].first - (a - c) * p[1].second + a * d - b * c;
  double res2 = (b - d) * p[3].first - (a - c) * p[3].second + a * d - b * c;

  return res1 * res2 < 0;
}

bool solve2() {
  double a = p[1].first, b = p[1].second, c = p[3].first, d = p[3].second;

  double res1 = (b - d) * p[0].first - (a - c) * p[0].second + a * d - b * c;
  double res2 = (b - d) * p[2].first - (a - c) * p[2].second + a * d - b * c;

  return res1 * res2 < 0;
}

int main() {
  for (int i = 0; i < 4; i++) {
    cin >> p[i].first >> p[i].second;
  }

  if (solve1() && solve2()) {
    Yes();
  } else {
    No();
  }

  return 0;
}