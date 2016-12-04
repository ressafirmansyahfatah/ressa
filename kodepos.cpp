#include "kodepos.h"

bool isemptyInduk (listi l){
    if (first(l)==NULL)
    {return true;}
    else
    {return false;}
}

void createlistInduk (listi &l){
    first(l) = NULL;
}

adr_i alokasiInduk (info_i x){
    adr_i p = new elmlist_i;
    info(p)= x;
    next(p)= NULL;
    firstA(p)= NULL;
    return p;
}

void dealokasiInduk (adr_i p){
    delete(p);
}

adr_i findelmInduk (listi l, info_i x){
    adr_i q = first(l);
    while (q!=NULL){
        if (info(q).provinsi==x.provinsi)
        {return q;}
        q=next(q);
    }
}

void insertlastInduk (listi &l, adr_i p){
    adr_i q = first(l);
    while (next(q)!=NULL){
        q=next(q);
    }
    next(q)=p;
}

void deletefirstInduk (listi &l){
    adr_i p = first(l);
    if (first(l)==NULL){
        cout<<"List Kosong"<<endl;}
    else if (next(p)==NULL){
        first(l)=NULL;
    }
    else{
        first(l)=next(p);
        next(p)=NULL;
    }
    dealokasiInduk(p);
}

void deleteafterInduk (listi &l, adr_i p, adr_i con){
    p=next(con);
    next(con)=next(p);
    next(p)=NULL;
}

void deletelastInduk (listi &l){
    adr_i p = first(l);
    adr_i q;
    while (next(p)!=NULL){
        q=p;
        p=next(p);
    }
    next(q)=NULL;
    dealokasiInduk(p);
}

void printinfoInduk (listi l){
    adr_i p=first(l);
    if (first(l)==NULL){
        cout<<"Data tidak ada"<<endl;
    }
    else{
        while (p!=NULL){
            cout<<endl;
            cout<<"Provinsi      : " << info(p).provinsi << endl;
            adr_a q = firstA(p);
            cout<<endl;
            if (q==NULL){
                cout<<"Tidak ada kota" << endl;
            }
            else{
                if (nextA(q)==firstA(p)){
                    printinfoAnak(q);
                }
                else{
                    do{
                        printinfoAnak(q);
                        q=nextA(q);
                        cout<<endl;
                    }
                    while (q != firstA(p));
                }
            }
            cout << endl;
            p=next(p);
        }
    }
}

bool isemptyAnak (adr_i p){
    if ((p)->firstA==NULL)
    {return true;}
    else
    {return false;}
}

adr_a alokasiAnak (info_a x){
    adr_a p = new elmlist_a;
    info(p)= x;
    nextA(p)=NULL;
    prevA(p)=NULL;
}

void dealokasiAnak (adr_a p){
    delete(p);
}

adr_a findelmAnak (listi l, info_a x){
    adr_i q=first(l);
    while (q!=NULL){
        adr_a p=firstA(q);
        if (p!=NULL){
            if (nextA(p)!=firstA(q)){
                do{
                    if (info(p).kode_pos==x.kode_pos){
                        return p;
                    }
                    p=nextA(p);
                }
                while ((p) != firstA(q));
            }
            else{
                if (info(p).kode_pos==x.kode_pos){
                    return p;
                }
            }
        }
        q=next(q);
    }
    return NULL;
}

void insertfirstAnak (adr_i q, adr_a p){
    if (firstA(q)==NULL){
        firstA(q)=p;
        nextA(p)=p;
        prevA(p)=p;
    }
    else if (nextA(firstA(q))!=firstA(q)){
        adr_a i = firstA(q);
        while (nextA(i)!=firstA(q)){
            i = nextA(i);
        }
        nextA(p)=firstA(q);
        prevA(firstA(q))=p;
        nextA(i) = p;
        prevA(p) = i;
        firstA(q) = p;
    }
    else{
        nextA(p)=firstA(q);
        prevA(firstA(q))= p;
        nextA(firstA(q))= p;
        prevA(p)=firstA(q);
        firstA(q)=p;
    }
}

void insertafterAnak (adr_a con, adr_a p){
    nextA(p) = nextA(con);
    prevA(p) = con;
    nextA(con) = p;
    prevA(nextA(p)) = p;
}

void insertlastAnak (adr_i q, adr_a p){
    adr_a i=firstA(q);
    while (nextA(i)!=firstA(q)){
        i=nextA(i);
    }
    nextA(i) = p;
    nextA(p) = firstA(q);
    prevA(p) = i;
    prevA(firstA(q)) = p;
}

void deletefirstAnak (adr_i q, adr_a p){
    adr_a i=firstA(q);
    while (nextA(i)!=firstA(q)){
        i = nextA(i);
    }
    p=firstA(q);
    if (firstA(q)==NULL){
        cout<<"Data tidak ada"<<endl;
    }
    else if (nextA(p)==firstA(q)){
        firstA(q)=NULL;
    }
    else{
        firstA(q)=nextA(p);
        prevA(firstA(q))=i;
        nextA(i)=firstA(q);
        nextA(p)=NULL;
        prevA(p)=NULL;
    }
    dealokasiAnak(p);
}

void deleteafterAnak (adr_a p, adr_a con){
    nextA(con)=nextA(p);
    prevA(nextA(p))=con;
    nextA(p)=NULL;
    prevA(p)=NULL;
    dealokasiAnak(p);
}

void deletelastAnak (adr_i q, adr_a p){
    p=firstA(q);
    while (nextA(p)!=firstA(q)){
        p=nextA(p);
    }
    adr_a i=prevA(p);
    nextA(i)=firstA(q);
    prevA(firstA(q))=i;
    nextA(p)=NULL;
    dealokasiAnak(p);
}

void printinfoAnak (adr_a p){
    cout<< "Kota          : "<<info(p).kota<<endl;
    cout<< "Kode Pos      : "<<info(p).kode_pos<<endl;
}

void tambahdata (info_i &x){
    cout<<"provinsi no spasi, contoh (jatim, jabar, dll)"<<endl;
    cout<<"Masukkan provinsi  : ";
    cin>>x.provinsi;
}

void tambahkota (info_a &y){
    cout << "Masukkan kota         : ";
    cin >> y.kota;
    cout << "Masukkan kode pos     : ";
    cin >> y.kode_pos;
    //cin.ignore();
    //getline(cin, y.kode_pos);
}

void put_array (adr_i p, adr_a c){
    if (firstA(p)==NULL){
        insertfirstAnak(p,c);
    }
    else{
        adr_a tmp=firstA(p);
        if (info(tmp).kode_pos<info(c).kode_pos){
            if (nextA(tmp)!=firstA(p)){
                insertafterAnak(tmp,c);
            }
            else{
                insertlastAnak(p,c);
            }
        }
        else if (tmp==firstA(p)){
            insertfirstAnak(p,c);
        }
        else{
            tmp=prevA(tmp);
            insertafterAnak(tmp,c);
        }
    }
}

void menu_utama (listi &l){
    info_i x;
    info_a y;
    char n;
    int pilih;
    system("cls");
    cout<<" ------- Program kode pos ------- "<<endl;
    cout<<endl;
    cout<<" - 1. Input data "<<endl;
    cout<<" - 2. Hapus data "<<endl;
    cout<<" - 3. Tampilkan "<<endl;
    cout<<" - 0. Keluar program"<<endl;
    cout<<endl;
    cout<<" - Pilih menu : "; cin>>pilih;
    cout<<endl;
    switch (pilih){
    case 1 :{
        menu_tambah(l);
        break;
        }
    case 2 :{
        menu_delete(l);
        break;
        }
    case 3 :{
        printinfoInduk(l);
        getch();
        menu_utama(l);
        cout<<endl;
        break;
        }
    case 0 :{
        break;
        }
    }
}

void menu_tambah (listi &l){
    info_i x;
    info_a y;
    adr_i p;
    int pilih;
    system("cls");
    cout<<" ------- Menu Input ------- "<<endl;
    cout<<endl;
    cout<<" - 1. Input provinsi "<<endl;
    cout<<" - 2. Input kota "<<endl;
    cout<<" - 0. Back"<<endl;
    cout<<endl;
    cout<<" - Pilih menu : "; cin>>pilih;
    cout<<endl;
    switch (pilih){
    case 1 :{
        tambahdata(x);
        p=alokasiInduk(x);
        adr_i chk=findelmInduk(l,x);
        if (chk==NULL){
            if (isemptyInduk(l)){
                    first(l)=p;
            }
            else{
                insertlastInduk(l,p);
            }
            cout<<"Berhasil";
        }
        else{
            cout<<endl;
            cout<<"Data sudah ada"<<endl;
        }
        getch();
        menu_tambah(l);
        cout<<endl;
        break;
        }
    case 2 : {
        cout<<"Masukkan provinsi : ";
        cin>>x.provinsi;
        adr_i q=findelmInduk(l,x);
        if (q!=NULL){
            tambahkota(y);
            adr_a p=alokasiAnak(y);
            adr_a chk=findelmAnak(l,y);
            if (chk==NULL){
                put_array(q,p);
                cout<<"Berhasil";
            }
            else{
                cout<<endl;
                cout<<"Data tidak ada";
            }
        }
        else{
            cout<<"Data tidak ditemukan";
        }
        getch();
        menu_tambah(l);
        cout<<endl;
        break;
    }
    case 0 :{
        menu_utama(l);
        cout<<endl;
        break;
        }
    }
}

void menu_delete (listi &l){
    info_i x;
    info_a y;
    int pilih;
    system("cls");
    cout<<" ------- Menu Delete ------- "<<endl;
    cout<<endl;
    cout<<" - 1. Delete provinsi "<<endl;
    cout<<" - 2. Delete kota "<<endl;
    cout<<" - 0. Back"<<endl;
    cout<<endl;
    cout<<" - Pilih menu : "; cin>>pilih;
    cout<<endl;
    switch (pilih){
    case 1 :{
        cout << "Masukkan provinsi :";
        cin >> x.provinsi;
        adr_i q=findelmInduk(l,x);
        if (q!=NULL){
            if (first(l)==q){
                deletefirstInduk(l);
                cout<<"Data Terhapus";
            }
            else if (next(q)==NULL){
                deletelastInduk(l);
                cout<<"Data Terhapus";
            }
            else{
                adr_i i=first(l);
                while (next(i)!=q){
                    i=next(i);
                }
                deleteafterInduk(l,q,i);
                cout<<"Data Terhapus";
            }
        }
        else{
            cout<<"Data tidak ada"<<endl;
            getch();
        }
        getch();
        menu_delete(l);
        cout<<endl;
        break;
    }
    case 2 :{
        cout << "Masukkan provinsi : ";
        cin >> x.provinsi;
        adr_i q=findelmInduk(l,x);
        if (q!=NULL){
            cout<<"Masukkan kota : ";
            cin>>y.kota;
            adr_a chk=findelmAnak(l,y);
            if (chk!=NULL){
                if (firstA(q)==chk){
                    deletefirstAnak(q,chk);
                    cout<<"Berhasil";
                }
                else if (nextA(chk)!=firstA(q)){
                    deleteafterAnak(chk,prevA(chk));
                    cout<<"Berhasil";
                }
                else{
                    deletelastAnak(q,chk);
                    cout<<"berhasil";
                }
            }
            else{
                cout<<"Kota tidak ada";
            }
        }
        else{
            cout<<"Provinsi tidak ada";
            getch();
        }
        getch();
        menu_delete(l);
        cout<<endl;
        break;
    }
    case 0 :{
        menu_utama(l);
        cout<<endl;
        break;
        }
    }
}
