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

double solve(double x) { return a * pow(x, 5) + b * x + c; }

int main() {
  cin >> a >> b >> c;
  double l = 1, r = 2;

  while (r - l > 1e-10) {
    double mid = (l + r) / 2;
    double s_l = solve(l), s_mid = solve(mid);

    if (s_l * s_mid <= 0) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << setprecision(32) << l << endl;

  return 0;
}