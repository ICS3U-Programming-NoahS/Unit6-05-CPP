// Copyright (c) 2023 Noah Smith All rights reserved.
//
// Created by: Noah Smith
// Date: Dec. 18th, 2023
// This program asks the user repeatedly to enter a mark between 0 and 100
// When the user enters -1, the loop stops
// then it finds and displays the average of those marks

#include <list>
#include <iostream>

float calcAverage(std::list<float>listMarks) {
    // initialize sum
    float sum = 0;

    // calculate sum with a loop
    for (int aNum : listMarks) {
        sum += aNum;
    }

    // calculate average
    float average = sum / listMarks.size();

    // return average
    return average;
}

int main() {
    // Declare variables
    std::string aNum;
    int aNumInt;

    // Initialize empty list
    std::list<float> listOfMarks;

    // get marks
    for (int counter = 0; counter < 100000; counter++) {
        std::cout << "Enter a mark: ";
        std::cin >> aNum;
        std::cout << std::endl;
        try {
            aNumInt = std::stoi(aNum);
            if (aNumInt < 0 || aNumInt > 100) {
                if (aNumInt == -1) {
                    break;
                } else {
                    std::cout << aNumInt;
                    std::cout << " is not a valid mark." << std::endl;
                }
            } else {
                listOfMarks.push_back(aNumInt);
            }
        } catch (std::exception) {
            std::cout << aNum << " is not an integer." << std::endl;
        }
    }

    // Function call
    float average = calcAverage(listOfMarks);

    // Display average
    std::cout << "" << std::endl;
    std::cout << "The average is " << average << "." << std::endl;
}
