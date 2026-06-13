#include "solver.hpp"

PetakInfo minimal (PetakInfo a, PetakInfo b) {
    if (a.minStep < b.minStep) {
        return a;
    }
    else {
        return b;
    }
}

PetakInfo solve (int idxPetak, int stepCount, string curDaduPath, string curRute) {
    // cout << " " << idxPetak << endl;
    if (idxPetak > UkuranPetak) {
        idxPetak = 2*UkuranPetak - idxPetak;
    }

    if (idxPetak == UkuranPetak) {
        return {stepCount, curDaduPath, curRute};
    }

    if (petak[idxPetak].minStep != NILAI_MAXIMAL) {
        return PetakInfo (stepCount + petak[idxPetak].minStep, curDaduPath + petak[idxPetak].urutanDadu, curRute + petak[idxPetak].rute);
        // return petak[idxPetak];
    }

    int petakSekarang = idxPetak;

    if (Tangga.count (idxPetak)) {
        petakSekarang = Tangga[idxPetak];
    }
    else if (Ular.count (idxPetak)) {
        petakSekarang = Ular[idxPetak];
    }

    PetakInfo best = PetakInfo ();
    for (int dadu = 1; dadu <= 6; dadu++) {
        string daduPath = curDaduPath + " " + to_string (dadu);
        string ruteBaru = petakSekarang == idxPetak ? curRute + " (" + to_string(idxPetak) + "=>" + to_string(petakSekarang) + ")" : curRute + " " + to_string(petakSekarang);
        best = minimal(best, solve (petakSekarang + dadu, stepCount + 1, daduPath, ruteBaru));
        // petak[idxPetak] = minimal (best, petak[idxPetak]);
    }

    return petak[idxPetak] = best;
}

void startSolve () {
    // initialize petak
    for (int i = 1; i <= UkuranPetak; i++) {
        petak[i] = PetakInfo ();
    }
    cout << "masuk sini" << endl;

    // solve satu-satu dari akhir sampe awal
    for (int i = UkuranPetak; i >= 1; i--) {
        cout << i << endl;
        petak[i] = solve (i, 0, "", "");
        // printSatuPetak (i);
    }
    cout << "kedua" << endl;
}