// Copyright (c) 2021 Layla Michel All rights reserved.
//
// Created by: Layla Michel
// Date: June 7, 2021
// This program gets the user's name and address information and displays it
// in Canadian post format

#include <iostream>
#include <string>
#include <cstring>

std::string AddressFormat(std::string name, std::string streetNum,
                          std::string streetNameType, std::string city,
                          std::string province, std::string postalCode,
                          std::string aptNum = "") {
    // this function takes address information from the user and capitalizes
    // every letter while formatting it in Canadian post format with a default
    // value of None for the apt_num
    std::string formattedAddress = "";
    formattedAddress = formattedAddress + name + "\n";

    if (aptNum != "") {
        formattedAddress = formattedAddress + aptNum + "-";
    }

    formattedAddress = formattedAddress + streetNum + " " + streetNameType
                       + "\n" + city + " " + province + " " + postalCode;

    return formattedAddress;
}


int main() {
    // define variables
    std::string userName, userApt, userAptNum, userStreetNum;
    std::string userStreetNameType, userCity, userProvince, userPostalCode;
    std::string userNameUpper = "", userAptNumUpper = "", userCityUpper = "";
    std::string userStreetNumUpper = "", userStreetNameTypeUpper = "";
    std::string userProvinceUpper = "", userPostalCodeUpper = "";
    std::string mailingAddress;

    // greet and get the user's address information
    std::cout << "This program formats an address to a Canadian ";
    std::cout << "mailing address.\n";

    std::cout << "Enter your full name: ";
    getline(std::cin, userName);
    int userNameLength = userName.length();
    char name_array[userNameLength + 1];
    strcpy(name_array, userName.c_str());
    for (int counter = 0; counter < userNameLength; counter++) {
        userNameUpper += std::toupper(name_array[counter]);
    }

    std::cout << "Do you live in an apartment? (y/n): ";
    getline(std::cin, userApt);

    if (userApt == "y") {
        // check if the user has an apartment
        std::cout << "Enter your apartment number: ";
        getline(std::cin, userAptNum);
        int userAptNumLength = userAptNum.length();
        char aptNum_array[userAptNumLength + 1];
        strcpy(aptNum_array, userAptNum.c_str());
        for (int counter = 0; counter < userAptNumLength; counter++) {
            userAptNumUpper += std::toupper(aptNum_array[counter]);
        }
    }

    std::cout << "Enter your street number: ";
    getline(std::cin, userStreetNum);
    int userStreetNumLength = userStreetNum.length();
    char streetNum_array[userStreetNumLength + 1];
    strcpy(streetNum_array, userStreetNum.c_str());
    for (int counter = 0; counter < userStreetNumLength; counter++) {
        userStreetNumUpper += std::toupper(streetNum_array[counter]);
    }

    std::cout << "Enter your street name AND type ";
    std::cout << "(Main St., Sunset Blvd., etc.): ";
    getline(std::cin, userStreetNameType);
    int userStreetNameTypeLength = userStreetNameType.length();
    char streetNameType_array[userStreetNameTypeLength + 1];
    strcpy(streetNameType_array, userStreetNameType.c_str());
    for (int counter = 0; counter < userStreetNameTypeLength; counter++) {
        userStreetNameTypeUpper += std::toupper(streetNameType_array[counter]);
    }

    std::cout << "Enter your city: ";
    getline(std::cin, userCity);
    int userCityLength = userCity.length();
    char city_array[userCityLength + 1];
    strcpy(city_array, userCity.c_str());
    for (int counter = 0; counter < userCityLength; counter++) {
        userCityUpper += std::toupper(city_array[counter]);
    }

    std::cout << "Enter your province as an abbreviation (ON, QC, etc.): ";
    getline(std::cin, userProvince);
    int userProvinceLength = userProvince.length();
    char province_array[userProvinceLength + 1];
    strcpy(province_array, userProvince.c_str());
    for (int counter = 0; counter < userProvinceLength; counter++) {
        userProvinceUpper += std::toupper(province_array[counter]);
    }

    std::cout << "Enter your postal code: ";
    getline(std::cin, userPostalCode);
    int userPostalCodeLength = userPostalCode.length();
    char postalCode_array[userPostalCodeLength + 1];
    strcpy(postalCode_array, userPostalCode.c_str());
    for (int counter = 0; counter < userPostalCodeLength; counter++) {
        userPostalCodeUpper += std::toupper(postalCode_array[counter]);
    }

    if (userApt == "y") {
        // call function if the user has an apartment number
        mailingAddress = AddressFormat(userNameUpper, userStreetNumUpper,
                                       userStreetNameTypeUpper, userCityUpper,
                                       userProvinceUpper, userPostalCodeUpper,
                                       userAptNumUpper);
    } else {
        // call function if the user does not have an apartment number
        mailingAddress = AddressFormat(userNameUpper, userStreetNumUpper,
                                       userStreetNameTypeUpper, userCityUpper,
                                       userProvinceUpper, userPostalCodeUpper);
    }

    std::cout << "\n";
    // display the formatted mailing address
    std::cout << "Your Canadian mailing address is: \n";
    std::cout << mailingAddress;
}
