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

vector<ll> primes;
bool visited[int(1e6 + 5)];
ll pow3[int(1e6 + 5)];

void prepare() {
  cin >> n;

  for (ll i = 2; i <= ll(1e6); i++) {
    if (visited[i]) {
      continue;
    }

    visited[i] = true;
    primes.push_back(i);
    pow3[i] = i * i * i;

    for (ll j = i; j <= ll(1e6); j += i) {
      visited[j] = true;
    }
  }

  return;
}

int main() {
  prepare();

  ll ans = 0;
  for (int i = 0; i < primes.size(); i++) {
    if (n / primes[i] < pow3[primes[i + 1]]) {
      break;
    }

    int l = i, r = primes.size();
    while (r - l > 1) {
      int mid = (l + r) / 2;
      ll rest = n / primes[i];

      if (pow3[primes[mid]] <= rest) {
        l = mid;
      } else {
        r = mid;
      }
    }

    ans += l - i;
  }

  cout << ans << endl;

  return 0;
}
