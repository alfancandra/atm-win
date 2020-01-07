#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <ctime>

using namespace std;

void sorting(string arr[], int n)
{
    int i, j;
    string key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void cetak(string arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << endl;
    cout << endl;
}

void tarik_tunai(int line2,int cash,int cash1){
    time_t now = time(0);
	tm *ltm = localtime(&now);
    string bulan[]={"januari","februari","maret","april","mei","juni","juli","agustus","september","oktober","november","desember",};
    int x;
    int tanggal;
    string month;
    int tahun;
    ifstream outa;
    outa.open("saldo.txt");
    if(outa.is_open())
    {
        while(!outa.eof())
        {
            outa >> line2;
            cout << "Masukan jumlah uang : ";
            cin >> cash;
            x=1 + ltm->tm_mon;
            month=bulan[x-1];
            tanggal=ltm->tm_mday;
            tahun=1900 + ltm->tm_year;
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
                inb.open("saldo.txt");
                if(inb.is_open())
                {
                    inb << cash1;
                }
                inb.close();
                fstream inx;
                inx.open("riwayat_tarik.txt", ios::app);
                if(inx.is_open())
                {
                    inx << "\tTanggal " << tanggal << " " << month << " " << tahun << endl;
                    inx << endl << "Rp. " << cash << endl;
                }
                inx.close();
            }
        }
    }
}

void setor_tunai(int line2,int cash2,int cash3){
    time_t now = time(0);
	tm *ltm = localtime(&now);
    string bulan[]={"januari","februari","maret","april","mei","juni","juli","agustus","september","oktober","november","desember",};
    int x;
    int tanggal;
    string month;
    int tahun;

    x=1 + ltm->tm_mon;
    month=bulan[x-1];
    tanggal=ltm->tm_mday;
    tahun=1900 + ltm->tm_year;

    ifstream outa;
    outa.open("saldo.txt");
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
            q.open("saldo.txt");
            if(q.is_open())
            {
                q << cash3;
            }
            q.close();
            fstream inx;
            inx.open("riwayat_setor.txt", ios::app);
            if(inx.is_open())
            {
                inx << "\tTanggal " << tanggal << " " << month << " " << tahun << endl;
                inx << endl << "Rp. " << cash2 << endl;
            }
            inx.close();
        }
    }
}

void riwayat_tarik_tunai(){
    ifstream f("riwayat_tarik.txt");
    if(f.is_open())
    cout << endl << f.rdbuf();

    f.close();
}

void riwayat_setor_tunai(){
    ifstream f("riwayat_setor.txt");
    if(f.is_open())
    cout << endl << f.rdbuf();
    f.close();
}

void info(){
    int line2;
    ifstream outo;
    outo.open("saldo.txt");
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
    string bulan[]={"januari","februari","maret","april","mei","juni","juli","agustus","september","oktober","november","desember",};
    string xxx;
    string x;
    string line;
    string line4;
    string search;
    string buffer;
    string a;
    int xx;
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
    outf.open("pin.txt");
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
                    cout << "       ATM BANGKIT    \n";
                    cout << "=========================\n";
                    cout << "1. Tarik Tunai\n";
                    cout << "2. Riwayat Tarik tunai\n";
                    cout << "3. Setor Tunai\n";
                    cout << "4. Riwayat Setor Tunai\n";
                    cout << "5. Info saldo\n";
                    cout << "6. Bayar Kuliah\n";
                    cout << "7. Lokasi ATM\n";
                    cout << "8. Keluar\n";
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
                            cout << "2. Cari Riwayat Tarik Tunai Berdasarkan bulan\n";
                            cout << "3. Cari Riwayat Tarik Tunai Berdasarkan tahun\n";
                            cout << "Pilih : ";
                            cin >> pilih;
                            switch(pilih){
                            case 1:{
                                riwayat_tarik_tunai();
                                goto coba;
                                break;
                            }
                            case 2:{
                                system("CLS");
                                ifstream file;
                                file.open("riwayat_tarik.txt");
                                cout << "Cari bulan ke - : ";
                                cin >> xx;
                                xxx=bulan[xx-1];
                                if(file.is_open()){
                                    while(getline(file,line)){
                                        if (line.find(xxx, 0) != string::npos){
                                            cout << endl;
                                            cout << "\t\t" << line << endl;
                                            cout << "\t\t======================================\n";
                                            getline(file,buffer);
                                            a.append(buffer);
                                            getline(file,buffer);
                                            a.append("\n"+buffer);
                                            cout << buffer << endl;
                                            cout << "=============\n";
                                        }
                                    }
                                    file.close();
                                    goto coba;
                                    break;
                                }
                            }case 3:{
                                system("CLS");
                                ifstream file;
                                file.open("riwayat_tarik.txt");
                                cout << "Cari berdasarkan tahun - : ";
                                cin >> xxx;
                                if(file.is_open()){
                                    while(getline(file,line)){
                                        if (line.find(xxx, 0) != string::npos){
                                            cout << endl;
                                            cout << "\t\t" << line << endl;
                                            cout << "\t\t======================================\n";
                                            getline(file,buffer);
                                            a.append(buffer);
                                            getline(file,buffer);
                                            a.append("\n"+buffer);
                                            cout << buffer << endl;
                                            cout << "=============\n";
                                        }
                                    }
                                    file.close();
                                    a = "0";
                                    goto coba;
                                    break;
                                }
                            }case 4:{
                                cout << "Tidak bisa buka file" << endl;
                                return 0;
                                break;
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
                            cout << "1. Tampilkan Semua Riwayat Tarik Tunai\n";
                            cout << "2. Cari Riwayat Setor Tunai Berdasarkan bulan\n";
                            cout << "3. Cari Riwayat Setor Tunai Berdasarkan tahun\n";
                            cout << "Pilih : ";
                            cin >> pilih;
                            switch(pilih){
                            case 1:{
                                riwayat_tarik_tunai();
                                goto coba;
                                break;
                            }
                            case 2:{
                                system("CLS");
                                ifstream file;
                                file.open("riwayat_setor.txt");
                                cout << "Cari bulan ke - : ";
                                cin >> xx;
                                xxx=bulan[xx-1];
                                if(file.is_open()){
                                    while(getline(file,line)){
                                        if (line.find(xxx, 0) != string::npos){
                                            cout << endl;
                                            cout << "\t\t" << line << endl;
                                            cout << "\t\t======================================\n";
                                            getline(file,buffer);
                                            a.append(buffer);
                                            getline(file,buffer);
                                            a.append("\n"+buffer);
                                            cout << buffer << endl;
                                            cout << "=============\n";
                                        }
                                    }
                                    file.close();
                                    goto coba;
                                    break;
                                }
                            }case 3:{
                                system("CLS");
                                ifstream file;
                                file.open("riwayat_setor.txt");
                                cout << "Cari berdasarkan tahun - : ";
                                cin >> xxx;
                                if(file.is_open()){
                                    while(getline(file,line)){
                                        if (line.find(xxx, 0) != string::npos){
                                            cout << endl;
                                            cout << "\t\t" << line << endl;
                                            cout << "\t\t======================================\n";
                                            getline(file,buffer);
                                            a.append(buffer);
                                            getline(file,buffer);
                                            a.append("\n"+buffer);
                                            cout << buffer << endl;
                                            cout << "=============\n";
                                        }
                                    }
                                    file.close();
                                    a = "0";
                                    goto coba;
                                    break;
                                }
                            }case 4:{
                                cout << "Tidak bisa buka file" << endl;
                                return 0;
                                break;
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
                            outa.open("saldo.txt");
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
                                                bayar.open("saldo.txt");
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
                        case 7:{
                            string arr[]={"Purwokerto","Bumiayu","Banyumas","Cilacap","Kebumen","Tegal"};
                            int n = sizeof(arr)/sizeof(*arr);
                            sorting(arr,n);
                            cetak(arr,n);
                            goto coba;
                            break;
                        }
                        case 8:
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
                while(c!=8);
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



