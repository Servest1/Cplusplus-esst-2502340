// C++ implementation​​​​​​‌‌​‌‌​​‌​‌‌‌​‌‌​​​‌​‌​‌​‌ below
// Uncomment these macros to control whether you see
// the expected result and/or hints.
//#define showExpectedResult
//#define showHints

#include <iostream>
#include <vector>

#include <fstream>
#include <sstream>
#include <array>

constexpr int numRows = 4;
constexpr int numCols = 4;

int test = 0;
using namespace std;


/**
 * @brief Liest aus Pfad "/tmp/deps/numbers.csv" die Datei ein.
 * @return Das file-Objekt 
*/
ifstream openNumbersFile()
{
    ifstream file("numbers.csv"); // Update the path to the correct one
    if (!file) {
        cerr << "Fehler, Datei nicht lesbar!" << endl;
    }
    return file;
}


/**
 * @brief Liest aus file-Objekt die Matrix aus
 * @return Ein matrix-Objekt in welcher die ausgelesenen Zahlen stehen
 */
array< array<float, numCols>, numRows > readCsvTable(std::ifstream &file)
{
    string line;
    array< array<float, numCols>, numRows > matrix;

    // TODO: Lies aus file die Zahlen und packe sie in das matrix-Objekt
    for (int row = 0; row < numRows; row++) {
        getline(file, line);
        stringstream ss(line);
        for (int col = 0; col < numCols; col++) {
                ss >> matrix[row][col];

            }
    }
    return matrix;
}

/**
 * @brief Berechnen der horizontalen Summen
 * @return Array aus Summen der Zeilen
 */
array<float, numRows> calcHorSums(const array< array<float, numCols>, numRows > &matrix)
{
    array<float, numCols> horSum = {};

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            horSum[row] += matrix[row][col];
        }
    }

    // TODO: Code zum berechnen der horizontalen Summen
    return horSum;
}

/**
 * @brief Berechnen der vertikalen Summen
 * @return Array aus Summen der Spalten
 */
array<float, numCols> calcVertSums(const array< array<float, numCols>, numRows > &matrix)
{
    array<float, numCols> vertSum = {};
    // TODO: Code zum berechnen der vertikalen Summen
    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row < numRows; row++) {
            vertSum[col] += matrix[row][col];
        }
    }
    return vertSum;
}

bool displaySums(const array<float, numCols> &horSum, 
                 const array<float, numRows> &vertSum)
{
    bool ok = false;   
    // TODO: Code zum Ausgeben der Summen. Bitte nicht mogeln ;-)
    cout << "Summe Reihen:" << endl;
    for (int row = 0; row < numRows; row++){
        cout << horSum[row] << endl;
    }
    cout << "Summe Spalten" << endl;
    for (int col=0; col < numCols; col++){
        cout << vertSum[col] << "    ";
    }
    cout << endl;
    return ok;
}

int main(){
    auto file = openNumbersFile();
    if (!file){
        return 1;
    }
    
    auto matrix = readCsvTable(file);

    auto HorSums = calcHorSums(matrix);
    auto VertSums = calcVertSums(matrix);

    auto why = displaySums(HorSums, VertSums);

    file.close();

    return 0;
}