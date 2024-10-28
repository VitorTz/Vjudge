#include <cstdio>
#include <cstring>



int N, numerator, denominator, count, i, k;
bool has_solution, first = true;
char nums[11], decimal[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


bool check() {
    sprintf(nums, "%05d%05d", numerator, denominator);

    for (i = 0; i < 10; i++) {
        count = 0;

        for (k = 0; k < 10; k++) {
            if (nums[k] == decimal[i])
                count++;
        }

        if (count != 1)
            return false;

    }

    return true;
}

int main() {

    while (true) {

        scanf("%d\n", &N);

        if (!N)
            break;

        if (!first) {
            printf("\n");
        }

        has_solution = false;

        denominator = 1234;

        while (denominator <= 98765) {
            numerator = N * denominator;

            if (numerator > 98765)
                break;

            if (check()) {
                printf("%05d / %05d = %d\n", numerator, denominator, N);
                has_solution = true;
            }

            denominator++;

        }

        if (!has_solution)
            printf("There are no solutions for %d.\n", N);

        first = false;

    }

    return 0;
};