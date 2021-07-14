// DoublePointerArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;
template <typename T>
T** AllocateDynamic_2D_Array(int nRows, int nCols){
    T** dynamicArray;
    dynamicArray = new T * [nRows];
    for (int i = 0; i < nRows; i++)
        dynamicArray[i] = new T[nCols];

    return dynamicArray;
}

template <typename T>
void FreeDynamicArray(T** dArray){
    delete[] * dArray;
    delete[] dArray;
}

int main()
{
    int nRows=12, nCols =5;
    string** my2dArr = AllocateDynamic_2D_Array<string>(nRows, nCols);
    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {
            my2dArr[r][c] = "A";
        }
    }
    string name = "Ali";
    string* ptr = &name;
    my2dArr[0][0] = *ptr;
    my2dArr[2][2] = "Mustafa";
    
    cout <<"*" << "\t" << "C[1]" <<"\t" << "C[2]" << "\t" << "C[3]" << "\t" << "C[4]" << "\t" << "C[5]" << "\n";
    for (int r = 0; r < nRows; r++) {
        cout << "R["<<r+1 << "]:\t";
        for (int c = 0; c < nCols; c++) {
            cout<<my2dArr[r][c]<<"\t";
        }
        cout << "\n";
    }

    FreeDynamicArray<string>(my2dArr);

    const int num_rows = 10;
    const int num_cols = 20;
    string** C = new string * [num_rows];
    for (int i = 0; i < num_rows; i++)
    {
        // Then, the type of C[i] is int*
        // It's a pointer to an element of type int
        // This pointer not allocated yet, you have now to allocate it
        C[i] = new string[num_cols];
    }

    return 0;
}
