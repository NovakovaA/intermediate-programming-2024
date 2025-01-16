#include <iostream>
#include <vector>
#include <cmath>

void print(std::vector<int> data) {
    if (data.size() == 0) {
        std::cout << "[]";
        return;
    }

    std::cout << "[ ";
    for (std::size_t i = 0; i < data.size() - 1; i++) {
        std::cout << data[i] << ", ";
    }

    std::cout << data.back() << " ]";
}

int sum(std::vector<int> data) {
    int total = 0;
    for (std::size_t i = 0; i < data.size(); i++){
        int num = data[i];
        total = total + num;
    }
    return total;
}

float average(std::vector<int> data){
    float total = 0;
    for (std::size_t i = 0; i < data.size(); i++){
        float num = data[i];
        total = total + num;
    }
    float average = total / data.size();

    return average;
}

float median(std::vector<int> data) {
    float m_position = 0;
    float median = 0;

    if(data.size() % 2 == 0){
        m_position = data.size()/2;
        median = (data[m_position] + data[m_position - 1]) / 2.0;

    } else{
        // std::cout << "HI";
        m_position = data.size()/2;
        median = (data[floor(m_position)]);


    }
    return median;
}

std::vector<int> range(int start, int end) {
    std::vector<int> vector;
    if(start < end){
        for(int i = start; i < end; i++){
            vector.push_back(i);
        }
    } else if(start > end){
        for(int i = start; i > end; i--){
            vector.push_back(i);
        }

    } else{
        std::cout << "[ ]";
    }
    return vector;
}

std::vector<int> runningSum(std::vector<int> data) {
    std::vector<int> vector;
    int num = 0;
    for (std::size_t i = 0; i < data.size(); i++){
        num = data[i] + num;
        vector.push_back(num);
    }
    return vector;
}

std::vector<int> rotateRight(std::vector<int> data, int count) {
    std::vector<int> new_data;
    new_data.resize(data.size());
    for(std::size_t i = 0; i < data.size(); i++){
        new_data[(i + count) % data.size()] = data[i];
    }
    return new_data;
}

int main() {
    std::vector<int> vec1 = { 1, 9, 4, 8, 4, 0, 9, 2, 3, 5, 6 };
    std::vector<int> asc1 = { 0, 2, 4, 7, 8, 10 };
    std::vector<int> asc2 = { 1, 3, 5, 6, 7, 9 };

    std::cout << "sum(vec1): " << sum(vec1) << std::endl;
    std::cout << "average(vec1): " << average(vec1) << std::endl;
    std::cout << "median(asc1): " << median(asc1) << std::endl;

    std::cout << "range(5, 10): ";
    print(range(5, 10));
    std::cout << std::endl;

    std::cout << "range(11, 4): ";
    print(range(11, 4));
    std::cout << std::endl;

    std::cout << "runningSum(vec1): ";
    print(runningSum(vec1));
    std::cout << std::endl;

    std::cout << "rotateRight: ";
    print(rotateRight(vec1, 2));
    std::cout << std::endl;
}
