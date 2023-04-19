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

int h, w;
char s[10][10], t[10][10], tmp[10][10];

int ti_start, ti_end, tj_start, tj_end;

void rotate() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tmp[i][j] = t[j][9 - i];
    }
  }

  ti_start = 10, ti_end = 0, tj_start = 10, tj_end = 0;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      t[i][j] = tmp[i][j];
      if (t[i][j] == '#') {
        ti_start = min(ti_start, i);
        ti_end = max(ti_end, i);
        tj_start = min(tj_start, j);
        tj_end = max(tj_end, j);
      }
    }
  }
  return;
}

bool check(int si_start, int sj_start) {
  for (int i = 0; i < ti_end - ti_start + 1; i++) {
    for (int j = 0; j < tj_end - tj_start + 1; j++) {
      if (i + si_start >= h || j + sj_start >= w) {
        return false;
      }

      if (t[i + ti_start][j + tj_start] == '#' &&
          s[i + si_start][j + sj_start] == '#') {
        return false;
      }
    }
  }

  return true;
}

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> t[i][j];
    }
  }

  for (int k = 0; k < 4; k++) {
    rotate();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (check(i, j)) {
          Yes();
          return 0;
        }
      }
    }
  }
  No();

  return 0;
}