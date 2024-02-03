#include<bits/stdc++.h>
using namespace std;


int arr[] = {2,4,1,-2,0,19,29,-7,20};

void display(int n){
    for(int i = 0; i<9;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int n){
    for(int i = 0; i<n-1;i++){
        int check = 1;
        for(int j = 0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                check = 0;
            }
        }
        if(check==1)break;
    }
}

void insertion_sort(int n){
    for(int i = 1; i<=(n-1);i++){
        int j = i-1;
        int x = arr[i];
        while(j>=0 && arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}

void selection_sort(int n){
    for(int i = 0; i<n-1;i++){
        int min = i;
        for(int j = i+1;j<n;j++){
            if(arr[min]>arr[j])min=j;
        }
        if(i!=min)swap(&arr[i],&arr[min]);
    }
}

void merge(int arr[],int low,int mid,int high){
    int temp[high-low+1];
    int k = 0,i=low,j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){temp[k]=arr[i];k++;i++;}
        else{temp[k]=arr[j];k++;j++;}
    }
    while(i<=mid){temp[k]=arr[i];i++;k++;}
    while(j<=high){temp[k]=arr[j];j++;k++;}

    for(int h = low;h<=high;h++){
        arr[h]=temp[h-low];
    }
}

void merge_sort(int arr[], int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    printf("Initially: ");
    display(arr,9);

    // bubble_sort(arr,9);
    // insertion_sort(arr,9);
    // selection_sort(arr,9);
    merge_sort(arr,0,8);
    printf("Finally: ");
    display(arr,9);
    return 0;
}