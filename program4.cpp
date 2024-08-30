/*
 * This program is written in C++ which reads integers from a text file using ifstream and
 * stores them in a vector. It then searches for any three numbers that sum to 27 using nested loops.
 * If found, it prints the numbers; otherwise, it informs the user that no combination exists.
 * Finally, it calculates and displays the time taken for the operation using the clock function.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    clock_t start, end;

    // Prompt user to enter the file path
    string filePath;
    cout << "Enter the text document: ";
    cin >> filePath;

    // Define the output file name
    string outputFileName = filePath + ".out";

    // Create and open the output file
    ofstream outFile(outputFileName);

    // Start the clock
    start = clock();

    // Open the file
    ifstream inFile(filePath);

    // Check if the file opened successfully
    if (!inFile) {
        cerr << "Unable to open file" << endl;
        return 1; // Exit if the file can't be opened
    }

    // Vector to store the integers
    vector<long> numbers;
    long num;

    // Read numbers from the file and add them to the vector
    while (inFile >> num) {
        numbers.push_back(num);
    }

    // Close the file after reading
    inFile.close();

    // Check if the vector contains at least three numbers
    if (numbers.size() < 3) {
        cerr << "The file must contain at least three integers." << endl;
        return 1; // Exit if there are not enough numbers
    }

    bool found = false;

    // Search for three numbers that sum to 27
    for (size_t i = 0; i < numbers.size() && !found; ++i) {
        for (size_t j = i + 1; j < numbers.size() && !found; ++j) {
            for (size_t k = j + 1; k < numbers.size() && !found; ++k) {
                long sum = numbers[i] + numbers[j] + numbers[k];

                if (sum == 27) {
                    outFile << "YES " << numbers[i] << ", " << numbers[j] << ", " << numbers[k] << endl;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        outFile << "NO - No combination adds up to 27!" << endl;
    }

    // Stop the clock
    end = clock();

    // Calculate and display the elapsed time in milliseconds
    double time_elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
    outFile << "Time elapsed: " << time_elapsed << " milliseconds" << endl;

    return 0;
}

/*
Sample Outputs:

In t1.txt:
YES 9274673, -591965, -8682681
Time elapsed: 38.978 milliseconds

In t2.txt:
YES 9274673, -591965, -8682681
Time elapsed: 42.119 milliseconds

In t3.txt:
NO - No combination adds up to 27!
Time elapsed: 766.091 milliseconds
*/
