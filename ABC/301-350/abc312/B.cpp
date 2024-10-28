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
char s[115][115];
vector<Pii> ans;

bool solve(int start_i, int start_j) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (s[start_i + i][start_j + j] != '#') {
        return false;
      }
      if (s[start_i + i][start_j + 3] != '.') {
        return false;
      }
      if (s[start_i + 3][start_j + j] != '.') {
        return false;
      }
    }
  }

  for (int i = 6; i < 9; i++) {
    for (int j = 6; j < 9; j++) {
      if (s[start_i + i][start_j + j] != '#') {
        return false;
      }
      if (s[start_i + i][start_j + 5] != '.') {
        return false;
      }
      if (s[start_i + 5][start_j + j] != '.') {
        return false;
      }
      if (s[start_i + 5][start_j + 5] != '.') {
        return false;
      }
    }
  }

  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (solve(i, j)) {
        cout << i << " " << j << endl;
      }
    }
  }

  return 0;
}
