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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
ll m;
ll dp[10][int(1e5 + 5)];
vector<Pii> ans;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = (dp[i][j - 1] * 10 + i) % m;

      if (dp[i][j] == 0) {
        ans.push_back({j, i});
      }
    }
  }
  sort(ans.begin(), ans.end(), greater<Pii>());

  if (ans.size() == 0) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < ans[0].first; i++) {
      cout << ans[0].second;
    }
    cout << endl;
  }

  return 0;
}