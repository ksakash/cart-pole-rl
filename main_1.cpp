#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    std::vector<double> value_before;
    std::vector<double> value_after;
    value_before.resize(91);
    value_after.resize(91);

    int iterations = 10;

    for (int i = 0; i < iterations; i++) {
        std::cout << "[ Iteration " << i << " ]: " << std::endl;
        for (int j = -45; j <= 45; j = j + 5) {
            double sum = 0;
            int count = 0;
            for (int k = -4; k <= 4; k++) {
                if (((j + 5*k) <= 45) && ((j + 5*k) >= -45)) {
                    sum = 1 + value_before[j + 5*k] + sum;
                    count++;
                }
            }
            value_after[j] = 0.11*sum;
        }
        for (int j = -45; j <= 45; j = j + 5) {
            value_before[j] = value_after[j];
            std::cout << "State[" << j << "] = " << value_before[j] << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }

    return 0;
}