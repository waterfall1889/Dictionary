#include <iostream>
#include "dictionary.h"
#include "dictionary.cpp"

using namespace std;

int main() {
    Dictionary<int,char> alphabet;
    for(int i=0;i<=6;++i){
        int n;char alpha;
        cin>>n>>alpha;
        alphabet.put(n,alpha);
    }
    alphabet.remove(7);
    alphabet.printAll();
    return 0;
}
