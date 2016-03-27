#include <iostream>

using namespace std;

void f(int n){
    if(n==1)
        printf("ok\n");
    else
        f(n-1);
}
int main() {
    f(4);
    cout << "Hello, World!" << endl;
    return 0;
}