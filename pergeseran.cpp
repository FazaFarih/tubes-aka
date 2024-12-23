#include <iostream>
#include <vector>
#include <chrono> // Untuk pengukuran waktu
#include <cstdlib> // Untuk random data

using namespace std;

// Fungsi Insertion Sort dengan penghitungan operasi pergeseran dan pertukaran
void insertionSort(vector<int>& arr, int& shiftCount, int& swapCount) {
    int n = arr.size();
    shiftCount = 0;
    swapCount = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shiftCount++;
        }
        arr[j + 1] = key;
        swapCount++; // Menghitung setiap penyisipan dianggap sebagai satu swap
    }
}

// Fungsi Selection Sort dengan penghitungan operasi pergeseran dan pertukaran
void selectionSort(vector<int>& arr, int& shiftCount, int& swapCount) {
    int n = arr.size();
    shiftCount = 0;
    swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
            shiftCount++; // Menghitung setiap perbandingan sebagai pergeseran
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swapCount++;
        }
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
    vector<int> sizes = {10, 100, 1000};
    int maxValue = 10000; // Nilai maksimum elemen data

    cout << "Perbandingan Operasi Pergeseran dan Pertukaran:\n";
    cout << "------------------------------------------------\n";
    cout << "Algoritma\tJumlah Data\tOperasi Pergeseran\tOperasi Pertukaran\n";

    for (int size : sizes) {
        // Generate data acak
        vector<int> data = generateRandomData(size, maxValue);

        // Salin data untuk masing-masing algoritma
        vector<int> dataForInsertionSort = data;
        vector<int> dataForSelectionSort = data;

        // Variabel untuk menghitung operasi
        int shiftCountInsertion = 0, swapCountInsertion = 0;
        int shiftCountSelection = 0, swapCountSelection = 0;

        // Jalankan Insertion Sort
        insertionSort(dataForInsertionSort, shiftCountInsertion, swapCountInsertion);

        // Tampilkan hasil untuk Insertion Sort
        cout << "Insertion Sort\t" << size << "\t\t" << shiftCountInsertion << "\t\t\t" << swapCountInsertion << "\n";

        // Jalankan Selection Sort
        selectionSort(dataForSelectionSort, shiftCountSelection, swapCountSelection);

        // Tampilkan hasil untuk Selection Sort
        cout << "Selection Sort\t" << size << "\t\t" << shiftCountSelection << "\t\t\t" << swapCountSelection << "\n";
    }

    return 0;
}
