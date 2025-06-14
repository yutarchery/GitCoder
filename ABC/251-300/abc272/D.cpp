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

int n, m, ans[405][405];
bool visited[405][405];

vector<Pii> dir;
const int di[4] = {-1, 1, -1, 1}, dj[4] = {1, 1, -1, -1};

int main() {
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i * i + j * j == m) {
        for (int k = 0; k < 4; k++) {
          dir.push_back({i * di[k], j * dj[k]});
        }
      }
    }
  }

  queue<Pii> que;
  que.push({1, 1});
  visited[1][1] = true;

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (Pii d : dir) {
      int i = q.first + d.first, j = q.second + d.second;

      if (1 <= i && i <= n && 1 <= j && j <= n && !visited[i][j]) {
        visited[i][j] = true;
        ans[i][j] = ans[q.first][q.second] + 1;
        que.push({i, j});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (visited[i][j] ? ans[i][j] : -1) << (j == n ? '\n' : ' ');
    }
  }

  return 0;
}
