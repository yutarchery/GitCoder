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
vector<int> graph[int(2e5 + 5)];

int ans[int(2e5 + 5)];
int group[int(2e5 + 5)];

int minGroup(int a) {
  int res = a;
  while (group[res] != res) {
    res = group[res];
  }

  while (group[a] != res) {
    group[a] = res;
    a = group[a];
  }

  return res;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    graph[a].push_back(b);
  }

  for (int i = n; i >= 1; i--) {

    ans[i] = ans[i + 1] + 1;

    vector<int> unionGroup;
    vector<bool> visited(n + 1);
    for (int node : graph[i]) {
      int m = minGroup(node);
      if (!visited[m]) {
        unionGroup.push_back(minGroup(m));
        visited[m] = true;
      }
    }
    ans[i] -= unionGroup.size();
    for (int node : unionGroup) {
      group[node] = i;
    }
  }

  for (int i = 2; i <= n + 1; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}