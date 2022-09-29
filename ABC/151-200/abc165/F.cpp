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

int n, a[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

int answer[int(2e5 + 5)];
set<int> lisSet;

void solve(int currentNode) {
  int deletedScore;

  auto iter = lisSet.lower_bound(a[currentNode]);
  bool deleteActive = iter != lisSet.end();
  if (deleteActive) {
    deletedScore = *iter;
    lisSet.erase(deletedScore);
  }
  lisSet.insert(a[currentNode]);

  answer[currentNode] = lisSet.size();

  for (int nextNode : graph[currentNode]) {
    if (answer[nextNode] == 0) {
      solve(nextNode);
    }
  }

  lisSet.erase(a[currentNode]);
  if (deleteActive) {
    lisSet.insert(deletedScore);
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  solve(1);
  for (int i = 1; i <= n; i++) {
    cout << answer[i] << endl;
  }

  return 0;
}