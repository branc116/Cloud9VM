#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
    for (int i=1;i<1000000000;i*=10){
        cout << "log(" log10(i) << endl;
    }
    return EXIT_SUCCESS;
}
