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

int n, a[int(2e5 + 5)];

vector<int> graph[int(6e5 + 5)];
int ans[int(6e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    graph[a[i]].push_back(2 * i);
    graph[a[i]].push_back(2 * i + 1);
  }

  queue<int> que;
  que.push(1);

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      ans[next] = ans[q] + 1;
      que.push(next);
    }
  }

  for (int i = 1; i <= 2 * n + 1; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
