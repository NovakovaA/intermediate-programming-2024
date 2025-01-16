#include <iostream>
#include <vector>

void print(std::vector<int> vec){
    if (vec.size() == 0) {
        std::cout << "{}";
        return;
    }

    std::cout << "{ ";
    for (std::size_t i = 0; i < (vec.size() - 1); i++) {
        std::cout << vec[i] << ", ";
    }

    std::cout << vec.back() << " }";
    
}

void print2(std::vector<std::vector<int>> vec){
    std::cout << "\n";
    std::cout << "{ ";
    for(std::vector<int> a: vec){
        print(a);
        std::cout << ", \n";
    }
    std::cout << " }";
}

std::vector<int> sum(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {1, 2, 0}
    std::vector<int> final;
    for(std::vector<int> a: vec){
        int suma = 0;
        for(std::size_t i = 0; i < a.size(); i++){
            suma += a[i];
        }
        
        final.push_back(suma);
    }
    return final;
}

std::vector<int> product(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {0, 2, 1}
    std::vector<int> final;
    for(std::vector<int> a: vec){
        int multiply = 1;
        for(std::size_t i = 0; i < a.size(); i++){
            multiply *= a[i];
        }
        
        final.push_back(multiply);
    }
    return final;
}

/*std::vector<int> concat(std::vector<std::vector<int>> vec) {
    // {{0, 1}, {2}, {}} -> {0, 1, 2}
    std::vector<int> final;
    for(std::vector<int> a: vec){
        for(std::size_t i = 0; i < a.size(); i++){
        }
        
    }
    return final;
}*/

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>> vec) {
    // {
    //   {0, 1, 2},
    //   {3, 4, 5},
    //   {6, 7, 8},
    // } -> {
    //   {0, 3, 6},
    //   {1, 4, 7},
    //   {2, 5, 8},
    // } 
    std::vector<std::vector<int>> final;
    for (std::size_t i = 0; i < final.size(); i++) {
        final[i].resize(vec.size()); 
    }
    int c = 0;
    for(std::vector<int> a: vec){
        int b = 0;
        for(std::size_t i = 0; i < final.size(); i++){
            final [b][c] = vec [c][b];
            b++;
        }
        c++;
    }
    std::cout << final [0][1];
    return final;
}

int main(){
    std::vector<std::vector<int>> a {{0, 1, 0}, {2, 4, 1}, {3, 5, 1}};
    std::vector<int> b = { 1, 3, 5, 6, 7, 9 };

    print(b);
    std::cout << '\n';
    print2(a);
    std::vector<int> c = sum(a);
    std::cout << '\n';
    print(c);
    std::cout << '\n';
    
    std::vector<int> d = product(a);
    print(d);
    std::cout << '\n';

    //std::vector<int> e = concat(a);
    //print(e);

    std::vector<std::vector<int>> f = transpose(a);
    print2(f);
    std::cout << '\n';
    //concat(a);
    //transpose(a);

}