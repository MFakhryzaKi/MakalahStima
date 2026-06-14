#include "io.hpp"

int Baris, Kolom;
int UkuranPetak;
map<int, int> Tangga;
map<int, int> Ular;
PetakInfo petak[1000000];

bool isInteger (string s) {
    try {
        size_t pos;
        stoi (s, &pos);
        return pos == s.length();
    }
    catch (...) {
        return false;
    }
}

vector<string> parse(string s) {
    stringstream ss(s);
    string token;
    vector <string> res;

    while (ss >> token) {
        res.push_back(token);
    }

    return res;
}


void verifyFile (ifstream &fileInput) {
    
    if (!fileInput.eof()) {
        // baris pertama
        string s;
        vector<string> v;

        getline (fileInput, s);
        v = parse (s);

        if (v.size() != 2) {
            throw ConfigException ("Input baris pertama harus 2 angka yang menunjukkan tinggi dan panjang papan!", 1);
        }

        if (!isInteger(v[0]) || !isInteger(v[1])) {
            throw ConfigException ("Input baris pertama harus 2 angka yang menunjukkan tinggi dan panjang papan!", 1);
        }

        Baris = stoi (v[0]);
        Kolom = stoi (v[1]);
        UkuranPetak = Baris * Kolom;

        if (Baris > 1000 || Kolom > 1000) {
            throw ConfigException ("Ukuran papan tidak boleh melebihi 1000!", 1);
        }

        if (!fileInput.eof()) {
            getline (fileInput, s);
            v = parse (s);

            if (v.size() != 1) {
                throw ConfigException ("Jumlah tangga hanya bisa diisi dengan satu buah bilangan bulat!", 2);
            }

            if (!isInteger(v[0])) {
                throw ConfigException ("Jumlah tangga hanya bisa diisi dengan satu buah bilangan bulat!", 2);
            }

            int tanggaCount = stoi (v[0]);

            for (int i = 1; i <= tanggaCount; i++) {
                if (fileInput.eof()) {
                    throw ConfigException ("Jumlah tangga tidak sesuai dengan yang didefinisikan!", 2 + i);
                }

                getline (fileInput, s);
                v = parse (s);

                if (v.size() != 2) {
                    throw ConfigException ("Satu tangga harus berisi 2 buah angka bilangan bulat", 2 + i);
                }

                if (!isInteger(v[0]) || !isInteger(v[1])) {
                    throw ConfigException ("Satu tangga harus berisi 2 buah angka bilangan bulat", 2 + i);
                }

                if (stoi(v[0]) > Baris*Kolom || stoi(v[0]) < 1 || stoi(v[1]) > Baris*Kolom || stoi(v[1]) < 1) {
                    throw ConfigException ("Petak yang ditunjuk tangga harus berada pada range 1-" + to_string(Baris*Kolom), 2 + i);
                }

                Tangga[min(stoi(v[0]), stoi(v[1]))] = max(stoi(v[0]), stoi(v[1]));
            }

            if (!fileInput.eof()) {
                getline (fileInput, s);
                v = parse (s);

                if (v.size() != 1) {
                    throw ConfigException ("Jumlah ular hanya bisa diisi dengan satu buah bilangan bulat!", 3 + tanggaCount);
                }

                if (!isInteger(v[0])) {
                    throw ConfigException ("Jumlah ular hanya bisa diisi dengan satu buah bilangan bulat!", 3 + tanggaCount);
                }

                int ularCount = stoi (v[0]);

                for (int i = 1; i <= ularCount; i++) {
                    if (fileInput.eof()) {
                        throw ConfigException ("Jumlah ular tidak sesuai dengan yang didefinisikan!", 3 + tanggaCount + i);
                    }

                    getline (fileInput, s);
                    v = parse (s);

                    if (v.size() != 2) {
                        throw ConfigException ("Satu ular harus berisi 2 buah angka bilangan bulat", 3 + tanggaCount + i);
                    }

                    if (!isInteger(v[0]) || !isInteger(v[1])) {
                        throw ConfigException ("Satu ular harus berisi 2 buah angka bilangan bulat", 3 + tanggaCount + i);
                    }

                    if (stoi(v[0]) > Baris*Kolom || stoi(v[0]) < 1 || stoi(v[1]) > Baris*Kolom || stoi(v[1]) < 1) {
                        throw ConfigException ("Petak yang ditunjuk ular harus berada pada range 1-" + to_string(Baris*Kolom), 3 + tanggaCount + i);
                    }

                    Ular[max(stoi(v[0]), stoi(v[1]))] = min(stoi(v[0]), stoi(v[1]));
                }
            } 
            else {
                throw ConfigException ("Config harus memuat sejumlah ular!", 3 + tanggaCount);
            }
        }
        else {
            throw ConfigException ("Config haru memuat sejumlah tangga!", 2);
        }

    }
    else {
        throw ConfigException ("File kosong!", 0);
    }


}

void readAndVerifyFile () {
    cout << "SELAMAT DATANG DI PENGHITUNG ULAR TANGGA" << endl;
    while (true) {
        Tangga.clear();
        Ular.clear();
        UkuranPetak = 0;

        cout << "Masukkan file input: ";
        string s;
        getline(cin, s);

        ifstream stream1 ("config/" + s);
        ifstream stream2 ("config/" + s + ".txt");

        if (!stream1.is_open() && !stream2.is_open()) {
            cout << "File dengan nama " << s << " tidak ditemukan!\n";
            continue;
        }
        else {
            ifstream fileInput;
            if (stream1.is_open()) {
                fileInput.open("config/" + s);
            }
            else {
                fileInput.open("config/" + s + ".txt");
            }

            try {
                verifyFile(fileInput);
                // kalo masuk sini berarti berhasil
                break;
            }
            catch (ConfigException& e) {
                cout << e.toString() << endl;
            }

        }
    }

}

void printPapan (int waktu) {
    cout << "------------ Papan Permainan ------------" << endl;
    for (int baris = Baris - 1; baris >= 0; baris--) {
        int awal = baris * Kolom + 1;

        if (baris % 2 == 0) {
            // kiri -> kanan
            for (int kolom = 0; kolom < Kolom; kolom++) {
                cout << awal + kolom << "\t";
            }
        } else {
            // kanan -> kiri
            for (int kolom = Kolom - 1; kolom >= 0; kolom--) {
                cout << awal + kolom << "\t";
            }
        }

        cout << endl;
    }

    cout << "List Tangga: " << endl;
    for (auto tangga : Tangga) {
        cout << tangga.first << " -> " << tangga.second << endl;
    }

    cout << "List Ular: " << endl;
    for (auto ular : Ular) {
        cout << ular.first << " -> " << ular.second << endl;
    }

    cout << "Waktu komputasi: " << waktu << " microseconds" << endl;
    cout << "-------------------------------------------" << endl;
}

void printSatuPetak (int idx) {
    cout << "===========================================" << endl << endl;
    cout << "               Petak " << idx << "               " << endl;
    cout << "Langkah Minimal    : " << petak[idx].minStep << endl;
    cout << "Urutan Dadu        :" << petak[idx].urutanDadu << endl;
    cout << "Rute               :" << petak[idx].rute << endl << endl;
    cout << "===========================================" << endl;
}

void printDetail () {
    cout << "===========================================" << endl << endl;
    // cout << "-------------------------------------------" << endl;
    for (int i = 1; i <= UkuranPetak; i++) {
        printSatuPetak (i);
        // cout << "-------------------------------------------" << endl;
    }
    cout << endl << "===========================================" << endl;

}

void printSingkat () {
    cout << "===========================================" << endl << endl;
    for (int i = 1; i <= UkuranPetak; i++) {
        cout << "Petak[" << i << "] : " << petak[i].minStep << endl;
    }
    cout << endl << "===========================================" << endl;

}

string to_lower_case (string s) {
    string res = "";
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            res += c - 'A' + 'a';
        }
        else {
            res += c;
        }
    }
    return res;
}

void tampilkanPanel () {
    while (true) {
        cout << "List perintah : " << endl;
        cout << "1. Melihat detail satu petak (cmd: 1-" << UkuranPetak << ")" << endl;
        cout << "2. Melihat summary dari semua petak (cmd: summary)" << endl;
        cout << "3. Melihat detail dari semua petak (cmd: detail)" << endl;
        cout << "4. Keluar dari program (cmd: quit/exit)" << endl;

        string s;
        cout << ">> ";
        getline(cin, s);
        s = to_lower_case (s);
        if (isInteger (s)) {
            int temp = stoi(s);
            if (temp >= 1 && temp <= UkuranPetak) {
                printSatuPetak (temp);
            }
            else {
                cout << "Angka harus berada di antara 1-" << UkuranPetak << "!" << endl;
                continue;
            }
        }
        else if (s == "summary") {
            printSingkat ();
        }
        else if (s == "detail") {
            printDetail ();
        }
        else if (s == "quit" || s == "exit") {
            break;
        }
    }
}