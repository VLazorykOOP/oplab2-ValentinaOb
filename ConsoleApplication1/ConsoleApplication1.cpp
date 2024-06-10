#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void moveCar(double V, double len) {
    double position = 0.0;

    while (position < len) {
        position += V;

        if (position > len) {
            break;
        }
        cout << "\nCar position: " << position;
    }
}
void moveMotorcycle(double V, double len) {
    double position = 0.0;

    while (position < len) {
        position += V;

        if (position > len) {
            break;
        }
        cout << "\nMotorcycle position: " << position;
    }
}

void one() {
    double areaLength;
    int numC, j = 0;

    cout << "Number of car: ";
    cin >> numC;
    cout << "X Area Length: ";
    cin >> areaLength;
    double V[10];

    for (int i = 0; i < numC; i++) {
        cout << "V " << (i + 1) << ": ";
        cin >> V[j];
        j++;
    }

    vector<thread> threads;

    for (int i = 0; i < numC; ++i) {
        threads.push_back(thread(moveCar, V[i], areaLength));
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void two() {
    double areaLength;
    int numC, j = 0;

    cout << "Number of motorcycle: ";
    cin >> numC;
    cout << "Y Area Length: ";
    cin >> areaLength;
    double V[10];

    for (int i = 0; i < numC; i++) {
        cout << "V " << (i + 1) << ": ";
        cin >> V[j];
        j++;
    }

    vector<thread> threads;

    for (int i = 0; i < numC; ++i) {
        threads.push_back(thread(moveMotorcycle, V[i], areaLength));
    }

    for (auto& thread : threads) {
        thread.join();
    }

}

int main() {
    int t;
    cout << "Task: ";
    cin >> t;
    switch (t) {
    case 1: {
        one();
        break; }
    case 2: {
        two();
        break; }
    default: cout << "Error: ";
    }

    return 0;
}