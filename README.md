# Makalah Strategi Algoritma
13524087
Muhammad Fakhry Zaki

## Pendahuluan
Program ini adalah program untuk menghitung langkah minimal dari suatu petak menuju petak akhir pada papan permainan ular tangga. Program juga dapat menampilkan urutan dadu serta rute petak yang dikunjugi mulai dari petak tersebut sendiri hingga petak akhir.

## Menjalankan Program
1. Pastikan anda berada di direktori utama (root), kemudian jalankan perintah ini pada terminal untuk melakukan kompilasi program
```bash
g++ -o .\bin\main .\src\main.cpp .\src\io.cpp .\src\solver.cpp
```

2. Setelah itu, jalankan file executable yang sudah terkompilasi dengan perintah berikut
```bash
.\bin\main.exe
```

3. Setelah program dijalankan, program akan meminta user untuk meng-input suatu file .txt yang berisi konfigurasi papan permainan ular tangga. Pastikan file .txt tersebut berada pada folder config. Contoh konfigurasi papan adalah sebagai berikut
```bash
10 10
7
4 23
13 46
33 52
42 63
50 69
62 81
74 93
8
27 5
40 2
43 17
54 31
66 45
89 53
95 76
99 41
```
Baris pertama pada contoh konfigurasi tersebut menunjukkan ukuran tinggi dan lebar dari papan permainan. Baris selanjutnya menunjukkan jumlah tangga yang ada pada papan disimpan pada variabel tanggaCount. Kemudian, sebanyak tanggaCount baris berikutnya mendefinisikan masing-masing tangga dengan nilai yang lebih kecil menunjukkan pangkal (asal) tangga dan nilai yang lebih besar menunjukkan ujung (akhir) tangga. Selanjutnya, baris selanjutnya menunjukkan jumlah ular yang ada pada papan disimpan dalam variabel ularCount. Terakhir, sebanyak ularCount baris terakhir menunjukkan masing-masing ular yang ada dengan nilai yang lebih besar menunjukkan mulut ular dan nilai yang lebih kecil menunjukkan ekor ular.

4. Setelah memasukkan file konfigurasi yang sesuai, program akan menampilkan papan permainan, list tangga, list ular, dan waktu eksekusi program. Kemudian, pengguna akan diberikan CLI interaktif untuk dapat melihat hasil lebih lanjut dari program ini.