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

int main() {
  double a, b;
  cin >> a >> b;

  double ok = 0, ng = 1;
  while (ng - ok > 1e-10) {
    double now = (ok + ng) / 2;
    double now_a = now * a, now_b = now * b;

    if (now_a * now_a + now_b * now_b <= double(1)) {
      ok = now;
    } else {
      ng = now;
    }
  }

  cout << fixed << setprecision(10) << ok * a << " " << ok * b << endl;

  return 0;
}
