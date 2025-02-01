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
ll m, k, a[int(1e5 + 5)];

ll p[int(1e5 + 5)], q[int(1e5 + 5)];
ll lower = 0, upper = 1e13;

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = a[i] / k;
    q[i] = a[i] % k;
  }

  while (upper - lower > 1) {
    ll mid = (lower + upper) / 2;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += max(0ll, mid - p[i]);
    }

    if (cnt <= m) {
      lower = mid;
    } else {
      upper = mid;
    }
  }

  priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> que;
  for (int i = 1; i <= n; i++) {
    if (p[i] <= lower) {
      m -= lower - p[i];
      p[i] = lower;
    }
    que.push({p[i], q[i], i});
  }

  while (m > 0) {
    array<ll, 3> a = que.top();
    que.pop();
    p[a[2]]++;
    m--;
    que.push({p[a[2]], q[a[2]], a[2]});
  }

  for (int i = 1; i <= n; i++) {
    cout << p[i] * k + q[i] << " \n"[i == n];
  }

  return 0;
}
