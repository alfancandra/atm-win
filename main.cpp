#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <conio.h>

using namespace std;

void tarik_tunai(int line2,int cash,int cash1){
    ifstream outa;
    outa.open("file2.txt");
    if(outa.is_open())
    {
        while(!outa.eof())
        {
            outa >> line2;
            cout << "Masukan jumlah uang : ";
            cin >> cash;
            if(cash>line2)
            {
                cout << "Maaf transaksi gagal";
            }
            else{
                cash1 = line2-cash;
                cout << endl;
                cout << "Sisa saldo = " << cash1 << endl;
                cout << "Terima Kasih" << endl << endl;
                outa.close();
                ofstream inb;
                inb.open("file2.txt");
                if(inb.is_open())
                {
                    inb << cash1;
                }
                inb.close();
                fstream inx;
                inx.open("file3.txt", ios::app);
                if(inx.is_open())
                {
                    inx << endl << "Rp. " << cash << endl;
                }
                inx.close();
            }
        }
    }
}

void setor_tunai(int line2,int cash2,int cash3){
    ifstream outa;
    outa.open("file2.txt");
    if(outa.is_open())
    {
        while(!outa.eof())
        {
            outa >> line2;
            cout << "Masukan jumlah = ";
            cin >> cash2;
            cash3 = line2+cash2;
            cout << endl;
            cout << "Saldo sekarang Rp. " << cash3 << endl << endl;
            cout << "Terima Kasih" << endl;
            outa.close();
            ofstream q;
            q.open("file2.txt");
            if(q.is_open())
            {
                q << cash3;
            }
            q.close();
            fstream inx;
            inx.open("file4.txt", ios::app);
            if(inx.is_open())
            {
                inx << endl << "Rp. " << cash2 << endl;
            }
            inx.close();
        }
    }
}

void riwayat_tarik_tunai(){
    ifstream f("file3.txt");
    if(f.is_open())
    cout << endl << f.rdbuf();

    f.close();
}

void riwayat_setor_tunai(){
    ifstream f("file4.txt");
    if(f.is_open())
    cout << endl << f.rdbuf();
    f.close();
}

void info(){
    int line2;
    ifstream outo;
    outo.open("file2.txt");
    if(outo.is_open())
    {
        while(!outo.eof())
        {
            outo>>line2;
            cout << "Saldo Anda Saat Ini Rp. " << line2 << endl;
        }
    }
    outo.close();
}


int main()
{
    main:
    string x;
    string line;
    string line4;
    string search;
    int cek;
    int cash;
    int cash1;
    int line2;
    int cash2;
    int cash3;
    int smt;
    int total;
    int pilih;
    int offset;
    string pin;
    string pass1;
    string pass2;
    int c;

    cout << "=============================\n";

    cout << "SELAMAT DATANG DI ATM BANGKIT\n";

    cout << "=============================\n";

    ifstream outf;
    outf.open("file.txt");
    cout << "Masukan 4 digit pin : ";
    cin >> pin;

    if(outf.is_open())
        {
        while(!outf.eof())
        {
        outf >> line;
            if(pin==line)
            {
                outf.close();
                system("CLS");
                do{
                    menu:
                    cout << endl;
                    cout << "=========================\n";
                    cout << "1. Tarik Tunai\n";
                    cout << "2. Riwayat Tarik tunai\n";
                    cout << "3. Setor Tunai\n";
                    cout << "4. Riwayat Setor Tunai\n";
                    cout << "5. Info saldo\n";
                    cout << "6. Bayar Kuliah\n";
                    cout << "7. Keluar\n";
                    cout << "Pilih = ";
                    cin >> c;
                    cout << endl;

                    switch(c)
                    {

                    case 1:
                        {
                            tarik_tunai(line2,cash,cash1);
                            goto coba;
                            break;
                        }

                    case 2:
                        {
                            system("CLS");
                            cout << "1. Tampilkan Semua Riwayat Tarik Tunai\n";
                            cout << "2. Cari Riwayat Tarik Tunai\n";
                            cout << "Pilih : ";
                            cin >> pilih;

                            if(pilih==1){
                                riwayat_tarik_tunai();
                                goto coba;
                            }else if(pilih==2){
                                ifstream file;
                                file.open("file3.txt");
                                cout << "Cari : ";
                                cin >> search;

                                if(file.is_open()){
                                    unsigned int curLine = 0;
                                    while(!file.eof()){
                                        curLine++;
                                        getline(file,line);
                                        if((offset = line.find(search,0))!= string::npos){
                                            cout << endl << "Ditemukan " << search << " di Baris ke : " << curLine << endl;
                                        }
                                    }
                                    file.close();
                                    goto coba;
                                }else{
                                    cout << "Tidak bisa buka file" << endl;
                                    return 0;
                                }
                            }

                            break;
                        }

                    case 3:
                        {
                            setor_tunai(line2,cash2,cash3);
                            goto coba;
                            break;
                        }
                        case 4:
                        {
                            system("CLS");
                            cout << "1. Tampilkan Semua Riwayat Setor Tunai\n";
                            cout << "2. Cari Riwayat Setor Tunai\n";
                            cout << "Pilih : ";
                            cin >> pilih;

                            if(pilih==1){
                                riwayat_setor_tunai();
                                goto coba;
                            }else if(pilih==2){
                                ifstream file;
                                file.open("file4.txt");
                                cout << "Cari : ";
                                cin >> search;

                                if(file.is_open()){
                                    unsigned int curLine = 0;
                                    while(!file.eof()){
                                        curLine++;
                                        getline(file,line);
                                        if((offset = line.find(search,0))!= string::npos){
                                            cout << endl << "Ditemukan " << search << " di Baris ke : " << curLine << endl;
                                        }
                                    }
                                    file.close();
                                    goto coba;
                                }else{
                                    cout << "Tidak bisa buka file" << endl;
                                    return 0;
                                }
                            }
                            break;
                        }
                        case 5:
                        {
                        info();
                        coba:
                        string pil;
                        cout << "Apakah anda ingin bertransaksi lagi ? (Y/N) : ";
                        cin >> pil;
                        if(pil=="y"|| pil=="Y"){
                            system("CLS");
                            goto menu;
                            }else if(pil=="n" || pil=="N"){
                                cout << "Terima kasih";
                                system("CLS");
                                return 0;
                            }else{
                                cout << "coba lagi\n";
                                goto coba;
                            }
                        break;
                        }
                        case 6:
                        {
                            ifstream outa;
                            outa.open("file2.txt");
                                if(outa.is_open())
                                {
                                    while(!outa.eof())
                                    {
                                        outa >> line2;

                                        ifstream smt;
                                        smt.open("smt.txt");
                                        smt >> cek;
                                        smt.close();
                                        if (cek==1)
                                        {
                                            cout << "Biaya Semester Kuliah Sebesar Rp. 5.000.0000, Apakah Ingin melanjutkan ? (Y/N) : ";
                                            cin >> x;
                                            if (x=="y" || x=="Y")
                                            {
                                                ofstream bayar;
                                                bayar.open("file2.txt");
                                                total= line2-5000000;
                                                if (bayar.is_open())
                                                {
                                                    bayar << total;
                                                }
                                                bayar.close();
                                                cout << "Saldo sekarang Rp. " << total << endl << endl;
                                                cout << "Terima Kasih" << endl;
                                                ofstream xx;
                                                xx.open("smt.txt");
                                                if(xx.is_open()){
                                                    xx << 0;
                                                }
                                                goto coba;
                                            }else if(x=="n" || x=="N"){
                                                system("CLS");
                                                goto menu;
                                            }

                                        }else{
                                            cout << "Anda Sudah Membayar Semester Kuliah\n";
                                            goto coba;
                                        }

                                    }
                                }
                                break;
                        }

                        case 7:
                        {
                            system("CLS");
                            cout << "Terima Kasih" << endl;
                            return 0;
                            break;
                        }

                        default:
                        {
                            cout << "Coba Lagi" << endl;
                            system("CLS");
                            goto menu;
                            return 0;
                            break;
                        }
                    }
                }
                while(c!=7);
        }
        else
        {
            cout << endl << "Pin Salah" << endl << endl;
            goto main;
        }
            }


        }
        return 0;
    }



