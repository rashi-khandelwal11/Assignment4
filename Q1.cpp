#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Vehicle {
private:
    std::string vehicleNumber;
    std::string ownerFirstName;
    std::string ownerLastName;
    int ownerAge;
    std::string ownerGender;
    std::string ownerAddress;

public:
    // Constructor
    Vehicle(const std::string& number, const std::string& firstName, const std::string& lastName, int age, const std::string& gender, const std::string& address)
        : vehicleNumber(number), ownerFirstName(firstName), ownerLastName(lastName), ownerAge(age), ownerGender(gender), ownerAddress(address) {}

    // Function to print vehicle information
    void printDetails() const {
        std::cout << "Vehicle Number: " << vehicleNumber << std::endl;
        std::cout << "Owner: " << ownerFirstName << " " << ownerLastName << std::endl;
        std::cout << "Owner's Age: " << ownerAge << std::endl;
        std::cout << "Owner's Gender: " << ownerGender << std::endl;
        std::cout << "Owner's Address: " << ownerAddress << std::endl;
        std::cout << "----------------------" << std::endl;
    }

    // Getter methods
    std::string getVehicleNumber() const { return vehicleNumber; }
    std::string getOwnerFirstName() const { return ownerFirstName; }
    std::string getOwnerLastName() const { return ownerLastName; }
    int getOwnerAge() const { return ownerAge; }
    std::string getOwnerGender() const { return ownerGender; }
    std::string getOwnerAddress() const { return ownerAddress; }
};

int main() {
    std::vector<Vehicle> vehicles; // Vector to store Vehicle objects

    // Read data from CSV file
    std::ifstream file("Q1.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Read and discard the header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == 7) {
            std::string combinedVehicleNumber = tokens[0] + tokens[1]; // Combine Index and Vehicle Number
            int age = 0;
            try {
                age = std::stoi(tokens[4]); // Convert age string to int
            } catch (const std::exception& e) {
                std::cerr << "Error converting age to integer: " << e.what() << std::endl;
                continue; // Skip this entry if age cannot be converted
            }

            Vehicle vehicle(combinedVehicleNumber, tokens[2], tokens[3], age, tokens[5], tokens[6]);
            vehicles.push_back(vehicle);
        } else {
            std::cerr << "Invalid data format in line: " << line << std::endl;
        }
    }
    file.close();

    // Print details of all vehicles
    int c=0;
    for (const auto& v : vehicles) {
        v.printDetails();
        c++;
    }

    std::cout<<"no. of rows ="<<c;
    return 0;
}
