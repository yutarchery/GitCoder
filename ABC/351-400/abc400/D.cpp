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

int h, w, a, b, c, d;
char s[1005][1005];

int ans[1005][1005];
bool visited[1005][1005];
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }
  cin >> a >> b >> c >> d;

  que.push({0, {a, b}});
  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();

    int i = q.second.first, j = q.second.second;
    if (visited[i][j]) {
      continue;
    }
    visited[i][j] = true;
    ans[i][j] = q.first;

    for (int k = 0; k < 4; k++) {
      int i1 = i + di[k], j1 = j + dj[k];
      int i2 = i + di[k] * 2, j2 = j + dj[k] * 2;

      if (1 <= i1 && i1 <= h && 1 <= j1 && j1 <= w && !visited[i1][j1]) {
        if (s[i1][j1] == '#') {
          que.push({q.first + 1, {i1, j1}});
        } else {
          que.push({q.first, {i1, j1}});
        }
      }

      if (1 <= i2 && i2 <= h && 1 <= j2 && j2 <= w && !visited[i2][j2]) {
        if (s[i1][j1] == '#' || s[i2][j2] == '#') {
          que.push({q.first + 1, {i2, j2}});
        } else {
          que.push({q.first, {i2, j2}});
        }
      }
    }
  }

  cout << ans[c][d] << endl;

  return 0;
}
