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

int cnt = 0;
char p[3][4][4];

void rotate(int i) {
  char tmp[4][4] = {};
  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 4; k++) {
      tmp[k][3 - j] = p[i][j][k];
    }
  }

  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 4; k++) {
      p[i][j][k] = tmp[j][k];
    }
  }
  return;
}

bool solve(vector<Pii> loc) {
  bool ans[4][4] = {};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int j_ = j + loc[i].first, k_ = k + loc[i].second;
        if (0 <= j_ && j_ < 4 && 0 <= k_ && k_ < 4 && p[i][j_][k_] == '#') {
          ans[j][k] = true;
        }
      }
    }
  }

  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 4; k++) {
      if (!ans[j][k]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        cin >> p[i][j][k];
        if (p[i][j][k] == '#') {
          cnt++;
        }
      }
    }
  }

  if (cnt != 16) {
    No();
    return 0;
  }

  bool ans = false;
  for (int r2 = 0; r2 < 4; r2++) {
    for (int r3 = 0; r3 < 4; r3++) {
      for (int i1 = -3; i1 < 4; i1++) {
        for (int j1 = -3; j1 < 4; j1++) {
          for (int i2 = -3; i2 < 4; i2++) {
            for (int j2 = -3; j2 < 4; j2++) {
              for (int i3 = -3; i3 < 4; i3++) {
                for (int j3 = -3; j3 < 4; j3++) {
                  if (solve({{i1, j1}, {i2, j2}, {i3, j3}})) {
                    Yes();
                    return 0;
                  }
                }
              }
            }
          }
        }
      }

      rotate(2);
    }
    rotate(1);
  }

  No();

  return 0;
}
