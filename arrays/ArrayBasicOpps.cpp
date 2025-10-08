#include <iostream>
using namespace std;

class ArrayOperations {
private:
    int* arr;
    int n;
public:
    ArrayOperations(int size) : n(size) {
        arr = new int[n];
    }

    ~ArrayOperations() {
        delete[] arr;
    }

    void inputElements() {
        cout << "Enter the elements: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void displayElements() {
        cout << "The elements are: " << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    void insertElement(int pos, int x) {
        for (int i = n - 1; i >= pos; i--) {
            arr[i + 1] = arr[i];
        }
        arr[pos] = x;
        n++;
    }

    void deleteElement(int pos) {
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    void linearSearch(int x) {
        int found_index = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                found_index = i;
                break;
            }
        }

        if (found_index != -1) {
            cout << "The element is present at " << found_index + 1 << " position." << endl;
        } else {
            cout << "The element is not found in the array." << endl;
        }
    }

    void binarySearch(int x) {
        int LB = 0, UB = n - 1, MID;
        int found_index = -1;

        while (LB <= UB) {
            MID = (LB + UB) / 2;
            if (arr[MID] == x) {
                found_index = MID;
                break;
            } else if (arr[MID] < x) {
                LB = MID + 1;
            } else {
                UB = MID - 1;
            }
        }

        if (found_index != -1) {
            cout << "The element is found at position " << found_index + 1 << "." << endl;
        } else {
            cout << "The element is not found in the array." << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the number of elements for the array: " << endl;
    cin >> size;

    ArrayOperations arrayOps(size);
    arrayOps.inputElements();
    arrayOps.displayElements();

    int choice, pos, x;
    do {
        cout << "Menu:" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display Elements" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter position for insertion: " << endl;
                cin >> pos;
                cout << "Enter the element to be inserted: " << endl;
                cin >> x;
                arrayOps.insertElement(pos, x);
                break;
            case 2:
                cout << "Enter position for deletion: " << endl;
                cin >> pos;
                arrayOps.deleteElement(pos);
                break;
            case 3:
                cout << "Enter the element for linear search: " << endl;
                cin >> x;
                arrayOps.linearSearch(x);
                break;
            case 4:
                cout << "Enter the element for binary search: " << endl;
                cin >> x;
                arrayOps.binarySearch(x);
                break;
            case 5:
                arrayOps.displayElements();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}