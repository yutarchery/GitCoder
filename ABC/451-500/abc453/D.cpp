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

int h, w;
char s[1005][1005];

const char dir[4] = {'U', 'R', 'D', 'L'};
const char rev[4] = {'D', 'L', 'U', 'R'};
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
bool visited[1005][1005][4];
int ans[1005][1005][4];

int si, sj, gi, gj;
char res[int(5e6 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];

      if (s[i][j] == 'S') {
        si = i, sj = j;
      } else if (s[i][j] == 'G') {
        gi = i, gj = j;
      }
    }
  }

  queue<array<int, 3>> que;
  for (int k = 0; k < 4; k++) {
    que.push({si, sj, k});
    visited[si][sj][k] = true;
  }

  while (!que.empty()) {
    array<int, 3> q = que.front();
    que.pop();

    int i = q[0], j = q[1], k = q[2];
    int next_i = i + di[k], next_j = j + dj[k];

    if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w) {

      if (s[next_i][next_j] == 'o') {
        if (!visited[next_i][next_j][k]) {
          visited[next_i][next_j][k] = true;
          que.push({next_i, next_j, k});
          ans[next_i][next_j][k] = ans[i][j][k] + 1;
        }
      } else if (s[next_i][next_j] == 'x') {
        for (int next_k = 0; next_k < 4; next_k++) {
          if (k != next_k && !visited[next_i][next_j][next_k]) {
            visited[next_i][next_j][next_k] = true;
            que.push({next_i, next_j, next_k});
            ans[next_i][next_j][next_k] = ans[i][j][k] + 1;
          }
        }
      } else if (s[next_i][next_j] != '#') {
        for (int next_k = 0; next_k < 4; next_k++) {
          if (!visited[next_i][next_j][next_k]) {
            visited[next_i][next_j][next_k] = true;
            que.push({next_i, next_j, next_k});
            ans[next_i][next_j][next_k] = ans[i][j][k] + 1;
          }
        }
      }
    }
  }

  bool flag = false;
  int gk;
  for (int k = 0; k < 4; k++) {
    if (visited[gi][gj][k]) {
      flag = true;
      gk = k;
      break;
    }
  }

  if (!flag) {
    No();
    return 0;
  }

  int ni = gi, nj = gj, nk = gk;
  while (ans[ni][nj][nk] > 0) {
    for (int k = 0; k < 4; k++) {
      if (ans[ni - di[k]][nj - dj[k]][k] + 1 == ans[ni][nj][nk] &&
          visited[ni - di[k]][nj - dj[k]][k]) {

        if (s[ni][nj] == 'o' && k != nk) {
          continue;
        }
        if (s[ni][nj] == 'x' && k == nk) {
          continue;
        }

        res[ans[ni][nj][nk]] = dir[k];

        ni -= di[k];
        nj -= dj[k];
        nk = k;
        break;
      }
    }
  }

  Yes();
  for (int i = 1; i <= ans[gi][gj][gk]; i++) {
    cout << res[i];
  }
  cout << '\n';

  return 0;
}
