#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>

using namespace std;
#define mod 1000000007

struct point{
	int x, y;
};
struct rectangle{
	point point1, point2;
};
struct circle{
	double r;
	point center;
};

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
point okvir,slika1,slika2;
int main()
{
    cin >> okvir.x >> okvir.y >> slika1.x >> slika1.y >> slika2.x >> slika2.y;
    if (slika1.x+slika2.x<=okvir.x && slika1.y<=okvir.y && slika2.y<=okvir.y){cout << "YES";return 0;}
	if (slika1.x+slika2.y<=okvir.x && slika1.y<=okvir.y && slika2.x<=okvir.y){cout << "YES";return 0;}
	if (slika1.y+slika2.x<=okvir.x && slika1.x<=okvir.y && slika2.y<=okvir.y){cout << "YES";return 0;}
	if (slika1.y+slika2.y<=okvir.x && slika1.x<=okvir.y && slika2.x<=okvir.y){cout << "YES";return 0;}
	
	if (slika1.y+slika2.y<=okvir.y && slika1.x<=okvir.x && slika2.x<=okvir.x){cout << "YES";return 0;}
	if (slika1.y+slika2.x<=okvir.y && slika1.x<=okvir.x && slika2.y<=okvir.x){cout << "YES";return 0;}
	if (slika1.x+slika2.y<=okvir.y && slika1.y<=okvir.x && slika2.x<=okvir.x){cout << "YES";return 0;}
	if (slika1.x+slika2.x<=okvir.y && slika1.y<=okvir.x && slika2.y<=okvir.x){cout << "YES";return 0;}
	cout << "NO";
	return 0;
}

