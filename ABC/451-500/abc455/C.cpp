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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, k;
ll a[int(3e5 + 5)];

ll sum = 0;
map<ll, ll> cnt;
map<ll, bool> visited;
priority_queue<ll> que;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    cnt[a[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[a[i]]) {
      visited[a[i]] = true;
      que.push(a[i] * cnt[a[i]]);
    }
  }

  while (!que.empty()) {
    if (k == 0) {
      break;
    }

    ll q = que.top();
    que.pop();
    k--;
    sum -= q;
  }
  cout << sum << '\n';

  return 0;
}
