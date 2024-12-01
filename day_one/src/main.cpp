#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void PopulateLists(int* first, int* second) {
    if (first == nullptr || second == nullptr) {
        return;
    }
    std::string filename = "input.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    int idx = 0;
    while (std::getline(file, line)) {
        std::istringstream stream(line);
        std::string token;

        int line_idx = 0;
        while (stream >> token) {
            if (line_idx % 2 == 0) {
                first[idx] = std::stoi(token);
            } else {
                second[idx] = std::stoi(token);
            }

            line_idx++;
        }

        idx++;

    }

    file.close();

    std::cout << "File is closed" << std::endl;

}
int main() {

    int* first_list = new int[1000];
    int* second_list = new int[1000];

    PopulateLists(first_list, second_list);

    std::sort(first_list, first_list + 1000);
    std::sort(second_list, second_list + 1000);
    
    for(int i = 0; i < 1000; i++) {
        std::cout << i << " First List: " << first_list[i] << ", Second List: " << second_list[i] << std::endl;
    }

    int answer = 0;
    for (int i = 0; i < 1000; i++) {

        int dist = std::abs(first_list[i] - second_list[i]);
        answer += dist;
    }
    std::cout << "Answer is: " << answer << std::endl;

    delete[] first_list;
    delete[] second_list;
    return 0;
}


