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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

ll x;
map<ll, bool> used;
vector<ll> num;

void dfs(ll now, ll diff) {
  if (now <= 0 || now >= ll(2e17)) {
    return;
  }

  if (!used[now]) {
    used[now] = true;
    num.push_back(now);
  }

  ll nextDigit = now % 10 + diff;
  ll next = now * 10 + nextDigit;
  if (0 <= nextDigit && nextDigit < 10) {
    dfs(next, diff);
  }

  return;
}

int main() {
  cin >> x;
  num.push_back(0);
  for (ll now = 1; now < 10; now++) {
    for (ll diff = -9; diff <= 9; diff++) {
      dfs(now, diff);
    }
  }
  sort(num.begin(), num.end());

  int l = 0, r = num.size() - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;

    if (x <= num[mid]) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << num[r] << endl;

  return 0;
}