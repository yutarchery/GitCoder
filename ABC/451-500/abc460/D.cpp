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

int h, w;
vector<char> s[int(1e6 + 5)];
vector<int> dist[int(1e6 + 5)];
vector<bool> visited[int(1e6 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w;
  for (int i = 0; i <= h + 1; i++) {
    s[i].resize(w + 2);
    dist[i].resize(w + 2);
    visited[i].resize(w + 2, false);
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  queue<Pii> que;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (s[i][j] == '#') {
        for (int di = -1; di <= 1; di++) {
          for (int dj = -1; dj <= 1; dj++) {
            if (!visited[i + di][j + dj] && 1 <= i + di && i + di <= h &&
                1 <= j + dj && j + dj <= w && s[i + di][j + dj] == '.') {
              que.push({i + di, j + dj});
              dist[i + di][j + dj] = 1;
              visited[i + di][j + dj] = true;
            }
          }
        }
      }
    }
  }

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        if (1 <= q.first + di && q.first + di <= h && 1 <= q.second + dj &&
            q.second + dj <= w && !visited[q.first + di][q.second + dj]) {
          que.push({q.first + di, q.second + dj});
          visited[q.first + di][q.second + dj] = true;
          dist[q.first + di][q.second + dj] = dist[q.first][q.second] + 1;
        }
      }
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (visited[i][j]) {
        cout << (dist[i][j] % 2 == 0 ? '#' : '.');
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }

  return 0;
}
