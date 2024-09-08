#include <bits/stdc++.h>
using namespace std;

class Heap{
    int arr[100];
    int size;
    
    public:
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    
    //Time complexity : O(LogN)
    void insert(int val){
         size = size + 1;
         int index = size;
         arr[index] = val;   //Element inserted at the end

         // Take the element to it's correct position
         while(index > 1)
         {
            int parent = index/2;
            if(arr[parent] < arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
         }
    }

    

    void print()
    {
         for(int i = 0; i <= size; i++){
         cout<<arr[i]<< " "; 
         }
         cout<<endl;
    }

   void deleteRoot(){
    if(size==0){
      cout << "Heap is empty\n";
      return;
    }
    //Step1 : Swap 1st and last element 
    arr[1]=arr[size];   
    // Step2 : Remove last element
    size--;
    //Step3 : Take root node to it's correct position
    int i=1;
    while(i<size){
      int leftInd=2*i;
      int rightInd=2*i+1;
    
      if(leftInd<=size && arr[i]<arr[leftInd] && arr[leftInd]>arr[rightInd])
      {
        swap(arr[i], arr[leftInd]);
        i=leftInd;
      }
      else if(rightInd<=size && arr[i]<arr[rightInd] && arr[rightInd]>arr[leftInd])
      {
        swap(arr[i], arr[rightInd]);
        i=rightInd;
      }else
      {
        return;
      }
    }
}

};


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
     
    if(left <=n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }

}

void heapSort(int arr[],int n)
{
    int size  = n;

    while(size > 1)
    {
        //Step1 : Swap 
        swap(arr[size],arr[1]);
        size--;

        //Step2 : Heapify the root element
        heapify(arr,size,1); 

    }
}

int main()
{

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
     
    h.deleteRoot();
    cout << "After deleting root: ";
    h.print();


    //***Heapify Alogirthm****** */
    int arr[6] ={-1,54,53,55,52,50}; 
    int n = 5;
    //Heap Creation  ****T.C = O(N)
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr,n,i);
    }

    cout<<"Printing the array after heapify: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //***Heap Sort Algorithm****** */
    heapSort(arr,n);
    cout<<"Printing the array after heap sort: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    //***Priority Queue */
    cout<<"Using priority queue: "<<endl;
    cout<<"Max heap"<<endl;
    //max heap
    priority_queue<int> pq;
    pq.push(2);
    pq.push(1);
    pq.push(3);
    pq.push(4);

    cout<<"Top element of max heap: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element of max heap after pop: "<<pq.top()<<endl;

    if(pq.empty())
    {
        cout<<"Priority queue is empty"<<endl;
    }
    else{
        cout<<"Priority queue is not empty"<<endl;
    }
    
    cout<<"Min heap"<<endl;
    //min heap
    priority_queue<int> minheap;
    minheap.push(1);
    minheap.push(3);
    minheap.push(4);
    minheap.push(2);

    cout<<"Top element of min heap: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Top element of min heap after pop: "<<minheap.top()<<endl;
    
    if(pq.empty())
    {
        cout<<"Priority queue is empty"<<endl;
    }
    else{
        cout<<"Priority queue is not empty"<<endl;
    }



    return 0;
}


