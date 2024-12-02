#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

void PartOne() {
    std::string filename = "input.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: could not open file" << filename << std::endl;
        return;
    }

    std::string line;
    int safe = 0;
    int unsafe = 0;
    while (std::getline(file, line)) {
        // Logic for a single line
        safe++;
        std::istringstream stream(line);
        std::string token;

        int prev = -1;
        int curr = 0;
        int is_desc = -1;
        while (stream >> token) {
            int curr = std::stoi(token);
            if (prev == -1) {
                prev = curr;
                continue;
            }

            std::cout << "Prev is: " << prev << " and curr is: " << curr << std::endl;

            if (is_desc == -1) {
                if (curr < prev) {
                    is_desc = 1;
                } else {
                    is_desc = 0;
                }
            }

            if (is_desc == 1 && curr > prev) {
                unsafe++;
                break;
            } else if (is_desc == 0 && curr < prev) {
                unsafe++;
                break;
            }

            int diff = std::abs(prev - curr);
            if (diff > 3 || diff == 0) {
                unsafe++;
                break;
            }

            prev = curr;

        }

        prev = -1;
        curr = 0;
        is_desc = -1;

        std::cout << std::endl;
    }
    
    std::cout << "Safe is: " << safe << std::endl;
    std::cout << "Unsafe is: " << unsafe << std::endl;
    std::cout << "Answer is " << safe - unsafe << std::endl;

    file.close();
}

int main() {

    //PartOne();


    return 0;
}
