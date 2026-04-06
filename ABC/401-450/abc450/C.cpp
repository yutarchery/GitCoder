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
char s[1005][1005];

bool visited[1005][1005];
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  int ans = 0;

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (visited[i][j] || s[i][j] != '.') {
        continue;
      }

      bool flag = true;
      queue<Pii> que;
      que.push({i, j});
      visited[i][j] = true;

      while (!que.empty()) {
        Pii q = que.front();
        que.pop();

        if (q.first == 1 || q.first == h || q.second == 1 || q.second == w) {
          flag = false;
        }

        for (int k = 0; k < 4; k++) {
          if (s[q.first + di[k]][q.second + dj[k]] == '.' &&
              !visited[q.first + di[k]][q.second + dj[k]]) {
            que.push({q.first + di[k], q.second + dj[k]});
            visited[q.first + di[k]][q.second + dj[k]] = true;
          }
        }
      }

      if (flag) {
        ans++;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
