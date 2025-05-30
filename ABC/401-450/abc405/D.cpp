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
char s[1005][1005], t[1005][1005];
bool visited[1005][1005];

queue<Pii> que;
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
const char c[4] = {'v', '>', '^', '<'};

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
      if (s[i][j] == 'E') {
        t[i][j] = 'E';
        visited[i][j] = true;
        que.push({i, j});
      } else if (s[i][j] == '#') {
        t[i][j] = '#';
        visited[i][j] = true;
      }
    }
  }

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int i = q.first + di[k], j = q.second + dj[k];

      if (!visited[i][j] && 1 <= i && i <= h && 1 <= j && j <= w) {
        visited[i][j] = true;
        t[i][j] = c[k];
        que.push({i, j});
      }
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cout << t[i][j];
    }
    cout << endl;
  }

  return 0;
}
