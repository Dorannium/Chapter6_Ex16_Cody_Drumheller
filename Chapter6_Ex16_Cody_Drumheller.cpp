/*
Title: Chapter 6 Exercise 16
File Name: Chapter6_Ex16_Cody_Drumheller
Programmer: Cody Drumheller
Date: 20241207
Requirements:
Write a program that displays the contents of the Teams.txt file on the screen and prompts the user to enter the name of one of the teams. 
The program should then display the number of times that team has won the World Series in the time period from 1903 to 2012.
TIP: Read the contents of the WorldSeriesWinners.txt file into an array or vector. 
When the user enters the name of a team, the program should step through the array or vector counting the number of times the selected team appears.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

vector<string> loadFileContents(const string& filename) {
    vector<string> contents;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return contents;
    }

    while (getline(file, line)) {
        contents.push_back(line);
    }

    file.close();
    return contents;
}

int countOccurrences(const vector<string>& data, const string& teamName) {
    return count(data.begin(), data.end(), teamName);
}

int main() {
 
    vector<string> teams = loadFileContents("Teams.txt");
    vector<string> winners = loadFileContents("WorldSeriesWinners.txt");

    if (teams.empty() || winners.empty()) {
        cout << "Error loading files. Please ensure the files exist and contain data." << endl;
        return 1;
    }

    cout << "Available Teams:" << endl;
    for (const string& team : teams) {
        cout << team << endl;
    }

    string userTeam;
    cout << "\nEnter the name of a team to check its World Series wins: ";
    getline(cin, userTeam);

    int wins = countOccurrences(winners, userTeam);

    if (wins > 0) {
        cout << userTeam << " has won the World Series " << wins << " times from 1903 to 2012." << endl;
    }
    else {
        cout << userTeam << " has not won the World Series during the specified period." << endl;
    }

    return 0;
}






