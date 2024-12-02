#include <iostream>
#include <fstream>

#include "stdafx.h"
#include "XAPI.h" // Pastikan header ini benar sesuai dengan SDK Anda

using namespace std;

// Fungsi untuk menangkap gambar dari kamera dan menyimpannya ke file
bool captureImage(XSDK_HANDLE hCamera, const string& outputFileName) {
    long lShutterSpeed = 0, lBulb = 0;
    unsigned char* pData = nullptr;
    unsigned long lDataSize = 0;

    // Pastikan kamera sudah dalam kondisi siap dan shutter speed berhasil diatur
   /* if (XSDK_CapShutterSpeed(hCamera, &lShutterSpeed, &lBulb)) {
        cerr << "Gagal mendapatkan kecepatan rana!" << endl;
        return false;
    }*/

    // Ambil gambar dari kamera
    /*(XSDK_ReadImage(hCamera, pData, &lDataSize)) {
        cerr << "Gagal membaca gambar!" << endl;
        return false;
    }*/

    // Simpan gambar ke file
    //ofstream outFile(outputFileName, ios::binary);
    //if (!outFile) {
    //    cerr << "Gagal membuka file untuk menulis!" << endl;
    //    return false;
    //}


    cout << "Gambar berhasil disimpan sebagai " << outputFileName << endl;
    return true;
}

// Fungsi utama
int main() {
    XSDK_HANDLE hCamera = nullptr;

    // Inisialisasi kamera
    if (XSDK_OpenEx("NamaDevice", &hCamera, nullptr, nullptr) != 0) {
        cerr << "Gagal membuka kamera!" << endl;
        return -1;
    }

    // Menangkap gambar dan menyimpannya
    if (!captureImage(hCamera, "output_image.jpg")) {
        cerr << "Gagal menangkap gambar!" << endl;
        return -1;
    }

    // Menutup kamera setelah selesai
    if (XSDK_Close(hCamera) != 0) {
        cerr << "Gagal menutup kamera!" << endl;
        return -1;
    }

    return 0;
}
