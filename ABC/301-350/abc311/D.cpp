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

int n, m;
string s[205];

bool visited[205][205][4];
int di[4] = {0, -1, 0, 1}, dj[4] = {-1, 0, 1, 0};

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  queue<pair<Pii, int>> que;
  for (int k = 0; k < 4; k++) {
    visited[1][1][k] = true;
    que.push({{1, 1}, k});
  }

  while (!que.empty()) {
    pair<Pii, int> q = que.front();
    que.pop();

    Pii now = q.first;
    int k = q.second;

    if (s[now.first + di[k]][now.second + dj[k]] == '.') {
      que.push({{now.first + di[k], now.second + dj[k]}, k});
      visited[now.first + di[k]][now.second + dj[k]][k] = true;
      continue;
    }

    for (int l = 0; l < 4; l++) {
      if (!visited[now.first][now.second][l]) {
        visited[now.first][now.second][l] = true;
        que.push({now, l});
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        if (visited[i][j][k]) {
          ans++;
          break;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}