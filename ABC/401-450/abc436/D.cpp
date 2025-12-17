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

const int di[4] = {0, -1, 0, 1}, dj[4] = {1, 0, -1, 0};
int ans[1005][1005];
bool visited[1005][1005], used[26];
vector<Pii> warp[26];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
      if ('a' <= s[i][j] && s[i][j] <= 'z') {
        warp[s[i][j] - 'a'].push_back({i, j});
      }
    }
  }

  visited[1][1] = true;
  queue<Pii> que;
  que.push({1, 1});
  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int next_i = q.first + di[k], next_j = q.second + dj[k];
      if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w &&
          s[next_i][next_j] != '#' && !visited[next_i][next_j]) {
        visited[next_i][next_j] = true;
        ans[next_i][next_j] = ans[q.first][q.second] + 1;
        que.push({next_i, next_j});
      }
    }

    if ('a' <= s[q.first][q.second] && s[q.first][q.second] <= 'z' &&
        !used[s[q.first][q.second] - 'a']) {
      used[s[q.first][q.second] - 'a'] = true;
      for (Pii next : warp[s[q.first][q.second] - 'a']) {
        if (!visited[next.first][next.second]) {
          visited[next.first][next.second] = true;
          ans[next.first][next.second] = ans[q.first][q.second] + 1;
          que.push(next);
        }
      }
    }
  }

  cout << (visited[h][w] ? ans[h][w] : -1) << endl;

  return 0;
}
