#include <iostream>

using namespace std;

void insert_sort(int A[], int n){
    
    for(int i = 0; i < n; i++){
        int cur_value = A[i];
        int j = i -1;
        while(j>= 0 and A[j] > cur_value){
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = cur_value;
    }
}

bool is_sorted(int A[], int n){
    for(int i = 0; i < n ; i++){
        if (A[i + 1] < A[i]){
            return false;
        }
    }
    return true;
}

void merge(int a[], int st, int  mid, int end){
    int aux1 = mid - st;
    int aux2 = end - mid;
    int * left = new int[aux1];
    int * right = new int[aux2];
    
    for(int i = 0; i < aux1; i++){
        left[i] = a[st + i];
    }
    for (int j = 0; j < aux2; j++){
        right[j] = a[mid + j];
    }
    
    int i = 0;
    int j = 1;
    
    for (int k = st; k < end; k++){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i = i + 1;
        }
        else{
            a[k] = right[j];
            j = j + 1;
        }
    }
}

void merge_sort(int a[], int st, int end){
    //if (size <= 1){
    //    return
    //}
    if (st < end){
        int mid = ((st + end)/2);
        merge_sort(a, st, mid);
        merge_sort(a, mid + 1, end);
        merge(a, st, mid, end);
    }
    
}

//Extend 

int main()
{   
    //Create the random lists
    int a[] = {2,3,4,8,1};
    int n = 5;
    
    //Uma vez que a é ordenada, então esse vetor ordenado ocupa o mesmo espaço de memória?
    //int * sorted_a = new int[n];
    
    //for (int i; i < n; i++){
    //    sorted_a[i] = a[i];
    //}
    
    //int sorted_a[5] = insert_sort(a, n); insert_sort é uma função void
    insert_sort(a, n); 
    
    if (is_sorted(a, n) == false){
        cout << "ERROR!" << endl;
    }
    else{
        cout << "Olá mundooooo" << endl;
    }
    
    int ab = 2.5; 
    cout << "oi" <<  ab  << "love" << endl;
    
    int nc = 9;
    int ac[] = {2,1,4,5,7,9,3, 6, 0};
    int b = 0;
    merge_sort(ac, b, n);
    bool sorted = is_sorted(ac, n);
    cout << sorted << endl;
    return 0;
}