#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    if (!(cin >> n)) {
        cerr << "Invalid input for size\n";
        return 1;
    }

    if (n <= 0) {
        cout << "Array size must be positive\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> arr[i])) {
            cerr << "Invalid input for array element\n";
            return 1;
        }
    }

    int largest = numeric_limits<int>::min();
    int secondLargest = numeric_limits<int>::min();

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == numeric_limits<int>::min())
        cout << "No second largest element\n";
    else
        cout << "Second largest element: " << secondLargest << '\n';

    return 0;
}
