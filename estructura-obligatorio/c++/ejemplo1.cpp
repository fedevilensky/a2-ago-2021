#include <iostream>
#include "tads/OpenHashTable.cpp"
#include "tads/Hasher.h"

using namespace std;

class HasherInt: public Hasher<int>{
    public:
        int hash(int key) override{
            return key;
        }
};


int main() {
    OpenHashTable<int,int> tabla = OpenHashTable<int,int>(new HasherInt);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int val;
        cin >> val;
        cout << (val * 2) << endl;
    }
}