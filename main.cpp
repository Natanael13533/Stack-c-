#include<iostream>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

using namespace std;

#define max 5
string data[max];
int top = 1;

struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

bool isEmpty() {
    if(top > 1) {
        return false;
    }
    else {
        return true;
    }
}

bool isFull() {
    if(top <= max) {
        return false;
    }
    else {
        return true;
    }
}

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout << " ";
        }
    }
}

void push(int x)
{
    if(!isFull()) 
    {
        gotoxy(20,15);cout << "Inputkan Jenis Barang    :";
        cin >> kirim[x].jenis_brg;
        gotoxy(20,16);cout << "Inputkan Berat           :";
        cin >> kirim[x].berat;
        gotoxy(20,17);cout << "Inputkan Kota Tujuan     :";
        cin >> kirim[x].kota;
        top++;
    }
    else
    {
        gotoxy(40,10);cout << "Sorry Stack is Full!!!" << endl;
    }
    gotoxy(40,20);cout << "Press Any Key...";
    getch();
}

void tampildata(int x)
{
    gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
    for(int a=1; a<x; a++)
    {
        gotoxy(40,12+a);
        cout << a << ". ";
        cout << kirim[a].jenis_brg << " | ";
        cout << kirim[a].berat << " Kg" << " | ";
        cout << kirim[a].kota << endl;
    }
    gotoxy(40,21);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void pop(int x)
{
    if(!isEmpty()) 
    {
        gotoxy(40,12);cout << "Data Terakhir yang anda Hapus Adalah :" << endl;
        gotoxy(40,13);cout << kirim[x].jenis_brg << " ";
        cout << kirim[x].berat << " Kg ";
        cout << kirim[x].kota << endl << endl;
        top--;
    }
    else 
    {
        gotoxy(40,10);cout << "Sorry, Stack is Empty!!!" << endl;
    }
    gotoxy(40,15);cout<<"Press Any Key...";
    getch();
}

int main()
{
    int pilih;
    do
    {
        // system("cls");
        bersihlayar();
        gotoxy(1,1);cout << "MENU UTAMA";
        gotoxy(1,2);cout << "1. Push data";
        gotoxy(1,3);cout << "2. Pop data Terakhir" << endl;
        gotoxy(1,4);cout << "3. Tampil Data" << endl;
        gotoxy(1,5);cout << "4. Keluar" << endl;

        gotoxy(1,7);cout << "Pilihan Anda [1-4] : ";
        cin >> pilih;

        if(pilih == 1)
        { /*Menambah data baru diletakan di DATAKE*/
            push(top);
        }
        else if(pilih == 2)
        { /*Menghapus Data Terakhir (DATAKE-1*/
            pop(top-1);
        }
        else if(pilih == 3)  //Menampilkan Data mulai
        {                //data ke-1 hingga DATAKE
            tampildata(top);
        }

    }
    while(pilih!=4);
    return 0;
}
