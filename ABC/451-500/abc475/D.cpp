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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

string s;

vector<int> primes[7];
bool visited[int(1e7 + 5)];

int digits(int num) {
  int res = 0;
  while (num > 0) {
    res++;
    num /= 10;
  }
  return res;
}

void prepare() {
  for (int i = 2; i <= int(1e7); i++) {
    if (visited[i]) {
      continue;
    }
    primes[digits(i)].emplace_back(i);

    for (int j = i; j <= int(1e7); j += i) {
      visited[j] = true;
    }
  }

  return;
}

bool solve(int num) {
  bool visited_num[10] = {};
  char now_char[10] = {};

  for (int i = s.length() - 1; i >= 0; i--) {
    if (visited_num[num % 10]) {
      if (now_char[num % 10] != s[i]) {
        return false;
      }
    } else {
      visited_num[num % 10] = true;
      now_char[num % 10] = s[i];
    }
    num /= 10;
  }

  for (int i = 0; i < 10; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (visited_num[i] && visited_num[j]) {
        if (now_char[i] == now_char[j]) {
          return false;
        }
      }
    }
  }

  return true;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  prepare();

  cin >> s;
  for (int i : primes[s.length()]) {
    if (solve(i)) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';

  return 0;
}
