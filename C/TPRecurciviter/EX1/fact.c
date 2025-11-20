
int recursive_factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * recursive_factorial(n - 1);
    }
}

int terminal_factorial(int n, int accumulator) {
    if (n <= 1) {
        return accumulator;
    } else {
        return terminal_factorial(n - 1, n * accumulator);
    }
}

int main(int argc, char *argv[]) {
    int result = recursive_factorial((int) argv[1]);
    return result;
}