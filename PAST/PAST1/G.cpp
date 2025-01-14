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
ll a[15][15], ans = -1e16;

void solve(int num) {
  vector<int> now[3] = {};
  for (int i = 1; i <= n; i++) {
    now[num % 3].push_back(i);
    num /= 3;
  }

  ll res = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < now[i].size(); j++) {
      for (int k = j + 1; k < now[i].size(); k++) {
        res += a[now[i][j]][now[i][k]];
      }
    }
  }

  ans = max(ans, res);
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < pow(3, n); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}
