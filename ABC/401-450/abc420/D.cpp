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
char a[505][505];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int ans[505][505][2];
bool visited[505][505][2];

int si, sj, gi, gj;
priority_queue<pair<int, array<int, 3>>, vector<pair<int, array<int, 3>>>,
               greater<pair<int, array<int, 3>>>>
    que;

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];

      if (a[i][j] == 'S') {
        si = i;
        sj = j;
      } else if (a[i][j] == 'G') {
        gi = i;
        gj = j;
      }
    }
  }

  que.push({0, {si, sj, 0}});
  while (!que.empty()) {
    pair<int, array<int, 3>> q = que.top();
    que.pop();
    int i = q.second[0], j = q.second[1], k = q.second[2];
    if (visited[i][j][k]) {
      continue;
    }
    visited[i][j][k] = true;
    ans[i][j][k] = q.first;

    for (int l = 0; l < 4; l++) {
      int next_i = i + di[l], next_j = j + dj[l];
      if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w &&
          a[next_i][next_j] != '#') {
        if (a[next_i][next_j] == '?') {
          que.push({q.first + 1, {next_i, next_j, 1 - k}});
        } else if (k == 0 && a[next_i][next_j] != 'x') {
          que.push({q.first + 1, {next_i, next_j, k}});
        } else if (k == 1 && a[next_i][next_j] != 'o') {
          que.push({q.first + 1, {next_i, next_j, k}});
        }
      }
    }
  }

  if (!visited[gi][gj][0] && !visited[gi][gj][1]) {
    cout << -1 << endl;
  } else {
    cout << min(visited[gi][gj][0] ? ans[gi][gj][0] : 1e9,
                visited[gi][gj][1] ? ans[gi][gj][1] : 1e9)
         << endl;
  }

  return 0;
}
