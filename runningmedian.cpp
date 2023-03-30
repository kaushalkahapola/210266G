#include <iostream> 

#include <vector> 

#include <algorithm> 

#include <iomanip> 

  

using namespace std; 

  

int main() { 

    vector<int> nums; 

    int n; 

    cin >> n; 

    for (int i = 0; i < n; i++) { 

        int x; 

        cin >> x; 

        nums.push_back(x); 

        sort(nums.begin(), nums.end()); 

        int size = nums.size(); 

        double median; 

        if (size % 2 == 0) { 

            median = (double)(nums[size/2-1] + nums[size/2])/2; 

        } else { 

            median = nums[size/2]; 

        } 

        cout << "Sorted "; 

        cout << "["; 

        for (int j = 0; j < size-1; j++) { 

            cout << nums[j] << ", "; 

        } 

        if (size > 0) { 

            cout << nums[size-1]; 

        } 

        cout << "]" << endl; 

        cout << "Median: " << fixed << setprecision(1) << median << endl; 

    } 

    return 0; 

} 
