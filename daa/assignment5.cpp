#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int sort(vector<int>&arr, int lb, int ub){//dont pass vector by not value
    int start=lb;
    int end=ub;
    int pivot= arr[lb];//not pivot= arr[0]
    while(start<end){
        while(start<=ub && arr[start]<=pivot){//two conditions remember the first one
            start++;
        }
        while(end>=lb && arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[lb], arr[end]);// its arr[end] not end
    return end;
}

void quicksort_deterministic(vector<int>&arr, int lb, int ub){
    if(lb<ub){
        int pi= sort(arr, lb, ub);
        quicksort_deterministic(arr, lb, pi-1);
        quicksort_deterministic(arr, pi+1, ub);
    }
}

int parition_rand(vector<int>&arr, int lb, int ub){
    int r= rand();
    int p= lb+ r% (ub-lb+1);
    cout<<"p is : "<<r<<endl;
    swap(arr[lb], arr[p]);
    return sort(arr, lb, ub);
}

void quicksort_Randomised(vector<int>&arr, int lb, int ub){
    if(lb<ub){
        int pi= parition_rand(arr, lb, ub);
        quicksort_Randomised(arr, lb, pi-1);
        quicksort_Randomised(arr, pi+1, ub);
    }
}

int main(){
    srand(time(0));
    vector<int>arr={9,3,8,10,1,2,17};
    int n= arr.size();
    // quicksort_deterministic(arr, 0, n-1);
    quicksort_Randomised(arr, 0, n-1);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}