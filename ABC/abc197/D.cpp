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

double N, X0, Y0, Xn, Yn;

int main(){
  cin >> N;
  cin >> X0 >> Y0;
  cin >> Xn >> Yn;

  double theta = PI / N * 2;

  double x = (X0 - Xn) / 2, y = (Y0 - Yn) / 2;

  double ansx = x * cos(theta) - y * sin(theta);
  double ansy = x * sin(theta) + y * cos(theta);

  ansx += (X0 + Xn) / 2;
  ansy += (Y0 + Yn) / 2;
  cout << setprecision(32) << ansx << " " << ansy << endl;

  return 0;
}