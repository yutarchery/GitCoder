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

ll a, n;
int ans[int(1e6 + 5)];
bool visited[int(1e6 + 5)];

int digitCount(int num) {
  int ans = 0;
  while (num > 0) {
    ans++;
    num /= 10;
  }
  return ans;
}

int transform(int num) {
  int digit = digitCount(num);

  int devide = 1;
  for (int i = 0; i < digit - 1; i++) {
    devide *= 10;
  }

  int top = num / devide;
  int rest = num / 10;

  return (num % 10) * devide + rest;
}

int main() {
  cin >> a >> n;

  queue<ll> que;
  que.push(1);
  visited[1] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    if (q == n) {
      cout << ans[q] << endl;
      return 0;
    }

    if (q * a < 1e6 && !visited[q * a]) {
      visited[q * a] = true;
      ans[q * a] = ans[q] + 1;
      que.push(q * a);
    }

    if (q % 10 != 0 && q >= 10) {
      int next = transform(q);
      if (!visited[next]) {
        visited[next] = true;
        ans[next] = ans[q] + 1;
        que.push(next);
      }
    }
  }

  cout << -1 << endl;

  return 0;
}