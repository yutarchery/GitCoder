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

int q;
deque<Pll> que;

void solve(ll total) {
  ll sum = 0, cnt = 0;

  while (cnt < total) {
    Pll p = que.front();
    que.pop_front();

    if (cnt + p.se <= total) {
      sum += p.fi * p.se;
      cnt += p.se;
    } else {

      sum += p.fi * (total - cnt);
      que.push_front({p.fi, p.se - (total - cnt)});
      cnt += (total - cnt);
    }
  }

  cout << sum << endl;

  return;
}

int main() {
  cin >> q;
  for (int i = 0; i < q; i++) {
    int num;
    cin >> num;
    if (num == 1) {
      ll x, c;
      cin >> x >> c;
      que.push_back({x, c});
      continue;
    }

    ll c;
    cin >> c;
    solve(c);
  }

  return 0;
}