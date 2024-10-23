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

int n, ans = 1e9;
string s[105];

int solve(int num) {
  int cnt[10] = {};
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      if (s[i][j] - '0' == num) {
        cnt[j]++;
      }
    }
  }

  int res = 0;
  for (int i = 0; i < 10; i++) {
    res = max(res, (cnt[i] - 1) * 10 + i);
  }

  return res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 10; i++) {
    ans = min(ans, solve(i));
  }
  cout << ans << endl;

  return 0;
}
