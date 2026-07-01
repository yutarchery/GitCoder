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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
double d[105], h[105];

bool solve(double now_h) {
  for (int i = 1; i <= n; i++) {
    if (h[i] < now_h) {
      continue;
    }
    if ((h[0] - now_h) * d[i] < (h[i] - now_h) * d[0]) {
      return false;
    }
  }

  return true;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> d[0] >> h[0];
  for (int i = 1; i <= n; i++) {
    cin >> d[i] >> h[i];
  }

  double ng = 0, ok = h[0];
  while (ok - ng > double(1e-10)) {
    double now = (ok + ng) / 2;
    if (solve(now)) {
      ok = now;
    } else {
      ng = now;
    }
  }
  cout << fixed << setprecision(32) << ok << '\n';

  return 0;
}
