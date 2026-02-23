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

ll my_pow(ll a, ll n, ll mod = MOD2) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

int n, a[int(2e5 + 5)];

ll ans[int(2e5 + 5)];
vector<Pii> primes[int(2e5 + 5)];
map<int, bool> visited;
set<Pii> st1, st2;

void prepare(int idx, int val) {
  int rest = val;
  for (int i = 2; i * i <= val; i++) {
    if (rest % i != 0) {
      continue;
    }

    int cnt = 0;
    while (rest % i == 0) {
      cnt++;
      rest /= i;
    }

    primes[idx].push_back({i, cnt});
  }
  if (rest > 1) {
    primes[idx].push_back({rest, 1});
  }

  for (Pii p_now : primes[idx]) {
    if (!visited[p_now.first]) {
      visited[p_now.first] = true;
      st1.insert(p_now);
      st2.insert({p_now.first, 0});
      continue;
    }

    auto iter1 = st1.lower_bound({p_now.first, 0});
    auto iter2 = st2.lower_bound({p_now.first, 0});
    Pii p1 = *iter1, p2 = *iter2;

    if (p1.second <= p_now.second) {
      st1.erase(p1);
      st1.insert(p_now);
      st2.erase(p2);
      st2.insert(p1);
    } else if (p2.second <= p_now.second) {
      st2.erase(p2);
      st2.insert(p_now);
    }
  }

  return;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    prepare(i, a[i]);
  }

  ll g = 1;
  for (Pii p1 : st1) {
    g *= my_pow(p1.first, p1.second);
    g %= MOD2;
  }

  for (int i = 1; i <= n; i++) {
    ans[i] = g;
    for (Pii p : primes[i]) {
      auto iter1 = st1.lower_bound({p.first, 0});
      Pii p1 = *iter1;

      if (p.second == p1.second) {
        ans[i] *= my_pow(my_pow(p.first, MOD2 - 2), p.second);
        ans[i] %= MOD2;

        auto iter2 = st2.lower_bound({p.first, 0});
        Pii p2 = *iter2;

        ans[i] *= my_pow(p.first, p2.second);
        ans[i] %= MOD2;
      }
    }
    cout << endl;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return;
}

void reset() {
  for (int i = 1; i <= n; i++) {
    primes[i].resize(0);
  }
  for (Pii p1 : st1) {
    visited[p1.first] = false;
  }
  for (Pii p2 : st2) {
    visited[p2.first] = false;
  }
  st1.clear();
  st2.clear();
  fill(ans + 1, ans + n + 1, 0);

  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    reset();
  }

  return 0;
}
