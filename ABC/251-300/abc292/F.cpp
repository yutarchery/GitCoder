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

double a, b;

int main() {
  cin >> a >> b;
  if (a < b) {
    swap(a, b);
  }

  double l = 0, r = PI * 30 / 180;
  while (r - l > 1e-9) {
    double theta = (l + r) / 2;
    double ans = b / cos(PI * 30 / 180 - theta);
    if (ans * sin(theta) <= b && ans * cos(theta) <= a) {
      r = theta;
    } else {
      l = theta;
    }
  }

  double ans = b / cos(PI * 30 / 180 - l);
  cout << std::setprecision(16) << ans << endl;

  return 0;
}