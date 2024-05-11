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

const int di[5] = {-1, 0, 1, 0, 0}, dj[5] = {0, -1, 0, 1, 0};
bool free_space[1005][1005];
bool visited[1005][1005];
int ans = 1;

void solve(int start_i, int start_j) {
  queue<Pii> que;
  set<Pii> st;
  que.push({start_i, start_j});
  st.insert({start_i, start_j});
  visited[start_i][start_j] = true;

  while (!que.empty()) {
    Pii now = que.front();
    que.pop();

    for (int k = 0; k < 5; k++) {
      int next_i = now.first + di[k], next_j = now.second + dj[k];
      if (s[next_i][next_j] != '.') {
        continue;
      }

      st.insert({next_i, next_j});
      if (!visited[next_i][next_j] && free_space[next_i][next_j]) {
        que.push({next_i, next_j});
        visited[next_i][next_j] = true;
      }
    }
  }

  ans = max(ans, int(st.size()));
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
      bool flag = true;
      for (int k = 0; k < 5; k++) {
        if (s[i + di[k]][j + dj[k]] == '#') {
          flag = false;
        }
      }
      free_space[i][j] = flag;
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (visited[i][j]) {
        continue;
      }
      if (!free_space[i][j]) {
        continue;
      }
      solve(i, j);
    }
  }
  cout << ans << endl;

  return 0;
}
