#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <math.h>
#include <chrono>
#include "ConfigException.hpp"
// #include "Node.hpp"

using namespace std;

#define NILAI_MAXIMAL 1000000

extern int Baris, Kolom;
extern int UkuranPetak;
extern map<int, int> Tangga;
extern map<int, int> Ular;

class PetakInfo {
public:
    int minStep;
    string urutanDadu;
    string rute;
    PetakInfo()
        : minStep(NILAI_MAXIMAL), urutanDadu(""), rute("") {}

    PetakInfo (int step, string dadu, string rut) 
        : minStep(step), urutanDadu(dadu), rute(rut) {}
};

extern PetakInfo petak[1000000];

bool isInteger (string s);
vector<string> parse(string s);
void verifyFile (ifstream &fileInput);
void readAndVerifyFile ();
void printPapan (int waktu);
void printSatuPetak (int idx);
void printDetail ();
void printSingkat ();
void tampilkanPanel ();