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

int a, b, c, d;

bool prime(int num) {
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

int main() {
  cin >> a >> b >> c >> d;

  for (int i = a; i <= b; i++) {
    bool secondary = false;
    for (int j = c; j <= d; j++) {
      if (prime(i + j))
        secondary = true;
    }

    if (!secondary) {
      cout << "Takahashi" << endl;
      return 0;
    }
  }

  cout << "Aoki" << endl;
  return 0;
}