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

int n, c;
char s[3005][3005];

int cnt[3005];
int ables[3005];
bool visited[3005][3005];

void solve() {
  cin >> n >> c;

  fill(cnt + 1, cnt + n + 1, 0);
  fill(ables + 1, ables + n + 1, 0);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
      if (s[i][j] == '#') {
        cnt[j]++;
      }

      visited[i][j] = false;
    }
  }

  for (int j = 1; j <= n; j++) {
    ables[j] = -1;
    for (int i = n; i >= 1; i--) {
      if (s[i][j] == '#') {
        ables[j] = i;
        break;
      }
    }
  }

  queue<Pii> que;
  que.push({n, c});
  visited[n][c] = true;

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int dj = -1; dj <= 1; dj++) {
      int next_i = q.first - 1, next_j = q.second + dj;

      if (!visited[next_i][next_j]) {
        if (s[next_i][next_j] == '.') {
          visited[next_i][next_j] = true;
          que.push({next_i, next_j});
        } else if (s[next_i][next_j] == '#' && ables[next_j] == next_i) {
          visited[next_i][next_j] = true;
          que.push({next_i, next_j});
          s[next_i][next_j] = '.';
          for (int i = next_i; i >= 1; i--) {
            if (s[i][next_j] == '#') {
              ables[next_j] = i;
              break;
            }
          }
        }
      }
    }
  }

  for (int j = 1; j <= n; j++) {
    cout << visited[1][j];
  }
  cout << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
