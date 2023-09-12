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

int a, b;
string s[3];
bool visited[10][10];

int main() {
  cin >> a >> b;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }

  queue<Pii> que;
  que.push({a, b});
  visited[a][b] = true;

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (s[i - 1][j - 1] == '.') {
          continue;
        }

        int next_x = q.first + i - 2, next_y = q.second + j - 2;
        if (1 <= next_x && next_x <= 9 && 1 <= next_y && next_y <= 9) {
          if (!visited[next_x][next_y]) {
            visited[next_x][next_y] = true;
            que.push({next_x, next_y});
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (visited[i][j]) {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}