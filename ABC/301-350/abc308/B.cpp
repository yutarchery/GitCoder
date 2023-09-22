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

int n, m, p[105];
string c[105], d[105];
map<string, int> price;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> d[i];
  }
  for (int i = 0; i <= m; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= m; i++) {
    price[d[i]] = p[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (price[c[i]] == 0) {
      ans += p[0];
    } else {
      ans += price[c[i]];
    }
  }

  cout << ans << endl;

  return 0;
}