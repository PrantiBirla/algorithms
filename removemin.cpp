#include <iostream>
#include <climits>
using namespace std;
#include <vector>
#include <iostream>

using namespace std;

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if(pq.empty()){
            return 0;
        }
        
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int pi = 0;
        int lci = (pi*2)+1;
        int rci = (pi*2)+2;
        while(lci < pq.size()){
            int maxindex = pi;
            if(pq[maxindex] > pq[lci]){
                maxindex = lci;
            }
            if(pq[rci] < pq[maxindex]){
                maxindex = rci;
            }
            if(maxindex == pi){
                break;
            }
            swap(pq[maxindex], pq[pi]);
            
            pi=maxindex;
            lci = (pi*2)+1;
            rci = (pi*2)+2;
            
        }
        return ans;
        
    }
};

int main() {
    PriorityQueue pq;

    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}
