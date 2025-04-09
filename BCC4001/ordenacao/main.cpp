#include "ordenarelem.h"
#include <vector>
#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> myVec(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> myVec[i];
    }

    vector<int> result = ordenar(myVec);

    cout << "Sorted vector: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

