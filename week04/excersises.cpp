#include <cassert>
#include <iostream>

// Napište funckci, která vrátí součin dvou čísel
int multiply(int a, int b) {
    return a*b;
}

// Napište funkci, která rozhodne jestli číslo je sudé
bool is_even(int x) {
    if((x % 2) == 1){    
        return false;
        }
    else{
        return true;
        }
}

// Vypište věechny čísla od start do stop (včetně)
void print_numbers(int start, int stop) {
    for(int i = start; i <= stop; i++){
        std::cout << i << '\n';
    }
}

// Naimplementujte funkci která pořítá faktoriál
// Faktoriál čísla x je definovaný jako součin všech kladných čísel <= x
int factorial(int x) {
    for(int i = (x - 1); i > 0; i--){
        
        x = x*i;
        
    }
    return x;
}

// Funkce vypíše count hvězdiček
void print_stars(unsigned int count) {
    for(int i = count; i > 0; i--){
    std::cout << '*';
    }
    std::cout << '\n';
    std::cout << '\n';
}

// Funkce vypíše obdélníček z hvězdiček
void print_rectangle(unsigned int sirka, unsigned int vyska) {
    for (int i = sirka; i < sirka; i--){
        std::cout << '*';
    }
    std::cout << '\n';

    for (int i = vyska - 2; i < vyska - 2; i--){
        std::cout << '*';
        for (int o = (sirka - 2); o <= (sirka - 2); o--){
            std::cout << ' ';
        }
        std::cout << '*';
        std::cout << '\n';
    }

    for (int i = sirka; i <= sirka; i--){
        std::cout << '*';
    }
    std::cout << '\n';
}


// Funkce vypíše takovýto trojúhelník o zadané výšce
// *
// **
// ***
// ****
void print_pyramid_l(unsigned int height) {
    int star = 1;
    for (int i = height; i > 0; i-- ){
        for (int s = star ; s >= 1; s--){
        std::cout << '*';
        }
        star++;
        std::cout << '\n';
    }
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
//    *
//   **
//  ***
// ****
void print_pyramid_r(unsigned int height) {
    int spaces = height - 1;
    int stars = 1;
    for (int i = height; i > 0; i-- ){
        for (int s = spaces; s >= 0; s-- ){
            std::cout << ' ';
        }
        spaces--;
        for (int r = stars; r >= 1; r-- ){
            std::cout << '*';
        }
        stars++;
        std::cout << '\n';
    }
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
//    *
//   ***
//  *****
// *******
void print_pyramid(unsigned int height) {
        int spaces = height - 1;
    int stars = 1;
    for (int i = height; i > 0; i-- ){
        for (int s = spaces; s >= 0; s-- ){
            std::cout << ' ';
        }
        spaces--;
        for (int r = stars; r >= 1; r-- ){
            std::cout << '*';
        }
        stars = stars + 2;
        std::cout << '\n';
    }
}

// Funkce vypíše takovýto trojúhelník o zadané výšce
// *******
//  *****
//   ***
//    *
void print_pyramid_inverse(unsigned int height) {
    int spaces = 0;
    int stars = height* 2 - 1;
    for (int i = height; i > 0; i-- ){
        for (int s = spaces; s >= 0; s-- ){
            std::cout << ' ';
        }
        spaces++;
        for (int r = stars; r >= 1; r-- ){
            std::cout << '*';
        }
        stars = stars - 2;
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    std::cout << "5 * 2:" << multiply(5, 2) << std::endl;
    std::cout << "Číslo 5 je sudé?:" << is_even(5) << std::endl;
    print_numbers(-5, 2);
    std::cout << "Faktoriál 5:" << factorial(5) << std::endl;
    print_stars(5);
    print_rectangle( 10, 20);
    print_pyramid_l(5);
    print_pyramid_r(5);
    print_pyramid(5);
    print_pyramid_inverse(5);
}
