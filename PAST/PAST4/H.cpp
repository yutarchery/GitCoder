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

int n, m, k;
string s[30];

int ans = 1;
int cnt[10];

void solve(int start_i, int start_j, int l) {
  fill(cnt, cnt + 10, 0);

  for (int i = start_i; i < start_i + l; i++) {
    for (int j = start_j; j < start_j + l; j++) {
      if (i >= n || j >= m) {
        return;
      }
      cnt[s[i][j] - '0']++;
    }
  }

  sort(cnt, cnt + 10, greater<int>());

  if (cnt[0] + k >= l * l) {
    ans = max(ans, l);
  }
  return;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int l = 1; l <= min(n, m); l++) {
        solve(i, j, l);
      }
    }
  }
  cout << ans << endl;

  return 0;
}