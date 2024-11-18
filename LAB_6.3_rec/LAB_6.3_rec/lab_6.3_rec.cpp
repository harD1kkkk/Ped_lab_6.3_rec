#include <iostream>
#include <iomanip>
using namespace std;

int CountEvenElements(int* a, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    if (a[i] % 2 == 0) {
        return 1 + CountEvenElements(a, size, i + 1);
    }
    else {
        return CountEvenElements(a, size, i + 1);
    }
}

template <typename T>
int CountEvenElements(T* a, const int size, int i = 0) {
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

void CreateArrayWithRandomElements(int* a, int numberOfElements, int start, int end, int i = 0) {
    if (i < numberOfElements) {
        a[i] = start + rand() % (end - start + 1);
        CreateArrayWithRandomElements(a, numberOfElements, start, end, i + 1);
    }
}

template <typename T>
void CreateArrayWithRandomElements(T* a, int numberOfElements, int start, int end, int i = 0) {
    if (i < numberOfElements) {
        a[i] = start + rand() % (end - start + 1);
        CreateArrayWithRandomElements<T>(a, numberOfElements, start, end, i + 1);
    }
}

void PrintArray(int* a, int size, int i = 0) {
    if (i < size) {
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
        PrintArray(a, size, i + 1);
    }
}

template <typename T>
void PrintArray(T* a, int size, int i = 0) {
    if (i < size) {
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
        PrintArray<T>(a, size, i + 1);
    }
}

int main() {
    srand((unsigned)time(NULL));

    const int size = 10;
    int a[size];

    cout << "Create Array" << endl;
    CreateArrayWithRandomElements(a, size, -20, 34, 0);

    cout << "Print" << endl;
    PrintArray(a, size, 0);

    int count1 = CountEvenElements(a, size);
    cout << "CountEvenElements (function) = " << count1 << endl;

    cout << endl;

    cout << "Create Array(template)" << endl;
    CreateArrayWithRandomElements<int>(a, size, -20, 34, 0);

    cout << "Print(template)" << endl;
    PrintArray<int>(a, size, 0);

    int count2 = CountEvenElements<int>(a, size);
    cout << "CountEvenElements (template) = " << count2 << endl;

    return 0;
}
