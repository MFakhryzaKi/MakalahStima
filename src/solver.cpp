#include "solver.hpp"

bool visiting[1000000];

PetakInfo minimal(PetakInfo a, PetakInfo b) {
    if (a.minStep < b.minStep) {
        return a;
    }
    else {
        return b;
    }
}

PetakInfo solve(int idxPetak) {
    if (idxPetak > UkuranPetak) {
        return PetakInfo(NILAI_MAXIMAL, "", "");
    }

    if (idxPetak == UkuranPetak) {
        return PetakInfo(0, "", " " + to_string(idxPetak));
    }

    if (petak[idxPetak].minStep != NILAI_MAXIMAL) {
        return petak[idxPetak];
    }

    if (visiting[idxPetak]) {
        return PetakInfo();
    }

    visiting[idxPetak] = true;

    int petakSekarang = idxPetak;

    if (Tangga.count(idxPetak)) {
        petakSekarang = Tangga[idxPetak];
    }
    else if (Ular.count(idxPetak)) {
        petakSekarang = Ular[idxPetak];
    }

    string prefixRute = petakSekarang != idxPetak
        ? " (" + to_string(idxPetak) + "=>" + to_string(petakSekarang) + ")"
        : " " + to_string(petakSekarang);

    PetakInfo best = PetakInfo();

    for (int dadu = 6; dadu >= 1; dadu--) {
        PetakInfo hasil = solve(petakSekarang + dadu);
        if (hasil.minStep == NILAI_MAXIMAL) continue;

        PetakInfo kandidat(
            1 + hasil.minStep,
            " " + to_string(dadu) + hasil.urutanDadu,
            prefixRute + hasil.rute
        );
        best = minimal(best, kandidat);
    }

    visiting[idxPetak] = false;
    return petak[idxPetak] = best;
}

void startSolve() {
    for (int i = 1; i <= UkuranPetak; i++) {
        petak[i] = PetakInfo();
    }

    for (int i = UkuranPetak; i >= 1; i--) {
        if (Ular.count(i)) {
            continue;
        }
        petak[i] = solve(i);
    }

}