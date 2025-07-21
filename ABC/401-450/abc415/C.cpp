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

int n;
char s[int(5e5 + 5)];

vector<int> graph[int(5e5 + 5)];
bool visited[int(5e5 + 5)];

void prepare() {
  for (int i = 0; i <= (1 << 18) - 1; i++) {
    for (int j = 0; j < 18; j++) {
      if ((i & (1 << j)) == 0) {
        graph[i].push_back(i + (1 << j));
      }
    }
  }

  return;
}

bool solve() {
  cin >> n;
  fill(visited, visited + (1 << n), false);

  for (int i = 1; i <= (1 << n) - 1; i++) {
    cin >> s[i];
  }

  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (!visited[next] && s[next] == '0') {
        visited[next] = true;
        que.push(next);
      }
    }
  }

  return visited[(1 << n) - 1];
}

int main() {
  prepare();
  int t;
  cin >> t;
  while (t--) {
    solve() ? Yes() : No();
  }

  return 0;
}
