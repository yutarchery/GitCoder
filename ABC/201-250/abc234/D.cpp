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

int n, k, p[int(5e5 + 5)];
priority_queue<int, vector<int>, greater<int>> que;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  for (int i = 1; i <= k; i++) {
    que.push(p[i]);
  }
  cout << que.top() << endl;
  for (int i = k + 1; i <= n; i++) {
    que.push(p[i]);
    que.pop();
    cout << que.top() << endl;
  }

  return 0;
}
