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

int h, w;
char s[4][4];
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

bool visited[4][4][(1 << 16)];
int ans[4][4][(1 << 16)];

int calc_idx(int i, int j) { return i * w + j; }
queue<array<int, 3>> que;

int main() {
  cin >> h >> w;
  int ans_idx = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
      que.push({i, j, 0});
      visited[i][j][0] = true;
      if (s[i][j] == '#') {
        ans_idx += (1 << (calc_idx(i, j)));
      }
    }
  }


  while (!que.empty()) {
    array<int, 3> q = que.front();
    que.pop();

    int state = q[2];
    for (int k = 0; k < 4; k++) {
      int i = q[0] + di[k], j = q[1] + dj[k];
      if (0 <= i && i < h && 0 <= j && j < w) {
        int next = (state ^ (1 << (calc_idx(q[0], q[1]))));
        if (!visited[i][j][next]) {
          visited[i][j][next] = true;
          ans[i][j][next] = ans[q[0]][q[1]][q[2]] + 1;
          que.push({i, j, next});
        }
      }
    }
  }
  cout << ans[0][0][ans_idx] << endl;

  return 0;
}
