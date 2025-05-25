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
char s[55][55];

int s_i, s_j, a_i, a_j, g_i, g_j;

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int to_idx(int i, int j) { return (i - 1) * w + j - 1; }
Pii to_location(int idx) { return {idx / w + 1, idx % w + 1}; }

int dist[2505][2505];
bool visited[2505][2505];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];

      if (s[i][j] == 's') {
        s_i = i, s_j = j;
      } else if (s[i][j] == 'a') {
        a_i = i, a_j = j;
      } else if (s[i][j] == 'g') {
        g_i = i, g_j = j;
      }
    }
  }

  queue<Pii> que;
  que.push({to_idx(s_i, s_j), to_idx(a_i, a_j)});
  visited[to_idx(s_i, s_j)][to_idx(a_i, a_j)] = true;

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    int s_idx = q.first, a_idx = q.second;
    Pii s_loc = to_location(s_idx), a_loc = to_location(a_idx);

    if (g_i == a_loc.first && g_j == a_loc.second) {
      cout << dist[s_idx][a_idx] << endl;
      return 0;
    }

    for (int k = 0; k < 4; k++) {
      if (s_loc.first + di[k] == a_loc.first &&
          s_loc.second + dj[k] == a_loc.second) {
        int next_i = a_loc.first + di[k], next_j = a_loc.second + dj[k];

        if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w &&
            s[next_i][next_j] != '#') {

          int next_a = to_idx(next_i, next_j);

          if (!visited[a_idx][next_a]) {
            visited[a_idx][next_a] = true;
            dist[a_idx][next_a] = dist[s_idx][a_idx] + 1;
            que.push({a_idx, next_a});
          }
        }
        continue;
      } else {
        int next_i = s_loc.first + di[k], next_j = s_loc.second + dj[k];

        if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w &&
            s[next_i][next_j] != '#') {
          int next_s = to_idx(next_i, next_j);
          if (!visited[next_s][a_idx]) {
            visited[next_s][a_idx] = true;
            dist[next_s][a_idx] = dist[s_idx][a_idx] + 1;
            que.push({next_s, a_idx});
          }
        }
      }
    }
  }

  cout << -1 << endl;

  return 0;
}
