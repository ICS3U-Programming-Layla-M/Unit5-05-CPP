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
    // value of "" for the aptNum
    std::string formattedAddress = "", formattedAddressUpper = "";
    formattedAddress = formattedAddress + name + "\n";

    if (aptNum != "") {
        formattedAddress = formattedAddress + aptNum + "-";
    }

    formattedAddress = formattedAddress + streetNum + " " + streetNameType
                       + "\n" + city + " " + province + " " + postalCode;

    // get the length of the string
    int formattedAddressLength = formattedAddress.length();
    // create an empty char array
    char char_array[formattedAddressLength + 1] = {};
    // copy the string to the char array letter by letter
    strcpy(char_array, formattedAddress.c_str());
    for (int counter = 0; counter < formattedAddressLength; counter++) {
        formattedAddressUpper += std::toupper(char_array[counter]);
    }

    return formattedAddressUpper;
}


int main() {
    // define variables
    std::string userName, userApt, userAptNum, userStreetNum;
    std::string userStreetNameType, userCity, userProvince, userPostalCode;
    std::string mailingAddress = "";

    // greet and get the user's address information
    std::cout << "This program formats an address to a Canadian ";
    std::cout << "mailing address.\n";

    std::cout << "Enter your full name: ";
    getline(std::cin, userName);

    std::cout << "Do you live in an apartment? (y/n): ";
    getline(std::cin, userApt);

    if (userApt == "y") {
        // check if the user has an apartment
        std::cout << "Enter your apartment number: ";
        getline(std::cin, userAptNum);
    }

    std::cout << "Enter your street number: ";
    getline(std::cin, userStreetNum);

    std::cout << "Enter your street name AND type ";
    std::cout << "(Main St., Sunset Blvd., etc.): ";
    getline(std::cin, userStreetNameType);

    std::cout << "Enter your city: ";
    getline(std::cin, userCity);

    std::cout << "Enter your province as an abbreviation (ON, QC, etc.): ";
    getline(std::cin, userProvince);

    std::cout << "Enter your postal code: ";
    getline(std::cin, userPostalCode);

    if (userApt == "y") {
        // call function if the user has an apartment number
        mailingAddress = AddressFormat(userName, userStreetNum,
                                       userStreetNameType, userCity,
                                       userProvince, userPostalCode,
                                       userAptNum);
    } else {
        // call function if the user does not have an apartment number
        mailingAddress = AddressFormat(userName, userStreetNum,
                                       userStreetNameType, userCity,
                                       userProvince, userPostalCode);
    }

    std::cout << "\n";
    // display the formatted mailing address
    std::cout << "Your Canadian mailing address is: \n";
    std::cout << mailingAddress;
}
