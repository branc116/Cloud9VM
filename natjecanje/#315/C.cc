//©branimir116™
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <iomanip>
#include <list>
#include <queue>

using namespace std;
#define mod 10000007
#define eps (1.0E-9)

struct point{
	double x, y;
};
struct rectangle{
	point point1, point2;
};
struct circle{
	double r;
	point center;
};
bool notprime[mod];
bool polin[mod];
vector <int> prims;
vector <int> polins;
void init(){
	ios::sync_with_stdio(false);
	cout << fixed;
}
int gcd(int a, int b){
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
int lcm(int a, int b){
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}
long long fast_pow(int a, int n){
	long long result = 1;
	long long power = n;
	long long value = a;
	while (power>0)
	{
		if (power & 1)
		{
			result = result*value;
			result = result % mod;
		}
		value = value*value;
		value = value % mod;
		power /= 2;
		//power >>= 1;
	}
	return result;
}
bool prov(string broj){
	
	int size=broj.size()/2+broj.size()%2;
	cout << size << "  " << broj;;
	for (int i=0;i<size;i++){
		cout << "ovde";
		if (broj[i]!=broj[broj.size()-1-i])return false;
	}
	return true;
}
string myto_string(int i){
	string temp="";
	for (int j=i;j;j/10){
		temp=((char)((j%10)+'0'))+temp;
	}
	return temp;
}
void gen(){
	
	for (int j=1;j<100;j++){
		string temp=myto_string(j);
		cout << temp << "  " << j << endl;
		if (prov(temp)){
			cout << "ovde";
			polins.push_back(j);
			cout << j << endl;
		}
	}
	cout << "ovde";
}

int main()
{
	init();
	
	for (int i=2;i<100;i++){
		if (!notprime[i]){
			for (int j=i+i;j<mod;j+=i){
				notprime[j]=true;
			}
			prims.push_back(i);
			cout << i << "  ";
		}
	}
	cout << "tu" ;
	gen();
	
	return 0;
}

