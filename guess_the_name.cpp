#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

void displayGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int getValidInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else if (input < min || input > max) {
            cout << "Input must be between " << min << " and " << max << ". Try again: ";
        } else {
            break;
        }
    }
    return input;
}

void showLoadingMessage() {
    cout << "\nSearching";
    char symbols[] = {'/', '\\'};
    int symbolIndex = 0;

    for (int i = 0; i < 10; ++i) {
        cout << "\rSearching " << symbols[symbolIndex];
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));
        symbolIndex = (symbolIndex + 1) % 2;
    }

    cout << "\rSearching Done!" << endl;
}

void printMessageWithAsterisks(const string& message) {
    int length = message.length();
    int borderWidth = 3;
    int totalWidth = length + 2 * borderWidth;

    for (int i = 0; i < borderWidth; ++i) {
        cout << string(totalWidth, '*') << endl;
    }

    cout << string(borderWidth, '*') << message << string(borderWidth, '*') << endl;

    for (int i = 0; i < borderWidth; ++i) {
        cout << string(totalWidth, '*') << endl;
    }
}

vector<vector<char>> createGrid(char startLetter, int rows, int cols) {
    vector<vector<char>> grid(rows, vector<char>(cols));
    char letter = startLetter;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (letter <= ((startLetter == 'A') ? 'Z' : 'z')) {
                grid[i][j] = letter++;
            } else {
                grid[i][j] = ' ';
            }
        }
    }

    return grid;
}

string guessName(const vector<vector<char>>& nameArrays, int nameLength) {
    string guessedName = "";

    for (int i = 0; i < nameLength; ++i) {
        vector<char> sortedChars = nameArrays[i];
        sort(sortedChars.begin(), sortedChars.end());

        char mostFrequentChar = sortedChars[0];
        int maxFreq = 1;
        int currentFreq = 1;

        for (int j = 1; j < sortedChars.size(); ++j) {
            if (sortedChars[j] == sortedChars[j - 1]) {
                currentFreq++;
                if (currentFreq > maxFreq) {
                    maxFreq = currentFreq;
                    mostFrequentChar = sortedChars[j];
                }
            } else {
                currentFreq = 1;
            }
        }

        if (mostFrequentChar == ' ') {
            mostFrequentChar = 'Z';
        }

        guessedName += mostFrequentChar;
    }

    return guessedName;
}


vector<vector<char>> getSelectedGrid(const vector<vector<char>>& grid, const set<int>& uniqueColumns) {
    vector<vector<char>> selectedGrid(6, vector<char>(uniqueColumns.size()));
    int colIndex = 0;

    for (int col : uniqueColumns) {
        for (int row = 0; row < 6; ++row) {
            selectedGrid[row][colIndex] = grid[row][col];
        }
        colIndex++;
    }

    return selectedGrid;
}

vector<vector<char>> buildNameArrays(const vector<vector<char>>& grid, const vector<int>& selectedColumns, int nameLength) {
    vector<vector<char>> nameArrays(nameLength);

    for (int i = 0; i < nameLength; ++i) {
        int col = selectedColumns[i];
        for (int row = 0; row < 6; ++row) {
            nameArrays[i].push_back(grid[row][col]);
        }
    }

    return nameArrays;
}

int main() {
    string message = "Welcome to the Name Guessing Game!";
    printMessageWithAsterisks(message);
    showLoadingMessage();

    cout << "\nDo you want to play with  (1) Uppercase letters or (2) Lowercase letters? ";
    int caseOption = getValidInput(1, 2);
    char startLetter = (caseOption == 1) ? 'A' : 'a';

    vector<vector<char>> grid = createGrid(startLetter, 6, 5);

    cout << "\nChoose your columns here!\n";
    displayGrid(grid);

    cout << "\nHow many characters are in your name? ";
    int nameLength = getValidInput(1, 30);

    vector<int> selectedColumns(nameLength);
    set<int> uniqueColumns;

    cout << "\nEnter the column numbers (1-5) :" << endl;
    for (int i = 0; i < nameLength; ++i) {
        cout << "Column for character " << (i + 1) << ": ";
        selectedColumns[i] = getValidInput(1, 5) - 1;
        uniqueColumns.insert(selectedColumns[i]);
    }

    vector<vector<char>> nameArrays = buildNameArrays(grid, selectedColumns, nameLength);

    vector<vector<char>> selectedGrid = getSelectedGrid(grid, uniqueColumns);

    cout << "\nSelect again from rows:\n";
    displayGrid(selectedGrid);

    vector<int> selectedRows(nameLength);
    cout << "\nEnter the row numbers (1-6) :" << endl;
    for (int i = 0; i < nameLength; ++i) {
        cout << "Row for character " << (i + 1) << ": ";
        selectedRows[i] = getValidInput(1, 6) - 1;
    }

    for (int i = 0; i < nameLength; ++i) {
        int row = selectedRows[i];
        for (int col = 0; col < uniqueColumns.size(); ++col) {
            nameArrays[i].push_back(selectedGrid[row][col]);
        }
    }

    string guessedName = guessName(nameArrays, nameLength);

    cout << "\nGuessed Name: " << guessedName << endl;

    return 0;
}