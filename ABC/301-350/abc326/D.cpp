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
string r, c;

bool flag = false;
char ans[5][5];

void solve(int turn) {
  if (turn == n) {

    if (!flag) {
      Yes();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          cout << ans[i][j];
        }
        cout << endl;
      }
      flag = true;
    }
    return;
  }

  if (turn < n) {
    do {
      bool now_flag = true;
      for (int j = 0; j < n; j++) {
        if (ans[turn][j] == '.') {
          continue;
        } else if (ans[turn][j] == r[turn]) {
          break;
        } else {
          now_flag = false;
          break;
        }
      }

      for (int j = 0; j < n; j++) {
        for (int i = 0; i <= turn; i++) {
          if (ans[i][j] == '.') {
            continue;
          } else if (ans[i][j] == c[j]) {
            break;
          } else {
            now_flag = false;
            break;
          }
        }
      }

      for (int j = 0; j < n; j++) {
        int cnt[3] = {};
        for (int i = 0; i <= turn; i++) {
          if (ans[i][j] != '.') {
            cnt[ans[i][j] - 'A']++;
          }
        }

        for (int i = 0; i < 3; i++) {
          if (cnt[i] > 1) {
            now_flag = false;
          }
        }
      }

      if (!now_flag) {
        continue;
      }

      solve(turn + 1);
    } while (next_permutation(ans[turn], ans[turn] + n));
  }

  return;
}

int main() {
  cin >> n;
  cin >> r;
  cin >> c;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      ans[i][j] = 'A' + j;
    }
    for (int j = 3; j < n; j++) {
      ans[i][j] = '.';
    }
    sort(ans[i], ans[i] + n);
  }
  solve(0);

  if (!flag) {
    No();
  }

  return 0;
}
