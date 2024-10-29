#include <cstdio>
#include <cmath>


#define MIN_VALUE 1e-9


int p, q, r, s, t, u;


double equation(double x) {
	return p * std::exp(-x) + q * std::sin(x) + r * std::cos(x) + s * std::tan(x) + t * x * x + u;
}


int main() {
	while (scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) == 6){
		double left = 0, right = 1;
		bool found = false;

		while (right > left) {
			double mid = (left + right) / 2;
			if (equation(mid) > MIN_VALUE) {
				left = mid;
            } else if (equation(mid) < -MIN_VALUE) {
				right = mid;
            } else {
				left = mid, found = true;	break;
			}
		}

		if (found) {
			printf("%.4lf\n", left);
        } else {
            puts("No solution");
        }
	}
	return 0;
}
