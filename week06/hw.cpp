#include <cassert>
#include <iostream>
#include <cmath>
// TODO: doplťe co potřebujete


// Implementujte funkci ‹power_digit_sum›, která vrátí „speciální“
// ciferný součet čísla ‹number›, který se od běžného ciferného
// součtu liší tím, že každou cifru před přičtením umocníme na číslo
// její pozice. Pozice číslujeme zleva, přičemž první má číslo 1.
// Vstupem funkce ‹power_digit_sum› bude libovolné nezáporné celé
// číslo, na výstupu se očekává celé číslo. Výpočet budeme provádět
// v číselné soustavě se základem 7.
//// Příklad: Číslo ⟦1234⟧ zapíšeme v sedmičkové soustavě jako
// ⟦(3412)₇⟧ – skutečně, ⟦3⋅7³ + 4⋅7² + 1⋅7¹ + 2⋅7⁰ = 1029 + 196 + 7
// + 2 = 1234⟧.  Proto ‹power_digit_sum(1234)› získáme jako ⟦3¹ + 4²
// + 1³ + 2⁴ = 36⟧.

int power_digit_sum(int number){
    int digits = 0;
    int number7 = 0;
    int remainder;
    int times = 0;
    while (number > 0){
        remainder = number % 7;
        number = number /7;
        //std::cout << remainder <<'\n';
        number7 = number7 +  remainder * pow(10, times);
        times++;
    }
    
    std::cout << number7 << '\n';

    float new_number = number7;
    while(number7 >= 1){
        number7 = number7 / 10;
        digits++;
        new_number = new_number / 10;
        //std::cout << new_number << '\n';
    }
    //std::cout << digits << '\n';
    //std::cout << new_number << '\n';

    int single_number;
    int sum = 0;
    int power = 1;
    int gone = 0;
    for(int i = 0; i < digits; i++){
        new_number = new_number * 10;
        single_number = floor(new_number);
        int normal_num = single_number - gone *10;
        //std::cout << normal_num << '\n';
        sum = sum + pow(normal_num, power);
        power++;
        gone = single_number;
    }

    std::cout << sum << " Here" << '\n';
    return 0;
}


// Napište funkci, která najde celé číslo ‹x›, které leží mezi
// hodnotami ‹low› a ‹high› (včetně), a pro které vrátí funkce ‹poly›
// maximální hodnotu (tzn. libovolné ⟦x⟧ takové, že pro všechny ⟦x'⟧
// platí ⟦f(x) ≥ f(x')⟧, kde ⟦f⟧ je funke, kterou počítá podprogram
// ‹poly›).

int poly(int x){
    //std::cout << x;
    return 10 + 30 * x - 15 * x * x * x + (x * x * x * x * x);
}

int function(int low, int high){
    int maxx = low;
    int x = low;
    int f = poly(low);
    int fnew;
    for(int i = low; i <= high; i++){
        fnew = poly(i);
        x++;
        if(fnew >= f){
            maxx = i;
            f = fnew;
        }
        
    }
    
    std::cout << maxx << '\n';
    return maxx;
}



// Napište funkci, která zjistí, kolik bude pracovních dnů v roce
// ‹year›. Dny v týdnu mají hodnoty 0–6 počínaje pondělím s hodnotou 0.
// Předpokládejte, že ‹year› je větší než 1600.
// České státní svátky jsou:
//
// │  datum │ svátek                                         │
// ├┄┄┄┄┄┄┄▻┼◅┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄│
// │   1.1. │ Den obnovy samostatného českého státu          │ day 1
// │      — │ Velký pátek                                    │
// │      — │ Velikonoční pondělí                            │
// │   1.5. │ Svátek práce                                   │ day 121/122
// │   8.5. │ Den vítězství                                  │ day 128/129
// │   5.7. │ Den slovanských věrozvěstů Cyrila a Metoděje   │ day 186/187
// │   6.7. │ Den upálení mistra Jana Husa                   │ day 187/188
// │  28.9. │ Den české státnosti                            │ day 271/272
// │ 28.10. │ Den vzniku samostatného československého státu │ day 301/302
// │ 17.11. │ Den boje za svobodu a demokracii               │ day 321/322
// │ 24.12. │ Štědrý den                                     │ day 358/359
// │ 25.12. │ 1. svátek vánoční                              │ day 359/360
// │ 26.12. │ 2. svátek vánoční                              │ day 360/361
// Přestupné roky: v některých letech se na konec února přidává 29.
// den. Jsou to roky, které jsou dělitelné čtyřmi, s výjimkou těch,
// které jsou zároveň dělitelné 100 a nedělitelné 400.
// Čistou funkci ‹first_day› můžete použít k tomu, abyste zjistili,
// na který den v týdnu padne 1. leden daného roku. Např.
// ‹first_day(2001)› vrátí nulu, protože rok 2001 začínal pondělím.


/* 0 Monday 1 Tuesday 2 Wednesday 3 Thursday 4 Friday 5 Saturday 6 Sunday*/
int first_day(int year) {
    assert(year >= 1601);
    int years = year - 1601;
    int offset = years + years / 4 - years / 100 + years / 400;
    //std::cout << offset % 7;
    return offset % 7;
}

int days_in_a_year(int year){
    int days = 365 - 2;
    int current_day = first_day(year);
    std::cout << first_day(year) << "\n";

    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        days++;

        for(int i = 1; i <= 366; i++){
            current_day++;
            if(current_day > 6){
                current_day = 0;
            }
            if(current_day == 5 || current_day == 6){
                days--;
            }
            if(current_day != 5 && current_day != 6){
                if(i == 1 || i == 122 || i == 129 || i == 187 || i == 188 || i == 272 || i == 302 || i == 322 || i == 359 || i == 360 || i == 361){
                    days--;
                }
            }
        }
    }

    else{
        for(int i = 1; i <= 365; i++){
            current_day++;
            if(current_day > 6){
                current_day = 0;
            }
            if(current_day == 5 || current_day == 6){
                days--;
            }
            if(current_day != 5 && current_day != 6){
                if(i == 1 || i == 121 || i == 128 || i == 186 || i == 187 || i == 271 || i == 301 || i == 321 || i == 358 || i == 359 || i == 360){
                    days--;
                }
            }
        }
    }
    
    std::cout << days << "\n";
    return days;
}





int main(){
    int year = 2021;
    power_digit_sum(1234);
    function(-1, 4);
    first_day(year);
    days_in_a_year(year);

}
