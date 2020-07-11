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

uint64_t MaxPairwiseProduct(const uint32_t* numbers, uint32_t max_idx) {
    uint64_t result = 0;
    //int n = numbers.size();
    //uint64_t temp =0;
    for (uint32_t i = 0; i < max_idx; ++i) {
        for (uint32_t j = i + 1; j < max_idx; ++j) {
            //temp = (uint64_t) numbers[i] * numbers[j];
            //if (temp > result) {
            //    result = temp;
            //} 
            if ((uint64_t)numbers[i] * numbers[j] > result) {
                result = (uint64_t)numbers[i] * numbers[j];
            }
        }
    }
    return result;
}

uint64_t MaxPairwiseProductOptimized(const uint32_t* numbers, uint32_t max_idx) {
    uint64_t result = 0;
    uint32_t max_num_larger1 = 0, max_num_larger2 = 0 , temp =0;
    //uint32_t index1 = 0, index2 =0;
    for (uint32_t i = 0; i < max_idx; ++i) {
        temp = numbers[i];
        if (max_num_larger1 < temp) {
            max_num_larger2 = max_num_larger1;
            max_num_larger1 = temp;
            continue;            
        }
        if (max_num_larger2 < temp) {
            max_num_larger2 = temp;
        }
        
    }
    result = (uint64_t)max_num_larger2 * max_num_larger1;
    return result;
}

int MaxPairwiseProduct(const int* numbers, int max_idx) {
    int result = 0;
    //int n = numbers.size();
    int temp =0;
    for (int i = 0; i < max_idx; ++i) {
        for (int j = i + 1; j < max_idx; ++j) {
            temp =  numbers[i] * numbers[j];
            if (temp > result) {
                result = temp;
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

#if 1
int main() {
    uint32_t n;
    cin >> n;
    uint32_t* numbers = new uint32_t[n];
    for (uint32_t i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    //auto start = high_resolution_clock::now();
    uint64_t result = MaxPairwiseProductOptimized(numbers,n);
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<microseconds>(stop - start);
    //cout << "Time taken by function: "  << duration.count() << " microseconds" << endl;
    cout << result << "\n";
    return 0;
}

#elif

//Stress Testing
int main() {
    //std::random_device rd;
    std::mt19937 mt(10987);
    
    uint32_t n,max;
    cin >> n >> max;
    std::uniform_int_distribution<uint32_t> dist(0, max);
    uint32_t* numbers= new uint32_t[n];
    //int n,max;
    //cin >> n >> max;
    //std::uniform_int_distribution<int> dist(0, max);
    //int* numbers= new int[n];
#ifdef StressTesting
    uint64_t result1, result2;
    while (true) {
        for (uint32_t i = 0; i < n; ++i) {
            numbers[i] = dist(mt);
        }
         result1 = MaxPairwiseProduct(numbers, n);
         result2 = MaxPairwiseProductOptimized(numbers, n);
         cout << result1 << " " << result2 << endl;
         if (result1 != result2) {
             for (uint32_t i = 0; i < n; ++i) {
                 cout << numbers[i] << " ";
             }
             break;
         }

    }
    return 0;
#endif
    for (uint32_t i = 0; i < n; ++i) {
        numbers[i]= dist(mt);
        //cout << numbers[i] << " ";
    }
    //cout << endl;
    //vector<int> Val_indx(max+1);
    //for (int i = 0; i < n; ++i) {
    //    for (int val = 0; val <= max; val++) {
    //        if (val == numbers[i]) {
    //            Val_indx[val]++;
    //        }
    //    }
    //}
    //for (int val = 0; val <= max; val++) {
    //    
    //     cout<<"Number "<<val << " has prob =" <<  Val_indx[val]*100.0/n <<endl;        
    //}


    auto start = high_resolution_clock::now();
    //int result = MaxPairwiseProduct(numbers);
    uint64_t result = MaxPairwiseProductOptimized(numbers,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "  << duration.count() << " microseconds" << endl;
    cout << result << "\n";
    return 0;
}
#endif