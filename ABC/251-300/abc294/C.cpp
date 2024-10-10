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

int n, m, a[int(1e5 + 5)], b[int(1e5 + 5)], c[int(2e5 + 5)];
map<int, int> ans;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[i] = a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    c[n + i] = b[i];
  }
  sort(c + 1, c + n + m + 1);
  for (int i = 1; i <= n + m; i++) {
    ans[c[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[a[i]];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[b[i]];
    if (i == m) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
