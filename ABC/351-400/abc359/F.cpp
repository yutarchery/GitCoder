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
ll a[int(2e5 + 5)];

ll ans = 0;
ll d[int(2e5 + 5)];

priority_queue<Pli, vector<Pli>, greater<Pli>> que;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans += a[i];
    d[i] = 1;
    que.push({((d[i] + 1) * (d[i] + 1) - d[i] * d[i]) * a[i], i});
  }

  for (int t = n + 1; t <= 2 * n - 2; t++) {
    Pli q = que.top();
    que.pop();
    int i = q.second;
    ans += q.first;

    d[i]++;
    que.push({((d[i] + 1) * (d[i] + 1) - d[i] * d[i]) * a[i], i});
  }

  cout << ans << endl;

  return 0;
}
