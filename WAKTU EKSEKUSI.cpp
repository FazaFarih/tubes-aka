#include <iostream>
#include <vector>
#include <chrono> // Untuk pengukuran waktu
#include <cstdlib> // Untuk random data

using namespace std;

// Fungsi Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Fungsi Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Fungsi untuk menghasilkan data acak
vector<int> generateRandomData(int size, int maxValue) {
    vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = rand() % maxValue;
    }
    return data;
}

// Fungsi utama
int main() {
    // Ukuran dataset
    vector<int> sizes = {10, 100, 1000, 10000};
    int maxValue = 100000; // Nilai maksimum elemen data

    cout << "Perbandingan Waktu Eksekusi Insertion Sort dan Selection Sort:\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Jumlah Data\tInsertion Sort (ms)\tSelection Sort (ms)\n";

    for (int size : sizes) {
        // Generate data acak
        vector<int> data = generateRandomData(size, maxValue);

        // Copy data untuk masing-masing algoritma
        vector<int> dataForInsertionSort = data;
        vector<int> dataForSelectionSort = data;

        // Pengukuran waktu untuk Insertion Sort
        auto start = chrono::high_resolution_clock::now();
        insertionSort(dataForInsertionSort);
        auto end = chrono::high_resolution_clock::now();
        auto insertionSortTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        // Pengukuran waktu untuk Selection Sort
        start = chrono::high_resolution_clock::now();
        selectionSort(dataForSelectionSort);
        end = chrono::high_resolution_clock::now();
        auto selectionSortTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        // Output hasil
        cout << size << "\t\t" << insertionSortTime << "\t\t\t" << selectionSortTime << "\n";
    }

    return 0;
}
