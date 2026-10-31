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

string n;
int digit[505];
ll dp1[505][1024][3], dp2[505][1024][3];

bool judge(int j, int k) {
  int res = 0;

  if ((j & (1 << 3)) != 0) {
    res++;
  }
  if (k % 3 == 0) {
    res++;
  }
  int cnt = 0;
  for (int i = 0; i <= 9; i++) {
    if ((j & (1 << i)) != 0) {
      cnt++;
    }
  }
  if (cnt == 3) {
    res++;
  }

  return (res == 1);
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n.length(); i++) {
    digit[i] = n[i] - '0';
  }

  for (int num = 1; num < digit[0]; num++) {
    dp1[0][(1 << num)][num % 3]++;
  }
  dp2[0][(1 << digit[0])][digit[0] % 3]++;

  for (int i = 1; i < n.length(); i++) {
    for (int num = 1; num <= 9; num++) {
      dp1[i][(1 << num)][num % 3]++;
    }

    for (int j = 0; j < 1024; j++) {
      for (int k = 0; k < 3; k++) {
        for (int nxt = 0; nxt <= 9; nxt++) {
          dp1[i][(j | (1 << nxt))][(k * 10 + nxt) % 3] += dp1[i - 1][j][k];
          dp1[i][(j | (1 << nxt))][(k * 10 + nxt) % 3] %= MOD2;
        }

        for (int nxt = 0; nxt < digit[i]; nxt++) {
          dp1[i][(j | (1 << nxt))][(k * 10 + nxt) % 3] += dp2[i - 1][j][k];
          dp1[i][(j | (1 << nxt))][(k * 10 + nxt) % 3] %= MOD2;
        }

        dp2[i][(j | (1 << digit[i]))][(k * 10 + digit[i]) % 3] +=
            dp2[i - 1][j][k];
        dp2[i][(j | (1 << digit[i]))][(k * 10 + digit[i]) % 3] %= MOD2;
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j < 1024; j++) {
    for (int k = 0; k < 3; k++) {
      if (judge(j, k)) {
        ans += dp1[n.length() - 1][j][k];
        ans += dp2[n.length() - 1][j][k];
        ans %= MOD2;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
