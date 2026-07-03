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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
char s[105][105];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 2; i <= 2 * n; i++) {
    char now = '?';

    for (int j = 1; j <= n; j++) {
      if (i - j <= 0 || i - j >= n + 1) {
        continue;
      }
      if (s[j][i - j] != '?') {
        if (now == '?') {
          now = s[j][i - j];
        } else if (now != s[j][i - j]) {
          cout << -1 << '\n';
          return 0;
        }
      }
    }

    if (now == '?') {
      now = '0';
    }

    for (int j = 1; j <= n; j++) {
      if (i - j <= 0 || i - j >= n + 1) {
        continue;
      }
      s[j][i - j] = now;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << s[i][j];
    }
    cout << '\n';
  }

  return 0;
}
