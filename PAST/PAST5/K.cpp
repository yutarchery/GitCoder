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

char s[4][4];

const int di[5] = {0, -1, 0, 1, 0};
const int dj[5] = {0, 0, -1, 0, 1};

bool solved[(1 << 16)];
double ans[(1 << 16)];

double solve(int state) {
  if (solved[state]) {
    return ans[state];
  }

  solved[state] = true;
  if (state == (1 << 16) - 1) {
    return ans[state] = 0;
  }

  double res = 1e16;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {

      bool now[4][4] = {};
      for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++) {
          if ((state & (1 << (4 * ii + jj))) > 0) {
            now[ii][jj] = true;
          }
        }
      }

      int next_state[5];
      for (int k = 0; k < 5; k++) {
        int next_i = i + di[k], next_j = j + dj[k];
        if (0 <= next_i && next_i < 4 && 0 <= next_j && next_j < 4 &&
            !now[next_i][next_j]) {
          next_state[k] = state + (1 << (next_i * 4 + next_j));
        } else {
          next_state[k] = state;
        }
      }
      sort(next_state, next_state + 5);

      if (next_state[4] == state) {
        continue;
      }

      int cnt = 0;
      double sum = 0;
      for (int k = 0; k < 5; k++) {
        if (next_state[k] == state) {
          cnt++;
          continue;
        }
        sum += solve(next_state[k]);
      }

      res = min(res, sum / (double)(5 - cnt) + (double)5 / (double)(5 - cnt));
    }
  }

  return ans[state] = res;
}

int main() {
  int state = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> s[i][j];
      if (s[i][j] == '.') {
        state += (1 << (4 * i + j));
      }
    }
  }

  cout << fixed << setprecision(10) << solve(state) << endl;

  return 0;
}
