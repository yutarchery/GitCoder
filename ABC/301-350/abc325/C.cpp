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
char s[1005][1005];
bool visited[1005][1005];

queue<Pii> que;
int di[3] = {-1, 0, 1}, dj[3] = {-1, 0, 1};
int ans = 0;

void solve(int si, int sj) {
  que.push({si, sj});
  visited[si][sj] = true;

  while (!que.empty()) {
    Pii now = que.front();
    que.pop();

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int ni = now.first + di[i], nj = now.second + dj[j];
        if (!visited[ni][nj] && s[ni][nj] == '#') {
          visited[ni][nj] = true;
          que.push({ni, nj});
        }
      }
    }
  }

  return;
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (!visited[i][j] && s[i][j] == '#') {
        ans++;
        solve(i, j);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
