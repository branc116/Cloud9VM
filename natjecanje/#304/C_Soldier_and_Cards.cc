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
#define mod 1000000007
#define eps (1.0E-9)

queue<int> a,b;
int n;
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
void ispis(){
    queue<int> c=a,d=b;
    cout << "A: ";
    for (;!c.empty();c.pop()){
        cout << c.front() << " ";
    }
    cout << endl << "B: ";
    for (;!d.empty();d.pop()){
        cout << d.front() << " ";
    }
    cout << endl;
}
void upis(){
    cin >> n;
    int temp1,temp2,temp;
    cin >> temp1;
    for (int i=0;i<temp1;i++){
        cin >> temp;
        a.push(temp);
    }
    cin >> temp2;
    for (int i=0;i<temp2;i++){
        cin >> temp;
        b.push(temp);
    }
}
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

int main()
{
	init();
	upis();
	for (int i=0;i<9000000;i++){
	   // ispis();
	   // cout << "tu";
	    if (b.empty()){
	        cout << i << ' '<< 1 << endl;
	        return 0;
	    }
	    if (a.empty()){
	        cout << i << ' ' << 2 << endl;
	        return 0;
	    }
	    if (a.front()>b.front()){
	        a.push(b.front());a.push(a.front());
	        a.pop();b.pop();
	    }else{
	        b.push(a.front());b.push(b.front());
	        a.pop();b.pop();
	    }
	    
	}
	cout << -1;
	return 0;
}

