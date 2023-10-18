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

int n, d;
string s[105];

int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int ans = 0, now = 0;
  for (int j = 0; j < d; j++) {
    bool flag = true;

    for (int i = 0; i < n; i++) {
      if (s[i][j] == 'x') {
        flag = false;
      }
    }

    if (flag) {
      now++;
    } else {
      now = 0;
    }

    ans = max(ans, now);
  }

  cout << ans << endl;

  return 0;
}