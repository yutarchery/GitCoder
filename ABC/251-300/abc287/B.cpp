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

int n, m;
string s[1005], t[1005];
int ans = 0;
bool flag[1005];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int j = 0; j < m; j++) {
    cin >> t[j];

    for (int i = 0; i < n; i++) {
      if (s[i][3] == t[j][0] && s[i][4] == t[j][1] && s[i][5] == t[j][2]) {
        flag[i] = true;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (flag[i]) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}