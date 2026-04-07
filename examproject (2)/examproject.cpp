#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

enum Ixtisas {
    CERRAHIYYE = 0, PEDIATRIYA, KARDIOLOGIYA, NEVROPOTOLOGIYA, LOR, OFTALMOLOGIYA
};

const char* ixtisasAdlari[] = { "Cerrahiye", "Pediatriya", "Kardiologiya", "Nevropotologiya", "LOR", "Oftalmologiya" };

struct Hekim {
    int id;
    char ad[50];
    char soyad[50];
    Ixtisas ixtisas;
    int tecrube;
    char telefon[20];
    char email[50];
};

char kicikHerf(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

bool sadeAxtaris(const char* menbe, const char* sorgu) {
    if (!sorgu[0]) return true;
    for (int i = 0; menbe[i] != '\0'; i++) {
        int j = 0;
        while (menbe[i + j] != '\0' && sorgu[j] != '\0' && kicikHerf(menbe[i + j]) == kicikHerf(sorgu[j])) {
            j++;
        }
        if (sorgu[j] == '\0') return true;
    }
    return false;
}

void jsonYaddaSaxla(Hekim** hekimler, int say) {
    ofstream fayl("hekimler.json");
    if (!fayl.is_open()) return;
    fayl << "[\n";
    for (int i = 0; i < say; ++i) {
        fayl << "  {\n";
        fayl << "    \"id\": " << hekimler[i]->id << ",\n";
        fayl << "    \"ad\": \"" << hekimler[i]->ad << "\",\n";
        fayl << "    \"soyad\": \"" << hekimler[i]->soyad << "\",\n";
        fayl << "    \"ixtisas\": \"" << ixtisasAdlari[hekimler[i]->ixtisas] << "\",\n";
        fayl << "    \"tecrube\": " << hekimler[i]->tecrube << ",\n";
        fayl << "    \"telefon\": \"" << hekimler[i]->telefon << "\",\n";
        fayl << "    \"email\": \"" << hekimler[i]->email << "\"\n";
        fayl << "  }" << (i == say - 1 ? "" : ",") << "\n";
    }
    fayl << "]";
    fayl.close();
}

Hekim** massivaHekimElaveEt(Hekim** kohneMassiv, int& say, Hekim* yeniHekim) {
    Hekim** yeniMassiv = new Hekim * [say + 1];
    for (int i = 0; i < say; i++) {
        yeniMassiv[i] = kohneMassiv[i];
    }
    yeniMassiv[say] = yeniHekim;
    if (kohneMassiv != nullptr) delete[] kohneMassiv;
    say++;
    return yeniMassiv;
}

void menyunuCapEt(int secilmis) {
    system("cls");
    const char* secimler[] = { "HEKIM ELAVE ET", "MELUMATI YENILE", "FILTRLEME", "ID ILE AXTAR", "AD/SOYAD ILE AXTAR", "EXIT" };
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    cout << "      HEKIM IDAREETME SISTEMI (CRUD)     \n";
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
    for (int i = 0; i < 6; ++i) {
        if (i == secilmis) cout << " ==> [ " << secimler[i] << " ] <==\n";
        else cout << "      " << secimler[i] << endl;
    }
}

int main() {
    int say = 0;
    Hekim** hekimler = nullptr;

    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 1, "Arzu", "Eliyeva", CERRAHIYYE, 15, "0708694089", "arzu.eliyeva@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 7, "Nuray", "Kerimova", CERRAHIYYE, 9, "0557658956", "nuray.kerimova@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 2, "Dilsad", "Eliyeva", PEDIATRIYA, 6, "0773012152", "dilsad.eliyeva@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 8, "Nuray", "Adigozelli", PEDIATRIYA, 12, "0501234567", "nuray.adigozelli@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 3, "Anar", "Isayev", KARDIOLOGIYA, 12, "0503505844", "anar.isayev@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 9, "Royal", "Azadxanli", KARDIOLOGIYA, 4, "0779876543", "royal.azadxanli@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 4, "Nurlan", "Huseynov", NEVROPOTOLOGIYA, 10, "0553632007", "nurlan.huseynov@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 10, "Nermin", "Eliyeva", NEVROPOTOLOGIYA, 13, "0516312662", "nermin.eliyeva@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 5, "Aytac", "Ashurova", LOR, 11, "0504055079", "aytac.ashurova@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 11, "Vaqif", "Quliyev", LOR, 9, "0701234567", "vaqif.quliyev@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 6, "Ulker", "Veliyeva", OFTALMOLOGIYA, 16, "0504055078", "ulker.veliyeva@mail.com" });
    hekimler = massivaHekimElaveEt(hekimler, say, new Hekim{ 12, "Sebine", "Quliyeva", OFTALMOLOGIYA, 8, "0553124567", "sebine.quliyeva@mail.com" });

    jsonYaddaSaxla(hekimler, say);

    int secilmis = 0;
    bool davamEdir = true;
    while (davamEdir) {
        menyunuCapEt(secilmis);
        int daxilEtme = _getch();
        if (daxilEtme == 224) {
            daxilEtme = _getch();
            switch (daxilEtme) {
            case 72: secilmis = (secilmis - 1 + 6) % 6; break;
            case 80: secilmis = (secilmis + 1) % 6; break;
            }
        }
        else if (daxilEtme == 13) {
            system("cls");
            switch (secilmis) {
            case 0: {
                Hekim* h = new Hekim;
                cout << "ID daxil edin: "; cin >> h->id;
                cout << "Ad: "; cin >> h->ad;
                cout << "Soyad: "; cin >> h->soyad;
                cout << "Ixtisas (0-Cerrahiye, 1-Pediatriya, 2-Kardiologiya, 3-Nevropotologiya, 4-LOR, 5-Oftalmoogiya): ";
                int ix; cin >> ix; h->ixtisas = (Ixtisas)ix;
                cout << "Tecrube (il): "; cin >> h->tecrube;
                cout << "Telefon: "; cin >> h->telefon;
                cout << "Email: "; cin >> h->email;
                hekimler = massivaHekimElaveEt(hekimler, say, h);
                jsonYaddaSaxla(hekimler, say);
                cout << "\nHekim ugurla elave edildi!\n";
                break;
            }
            case 1: {
                int id; cout << "Yenilemek ucun ID daxil edin: "; cin >> id;
                bool tapildi = false;
                for (int i = 0; i < say; i++) {
                    if (hekimler[i]->id == id) {
                        tapildi = true;
                        cout << "\nHekim tapildi: " << hekimler[i]->ad << " " << hekimler[i]->soyad << endl;
                        cout << "Neyi yenilemek isteyirsiniz?\n";
                        cout << "1. Ad\n2. Soyad\n3. Telefon\n4. Tecrube\nSecim edin: ";
                        int yenileSecim; cin >> yenileSecim;
                        switch (yenileSecim) {
                        case 1: cout << "Yeni ad: "; cin >> hekimler[i]->ad; break;
                        case 2: cout << "Yeni soyad: "; cin >> hekimler[i]->soyad; break;
                        case 3: cout << "Yeni telefon: "; cin >> hekimler[i]->telefon; break;
                        case 4: cout << "Yeni tecrube: "; cin >> hekimler[i]->tecrube; break;
                        }
                        jsonYaddaSaxla(hekimler, say);
                        cout << "Melumat yenilendi!\n";
                        break;
                    }
                }
                if (!tapildi) cout << "Hekim tapilmadi!\n";
                break;
            }
            case 2: {
                cout << "-*- FILTRLEME SECIMLERI -*-\n";
                cout << "1. Ixtisasa gore\n2. Tecrubeye gore\nSecim edin: ";
                int filtrSecim; cin >> filtrSecim;

                if (filtrSecim == 1) {
                    cout << "\n-*- IXTISASLAR -*-\n";
                    for (int i = 0; i < 6; i++) cout << i << ". " << ixtisasAdlari[i] << endl;
                    int ix; cout << "\nIxtisas nomresini secin (0-5): "; cin >> ix;
                    if (ix >= 0 && ix <= 5) {
                        cout << "\n-*- " << ixtisasAdlari[ix] << " uzre hekimler -*-\n";
                        bool t = false;
                        for (int i = 0; i < say; i++) {
                            if (hekimler[i]->ixtisas == ix) {
                                cout << "ID: " << hekimler[i]->id << " | " << hekimler[i]->ad << " " << hekimler[i]->soyad << endl;
                                t = true;
                            }
                        }
                        if (!t) cout << "Bu ixtisas uzre hekim tapilmadi.\n";
                    }
                }
                else if (filtrSecim == 2) {
                    int limit; cout << "Tecrube ilini daxil edin: "; cin >> limit;
                    cout << "1. >= " << limit << " il olanlar\n2. <= " << limit << " il olanlar\nSecim: ";
                    int op; cin >> op;
                    bool t = false;
                    for (int i = 0; i < say; i++) {
                        if ((op == 1 && hekimler[i]->tecrube >= limit) || (op == 2 && hekimler[i]->tecrube <= limit)) {
                            cout << "ID: " << hekimler[i]->id << " | " << hekimler[i]->ad << " " << hekimler[i]->soyad << " [" << hekimler[i]->tecrube << " il]\n";
                            t = true;
                        }
                    }
                    if (!t) cout << "Uygun hekim tapilmadi.\n";
                }
                break;
            }
            case 3: {
                int id; cout << "Axtarilan ID-ni daxil edin: "; cin >> id;
                bool tap = false;
                for (int i = 0; i < say; i++) {
                    if (hekimler[i]->id == id) {
                        cout << "\nAd/Soyad: " << hekimler[i]->ad << " " << hekimler[i]->soyad;
                        cout << "\nIxtisas: " << ixtisasAdlari[hekimler[i]->ixtisas];
                        cout << "\nTecrube: " << hekimler[i]->tecrube << " il";
                        cout << "\nTelefon: " << hekimler[i]->telefon << "\nEmail: " << hekimler[i]->email << endl;
                        tap = true;
                    }
                }
                if (!tap) cout << "Bu ID ile hekim tapilmadi.\n";
                break;
            }
            case 4: {
                cout << "-*- MOVCUD HEKIMLERIN SIYAHISI -*-\n";
                for (int i = 0; i < say; i++) cout << hekimler[i]->ad << " " << hekimler[i]->soyad << " [ID: " << hekimler[i]->id << "]\n";
                char sorgu[50]; cout << "\nAxtarilan ad ve ya soyad: "; cin >> sorgu;
                bool tapildi = false;
                for (int i = 0; i < say; i++) {
                    if (sadeAxtaris(hekimler[i]->ad, sorgu) || sadeAxtaris(hekimler[i]->soyad, sorgu)) {
                        cout << "Tapildi: " << hekimler[i]->ad << " " << hekimler[i]->soyad << " [ID: " << hekimler[i]->id << "]\n";
                        tapildi = true;
                    }
                }
                if (!tapildi) cout << "Melumat tapilmadi!\n";
                break;
            }
            case 5: davamEdir = false; break;
            }
            if (davamEdir) system("pause");
        }
    }
    for (int i = 0; i < say; i++) delete hekimler[i];
    delete[] hekimler;
    return 0;
}