#include "io.hpp"
#include "solver.hpp"

int main () {
    readAndVerifyFile();
    printPapan();
    startSolve ();
    printDetail ();
}