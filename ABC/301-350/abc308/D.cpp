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
string s[505];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
const string snuke = "snukes";

bool visited[505][505];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  if (s[0][0] != 's') {
    No();
    return 0;
  }

  queue<Pii> que;
  que.push({0, 0});
  visited[0][0] = true;
  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int i = q.first + di[k], j = q.second + dj[k];
      if (0 <= i && i < h && 0 <= j && j < w && !visited[i][j]) {
        for (int l = 0; l < 5; l++) {
          if (snuke[l] == s[q.first][q.second] && snuke[l + 1] == s[i][j]) {
            visited[i][j] = true;
            que.push({i, j});
            break;
          }
        }
      }
    }
  }

  if (visited[h - 1][w - 1]) {
    Yes();
  } else {
    No();
  }

  return 0;
}