#include <iostream>
#include <vector>
#include <algorithm>

using std::cout, std::cin, std::endl;


int main() {
    cout << "Number types:" << endl;

    bool quit = false;
    while (!quit)
    {
        int number = 0xDEAD;

        cout << "Enter a number (-1 to quit): ";
        cin >> number;

        if (number == -1) {
            quit = true;
            continue;
        }

        std::vector<int> factors;
        int num_in_half = number / 2;

        factors.push_back(1); // 1 is always a factor
        for (int i = 2; i <= num_in_half; i++) // 'i' is equal to 2 because 1 will always be a factor of our number
            if (number % i == 0)
                factors.push_back(i);

        std::sort(factors.begin(), factors.end());
        // cout << "DEBUG: factors = " << endl;
        // for (int n : factors)
        //     cout << "\t" <<  n << endl;

        int sum = 0;

        for (int factor : factors)
            sum += factor;

        // cout << "DEBUG: sum = " << sum << endl;

        if (sum > number)
            cout << number << " is an abundant number.\n" << endl;
        else if (sum == number)
            cout << number << " is a perfect number.\n" << endl;
        else if (sum < number) // yes I could just do else but this is more concise in my opinion
            cout << number << " is a deficient number.\n" << endl;
    }
    return 0;
}
