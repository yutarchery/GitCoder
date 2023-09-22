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

ll n, m, l[int(2e5 + 5)];

bool check(ll now) {
  if (l[0] > now) {
    return false;
  }

  ll sum = l[0], cnt = 1;
  for (int i = 1; i < n; i++) {
    if (sum + l[i] + 1 <= now) {
      sum += l[i] + 1;
    } else if (l[i] <= now) {
      cnt++;
      sum = l[i];
    } else {
      return false;
    }
  }

  return cnt <= m;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }

  ll left = 0, right = 1e16;
  while (right - left > 1) {
    ll now = (left + right) / 2;
    if (check(now)) {
      right = now;
    } else {
      left = now;
    }
  }

  cout << right << endl;

  return 0;
}