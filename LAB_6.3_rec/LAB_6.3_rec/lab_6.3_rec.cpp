#include <iostream>
using namespace std;

int CountEvenElements(int* a, const int size, int i);
template <typename T>
int CountEvenElements(T* a, const int size, int i);

int main() {
    const int n = 10;
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int count1 = CountEvenElements(a, n, 0);
    cout << "CountEvenElements(a, n, 0) = " << count1 << endl;

    int count2 = CountEvenElements<int>(a, n, 0);
    cout << "CountEvenElements<int>(a, n, 0) = " << count2 << endl;

    return 0;
}

int CountEvenElements(int* a, const int size, int i) {
    if (i >= size) {
        return 0;
    }
    return (a[i] % 2 == 0 ? 1 : 0) + CountEvenElements(a, size, i + 1);
}

template <typename T>
int CountEvenElements(T* a, const int size, int i) {
    if (i >= size) {
        return 0;
    }
    if (a[i] % 2 == 0) {
        return 1 + CountEvenElements<T>(a, size, i + 1);
    }
    else {
        return CountEvenElements<T>(a, size, i + 1);
    }
}
