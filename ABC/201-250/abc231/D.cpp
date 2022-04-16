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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m;
vector<int> graph[int(1e5 + 5)];
bool ans = true;
bool visited[int(1e5 + 5)];

void loopCheck(int start) {
  visited[start] = true;

  for (int next : graph[start]) {
    if (!visited[next]) {
      loopCheck(next);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (graph[i].size() > 2) {
      ans = false;
    }
    if (graph[i].size() == 1) {
      loopCheck(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (graph[i].size() == 2 && !visited[i]) {
      ans = false;
    }
  }

  if (ans) {
    Yes();
  } else {
    No();
  }

  return 0;
}