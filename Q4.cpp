#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

// Structure to hold report information
struct ReportInfo {
    std::string typeOfReport;
    std::string reportLocation;
};

// Structure to hold evidence information
struct EvidenceInfo {
    std::string witnesses;
    std::string violationDetails;
    std::string personResponse;
};

int main() {
    std::string carNumberToSearch;

    std::cout << "Enter Car Number: ";
    std::cin >> carNumberToSearch;

    // File paths
    std::string q2FilePath = "Q2.csv";
    std::string evidenceFilePath = "evidence.csv";

    // Mapping car number to report info and evidence info
    std::unordered_map<std::string, ReportInfo> q2Data;
    std::unordered_map<std::string, EvidenceInfo> evidenceData;

    // Reading Q2.csv
    std::ifstream q2File(q2FilePath);
    if (q2File.is_open()) {
        std::string line;
        std::getline(q2File, line); // Skip header

        while (std::getline(q2File, line)) {
            std::stringstream ss(line);
            std::string carNumber, typeOfReport, reportLocation;
            std::getline(ss, carNumber, ',');
            std::getline(ss, typeOfReport, ',');
            std::getline(ss, reportLocation, ',');

            q2Data[carNumber] = {typeOfReport, reportLocation};
        }
        q2File.close();
    } else {
        std::cerr << "Unable to open file: " << q2FilePath << std::endl;
        return 1;
    }

    // Reading evidence.csv
    std::ifstream evidenceFile(evidenceFilePath);
    if (evidenceFile.is_open()) {
        std::string line;
        std::getline(evidenceFile, line); // Skip header

        while (std::getline(evidenceFile, line)) {
            std::stringstream ss(line);
            std::string carNumber, witnesses, violationDetails, personResponse;
            std::getline(ss, carNumber, ',');
            std::getline(ss, witnesses, ',');
            std::getline(ss, violationDetails, ',');
            std::getline(ss, personResponse, ',');

            evidenceData[carNumber] = {witnesses, violationDetails, personResponse};
        }
        evidenceFile.close();
    } else {
        std::cerr << "Unable to open file: " << evidenceFilePath << std::endl;
        return 1;
    }

    // Check if carNumberToSearch exists in both maps
    if (q2Data.find(carNumberToSearch) != q2Data.end() && evidenceData.find(carNumberToSearch) != evidenceData.end()) {
        //std::cout << "Car Number: " << carNumberToSearch << std::endl;
        std::cout << "--------------------------"<< std::endl;
        std::cout << "Type of Report: " << q2Data[carNumberToSearch].typeOfReport << std::endl;
        std::cout << "Report Location: " << q2Data[carNumberToSearch].reportLocation << std::endl;
        std::cout<<std::endl;
        std::cout << "Witnesses: " << evidenceData[carNumberToSearch].witnesses << std::endl;
        std::cout << "Violation Details: " << evidenceData[carNumberToSearch].violationDetails << std::endl;
        std::cout << "Person Response: " << evidenceData[carNumberToSearch].personResponse << std::endl;
        std::cout << "--------------------------"<< std::endl;

    } else {
        std::cout << "Car Number not found or incomplete information." << std::endl;
    }

    return 0;
}
