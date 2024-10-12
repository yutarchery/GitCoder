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

int n, m, shirt[1005][2];
char s[1005];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = n; i >= 1; i--) {
    if (s[i] == '1') {
      shirt[i][0] = shirt[i + 1][0] + 1;
      shirt[i][1] = shirt[i + 1][1];
    } else if (s[i] == '2') {
      shirt[i][0] = shirt[i + 1][0];
      shirt[i][1] = shirt[i + 1][1] + 1;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, max(shirt[i][0] - m, 0) + shirt[i][1]);
  }
  cout << ans << endl;

  return 0;
}
