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
bool visited[int(2e6 + 5)];
vector<ll> primes;

void make_primes() {
  for (ll i = 2; i * i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    primes.push_back(i);
    for (ll j = i; j * j <= n; j += i) {
      visited[j] = true;
    }
  }

  return;
}

ll my_pow(ll num) {
  ll res = 1;
  for (int i = 0; i < 8; i++) {
    res *= num;
  }
  return res;
}

int main() {
  cin >> n;
  make_primes();

  int ans = 0;
  int r = primes.size() - 1;
  for (int i = 0; i < primes.size(); i++) {
    while (primes[i] * primes[i] * primes[r] * primes[r] > n) {
      if (i >= r) {
        break;
      }
      r--;
    }
    ans += r - i;
    if (i >= r) {
      break;
    }
  }

  for (ll p : primes) {
    if (my_pow(p) <= n) {
      ans++;
    } else {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
