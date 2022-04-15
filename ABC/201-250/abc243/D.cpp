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

int n;
ll x;
string s;
deque<ll> que;

int main() {
  cin >> n >> x;
  cin >> s;

  while (x > 0) {
    que.push_front(x % 2);
    x /= 2;
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      que.pop_back();
    } else if (s[i] == 'L') {
      que.push_back(0);
    } else {
      que.push_back(1);
    }
  }

  ll ans = 0, digit = 1;
  while (!que.empty()) {
    ans += digit * que.back();
    que.pop_back();
    digit *= 2;
  }
  cout << ans << endl;

  return 0;
}