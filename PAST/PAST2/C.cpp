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
char s[55][105], t[55][105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      cin >> s[i][j];
      t[i][j] = s[i][j];
    }
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = 2; j <= 2 * n - 2; j++) {
      if (t[i][j] == '#') {
        if (t[i + 1][j - 1] == 'X' || t[i + 1][j] == 'X' ||
            t[i + 1][j + 1] == 'X') {
          t[i][j] = 'X';
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      cout << t[i][j];
    }
    cout << endl;
  }

  return 0;
}
