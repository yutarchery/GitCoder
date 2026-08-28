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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int h, w, k;
vector<char> s[int(5e5 + 5)];
vector<int> dist[int(5e5 + 5)];
vector<bool> visited[int(5e5 + 5)];

set<int> st_i, st_j;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w >> k;
  for (int i = 0; i <= h + 1; i++) {
    s[i].resize(w + 2);
    dist[i].resize(w + 2, 0);
    visited[i].resize(w + 2, false);
  }

  for (int i = 1; i <= h; i++) {
    st_i.insert(i);
  }
  for (int j = 1; j <= w; j++) {
    st_j.insert(j);
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];

      if (s[i][j] == '#') {
        st_i.erase(i);
        st_j.erase(j);
      }
    }
  }

  int ans = 0;
  queue<Pii> que;
  for (int i : st_i) {
    for (int j : st_j) {
      visited[i][j] = true;
      que.push({i, j});
      ans++;
    }
  }

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    if (dist[q.first][q.second] == k) {
      continue;
    }

    for (int k = 0; k < 4; k++) {
      if (!visited[q.first + di[k]][q.second + dj[k]] &&
          s[q.first + di[k]][q.second + dj[k]] == '.') {
        visited[q.first + di[k]][q.second + dj[k]] = true;
        dist[q.first + di[k]][q.second + dj[k]] = dist[q.first][q.second] + 1;
        que.push({q.first + di[k], q.second + dj[k]});
        ans++;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
