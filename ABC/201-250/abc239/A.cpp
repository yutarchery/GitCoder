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

double h;

int main() {
  cin >> h;
  double ok = 0, ng = 1e16;
  while (ng - ok > 1e-6) {
    double mid = (ok + ng) / 2;

    if (mid * mid <= h * (h + 12800000)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << fixed << setprecision(10) << ok << endl;

  return 0;
}
