#include <algorithm>
#include <array>
#include <iostream>


int main() {
	int n, d, r;
	int total_to_pay;
	int hours;
    std::array<int, 100> morning_route{};
    std::array<int, 100> evening_route{};

	while (std::cin >> n >> d >> r && n || d || r) {
		total_to_pay = 0;

		for (int i = 0; i < n; i++) {
            std::cin >> morning_route[i];			
		}

		std::sort(morning_route.begin(), morning_route.begin() + n);
		
        for (int i = 0; i < n; i++) {
            std::cin >> evening_route[i];			
		}

		std::sort(evening_route.begin(), evening_route.begin() + n, std::greater<int>());

		for (int i = 0; i < n; i++) {
			hours = morning_route[i] + evening_route[i];
			if (hours > d)
				total_to_pay += (hours - d) * r;
		}

        std::cout << total_to_pay << '\n';		
	}

	return 0;
}