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
vector<char> s[int(3e5 + 5)];
vector<int> idx[int(3e5 + 5)];
vector<bool> visited[int(3e5 + 5)], ans[int(3e5 + 5)];

priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int main() {
  cin >> h >> w;
  for (int i = 0; i <= h + 1; i++) {
    s[i].resize(w + 2);
    visited[i].resize(w + 2);
    idx[i].resize(w + 2);
    ans[i].resize(w + 2);
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];

      if (s[i][j] == '#') {
        ans[i][j] = true;
        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
          if (1 <= i + di[k] && i + di[k] <= h && 1 <= j + dj[k] &&
              j + dj[k] <= w && !visited[i + di[k]][j + dj[k]]) {
            que.push({1, {i + di[k], j + dj[k]}});
          }
        }
      }
    }
  }

  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();
    int now = q.first, i = q.second.first, j = q.second.second;

    if (visited[i][j]) {
      continue;
    }

    visited[i][j] = true;
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
      if (ans[i + di[k]][j + dj[k]] && idx[i + di[k]][j + dj[k]] <= now - 1) {
        cnt++;
      }
    }

    if (cnt != 1) {
      continue;
    }

    idx[i][j] = now;
    ans[i][j] = true;
    for (int k = 0; k < 4; k++) {
      if (1 <= i + di[k] && i + di[k] <= h && 1 <= j + dj[k] &&
          j + dj[k] <= w && !visited[i + di[k]][j + dj[k]]) {
        que.push({now + 1, {i + di[k], j + dj[k]}});
      }
    }
  }

  int cnt = 0;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (ans[i][j]) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
