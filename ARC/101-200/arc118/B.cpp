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

int k;
ll n, m, a[int(1e5 + 5)], b[int(1e5 + 5)];
priority_queue<Pli> que;

int main() {
  cin >> k >> n >> m;

  ll rest = m;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    b[i] = a[i] * m / n;
    que.push({abs(n * b[i] - m * a[i]), i});
    rest -= b[i];
  }

  for (int i = 0; i < rest; i++) {
    Pli q = que.top();
    que.pop();
    b[q.second]++;
  }

  cout << b[0];
  for (int i = 1; i < k; i++) {
    cout << " " << b[i];
  }
  cout << endl;

  return 0;
}