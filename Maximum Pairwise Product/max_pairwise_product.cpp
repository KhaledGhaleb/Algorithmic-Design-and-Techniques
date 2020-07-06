#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using std::vector;
using std::cin;
using std::cout;
using namespace std::chrono;
using namespace std;

int MaxPairwiseProduct(const vector<int>& numbers) {
  int result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

int MaxPairwiseProduct(const int * numbers, int max_idx) {
    int result = 0;
    //int n = numbers.size();
    for (int i = 0; i < max_idx; ++i) {
        for (int j = i + 1; j < max_idx; ++j) {
            if (numbers[i] * numbers[j] > result) {
                result = numbers[i] * numbers[j];
            }
        }
    }
    return result;
}
//int main() {
//    int n;
//    cin >> n;
//    vector<int> numbers(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> numbers[i];
//    }
//    auto start = high_resolution_clock::now();
//    int result = MaxPairwiseProduct(numbers);
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "Time taken by function: "  << duration.count() << " microseconds" << endl;
//    cout << result << "\n";
//    return 0;
//}
int main() {
    //std::random_device rd;
    std::mt19937 mt(10987);
    
    int n,max;
    cin >> n >> max;
    std::uniform_int_distribution<int> dist(0, max);
    //vector<int> numbers(n);
    int *numbers= new int[n];
    for (int i = 0; i < n; ++i) {
        numbers[i]= dist(mt);
        //cout << numbers[i] << " ";
    }
    cout << endl;
    vector<int> Val_indx(max+1);
    for (int i = 0; i < n; ++i) {
        for (int val = 0; val <= max; val++) {
            if (val == numbers[i]) {
                Val_indx[val]++;
            }
        }
    }
    for (int val = 0; val <= max; val++) {
        
         cout<<"Number "<<val << " has prob =" <<  Val_indx[val]*100.0/n <<endl;        
    }


    auto start = high_resolution_clock::now();
    //int result = MaxPairwiseProduct(numbers);
    int result = MaxPairwiseProduct(numbers,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "  << duration.count() << " microseconds" << endl;
    cout << result << "\n";
    return 0;
}
