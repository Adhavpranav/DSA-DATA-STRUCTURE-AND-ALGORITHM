#include<iostream>
using namespace std;
class Sort {
public:
    void merge(int a[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int a1[100], a2[100];
        for (int i = 0; i < n1; i++)
            a1[i] = a[left + i];
        for (int j = 0; j < n2; j++)
            a2[j] = a[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (a1[i] <= a2[j])
                a[k++] = a1[i++];
            else
                a[k++] = a2[j++];
        }
        while (i < n1)
            a[k++] = a1[i++];
        while (j < n2)
            a[k++] = a2[j++];
    }
    void mergeSort(int a[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(a, left, mid);
            mergeSort(a, mid + 1, right);
            merge(a, left, mid, right);
        }
    }
    void printArray(int a[], int limit) {
        for (int i = 0; i < limit; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};
int main() {
    Sort ob;
    int a[100], limit;
    cout << "Enter limit: ";
    cin >> limit;
    cout << "Enter array elements: ";
    for (int i = 0; i < limit; i++)
        cin >> a[i];
    cout << "Given array is: ";
    ob.printArray(a, limit);
    ob.mergeSort(a, 0, limit - 1);
    cout << "Sorted array: ";
    ob.printArray(a, limit);
    return 0;
}
