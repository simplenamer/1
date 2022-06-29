#include <iostream>

void swap(int& a, int& b){
    int y = a;
    a = b;
    b = y;
}

void swap(float* a, float* b, int n){
    float c[n];
    for (size_t i = 0; i < n; i++)
    {
        c[i] = a[i];
        a[i] = b[i];
        b[i] = c[i];
    }
    
}

int* bubble_sort(int* arr, int n){

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            if(arr[j - 1] > arr[j]) swap(arr[j - 1], arr[j]);
        }
    }
    
    return arr;
}

int* v_sort(int* arr, int n){

    for (size_t i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j])
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
        
    }
    
    
    return arr;
}



void out(int* arr, int n){
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    //int arr1[9] = {5, 5, 9, 7, 89, 67, 12, 55, 24};

    float arr[3][3] = {{12, 12, 98}, {12, 15, 55}, {76, 89, 65}};

    //out(bubble_sort(arr, 9), 9);
    //out(v_sort(arr, 9), 9);

    float d = 1;

    size_t j = 0;
    for (size_t i = 0; i < 3 - 1; i++)
    {
        //j = i + 1;
        //if(arr[i][i] == 0){
        //    swap(arr[i], arr[j], 4);
        //    j++;
        //}
        for (j = i + 1; j < 3; j++)
        {

            for (size_t k = i; k < 3; k++)
            {
                arr[j][k] = arr[j][k] - arr[i][k]*arr[j][i]/arr[i][i];
            }
            
        }
        
    }

    for (size_t i = 0; i < 3; i++)
    {
        d*= arr[i][i];
    }
    
    std::cout << d;
    
}