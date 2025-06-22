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

int n, u, v;
vector<int> graph[105];
int dist[105][105];
set<Pii> st;

void prepare(int start) {
  bool visited[105] = {};
  queue<int> que;
  que.push(start);
  visited[start] = true;

  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (int next : graph[now]) {
      if (!visited[next]) {
        visited[next] = true;
        dist[start][next] = dist[start][now] + 1;
        que.push(next);
      }
    }
  }

  for (int j = start + 1; j <= n; j++) {
    if (dist[start][j] % 2 == 1 && dist[start][j] >= 3) {
      st.insert({start, j});
    }
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    prepare(i);
  }

  int turn = int(st.size()) % 2;
  if (turn == 1) {
    cout << "First\n";
  } else {
    cout << "Second\n";
  }

  int ti = 0, tj = 0;
  while (true) {
    if (turn == 1) {
      auto iter = st.begin();
      Pii now = *iter;
      cout << now.first << " " << now.second << endl;
      st.erase(now);
    } else {
      cin >> ti >> tj;
      if (ti == -1 && tj == -1) {
        return 0;
      }
      if (ti >= tj) {
        swap(ti, tj);
      }
      st.erase({ti, tj});
    }

    turn = 1 - turn;
  }

  return 0;
}
