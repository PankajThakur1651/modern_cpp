#include <iostream>

int divide(int x, int y) {
    [[expects y != 0]]  // Precondition: divisor should not be zero
    int result = x / y;
    [[ensures: result * y == x]]  // Postcondition: the division result must be correct
    return result;
}

void processData(int data) {
    [[assert: data >= 0]]  // Assertion: data must be non-negative during processing
            // process data here
            std::cout << "Processing data: " << data << std::endl;
}

int main() {
    try {
        divide(10, 0);  // Will fail precondition: y != 0
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    processData(-5);  // Will fail assertion: data >= 0
    return 0;
}
