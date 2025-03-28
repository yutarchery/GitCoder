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
string x, y, s[int(2e5 + 5)], t[int(2e5 + 5)];

int now = 1;
map<string, bool> visited;
map<string, int> idx;
vector<int> graph[int(4e5 + 5)];

bool ans[int(4e5 + 5)];

int main() {
  cin >> n;
  cin >> x >> y;
  visited[x] = true;
  idx[x] = 0;
  visited[y] = true;
  idx[y] = 1;

  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> t[i];
    if (!visited[s[i]]) {
      visited[s[i]] = true;
      now++;
      idx[s[i]] = now;
    }
    if (!visited[t[i]]) {
      visited[t[i]] = true;
      now++;
      idx[t[i]] = now;
    }
    graph[idx[s[i]]].push_back(idx[t[i]]);
  }

  queue<int> que;
  que.push(0);
  ans[0] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (!ans[next]) {
        ans[next] = true;
        que.push(next);
      }
    }
  }

  ans[1] ? Yes() : No();

  return 0;
}
