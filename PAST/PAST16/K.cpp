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
char s[1505][1505];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
int max_dir[1505][1505][4];

int start_i, start_j;

void prepare() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];

      if (s[i][j] == 'S') {
        start_i = i;
        start_j = j;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      max_dir[i][j][1] = max_dir[i][j - 1][1] + 1;
      if (s[i][j] == 'X' || s[i][j - 1] == 'X') {
        max_dir[i][j][1] = 0;
      }
    }

    for (int j = n - 1; j >= 1; j--) {
      max_dir[i][j][3] = max_dir[i][j + 1][3] + 1;
      if (s[i][j] == 'X' || s[i][j + 1] == 'X') {
        max_dir[i][j][3] = 0;
      }
    }
  }

  for (int j = 1; j <= n; j++) {
    for (int i = 2; i <= n; i++) {
      max_dir[i][j][0] = max_dir[i - 1][j][0] + 1;
      if (s[i][j] == 'X' || s[i - 1][j] == 'X') {
        max_dir[i][j][0] = 0;
      }
    }

    for (int i = n - 1; i >= 1; i--) {
      max_dir[i][j][2] = max_dir[i + 1][j][2] + 1;
      if (s[i][j] == 'X' || s[i + 1][j] == 'X') {
        max_dir[i][j][2] = 0;
      }
    }
  }

  return;
}

int solve(int num) {
  map<Pii, bool> visited;
  map<Pii, int> dist;

  queue<Pii> que;
  que.push({start_i, start_j});
  visited[{start_i, start_j}] = true;

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    int i = q.first, j = q.second;
    if (s[i][j] == 'G') {
      return dist[{i, j}];
    }

    for (int k = 0; k < 4; k++) {
      if (max_dir[i][j][k] < num) {
        continue;
      }

      int next_i = i + num * di[k], next_j = j + num * dj[k];

      if (1 <= next_i && next_i <= n && 1 <= next_j && next_j <= n &&
          !visited[{next_i, next_j}]) {
        visited[{next_i, next_j}] = true;
        dist[{next_i, next_j}] = dist[{i, j}] + 1;
        que.push({next_i, next_j});
      }
    }
  }

  return -1;
}

int main() {
  prepare();
  for (int i = 1; i <= n - 1; i++) {
    cout << solve(i) << endl;
  }

  return 0;
}
