#ifndef KODEPOS_H_INCLUDED
#define KODEPOS_H_INCLUDED
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define nil NULL
#define nextA(p) (p)->nextA
#define prevA(p) (p)->prevA
#define firstA(p) (p)->firstA
#define info(p) (p)->info
#define next(p) (p)->next
#define first(l) (l).first

using namespace std;

typedef struct elmlist_i *adr_i;
typedef struct elmlist_a *adr_a;

struct info_i
{
    string provinsi;
};

struct elmlist_i
{
    info_i info;
    adr_a firstA;
    adr_i next;
};

struct info_a
{
    string kode_pos;
    string kota;
};

struct elmlist_a
{
    info_a info;
    adr_a nextA;
    adr_a prevA;
};

struct listi
{
    adr_i first;
};

bool isemptyInduk (listi l);
void createlistInduk (listi &l);
adr_i alokasiInduk (info_i x);
void dealokasiInduk (adr_i p);
adr_i findelmInduk (listi l, info_i x);

void insertlastInduk (listi &l, adr_i p);

void deletefirstInduk (listi &l);
void deleteafterInduk (listi &l, adr_i p, adr_i con);
void deletelastInduk (listi &l);

void printinfoInduk (listi l);


bool isemptyAnak (adr_i p);
adr_a alokasiAnak (info_a x);
void dealokasiAnak (adr_a p);
adr_a findelmAnak (listi l, info_a x);

void insertfirstAnak (adr_i q, adr_a p);
void insertafterAnak (adr_a con, adr_a p);
void insertlastAnak (adr_i q, adr_a p);

void deletefirstAnak (adr_i q, adr_a p);
void deleteafterAnak (adr_a p, adr_a con);
void deletelastAnak (adr_i q, adr_a p);

void printinfoAnak (adr_a p);

void menu_utama (listi &l);
void menu_tambah (listi &l);
void menu_delete (listi &l);

#endif // KODEPOS_H_INCLUDED
