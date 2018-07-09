#include <iostream> 
#include <vector>

#define S_MINUS 0
#define S_PLUS 1
#define S_ZERO 2

int main(int argc, char** argv) {
    std::vector<int> value_before;
    std::vector<int> value_after;
    value_before.resize(3);
    value_after.resize(3);
    
    int iterations = 10;

    for (int i = 0; i < iterations; i++) {
        value_after[S_MINUS] = 0.5 + 0.5*value_before[S_ZERO];
        value_after[S_ZERO] = 1 + 0.5*(value_before[S_MINUS] + value_before[S_PLUS]);
        value_after[S_PLUS] = 0.5 + 0.5*value_before[S_ZERO];

        value_before[S_MINUS] = value_after[S_MINUS];
        value_before[S_PLUS] = value_after[S_PLUS];
        value_before[S_ZERO] = value_after[S_ZERO];

        std::cout << "[ " << i << " iteration]: " << "Values S_MINUS: " << value_before[S_MINUS] << ", S_ZERO: " << value_before[S_ZERO] << ", S_PLUS: " << value_before[S_PLUS] << std::endl;
    }

    return 0;
}