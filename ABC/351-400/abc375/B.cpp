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

int n;
ll x[int(2e5 + 5)], y[int(2e5 + 5)];

double ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 1; i <= n + 1; i++) {
    ans += sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) +
                (y[i] - y[i - 1]) * (y[i] - y[i - 1]));
  }
  cout << fixed << setprecision(32) << ans << endl;

  return 0;
}
