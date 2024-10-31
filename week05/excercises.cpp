#include <iostream>
// TODO: Doplňte potřebné hlavičky

// Vypište obdélník o zadaných parametrech
// Vraťte 0 pokud vše v pořádku, -1 pokud nastala chyba
int hollow_rect(int x, int y, int thickness) {
    if(x < 0 || y < 0 || thickness >= x + 1 || thickness >= y + 1 || thickness < 0){
        return -1;
    }

    for(int i = 0; i < y; i++){
        if(i < thickness || i >= y - thickness){
            for(int h = 0; h < x; h++){
                std::cout << '*';
            }
            std::cout << '\n';
        }
        else{
            int s;
            int p;
            if(s <= thickness || s >= thickness){
                for(s = 0; s < thickness; s++){
                    std::cout << '*';
                }
                for(p = 0; p < x - thickness*2; p++){
                    std::cout << ' ';
                    }
                for(s = 0; s < thickness; s++){
                    std::cout << '*';
                }
                
            std::cout << '\n';
        }
    }
    }
    return 0;

}

// Vraťte a na n
int power(int a, int n) {
    int h = a;
    for(int i = 1; i < n; i++){
        h = h*a;
    }
    std::cout << h;
    std::cout << '\n';
    return 0;
}

// Vraťte idx-té fibonacciho číslo
int fibonacci(int idx) {
    int x = 0;
    int y = 1;
    
        int z;
    for(int i = 0; i < idx; i++){
        z = x + y;
        x = y;
        y = z;
    }
    std::cout << z;
    return 0;
}

int main() {
    hollow_rect(12, 11, 3);
    power(2, 3);
    fibonacci(5);
}
