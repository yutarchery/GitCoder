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

ll pows[40], digits[40];
map<ll, bool> visited;
vector<ll> nums;

ll calc_digit(ll num) {
  int cnt = 0;
  while (num > 0) {
    cnt++;
    num /= 10;
  }
  return cnt;
}

void prepare(int num) {
  for (int i = 0; i <= 40; i++) {
    if (pows[i] == 0) {
      break;
    }

    ll next = num * pow(10, calc_digit(pows[i])) + pows[i];
    if (next > ll(1e9)) {
      break;
    }

    if (!visited[next]) {
      visited[next] = true;
      nums.emplace_back(next);
      prepare(next);
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  pows[0] = 1;
  digits[0] = 1;
  for (int i = 1; i < 40; i++) {
    pows[i] = pows[i - 1] * 2;
    digits[i] = calc_digit(pows[i]);
    if (pows[i] > ll(1e9)) {
      break;
    }
  }

  nums.emplace_back(0);
  visited[0] = true;
  prepare(0);
  sort(nums.begin(), nums.end());

  int n;
  cin >> n;
  cout << nums[n] << endl;

  return 0;
}
