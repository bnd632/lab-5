#include <iostream>
#include <cmath>
using namespace std;

void checkValidInput() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        throw "Invalid input. Please enter a number.";
    }
}

void checkValidParams(int n) {
    if (n <= 3) {
        throw "Invalid value for n. n must be greater than 3.";
    }
}

double Calculate(double x_1, double x_2, double step, int n) {
    double total_y = 0.0;

    for (double current_x = x_1; (step > 0 ? current_x <= x_2 : current_x >= x_2); current_x += step) {
        cout << "Current value of x: " << current_x << endl;
        double y = 1.0;

        if (current_x < 3) {
            for (int i = 1; i <= n - 2; i++) {
                y *= (i + current_x);
            }
        }
        else {
            for (int i = 1; i <= n; i++) {
                double sum = 0.0;
                for (int j = 1; j <= n + 3; j++) {
                    sum += (i + 1.0 / (4.0 * j * j));
                }
                y *= sum;
            }
        }

        cout << "Result y = " << y << endl;
        total_y += y;
    }

    return total_y;
}

int main() {
    double x_1, x_2, step;
    int n;
    char restart;

    do {
        while (true) {
            try {
                cout << "Enter x_1: ";
                cin >> x_1;
                checkValidInput();

                cout << "Enter x_2 (x_2 >= x_1): ";
                cin >> x_2;
                checkValidInput();
                if (x_2 < x_1) {
                    throw "Invalid input. x_2 must be greater than or equal to x_1.";
                }

                cout << "Enter step: ";
                cin >> step;
                checkValidInput();
                if ((x_1 < x_2 && step <= 0) || (x_1 > x_2 && step >= 0)) {
                    throw "Invalid input. Step must move x_1 towards x_2.";
                }

                while (true) {
                    try {
                        cout << "Enter n (n > 3) must be an integer: ";
                        cin >> n;
                        checkValidInput();
                        checkValidParams(n);
                        break;
                    }
                    catch (const char* ex) {
                        cout << ex << endl;
                    }
                }

                double result = Calculate(x_1, x_2, step, n);
                cout << "Total result of all y values: " << result << endl;
                break;
            }
            catch (const char* ex) {
                cout << ex << endl;
            }
        }

        cout << "Do you want to restart the program? (y/n): ";
        cin >> restart;
        cin.ignore(10000, '\n');

    } while (restart == 'y' || restart == 'Y');

    cout << "Program terminated." << endl;
    return 0;
}
