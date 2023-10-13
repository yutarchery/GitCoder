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

int n, m;
vector<int> graph[105];

int before_node[105];
bool visited[105];

void input(int start) {
  int k;
  cin >> k;

  for (int i = 0; i < k; i++) {
    int u;
    cin >> u;
    if (!visited[start]) {
      graph[start].push_back(u);
    }
  }
  visited[start] = true;
  return;
}

int main() {
  cin >> n >> m;

  int now = 1;
  while (now != n) {
    input(now);

    int next = 0;
    for (int j : graph[now]) {
      if (!visited[j]) {
        next = j;
        before_node[j] = now;
        break;
      }
    }
    if (next == 0) {
      next = before_node[now];
    }

    cout << next << endl;
    now = next;
  }

  string s;
  cin >> s;

  return 0;
}