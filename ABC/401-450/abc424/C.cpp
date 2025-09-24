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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];
queue<int> que;
bool ans[int(2e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];

    if (a[i] == 0 && b[i] == 0) {
      que.push(i);
      ans[i] = true;
    }

    if (a[i] != 0) {
      graph[a[i]].push_back(i);
    }
    if (b[i] != 0) {
      graph[b[i]].push_back(i);
    }
  }

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

  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i]) {
      res++;
    }
  }
  cout << res << endl;

  return 0;
}
