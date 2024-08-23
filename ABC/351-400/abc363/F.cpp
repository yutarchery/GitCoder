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

ll n;
map<ll, bool> visited;
map<ll, vector<ll>> res;

ll rev(ll num) {
  ll ans[105] = {};
  int digit = 0;

  while (num > 0) {
    ans[digit] = num % 10;
    digit++;
    num /= 10;
  }

  ll res = 0;
  for (int i = 0; i < digit; i++) {
    res *= 10;
    res += ans[i];
  }
  return res;
}

bool contain_zero(ll num) {
  while (num > 0) {
    if (num % 10 == 0) {
      return true;
    }
    num /= 10;
  }
  return false;
}

vector<ll> solve(ll num) {
  if (visited[num]) {
    return res[num];
  }

  visited[num] = true;
  vector<ll> ans;
  if (!contain_zero(num) && num == rev(num)) {
    ans.push_back(num);
    return res[num] = ans;
  }

  for (ll i = 2; i * i <= num; i++) {
    if (contain_zero(i)) {
      continue;
    }

    ll r = rev(i);
    if (num % (i * r) != 0) {
      continue;
    }

    vector<ll> next = solve(num / (i * r));
    if (next.empty()) {
      continue;
    }

    ans.push_back(i);
    for (ll j : next) {
      ans.push_back(j);
    }
    ans.push_back(r);
    break;
  }

  return res[num] = ans;
}

int main() {
  cin >> n;

  vector<ll> ans = solve(n);

  if (ans.empty()) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << "*";
    }
  }

  return 0;
}
