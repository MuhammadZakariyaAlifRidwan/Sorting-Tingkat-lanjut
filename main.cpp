#include <iostream>
using namespace std;

void printdata(int data[], int n)
{
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
}

void bubblesort(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j] > data[j + 1])
                swap(data[j], data[j + 1]);
        }
        cout << "Tahap : " << i + 1 << endl;
        printdata(data, n);
    }
}

void insertsort(int data[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        int temp = data[i];
        while (j > 0 && (data[j - 1] > temp))
        {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = temp;
        cout << "Tahap : " << i << endl;
        printdata(data, n);
    }
}

void selectionsort(int data[], int n)
{
    for (int posawal = 0; posawal < n - 1; posawal++)
    {
        int posmin = posawal;
        for (int i = posawal + 1; i < n; i++)
        {
            if (data[posmin] > data[i])
                posmin = i;
        }
        if (posawal != posmin)
            swap(data[posawal], data[posmin]);
        cout << "Tahap : " << posawal + 1 << endl;
        printdata(data, n);
    }
}

int main()
{
    ulang:
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int* data = new int[n];
    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    cout << "Data asal:" << endl;
    printdata(data, n);

    ulang2:
    cout << "Pilih metode pengurutan: " << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;

    int pilihan;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    cout << "Proses Sorting:" << endl;
    switch (pilihan)
    {
    case 1:
        bubblesort(data, n);
        break;
    case 2:
        system("CLS");
        insertsort(data, n);
        break;
    case 3:
        system("CLS");
        selectionsort(data, n);
        break;
    default:
        system("CLS");
        cout << "Pilihan tidak valid." << endl;
        goto ulang2;
        break;
    }

    cout << endl << "Data urut:" << endl;
    printdata(data, n);

    delete[] data;
    return 0;
}

