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

int count_elem(int num) {
  if (num == 1) {
    return 1;
  }

  int rest = num, res = 1;
  for (int i = 2; i * i <= num; i++) {
    int cnt = 0;
    while (rest % i == 0) {
      rest /= i;
      cnt++;
    }
    res *= cnt + 1;
  }

  if (rest > 1) {
    res *= 2;
  }
  return res;
}

int main() {
  int x, y;
  cin >> x >> y;

  if (count_elem(x) > count_elem(y)) {
    cout << "X" << endl;
  } else if (count_elem(x) < count_elem(y)) {
    cout << "Y" << endl;
  } else {
    cout << "Z" << endl;
  }

  return 0;
}