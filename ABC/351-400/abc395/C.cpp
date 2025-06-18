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

int n, a[int(2e5 + 5)];
vector<int> v[int(1e6 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }

  int ans = 1e9;
  for (int i = 1; i <= int(1e6); i++) {
    if (v[i].size() >= 2) {
      for (int j = 0; j + 1 < v[i].size(); j++) {
        ans = min(ans, v[i][j + 1] - v[i][j] + 1);
      }
    }
  }

  cout << (ans == int(1e9) ? -1 : ans) << endl;

  return 0;
}
