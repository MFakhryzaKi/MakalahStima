#include "io.hpp"
#include "solver.hpp"

int main () {
    readAndVerifyFile();
    
    auto startTime = chrono::high_resolution_clock::now();
    startSolve ();
    auto endTime = chrono::high_resolution_clock::now();
    auto duration_us = chrono::duration_cast<chrono::microseconds> (endTime - startTime);
    
    printPapan(duration_us.count());
    tampilkanPanel ();
    // printDetail ();
}