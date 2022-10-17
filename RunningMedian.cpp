#include <iostream>
using namespace std;

#include<queue>
void balanceHeap(priority_queue<int,vector<int>,greater<int>> &minHeap , priority_queue<int>&maxHeap)
{
     int miSize = minHeap.size();
     int mxSize = maxHeap.size();
     if(abs(miSize - mxSize) >= 2)
     {
         if(miSize > mxSize)
         {
             maxHeap.push(minHeap.top());
             minHeap.pop();
         }
         else
         {
             minHeap.push(maxHeap.top()); 
             maxHeap.pop();
         }
     }
}
void findMedian(int arr[], int n){
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    for(int i=0;i<n;i++)
    {
        //Push the element
        if(max.empty())
            max.push(arr[i]);
        else if(arr[i]>max.top())
            min.push(arr[i]);
        else 
            max.push(arr[i]);
        //comparing sizes
        balanceHeap(min,max);
        //printing median
        if(max.size()>min.size())
            cout<<max.top()<<" ";
        else if(min.size()>max.size())
            cout<<min.top()<<" ";
        else
            cout<<(max.top()+min.top())/2<<" ";
        
    }
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
