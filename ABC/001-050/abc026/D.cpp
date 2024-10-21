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

double a, b, c;

double calc(double t) { return a * t + b * sin(c * t * PI); }

double solve(double l, double r) {
  while (abs(r - l) > 1e-10) {
    double mid = (l + r) / 2;

    if (calc(mid) <= 100) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

int main() {
  cin >> a >> b >> c;

  for (int i = 0; i <= int(1e6); i++) {
    double now_l = max(double(0), double(i * 2 - 1) / (c * 2));
    double now_r = double(i * 2 + 1) / (c * 2);

    if (calc(now_l) >= calc(now_r)) {
      continue;
    }
    if (calc(now_l) <= double(100) && double(100) <= calc(now_r)) {
      cout << fixed << setprecision(32) << solve(now_l, now_r) << endl;
      return 0;
    }
  }

  return 0;
}
