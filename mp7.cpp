#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cstdlib> // untuk fungsi system

using namespace std;

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

class TeksEditor
{
private:
    string filename;
    string text;
    string line;
    string word;

public:
    // Deklarasi fungsi
    void createFile(); // fungsi untuk membuat file baru
    void appendToFile(); // fungsi untuk menambahkan isi file
    void readFile(); // fungsi untuk membaca file
    void emptyFile(); // fungsi untuk mengosongkan file
    void deleteFile(); // fungsi untuk menghapus file
    void analyzeFile(); // fungsi untuk menganalisis file
    void compileFile(); // fungsi untuk mengkompilasi file
};


// fungsi untuk membuat file baru
void TeksEditor::createFile()
{
    cout << GREEN << "Masukkan nama file: " << RESET;
    cin >> filename;

    // Buka file dengan nama yang dimasukkan
    ofstream file(filename);

    cout << BLUE << "Isi telah dibuat" << endl;

    file.close();
}

// fungsi untuk menambahkan isi ke file
void TeksEditor::appendToFile()
{
    cout << GREEN << "Masukkan nama file: " << RESET;
    cin >> filename;

    // Buka file dalam mode append
    ofstream file(filename, ios::app);

   
    cout << GREEN << "Masukkan isi untuk ditambahkan (Masukkan 'EOF' untuk berhenti): " << RESET << endl;
    cin.ignore();
    while (getline(cin, text)) {
        if (text == "EOF") {
            break;
        }
        // Tulis teks ke dalam file
        file << text << endl;
    }

    file.close();

    cout << BLUE << "Isi telah ditambahkan ke dalam file." << RESET << endl;
}

// fungsi untuk membaca isi file
void TeksEditor::readFile()
{
   
    cout << "Masukkan nama file: ";
    cin >> filename;

    // Buka file untuk dibaca
    ifstream file(filename);

    if (!file) {
        cout << "Error membuka file" << endl;
        return;
    }

   
    while (getline(file, text)) {
        // Cetak setiap baris teks
        cout << text << endl;
    }

    file.close();
}

// fungsi untuk mengosongkan isi file
void TeksEditor::emptyFile()
{
    
    cout << "Masukkan nama file: ";
    cin >> filename;

    // Buka file dengan mode truncate (mengosongkan isi file)
    ofstream file(filename, ofstream::trunc);
    file.close();

    cout << BLUE << "File telah berhasil dikosongkan." << RESET << endl;
}

// fungsi untuk menghapus file
void TeksEditor::deleteFile()
{
  
    cout << GREEN << "Masukkan nama file: " << RESET;
    cin >> filename;
    remove(filename.c_str()) == 0;
}

// fungsi untuk menganalisis file
void TeksEditor::analyzeFile()
{

    cout << GREEN << "Masukkan nama file: " << RESET;
    cin >> filename;

    // Buka file untuk dibaca
    ifstream file(filename);

    int lineCount = 0;
    int wordCount = 0;
    int characterCount = 0;

    
    while (getline(file, line)) {
        lineCount++;

        istringstream iss(line);
       

        while (iss >> word) {
            wordCount++;

            // Hapus tanda baca dan karakter khusus dari kata
            word.erase(remove_if(word.begin(), word.end(), [](char c) {
                return !isalpha(c);
            }), word.end());

            characterCount += word.length();
        }
    }

    file.close();

    cout << endl << "Hasil analisis untuk file: " << filename << endl;
    cout << "Jumlah baris: " << lineCount << endl;
    cout << "Jumlah kata: " << wordCount << endl;
    cout << "Jumlah karakter: " << characterCount << endl;
}

// fungsi untuk mengkompilasi file C++
void TeksEditor::compileFile()
{
    cout << GREEN << "Masukkan nama file yang akan dikompilasi: " << RESET;
    cin >> filename;

    string command1 = "g++ " + filename + " -o " + filename + ".exe";
    int result1 = system(command1.c_str());

    string command2 = "C:/Users/ASUS/cpp/" + filename + ".exe";
    int result2 = system(command2.c_str());
}

int main()
{
    int choice;

    cout << BLUE << "TEKS EDITOR 7" << RESET << endl << endl;
    TeksEditor T;

    do {
        cout << GREEN << "Menu:" << endl;
        cout << "1. Buat file baru" << endl;
        cout << "2. Tambahkan isi ke file" << endl;
        cout << "3. Baca isi dari file" << endl;
        cout << "4. Kosongkan isi file" << endl;
        cout << "5. Hapus file" << endl;
        cout << "6. Analisis file" << endl;
        cout << "7. compile dan run file" << endl;
        cout << "8. Keluar" << RESET << endl << endl;
        cout << YELLOW << "Tentukan pilihan: " << RESET;
        cin >> choice;

        switch (choice) {
            case 1:
                T.createFile();
                break;
            case 2:
                 T.appendToFile();
                break;
            case 3:
                 T.readFile();
                break;
            case 4:
                 T.emptyFile();
                break;
            case 5:
                 T.deleteFile();
                break;
            case 6:
                 T.analyzeFile();
                break;
            case 7:
                 T.compileFile();
                break;
            case 8:
                cout << "Keluar..." << endl;
                break;
            default:
                cout << "Salah pilih. Tetap semangat dan jangan menyerah." << endl;
                break;
        }

        cout << endl;
    } while (choice != 8);

return 0;
}
