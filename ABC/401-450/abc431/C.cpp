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

int n, m, k;
int h[int(2e5 + 5)], b[int(2e5 + 5)];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  sort(h + 1, h + n + 1, greater<int>());
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(b + 1, b + m + 1);

  int now_b = m, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (h[i] > b[now_b]) {
      continue;
    } else {
      ans++;
      now_b--;
    }
  }

  (ans >= k) ? Yes() : No();

  return 0;
}
