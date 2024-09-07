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
string s[105];

char c[105][105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    m = max(m, int(s[i].length()));
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      c[i][j] = '*';
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < s[i].length(); j++) {
      c[j][n - i] = s[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    int r = 0;
    for (int j = 1; j <= n; j++) {
      if (c[i][j] != '*') {
        r = j;
      }
    }

    for (int j = 0; j <= r; j++) {
      cout << c[i][j];
    }
    cout << endl;
  }

  return 0;
}
