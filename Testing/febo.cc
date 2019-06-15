#include <iostream>

using namespace std;
long long int  n[100000];
long long int febo(int i){
    if (!n[i]){long long int  broj=febo(i-1)+febo(i-2);n[i]=broj;return broj;}
    return n[i];
}

int main(){
    
    n[1]=1;
    n[2]=1;
    int i=9;
    cout << " ahhdadhadhada  " << i << i;
   
    
}