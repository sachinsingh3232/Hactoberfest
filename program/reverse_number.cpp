#include <iostream>
using namespace std;

int main() {
    int num,n, r,rev=0;
    cout << "Enter a  integer: ";
    cin >> num;
    n=num;
    while(num!=0){
    r=num%10;
    rev=(rev*10)+r;
    num=num/10;
    }
    
        cout <<"reverse of number  "<<n<<" is "<<rev;

    return 0;
}