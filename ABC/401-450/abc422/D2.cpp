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

int n, k;
vector<int> ans[21];

int main() {
  cin >> n >> k;
  ans[0] = {k};
  for (int i = 1; i <= n; i++) {
    for (int j : ans[i - 1]) {
      if (j % 2 == 0) {
        ans[i].push_back(j / 2);
        ans[i].push_back(j / 2);
      } else {
        ans[i].push_back(j / 2 + 1);
        ans[i].push_back(j / 2);
      }
    }
  }

  if (k % (1 << n) == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
  for (int i = 0; i < ans[n].size(); i++) {
    cout << ans[n][i] << (i == ans[n].size() - 1 ? '\n' : ' ');
  }

  return 0;
}
