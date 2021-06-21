#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

double T, L, X, Y, E;
int Q;

int solve(){
  double y = -1 * L / 2 * sin(2 * PI * E / T);
  double z = L / 2 * (1 - cos(2 * PI * E / T));
  double dist = sqrt(X * X + (Y - y) * (Y - y) + z * z);
  cout << setprecision(32) << asin(z / dist) * (2 / PI) * 90 << endl;
  return 0;
}

int main(){
  cin >> T;
  cin >> L >> X >> Y;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    cin >> E;
    solve();
  }

  return 0;
}