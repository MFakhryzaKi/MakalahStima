#pragma once
#include "io.hpp"

PetakInfo minimal (PetakInfo a, PetakInfo b);

PetakInfo solve (int idxPetak, int stepCount, string curDaduPath, string curRute);

void startSolve ();