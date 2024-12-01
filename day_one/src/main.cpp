#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
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

void PartOne(int* first, int* second) {
    if (first == nullptr || second == nullptr) {
        return;
    }

    std::sort(first, first + 1000);
    std::sort(second, second + 1000);

    int answer = 0;
    for (int i = 0; i < 1000; i++) {

        int dist = std::abs(first[i] - second[i]);
        answer += dist;
    }
    std::cout << "Answer is: " << answer << std::endl;
}

void PartTwo(int* first, int* second) {

    std::map<int, int> first_freq;
    std::map<int, int> second_freq;
    
    for (int i = 0; i < 1000; i++) {
        int key = second[i];
        if (second_freq.find(key) == second_freq.end()) {
            second_freq[key] = 1;
        } else {
            second_freq[key]++;
        }
    }

    int answer = 0;
    for (int i = 0; i < 1000; i++) {
        int current = first[i];
        int freq = 0;
        if (second_freq.find(current) != second_freq.end()) {
            freq = second_freq[current];
        }


        answer += current * freq;
    }

    std::cout << "Answer is: " << answer << std::endl;
}
int main() {

    int* first_list = new int[1000];
    int* second_list = new int[1000];

    PopulateLists(first_list, second_list);

    //PartOne(first_list, second_list);
    PartTwo(first_list, second_list);

    delete[] first_list;
    delete[] second_list;
    return 0;
}


