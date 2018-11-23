#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

using ll = long long int;
const ll mod = 1000000007;

ll calc(ll number)
{
  ll result = 1;
  if(number == 0) return result;
  for(int i = 0; i < 10; i++)
  {
    result *= number;
    result %= mod;
  }
  return result;
}

int main(){
  int n;
  cin >> n;
  ll count = 0;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  for(int i = 1; i <= n; i++)
  {
    ll temp;
    if(i == 1)
    {
      temp = calc(i);
    }else{
      temp = calc(i) + mod - calc(i - 1);
    }
    temp = (temp * calc(floor((double)(n / i)))) % mod;
    count += temp;
    count %= mod;
  }
  cout << count << endl;
	return 0;
}
