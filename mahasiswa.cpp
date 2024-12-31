#include <iostream>
#include <vector>
#include <string>
#include <limits>

// Struktur Data Mahasiswa
struct Mahasiswa {
    std::string nama;
    int nim;
    std::string jurusan;
    float ipk;
};

// Fungsi untuk menambahkan mahasiswa
void tambahMahasiswa(std::vector<Mahasiswa>& database) {
    Mahasiswa mhs;
    std::cout << "Masukkan Nama: ";
    std::cin.ignore(); // Mengabaikan karakter newline sebelumnya
    std::getline(std::cin, mhs.nama);
    std::cout << "Masukkan NIM: ";
    std::cin >> mhs.nim;
    std::cout << "Masukkan Jurusan: ";
    std::cin.ignore();
    std::getline(std::cin, mhs.jurusan);
    std::cout << "Masukkan IPK: ";
    std::cin >> mhs.ipk;

    database.push_back(mhs);
    std::cout << "Data mahasiswa berhasil ditambahkan!\n\n";
}

// Fungsi untuk menampilkan semua mahasiswa
void tampilkanMahasiswa(const std::vector<Mahasiswa>& database) {
    if (database.empty()) {
        std::cout << "Tidak ada data mahasiswa.\n\n";
        return;
    }

    std::cout << "=== Data Mahasiswa ===\n";
    for (const auto& mhs : database) {
        std::cout << "Nama     : " << mhs.nama << '\n';
        std::cout << "NIM      : " << mhs.nim << '\n';
        std::cout << "Jurusan  : " << mhs.jurusan << '\n';
        std::cout << "IPK      : " << mhs.ipk << '\n';
        std::cout << "----------------------\n";
    }
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
void cariMahasiswa(const std::vector<Mahasiswa>& database) {
    if (database.empty()) {
        std::cout << "Tidak ada data mahasiswa untuk dicari.\n\n";
        return;
    }

    int nim;
    std::cout << "Masukkan NIM yang dicari: ";
    std::cin >> nim;

    for (const auto& mhs : database) {
        if (mhs.nim == nim) {
            std::cout << "=== Mahasiswa Ditemukan ===\n";
            std::cout << "Nama     : " << mhs.nama << '\n';
            std::cout << "NIM      : " << mhs.nim << '\n';
            std::cout << "Jurusan  : " << mhs.jurusan << '\n';
            std::cout << "IPK      : " << mhs.ipk << '\n\n';
            return;
        }
    }

    std::cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n\n";
}

// Fungsi untuk menghapus mahasiswa berdasarkan NIM
void hapusMahasiswa(std::vector<Mahasiswa>& database) {
    if (database.empty()) {
        std::cout << "Tidak ada data mahasiswa untuk dihapus.\n\n";
        return;
    }

    int nim;
    std::cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
    std::cin >> nim;

    for (auto it = database.begin(); it != database.end(); ++it) {
        if (it->nim == nim) {
            database.erase(it);
            std::cout << "Mahasiswa dengan NIM " << nim << " berhasil dihapus.\n\n";
            return;
        }
    }

    std::cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n\n";
}

// Fungsi untuk mengedit data mahasiswa
void editMahasiswa(std::vector<Mahasiswa>& database) {
    if (database.empty()) {
        std::cout << "Tidak ada data mahasiswa untuk diedit.\n\n";
        return;
    }

    int nim;
    std::cout << "Masukkan NIM mahasiswa yang ingin diedit: ";
    std::cin >> nim;

    for (auto& mhs : database) {
        if (mhs.nim == nim) {
            std::cout << "=== Data Mahasiswa ===\n";
            std::cout << "Nama     : " << mhs.nama << '\n';
            std::cout << "Jurusan  : " << mhs.jurusan << '\n';
            std::cout << "IPK      : " << mhs.ipk << '\n';

            std::cout << "\nMasukkan data baru:\n";
            std::cout << "Nama: ";
            std::cin.ignore();
            std::getline(std::cin, mhs.nama);
            std::cout << "Jurusan: ";
            std::getline(std::cin, mhs.jurusan);
            std::cout << "IPK: ";
            std::cin >> mhs.ipk;

            std::cout << "Data mahasiswa berhasil diperbarui!\n\n";
            return;
        }
    }

    std::cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n\n";
}

// Fungsi utama
int main() {
    std::vector<Mahasiswa> database;
    bool running = true;

    while (running) {
        std::cout << "=== Sistem Pengelolaan Data Mahasiswa ===\n";
        std::cout << "1. Tambah Mahasiswa\n";
        std::cout << "2. Tampilkan Semua Mahasiswa\n";
        std::cout << "3. Cari Mahasiswa\n";
        std::cout << "4. Hapus Mahasiswa\n";
        std::cout << "5. Edit Mahasiswa\n";
        std::cout << "6. Keluar\n";
        std::cout << "Pilih menu (1-6): ";

        int pilihan;
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa(database);
                break;
            case 2:
                tampilkanMahasiswa(database);
                break;
            case 3:
                cariMahasiswa(database);
                break;
            case 4:
                hapusMahasiswa(database);
                break;
            case 5:
                editMahasiswa(database);
                break;
            case 6:
                running = false;
                std::cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi.\n\n";
                break;
        }
    }

    return 0;
}
