#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class TrafficViolationDatabase {
private:
    struct TrafficViolation {
        std::string car_number;
        std::string report_type;
        std::string report_location;
    };

    std::vector<TrafficViolation> violations;

public:
    void readCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            TrafficViolation violation;

            std::getline(ss, violation.car_number, ',');
            std::getline(ss, violation.report_type, ',');
            std::getline(ss, violation.report_location, ',');

            violations.push_back(violation);
        }

        file.close();
    }

    void displayAllViolations() const {
        std::cout << "All Violations:" << std::endl;
        for (const auto& violation : violations) {
            std::cout<<"--------------------------"<<std::endl;
            std::cout << "Car Number: " << violation.car_number<<std::endl
                      << "Type of Report: " << violation.report_type<<std::endl
                      << "Location: " << violation.report_location << std::endl;

        }
        std::cout<<"--------------------------"<<std::endl;
    }
};

int main() {
    TrafficViolationDatabase database;
    database.readCSV("Q2.csv");

    database.displayAllViolations();

    return 0;
}
