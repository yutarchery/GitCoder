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

bool isPrime(int number){
  if (number == 1) return false;
  for (int i = 2; i * i <= number; i++){
    if (number % i == 0) return false;
  }
  return true;
}

ll GCD(ll A, ll B){
  if (A < B) swap(A, B);
  while (A % B != 0){
    A %= B; swap(A, B);
  }
  return B;
}

int N; 
ll X[55], ans = 1;
vector <ll> Prime;

ll calcNowNumber(int indexNum){
  ll res = 1;
  for (int i = 0; i < Prime.size(); i++){
    if (indexNum % 2 != 0) res *= Prime[i];
    indexNum /= 2; 
  }
  return res;
}

bool check(ll nowNumber){
  for (int i = 0; i < N; i++){
    if (GCD(nowNumber, X[i]) == 1) return false;
  }
  return true;
}

int main(){
  ll ans = 1;
  for (ll i = 2; i <= 50; i++){
    if (isPrime(i)) {
      ans *= i;  
      Prime.push_back(i);
    }
  }

  cin >> N;
  for (int i = 0; i < N; i++) cin >> X[i];

  int primeSize = Prime.size();
  for (int i = 0; i < (1<<primeSize); i++){
    ll nowNumber = calcNowNumber(i);
    if (check(nowNumber)){
      ans = min(ans, nowNumber);
    }
  }
  cout << ans << endl;

  return 0;
}