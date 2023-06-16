#include <iostream>
using namespace std;

int arr[101];
int size, element, pos;

class ArrayClass {
    public:
    bool isFull() {
        return size == 101;
    }

    bool isEmpty() {
        return size == 0;
    }

    void insStart() {
        if (isFull()) {
            cout << "\nArray Size Exausted!";
        }
        else {
            cout << "\nEnter Element to Insert: ";
            cin >> element;
            for (int i=size-1;i>=0;i--) {
                arr[i+1]=arr[i];
            }
            arr[0]=element;
            size++;
            cout << "Element Inserted!";
        }
    }

    void insEnd() {
        if (isFull()) {
            cout << "\nArray Size Exausted!";
        }
        else {
            cout << "\nEnter Element to Insert: ";
            cin >> element;
            arr[size]=element;
            size++;
            cout << "Element Inserted!";
        }
    }

    void insPos() {
        if (isFull()) {
            cout << "\nArray Size Exausted!";
        }
        else {
            cout << "\nEnter Position: ";
            cin >> pos;
            if (pos <= 0 || pos > size+1) {
                cout << "Position out of Bounds!";
            }
            else {
                cout << "\nEnter Element to Insert: ";
                cin >> element;
                for (int i = size - 1; i >= pos - 1; i--) {
                    arr[i + 1] = arr[i];
                }
                arr[pos - 1] = element;
                size++;
                cout << "Element Inserted!";
            }
        }
    }

    void delStart() {
        if (isEmpty()) {
            cout << "\nArray Empty!";
        }
        else {
            for (int i=0;i<size;i++) {
                arr[i]=arr[i+1];
            }
            size--;
            cout << "\nElement Deleted!";
        }
    }

    void delEnd() {
        if (isEmpty()) {
            cout << "\nArray Empty!";
        }
        else {
            if (isEmpty()) {
                cout << "\nArray Empty!";
            }
            size--;
            cout << "\nElement Deleted!";
        }
    }

    void delPos() {
        cout<<"\nEnter Position of Element you want to Delete: ";
        cin>>pos;
        if(pos<=0 || pos>=size) {
            cout<<"Enter Valid Position!";
        }
        else {
            for (int i=pos-1;i<size;i++) {
                arr[i]=arr[i+1];
            }
            size--;
            cout << "Element Deleted!";
        }
    }

    void search() {
        cout << "\nDisplaying Provided Elements after Sorting: ";
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                int temp;
                if (arr[i]<arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        for (int i = 0; i<size; i++) {
            cout << arr[i] << " ";
        }
        int key;
        bool isFound = false;
        cout << "\nEnter Key to be Searched: ";
        cin >> key;
        cout << "\nSearching...";
        int low = 0;
        int high = size - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (key == arr[mid]) {
                isFound = true;
                break;
            }
            if (key > arr[mid]) {
                low = mid + 1;
            }
            if (key < arr[mid]) {
                high = mid - 1;
            }
        }
        if (isFound) {
            cout << "\n" << key << " Found at Position " << mid + 1;
        }
        else {
            cout << "\n" << key << " Not Found";
        }
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    void reverse() {
        int start = 0;
        int end = size-1;
        while (start < end) {
            char temp;
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        cout << "\nElements Sorted!";
    }

    void display() {
        if (isEmpty()) {
            cout << "\nArray Empty!";
        }
        else {
            cout << "\nDisplaying Elements in the Array...\n";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
        }
    }
};

int main() {
    ArrayClass arrObject;
    cout << "\nEnter Array Size: ";
    cin >> size;
    cout << "\nEnter Elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    int choice;
    do {
        cout << "\n\n1 to Insert At Start \n2 to Insert At End \n3 to Insert at specific Position";
        cout << "\n4 to Delete from Start \n5 to Delete from End \n6 to Delete from specific Position";
        cout << "\n7 to Search \n8 to Sort \n9 to Reverse \n10 to Display";
        cout << "\n0 to Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            arrObject.insStart();
            break;
        case 2:
            arrObject.insEnd();
            break;
        case 3:
            arrObject.insPos();
            break;
        case 4:
            arrObject.delStart();
            break;
        case 5:
            arrObject.delEnd();
            break;
        case 6:
            arrObject.delPos();
            break;
        case 7:
            arrObject.search();
            break;
        case 8:
            arrObject.sort();
            break;
        case 9:
            arrObject.reverse();
            break;
        case 10:
            arrObject.display();
            break;
        case 0:
            break;
        default:
            cout<<"\nInvalid Choice! Please Choose Again!";
            break;
        }
    } while (choice!=0);
    return 0;
}