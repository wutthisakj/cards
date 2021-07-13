#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int multiply(int a = 10, int b =7);
int multiply(int a, int b) {
    return a * b;
}
vector<int> randomVector (int n, int upperBound) {
    vector<int> vec (n);
    for (int i =0; i<vec.size(); i++) {
        //int x = random ();
        //double y = double(x) / RAND_MAX;
        vec[i] = random( ) % upperBound;
    };
    return vec;
}

void printVector (const vector<int>& vec) {
    //for (int i = 0; i<vec.size(); i++)
    //    cout << vec[i] << " ";
    int len = vec.size();
    for (int i = 0; i< len; i++) {
        cout << vec[i] << " ";
    }
}
int howMany(const vector<int>& vec, int value) {
    int count = 0;
    int vec_size = vec.size();

    for (int i=0; i<vec_size; i++){
        if (vec[i] == value) count++;
    }
    return count++;
}
