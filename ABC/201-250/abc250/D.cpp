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

bool judgePrime(ll number) {
  if (number == 1) {
    return false;
  }

  for (ll i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

ll n;
vector<ll> primes;

int ans = 0;

int main() {
  cin >> n;

  primes.push_back(2);
  for (ll i = 3; i <= int(1e6); i += 2) {
    if (judgePrime(i)) {
      primes.push_back(i);
    }
  }

  int p = primes.size();
  for (int i = 0; i < p - 1; i++) {
    ll rest = n / primes[i];
    if (rest < primes[i + 1] * primes[i + 1] * primes[i + 1]) {
      break;
    }

    int l = i + 1, r = p;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      ll sum = primes[mid] * primes[mid] * primes[mid];
      if (rest < sum) {
        r = mid;
      } else {
        l = mid;
      }
    }
    ans += l - i;
  }

  cout << ans << endl;

  return 0;
}