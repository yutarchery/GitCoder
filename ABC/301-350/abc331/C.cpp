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
map<ll, ll> mp;

int main() {
  cin >> n;

  priority_queue<ll> que;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    que.push(a[i]);
  }

  ll sum = 0, now = 0, cnt = 1;
  while (!que.empty()) {
    ll q = que.top();
    que.pop();
    if (now != q) {
      sum += now * cnt;
      mp[q] = sum;
      now = q;
      cnt = 1;
    } else {
      cnt++;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << mp[a[i]];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
