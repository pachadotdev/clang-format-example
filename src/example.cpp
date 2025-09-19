#include <iostream>
#include <string>
#include <vector>

class DataProcessor {
   public:
    DataProcessor(std::string name) : m_name(name) {}

    void processNumbers(std::vector<int> numbers) {
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] % 2 == 0) {
                std::cout << "Even: " << numbers[i] << std::endl;
            } else {
                std::cout << "Odd: " << numbers[i] << std::endl;
            }
        }
    }

    std::string getName() {
        return m_name;
    }

   private:
    std::string m_name;
};

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    DataProcessor processor("MyProcessor");

    std::cout << "Starting processing with: " << processor.getName() << std::endl;
    processor.processNumbers(data);

    return 0;
}
