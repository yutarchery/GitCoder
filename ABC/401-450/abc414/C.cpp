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

int a;
ll n, ans;

bool judge(ll num) {
  if (num > n) {
    return false;
  }

  vector<ll> now;
  while (num > 0) {
    now.push_back(num % a);
    num /= a;
  }

  for (int i = 0; i < now.size(); i++) {
    if (now[i] != now[now.size() - 1 - i]) {
      return false;
    }
  }

  return true;
}

void solve(ll num) {
  vector<ll> now;
  while (num > 0) {
    now.push_back(num % 10);
    num /= 10;
  }

  ll val = 0;
  for (int i = now.size() - 1; i >= 0; i--) {
    val *= 10;
    val += now[i];
  }
  for (int i = 1; i < now.size(); i++) {
    val *= 10;
    val += now[i];
  }
  if (judge(val)) {
    ans += val;
  }

  val = 0;
  for (int i = now.size() - 1; i >= 0; i--) {
    val *= 10;
    val += now[i];
  }
  for (int i = 0; i < now.size(); i++) {
    val *= 10;
    val += now[i];
  }
  if (judge(val)) {
    ans += val;
  }
  return;
}

int main() {
  cin >> a;
  cin >> n;

  for (int i = 1; i <= int(1e6); i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}
