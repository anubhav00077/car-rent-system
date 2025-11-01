#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Car {
public:
    string carID;
    string carName;
    float rentPerDay;
    
    void inputCar() {
        cout << "Enter Car ID: ";
        cin >> carID;
        cout << "Enter Car Name: ";
        cin.ignore();
        getline(cin, carName);
        cout << "Enter Rent per Day: ";
        cin >> rentPerDay;
    }

    void displayCar() {
        cout << "Car ID: " << carID << ", Name: " << carName 
             << ", Rent/Day: Rs." << rentPerDay << endl;
    }
};

class Rental {
public:
    string userName;
    string carID;
    int days;
    float totalRent;

    void rentCar() {
        cout << "\nEnter Your Name: ";
        cin.ignore();
        getline(cin, userName);
        cout << "Enter Car ID to Rent: ";
        cin >> carID;
        cout << "Enter Number of Days: ";
        cin >> days;
    }

    void calculateRent(float rentPerDay) {
        totalRent = rentPerDay * days;
    }

    void displayRental() {
        cout << "Customer: " << userName 
             << ", Car ID: " << carID 
             << ", Days: " << days 
             << ", Total Rent: Rs." << totalRent << endl;
    }
};

int main() {
    Car cars[3];
    cout << "----- Enter Car Details -----\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nCar " << i + 1 << ":\n";
        cars[i].inputCar();
    }

    Rental r;
    r.rentCar();

    // Find car and calculate rent
    bool found = false;
    for (int i = 0; i < 3; i++) {
        if (cars[i].carID == r.carID) {
            r.calculateRent(cars[i].rentPerDay);
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Car not found!" << endl;
    else {
        ofstream file("rental.txt", ios::app);
        if (file.is_open()) {
            file << "Customer: " << r.userName << ", Car ID: " << r.carID
                 << ", Days: " << r.days << ", Total Rent: Rs." << r.totalRent << endl;
            file.close();
        }
        cout << "\n----- Rental Summary -----\n";
        r.displayRental();
        cout << "Record saved to 'rental.txt'.\n";
    }

return 0;
}
