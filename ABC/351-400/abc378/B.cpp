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

int n, nq;
ll q[105], r[105], t[105], d[105], ans[105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> q[i] >> r[i];
  }
  cin >> nq;
  for (int i = 1; i <= nq; i++) {
    cin >> t[i] >> d[i];

    ans[i] = (d[i] / q[t[i]]) * q[t[i]] + r[t[i]];
    if (ans[i] < d[i]) {
      ans[i] += q[t[i]];
    }
  }

  for (int i = 1; i <= nq; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
