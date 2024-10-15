#include <iostream>

using namespace std;

int super(long long x){
    cout << "=> " << x << endl;
    if(x <10) return x;
    int newX = 0;
    while(x){
        cout << x << ":" << newX << endl;
        newX += x % 10;
        x /= 10;
    }
    
    return super(newX);
}

int superDigit(string n, int k){
    long long p = 0;
    for(int i=0; i<n.size(); i++){
        p += n[i] - '0';
    }
    p *= k;
    int ret = super(p);
    return ret;
}

int main() {

    //cout << superDigit("9875", 4);  // 8
    cout << superDigit("148", 3);   // 3
    //cout << superDigit("123", 3);   // 9

    return 0;
}