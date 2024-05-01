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

int n, m, l, a[int(1e5 + 5)];
Pii b[int(1e5 + 5)];

map<int, bool> used[int(1e5 + 5)];

int main() {
  cin >> n >> m >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(b + 1, b + m + 1, greater<Pii>());
  for (int i = 0; i < l; i++) {
    int c, d;
    cin >> c >> d;
    used[c][d] = true;
    used[d][c] = true;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!used[i][b[j].second]) {
        ans = max(a[i] + b[j].first, ans);
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
