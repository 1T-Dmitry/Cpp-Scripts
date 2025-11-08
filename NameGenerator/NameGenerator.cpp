#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;

class NameGenerator {
private:
    std::vector<std::string> maleFirstNames;
    std::vector<std::string> maleLastNames;
    std::vector<std::string> maleMiddleNames;
    std::vector<std::string> femaleFirstNames;
    std::vector<std::string> femaleLastNames;
    std::vector<std::string> femaleMiddleNames;

public:
    NameGenerator() {
        std::ifstream maleFirstNameFile("JSON/male_firstNames.json");
        if (!maleFirstNameFile.is_open()) {
            throw std::runtime_error("Could not open male_firstNames.json");
        }
        json data = json::parse(maleFirstNameFile);
        maleFirstNames = data["male_firstNames"];

        std::ifstream maleLastNameFile("JSON/male_lastNames.json");
        if (!maleLastNameFile.is_open()) {
            throw std::runtime_error("Could not open male_lastNames.json");
        }
        data = json::parse(maleLastNameFile);
        maleLastNames = data["male_lastNames"];

        std::ifstream maleMiddleNameFile("JSON/male_middleNames.json");
        if (!maleMiddleNameFile.is_open()) {
            throw std::runtime_error("Could not open male_middleNames.json");
        }
        data = json::parse(maleMiddleNameFile);
        maleMiddleNames = data["male_middleNames"];

        std::ifstream femaleFirstNameFile("JSON/female_firstNames.json");
        if (!femaleFirstNameFile.is_open()) {
            throw std::runtime_error("Could not open female_firstNames.json");
        }
        data = json::parse(femaleFirstNameFile);
        femaleFirstNames = data["female_firstNames"];

        std::ifstream femaleLastNameFile("JSON/female_lastNames.json");
        if (!femaleLastNameFile.is_open()) {
            throw std::runtime_error("Could not open female_lastNames.json");
        }
        data = json::parse(femaleLastNameFile);
        femaleLastNames = data["female_lastNames"];

        std::ifstream femaleMiddleNameFile("JSON/female_middleNames.json");
        if (!femaleMiddleNameFile.is_open()) {
            throw std::runtime_error("Could not open female_middleNames.json");
        }
        data = json::parse(femaleMiddleNameFile);
        femaleMiddleNames = data["female_middleNames"];
    }

    std::string MaleGenerate() {
        return maleFirstNames[rand() % 10] +
            " " + maleLastNames[rand() % 10] +
            " " + maleMiddleNames[rand() % 10];
    }

    std::string FemaleGenerate() {
        return femaleFirstNames[rand() % 10] +
            " " + femaleLastNames[rand() % 10] +
            " " + femaleMiddleNames[rand() % 10];
    }
};

int main() {
    std::cout << "This program can generate a name.\nSelect an option to generate a name:\n" <<
        "1. Generate a male name.\n2. Generate a female name.\n: ";

    int choice = 0;
    std::cin >> choice;

    std::srand(std::time(NULL));
    NameGenerator nameGenerator;

    if (choice == 1) {
        std::cout << nameGenerator.MaleGenerate();
    }
    else if (choice == 2) {
        std::cout << nameGenerator.FemaleGenerate();
    }
    else {
        std::cout << "The wrong enter!";
    }

    return 0;
}
