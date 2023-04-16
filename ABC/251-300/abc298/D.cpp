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

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD2;
  }
}

int q;
int head_idx = 0;
ll now = 1;
string s = "1";

int main() {
  cin >> q;
  for (int i = 0; i < q; i++) {
    int num;
    cin >> num;

    if (num == 1) {
      int next;
      cin >> next;
      s += '0' + next;
      now = (now * 10 + next) % MOD2;
    } else if (num == 2) {
      ll head_digit = s[head_idx] - '0';
      ll num_to_delete =
          head_digit * my_pow(10, s.length() - (head_idx + 1)) % MOD2;

      now -= num_to_delete;
      now %= MOD2;
      if (now < 0) {
        now += MOD2;
      }

      head_idx++;
    } else {
      cout << now << endl;
    }
  }

  return 0;
}