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

ll GCD(ll A, ll B){
  if (A < B) swap(A, B);
  while (A % B != 0){
    A %= B;
    swap(A, B);
  }
  return B;
}

ll LCM(ll A, ll B){
  ll G = GCD(A, B);
  return A / G * B;
}

int N;
ll T[105], ans = 1;

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> T[i];
    ans = LCM(ans, T[i]);
  }
  cout << ans << endl;


  return 0;
}