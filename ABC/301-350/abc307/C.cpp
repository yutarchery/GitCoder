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

int ha, hb, hx, wa, wb, wx;
char a[15][15], b[15][15], x[15][15];

map<Pii, bool> visited;
bool now[40][40];

bool judge(int xi, int xj) {
  for (int i = 1; i <= hx; i++) {
    for (int j = 1; j <= wx; j++) {
      if (now[i + xi][j + xj] && x[i][j] == '.') {
        return false;
      }
      if (!now[i + xi][j + xj] && x[i][j] == '#') {
        return false;
      }
    }
  }

  return true;
}

bool judge(int ai, int aj, int bi, int bj, int x_cnt) {
  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= 30; j++) {
      now[i][j] = false;
    }
  }

  for (int i = 1; i <= ha; i++) {
    for (int j = 1; j <= wa; j++) {
      if (a[i][j] == '#') {
        now[i + ai][j + aj] = true;
      }
    }
  }
  for (int i = 1; i <= hb; i++) {
    for (int j = 1; j <= wb; j++) {
      if (b[i][j] == '#') {
        now[i + bi][j + bj] = true;
      }
    }
  }

  int cnt = 0;
  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= 30; j++) {
      if (now[i][j]) {
        cnt++;
      }
    }
  }

  if (cnt != x_cnt) {
    return false;
  }

  for (int i = 1; i + hx <= 30; i++) {
    for (int j = 1; j + wx <= 30; j++) {
      if (judge(i, j)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> ha >> wa;
  for (int i = 1; i <= ha; i++) {
    for (int j = 1; j <= wa; j++) {
      cin >> a[i][j];
    }
  }
  cin >> hb >> wb;
  for (int i = 1; i <= hb; i++) {
    for (int j = 1; j <= wb; j++) {
      cin >> b[i][j];
    }
  }
  cin >> hx >> wx;
  int x_cnt = 0;
  for (int i = 1; i <= hx; i++) {
    for (int j = 1; j <= wx; j++) {
      cin >> x[i][j];
      if (x[i][j] == '#') {
        x_cnt++;
      }
    }
  }

  for (int i = 1; i + ha <= 30; i++) {
    for (int j = 1; j + wa <= 30; j++) {
      for (int ii = 1; ii + hb <= 30; ii++) {
        for (int jj = 1; jj + wb <= 30; jj++) {
          if (!visited[{i - ii, j - jj}]) {
            visited[{i - ii, j - jj}] = true;
          }
          if (judge(i, j, ii, jj, x_cnt)) {
            Yes();
            return 0;
          }
        }
      }
    }
  }
  No();

  return 0;
}
