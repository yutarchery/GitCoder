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

int d;
string a, b;

int num_a, num_b, digit[105];
int cnt_a, cnt_b;
bool flag_a = false, flag_b = false;

int main() {
  cin >> d >> a >> b;

  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '.') {
      flag_a = true;
      continue;
    }

    if (!flag_a) {
      num_a *= 10;
      num_a += a[i] - '0';
    } else {
      digit[cnt_a] += a[i] - '0';
      cnt_a++;
    }
  }
  for (int i = 0; i < b.length(); i++) {
    if (b[i] == '.') {
      flag_b = true;
      continue;
    }

    if (!flag_b) {
      num_b *= 10;
      num_b += b[i] - '0';
    } else {
      digit[cnt_b] += b[i] - '0';
      cnt_b++;
    }
  }

  for (int i = d - 1; i >= 1; i--) {
    digit[i - 1] += digit[i] / 10;
    digit[i] %= 10;
  }
  num_a += digit[0] / 10;
  digit[0] %= 10;

  cout << num_a + num_b << ".";
  for (int i = 0; i < d; i++) {
    cout << digit[i];
  }
  cout << endl;

  return 0;
}
