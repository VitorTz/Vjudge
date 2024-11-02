#include <iostream>


int calc_price(int price) {
    int total = 0;
    total += std::min(std::max(0, price / 2), 100); 
    price -= 2 * 100;
    
    total += std::min(std::max(0, price / 3), 9900); 
    price -= 3 * 9900;
    
    total += std::min(std::max(0, price / 5), 990000); 
    price -= 5 * 990000;
    
    total += std::max(0, price / 7);
    return total;
}

int calc_price_neigh(int cons) {
    int price = 0;
    price += std::min(std::max(0, cons * 2), 2 * 100); 
    cons -= 100;
    
    price += std::min(std::max(0, cons * 3), 3 * 9900); 
    cons -= 9900;
    
    price += std::min(std::max(0, cons * 5), 5 * 990000); 
    cons -= 990000;
    
    price += std::max(0, cons * 7);
    return price;
}


int main() {
    int a, b;
    
    while (std::cin >> a >> b, a | b) {

        const int total = calc_price(a);
        int begin = 0;
        int end = total;
        int total_price = 0;

        while (begin < end) {

            int price = (begin + end) / 2;
            int delta = calc_price_neigh(total - price) - calc_price_neigh(price);

            if (delta > b) {
                begin = price;
            } else if (delta < b) {
                end = price;
            } else { 
                total_price = price; 
                break; 
            }
        }
        
        std::cout << calc_price_neigh(total_price) << '\n';
    }

    return 0;
}