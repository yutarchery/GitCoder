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
char s[1005][1005];

queue<array<int, 3>> que;

vector<array<int, 3>> graph[1005][1005][4], rev[1005][1005][4];

bool visited[1005][1005][4];
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, -1, 0, 1};

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '.') {
        for (int k = 0; k < 4; k++) {
          if (s[i + di[k]][j + dj[k]] == '.') {
            graph[i][j][k].push_back({i + di[k], j + dj[k], k});
            rev[i + di[k]][j + dj[k]][k].push_back({i, j, k});
          } else {
            graph[i][j][k].push_back({i, j, (k + 1) % 4});
            rev[i][j][(k + 1) % 4].push_back({i, j, k});
          }
        }
      }
    }
  }

  for (int k = 0; k < 4; k++) {
    que.push({2, 2, k});
    visited[2][2][k] = true;
  }

  while (!que.empty()) {
    array<int, 3> q = que.front();
    que.pop();

    int i = q[0], j = q[1], k = q[2];

    for (array<int, 3> next : rev[i][j][k]) {
      if (!visited[next[0]][next[1]][next[2]]) {
        visited[next[0]][next[1]][next[2]] = true;
        que.push(next);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '.') {
        bool flag = false;
        for (int k = 0; k < 4; k++) {
          if (visited[i][j][k]) {
            flag = true;
          }
        }

        if (flag) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
