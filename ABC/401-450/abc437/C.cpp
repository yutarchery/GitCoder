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
ll w[int(3e5 + 5)], p[int(3e5 + 5)];

int solve() {
  cin >> n;

  ll sum = 0;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> p[i];
    sum += p[i];
    que.push(w[i] + p[i]);
  }

  int ans = 0;
  while (!que.empty()) {
    ll q = que.top();
    que.pop();

    if (sum - q >= 0) {
      ans++;
    } else {
      break;
    }

    sum -= q;
  }

  return ans;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
