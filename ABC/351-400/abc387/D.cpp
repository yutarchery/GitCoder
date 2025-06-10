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

int h, w, si, sj, gi, gj;
char s[1005][1005];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
bool visited[1005][1005][4];
int ans[1005][1005][4];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];

      if (s[i][j] == 'S') {
        si = i;
        sj = j;
      }
      if (s[i][j] == 'G') {
        gi = i;
        gj = j;
      }
    }
  }

  queue<pair<Pii, int>> que;
  for (int k = 0; k < 4; k++) {
    que.push({{si, sj}, k});
    visited[si][sj][k] = true;
  }

  while (!que.empty()) {
    pair<Pii, int> q = que.front();
    que.pop();

    int i = q.first.first, j = q.first.second, k = q.second;

    for (int l = 0; l < 4; l++) {
      if (l % 2 == k % 2) {
        continue;
      }

      int next_i = i + di[l], next_j = j + dj[l];
      if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w &&
          s[next_i][next_j] != '#' && !visited[next_i][next_j][l % 2]) {
        visited[next_i][next_j][l % 2] = true;
        ans[next_i][next_j][l % 2] = ans[i][j][k] + 1;
        que.push({{next_i, next_j}, l % 2});
      }
    }
  }

  int res = 1e9;
  for (int k = 0; k < 4; k++) {
    if (visited[gi][gj][k]) {
      res = min(res, ans[gi][gj][k]);
    }
  }

  cout << (res == 1e9 ? -1 : res) << endl;

  return 0;
}
