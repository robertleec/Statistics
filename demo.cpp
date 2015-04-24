#include "Statistics.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    double array1[] = {1, 9, 3, 0, 4};
    vector<double> vector1(array1, array1 + 5);
    
    double variance1 = Math::variance(vector1);
    
    return 0;
}