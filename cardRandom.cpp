#include <vector>
#include <cstdlib>
using namespace std;

vector<int> randomVector (int n, int upperBound) {
    vector<int> vec(n);

    for (int i =0; i<=vec.size(); i++)
        vec[i] = arc4random() % upperBound;
    return vec;
}

int myRandom (int offset, int range) {
    srand((unsigned) time(NULL));
    return offset + (arc4random() % range);
}
