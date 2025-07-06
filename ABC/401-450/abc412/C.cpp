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
ll s[int(2e5 + 5)];

int solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  priority_queue<ll> que;
  priority_queue<ll, vector<ll>, greater<ll>> rest;

  que.push(s[1]);
  for (int i = 2; i <= n; i++) {
    rest.push(s[i]);
  }

  vector<ll> ans;
  while (!que.empty()) {
    ll q = que.top();
    que.pop();

    ans.push_back(q);

    while (!rest.empty()) {
      ll r = rest.top();
      if (q * 2 >= r) {
        que.push(r);
        rest.pop();
        if (r == s[n]) {
          ans.push_back(r);
          return ans.size();
        }
      } else {
        break;
      }
    }
  }

  return -1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
