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
string s[int(2e5 + 5)];
ll ans[int(2e5 + 5)];

const ll mods[3] = {MOD, MOD2, MOD3};
map<array<ll, 3>, bool> visited;
map<array<ll, 3>, ll> cost;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    ans[i] = ll(s[i].length());

    array<ll, 3> now = {};
    for (int j = 0; j < s[i].length(); j++) {
      for (int k = 0; k < 3; k++) {
        now[k] = (now[k] * ll(1e9) + s[i][j]) % mods[k];
      }

      if (visited[now]) {
        ans[i] = min(ans[i], cost[now] + ll(s[i].length()) - (j + 1));
        cost[now] = min(cost[now], ll(s[i].length() - (j + 1)));
      } else {
        visited[now] = true;
        cost[now] = ll(s[i].length()) - (j + 1);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
