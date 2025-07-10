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
char s[505][505];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;
int ans[505][505];
bool visited[505][505];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  que.push({0, {1, 1}});
  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();

    int val = q.first, i = q.second.first, j = q.second.second;
    if (visited[i][j]) {
      continue;
    }
    visited[i][j] = true;
    ans[i][j] = val;

    for (int k = 0; k < 4; k++) {
      int next_i = i + di[k], next_j = j + dj[k];
      if (s[next_i][next_j] == '.' && !visited[next_i][next_j]) {
        que.push({val, {next_i, next_j}});
      }
    }

    for (int ii = -2; ii <= 2; ii++) {
      for (int jj = -2; jj <= 2; jj++) {
        if (abs(ii) == 2 && abs(jj) == 2) {
          continue;
        }

        int next_i = i + ii, next_j = j + jj;
        if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w &&
            !visited[next_i][next_j]) {
          que.push({val + 1, {next_i, next_j}});
        }
      }
    }
  }

  cout << ans[h][w] << endl;

  return 0;
}
