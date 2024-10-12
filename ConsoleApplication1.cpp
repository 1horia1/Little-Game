#include <cstdlib> 
#include <iostream> 
#include <time.h> 
#include <string>
#include <vector> 
#include <map>
#include <exception>
#include <limits>
#include <algorithm>
#include <fstream>
#include <set>
#include <list>
using namespace std;
ifstream f("date.in.txt");
ofstream g("cont.txt");
class Pilot
{
private:
    string Nume;
    string Prenume;
    int puncte_campionat;
    int pozitie_campionat;
    int vechime;
    int campionate_castigate;
    int cmblat;      //cel mai bun loc anul trecut
public:
    Pilot()
    {
        Nume = "Necunoscut";
        Prenume = "Necunoscut";
        puncte_campionat = 0;
        pozitie_campionat = 0;
        vechime = 0;
        campionate_castigate = 0;
        cmblat = 0;

    }
    Pilot(string Nume, string Prenume, int puncte_campionat, int pozitie_campionat, int vechime, int campionate_castigate, int cmblat)
    {
        this->Nume = Nume;
        this->Prenume = Prenume;
        this->puncte_campionat = puncte_campionat;
        this->pozitie_campionat = pozitie_campionat;
        this->vechime = vechime;
        this->campionate_castigate = campionate_castigate;
        this->cmblat = cmblat;
    }
    Pilot(const Pilot& nou)
    {
        this->Nume = nou.Nume;
        this->Prenume = nou.Prenume;
        this->puncte_campionat = nou.puncte_campionat;
        this->pozitie_campionat = nou.pozitie_campionat;
        this->vechime = nou.vechime;
        this->campionate_castigate = nou.campionate_castigate;
        this->cmblat = nou.cmblat;
    }
    Pilot& operator=(const Pilot& nou)
    {
        this->Nume = nou.Nume;
        this->Prenume = nou.Prenume;
        this->puncte_campionat = nou.puncte_campionat;
        this->pozitie_campionat = nou.pozitie_campionat;
        this->vechime = nou.vechime;
        this->campionate_castigate = nou.campionate_castigate;
        this->cmblat = nou.cmblat;
        return *this;
    }
    friend istream& operator>>(istream& in, Pilot& nou);
    friend ostream& operator<<(ostream& out, const Pilot& nou);

    string get_Nume_Prenume() const
    {
        return Nume + " " + Prenume;
    }
    void set_campionat(int punct)
    {
        puncte_campionat = puncte_campionat + punct;
    }
    bool operator<(const Pilot& S2) const
    {
        if (this->puncte_campionat < S2.puncte_campionat)
            return true;
        return false;
    }
    bool operator>(const Pilot& S2) const
    {
        if (this->puncte_campionat > S2.puncte_campionat)
            return true;
        return false;
    }
    bool operator==(const Pilot& S2) const
    {
        if (this->Nume == S2.Nume)
            if (this->campionate_castigate == S2.campionate_castigate)
                if (this->cmblat == S2.cmblat)
                    return true;
        return false;
    }

};

class myException : public exception {

public:
    const char* what() const throw()
    {
        return "Exceptie Numele nu este corect";
    }
}ex;
class myException67 : public exception {

public:
    const char* what() const throw()
    {
        return "";
    }
}GRESIT;
class myException1 : public myException {

public:
    const char* what() const throw()
    {
        return "Exceptie Prenumele nu este corect";
    }
}es;
class myException2 : public myException {

public:
    const char* what() const throw()
    {
        return "Exceptie Campionat_puncte  nu este corect";
    }
}et;
class myException3 : public myException {

public:
    const char* what() const throw()
    {
        return "Exceptie loc_campionat  nu este corect";
    }
}ej;
class myException4 : public myException {

public:
    const char* what() const throw()
    {
        return "Exceptie vechime  nu este corect";
    }
}ev;
class myException5 : public myException {

public:
    const char* what() const noexcept override
    {
        return "Exceptie campionat  nu este corect";
    }
}eroare;
class myException6 : public exception {

public:
    const char* what() const noexcept override
    {
        return "Input Invalid";
    }
}error;


istream& operator>>(istream& in, Pilot& nou)
{
    int ok = 1;
    while (ok == 1)
    {
        cout << "Nume:";
        try
        {
            getline(in, nou.Nume);
            if (nou.Nume != "")
            {
                cout << "Inregistrare cu succes" << endl;
                ok = 0;
            }
            else
                throw ex;
        }
        catch (myException& e)
        {
            ok = 1;
            cout << e.what();
        }
    }
    ok = 1;
    while (ok == 1)
    {
        cout << "Prenume:";
        try
        {

            getline(in, nou.Prenume);

            if (nou.Prenume != "")
            {
                cout << "Inregistrare cu succes" << endl;
                ok = 0;
            }
            else
                throw ex;
        }
        catch (myException& e)
        {
            ok = 1;
            cout << e.what();
        }
    }
    ok = 0;
    cout << endl;
    char c;

    while (ok == 0) {
        cout << "Puncte campionat: ";
        in >> nou.puncte_campionat;
        in.get(c);
        if (cin.fail()) {
            ok = 0;
            cin.clear(); // Reseteaza starea fluxului
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
        }
        else {

            if (c == 10)
                ok = 1;
            else
            {
                cout << "Introdu din nou valoarae";
                ok = 0;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            }
        }
        if (ok == 1)
        {
            try
            {

                if (nou.puncte_campionat >= 0)
                {
                    cout << "Inregistrare cu succes" << endl;
                    ok = 1;
                }
                else
                    throw et;
            }
            catch (myException2& e)
            {
                ok = 0;
                cout << e.what();
            }
        }
    }
    ok = 0;
    cout << endl;

    while (ok == 0) {
        cout << "Pozitie Campionat: ";
        in >> nou.pozitie_campionat;
        in.get(c);
        if (cin.fail()) {
            ok = 0;
            cin.clear(); // Reseteaza starea fluxului
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
        }
        else {

            if (c == 10)
                ok = 1;
            else
            {
                cout << "Introdu din nou valoarae";
                ok = 0;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            }
        }
        if (ok == 1)
        {
            try
            {

                if (nou.pozitie_campionat >= 0)
                {
                    cout << "Inregistrare cu succes" << endl;
                    ok = 1;
                }
                else
                    throw ej;
            }
            catch (myException3& e)
            {
                ok = 0;
                cout << e.what();
            }
        }
    }
    ok = 0;
    cout << endl;

    while (ok == 0) {
        cout << "Vechime: ";
        in >> nou.vechime;
        in.get(c);
        if (cin.fail()) {
            ok = 0;
            cin.clear(); // Reseteaza starea fluxului
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
        }
        else {

            if (c == 10)
                ok = 1;
            else
            {
                cout << "Introdu din nou valoarae";
                ok = 0;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            }

        }
        if (ok == 1)
        {
            try
            {

                if (nou.vechime >= 0)
                {
                    cout << "Inregistrare cu succes" << endl;
                    ok = 1;
                }
                else
                    throw ev;
            }
            catch (myException4& e)
            {
                ok = 0;
                cout << e.what();
            }
        }
    }
    ok = 0;
    cout << endl;

    while (ok == 0) {
        cout << "Campionate castigate: ";
        in >> nou.campionate_castigate;
        in.get(c);
        if (cin.fail()) {
            ok = 0;
            cin.clear(); // Reseteaza starea fluxului
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
        }
        else {

            if (c == 10)
                ok = 1;
            else
            {
                cout << "Introdu din nou valoarae";
                ok = 0;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            }
        }
        if (ok == 1)
        {
            try
            {

                if (nou.campionate_castigate >= 0)
                {
                    cout << "Inregistrare cu succes" << endl;
                    ok = 1;
                }
                else
                    throw eroare;
            }
            catch (myException5& e)
            {
                ok = 0;
                cout << e.what();
            }
        }
    }


    ok = 0;
    cout << endl;

    while (ok == 0) {
        cout << "Cel mai bun loc anul trecut: ";
        in >> nou.cmblat;
        in.get(c);
        if (cin.fail()) {
            ok = 0;
            cin.clear(); // Reseteaza starea fluxului
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
        }
        else {

            if (c == 10)
                ok = 1;
            else
            {
                cout << "Introdu din nou valoarae";
                ok = 0;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            }
        }
        if (ok == 1)
        {
            try
            {

                if (nou.cmblat >= 0)
                {
                    cout << "Inregistrare cu succes" << endl;
                    ok = 1;
                }
                else
                    throw eroare;
            }
            catch (myException5& e)
            {
                ok = 0;
                cout << e.what();
            }
        }
    }



    return in;
    //rezolva erorile
}
ostream& operator<<(ostream& out, const Pilot& nou)
{
    out << "Nume:";
    out << nou.Nume << endl;
    out << "Prenume:";
    out << nou.Prenume << endl;
    out << "Puncte campionat:";
    out << nou.puncte_campionat << endl;
    out << "Pozitie campionat:";
    out << nou.pozitie_campionat << endl;
    out << "Vechime:";
    out << nou.vechime << endl;
    out << "Campionate castigate:";
    out << nou.campionate_castigate << endl;
    out << "Cel mai bun loc luat anul trecut:";
    out << nou.cmblat << endl;
    return out;
}

//pentru clasa template ar putea sa fie clasa campionat, care sa contina o clasa T , si  sa tot adaug puncte la campionat, prin asta.sau ceva cu care sa modific , mai mai gandesc
class Masina {
protected:
    string Marca, Model, tip_caroserie, jante, faruri;
public:
    Masina()
    {
        Marca = "Necunoscut";
        Model = "Necunoscut";
        tip_caroserie = "necunoscut";
        jante = "necunoscut";
        faruri = "necunoscute";

    }
    Masina(string Marca, string Model, string tip_caroserie, string jante, string faruri)
    {
        this->Marca = Marca;
        this->Model = Model;
        this->tip_caroserie = tip_caroserie;
        this->jante = jante;
        this->faruri = faruri;
    }
    Masina(const Masina& ob)
    {
        this->Marca = ob.Marca;
        this->Model = ob.Model;
        this->tip_caroserie = ob.tip_caroserie;
        this->jante = ob.jante;
        this->faruri = ob.faruri;
    }
    Masina& operator=(const Masina& ob)
    {
        if (this != &ob)
        {
            this->Marca = ob.Marca;
            this->Model = ob.Model;
            this->tip_caroserie = ob.tip_caroserie;
            this->jante = ob.jante;
            this->faruri = ob.faruri;
        }
        return *this;
    }
    //destructorul se face singur in acest caz
    friend istream& operator>>(istream& in, Masina& m);
    virtual istream& citire(istream& in)
    {
        int ok = 1;
        cout << "Nume marca";
        while (ok == 1)
        {
            getline(in, Marca);
            if (Marca != "")
                ok = 0;
            else
            {
                cout << "Nume invalid";
                ok = 1;
            }
        }
        cout << "Model";
        ok = 1;
        while (ok == 1)
        {
            getline(in, Model);
            if (Model != "")
                ok = 0;
            else
            {
                cout << "Nume invalid";
                ok = 1;
            }
        }
        ok = 1;
        while (ok == 1)
        {
            cout << "Tip caroserie(berlina, coupe):";
            getline(in, tip_caroserie);
            if (tip_caroserie == "berlina" or tip_caroserie == "coupe")
                ok = 0;
            else
                cout << "INPUT INVALID" << endl;
        }
        ok = 1;
        while (ok == 1)
        {
            cout << "Tip jante(aliaj,magneziu):";
            getline(in, jante);
            if (jante == "aliaj" or jante == "magneziu")
                ok = 0;
            else
                cout << "INPUT INVALID" << endl;
        }
        ok = 1;
        while (ok == 1)
        {
            cout << "Tip faruri(led,halogen):";
            getline(in, faruri);
            if (faruri == "led" or faruri == "halogen")
                ok = 0;
            else
                cout << "INPUT INVALID" << endl;
        }
        return in;
    }
    void set_modificare()
    {
        string far, jantel;
        int ok = 1;

        while (ok == 1)
        {
            cout << "Ce tip de far vrei pe masina ta(led, halogen)" << endl;
            getline(cin, far);

            if (far == "led" or far == "halogen")
            {
                this->faruri = far;
                ok = 0;
            }
            else
                cout << "Input invalid" << endl;

        }
        ok = 1;
        while (ok == 1)
        {
            cout << "Ce tip de janta vrei(aliaj, magneziu)" << endl;
            getline(cin, jantel);
            if (jantel == "aliaj" or jantel == "magneziu")
            {
                this->jante = jantel;
                ok = 0;
            }
            else
                cout << "Input invalid";
        }
        cout << "Felicitari,ti ai modificat masina" << endl;
    }
    friend ostream& operator<<(ostream& out, Masina& m);
    virtual ostream& afisare(ostream& out) const
    {
        out << "Nume marca:";
        out << this->Marca << endl;
        out << "Model:";
        out << this->Model << endl;
        out << "Tip caroserie:";
        out << this->tip_caroserie << endl;
        out << "Tip jante:";
        out << this->jante << endl;
        out << "Tip Faruri:";
        out << this->faruri << endl;
        return out;
    }
    virtual float calculare_consum() const = 0;
    virtual ~Masina() {}
};
istream& operator>>(istream& in, Masina& m)
{
    return m.citire(in);
}
ostream& operator<<(ostream& out, Masina& m)
{
    return m.afisare(out);
}
class masina_benzina :public virtual  Masina
{
protected:
    int rezervor_capacitate, range_max, putere;
    string combustibil;
public:
    masina_benzina() :Masina()//constructor fara parametrii
    {
        this->putere = 0;
        this->rezervor_capacitate = 30;
        this->range_max = 0;
        this->combustibil = "necunoscut";
    }
    masina_benzina(int putrere, int rezervor_capacitate, int range_max, string combustibil) :Masina(Marca, Model, tip_caroserie, jante, faruri)//cu paramametrii
    {
        this->putere = putere;
        this->rezervor_capacitate = rezervor_capacitate;
        this->range_max = range_max;
        this->combustibil = combustibil;
    }
    masina_benzina(const masina_benzina& bn) :Masina(bn)//copy constructor
    {
        this->putere = putere;
        this->rezervor_capacitate = bn.rezervor_capacitate;
        this->range_max = bn.range_max;
        this->combustibil = bn.combustibil;
    }
    masina_benzina& operator=(const masina_benzina& mb)
    {
        if (this != &mb)
        {
            this->Masina::operator=(mb);
            this->putere = mb.putere;
            this->rezervor_capacitate = mb.rezervor_capacitate;
            this->range_max = mb.range_max;
            this->combustibil = mb.combustibil;

        }
        return *this;
    }
    friend istream& operator>>(istream& in, masina_benzina& m);
    virtual istream& citire(istream& in)
    {
        this->Masina::citire(in);
        int ok = 1;
        while (ok == 1)
        {
            cout << "Combustibil folosit (benzina,diesel)";
            getline(in, combustibil);
            if (combustibil == "benzina" or combustibil == "diesel")
                ok = 0;
            else
                cout << "Input invalit" << endl;

        }
        ok = 1;
        char c;
        while (ok == 1) {
            cout << "Rezervor  capacitate:";
            in >> this->rezervor_capacitate;
            in.get(c);
            if (cin.fail()) {
                ok = 1;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                cout << "Varianta ta este:";
            }
            else {

                if (c == 10)
                    ok = 0;
                else
                {
                    cout << "Introdu din nou valoarae";
                    ok = 1;
                    cin.clear(); // Reseteaza starea fluxului
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                }
            }
            if (ok == 0)
            {
                try
                {

                    if (rezervor_capacitate > 0)
                    {
                        cout << "Inregistrare cu succes" << endl;
                        ok = 0;
                    }
                    else
                    {
                        cout << "Input gresit" << endl;
                        throw GRESIT;
                    }

                }
                catch (myException67& e)
                {
                    ok = 1;
                    cout << e.what() << endl;
                    cout << "Varianta ta este:";
                }
            }
        }
        ok = 1;
        while (ok == 1) {
            cout << "Maximul de km cu care s-a putut merge cu masina";
            in >> this->range_max;
            in.get(c);
            if (cin.fail()) {
                ok = 1;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                cout << "Varianta ta este:";
            }
            else {

                if (c == 10)
                    ok = 0;
                else
                {
                    cout << "Introdu din nou valoarae";
                    ok = 1;
                    cin.clear(); // Reseteaza starea fluxului
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                }
            }
            if (ok == 0)
            {
                try
                {

                    if (range_max > 0)
                    {
                        cout << "Inregistrare cu succes" << endl;
                        ok = 0;
                    }
                    else
                    {
                        cout << "Input gresit" << endl;
                        throw GRESIT;
                    }

                }
                catch (myException67& e)
                {
                    ok = 1;
                    cout << e.what() << endl;
                    cout << "Varianta ta este:";
                }
            }
        }
        ok = 1;
        while (ok == 1) {
            cout << "Ce putere are  motorul benzina:";
            in >> this->putere;
            in.get(c);
            if (cin.fail()) {
                ok = 1;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                cout << "Varianta ta este:";
            }
            else {

                if (c == 10)
                    ok = 0;
                else
                {
                    cout << "Introdu din nou valoarae";
                    ok = 1;
                    cin.clear(); // Reseteaza starea fluxului
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                }
            }
            if (ok == 0)
            {
                try
                {

                    if (putere > 0)
                    {
                        cout << "Inregistrare cu succes" << endl;
                        ok = 0;
                    }
                    else
                    {
                        cout << "Input gresit" << endl;
                        throw GRESIT;
                    }

                }
                catch (myException67& e)
                {
                    ok = 1;
                    cout << e.what() << endl;
                    cout << "Varianta ta este:";
                }
            }
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, masina_benzina& m);
    virtual ostream& afisare(ostream& out) const
    {
        this->Masina::afisare(out);
        out << "Combustibil folosit";
        out << this->combustibil << endl;
        out << "Rezervor  capacitate:";
        out << this->rezervor_capacitate << endl;
        out << "Maximul de km cu care s-a putut merge cu masina";
        out << this->range_max << endl;
        out << "Puterea masinii pe benzina";
        out << this->putere << endl;
        return out;
    }
    float calculare_consum() const
    {
        return rezervor_capacitate * 100 / range_max;
    }
};

istream& operator>>(istream& in, masina_benzina& m)
{
    return m.citire(in);
}
ostream& operator<<(ostream& out, masina_benzina& m)
{
    return m.afisare(out);
}


class masina_hibrid :public masina_benzina
{
private:
    string tip_hibrid;
    int putere_totala;
public:
    masina_hibrid() : Masina(), masina_benzina() {
        this->tip_hibrid = "necunoscut";
        this->putere_totala = 0;
    }
    masina_hibrid(string tip_hibrid, int putere_totala) :Masina(), masina_benzina()
    {
        this->tip_hibrid = tip_hibrid;
        this->putere_totala = putere_totala;

    }
    masina_hibrid(const masina_hibrid& bn) :Masina(bn), masina_benzina(bn)
    {
        this->tip_hibrid = bn.tip_hibrid;
        this->putere_totala = bn.putere_totala;
    }
    masina_hibrid& operator=(const masina_hibrid& m)
    {

        if (this != &m)
        {
            // Atribuirea membrilor din clasa de bază (Masina)

            this->masina_benzina::operator=(m);
            this->tip_hibrid = m.tip_hibrid;
            this->putere_totala = m.putere_totala;

        }

        return *this;
    }
    friend istream& operator>>(istream& in, masina_hibrid& m);
    virtual istream& citire(istream& in)
    {
        //revenire
        int ok = 1;
        this->masina_benzina::citire(in);
        while (ok == 1)
        {
            cout << "Ce tip de hibrid este (mild-hybrid , full-hybrid)";

            in >> this->tip_hibrid;
            if (tip_hibrid == "mild-hybrid" or tip_hibrid == "full-hybrid")
                ok = 0;
            else
                cout << "Input-invalid" << endl;
        }
        ok = 1;
        char c;
        while (ok == 1) {
            cout << "Ce putere are  motorul:";
            in >> this->putere_totala;
            in.get(c);
            if (cin.fail()) {
                ok = 1;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                cout << "Varianta ta este:";
            }
            else {

                if (c == 10)
                    ok = 0;
                else
                {
                    cout << "Introdu din nou valoarae";
                    ok = 1;
                    cin.clear(); // Reseteaza starea fluxului
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                }
            }
            if (ok == 0)
            {
                try
                {

                    if (putere_totala > 0)
                    {
                        cout << "Inregistrare cu succes" << endl;
                        ok = 0;
                    }
                    else
                    {
                        cout << "Input gresit" << endl;
                        throw GRESIT;
                    }

                }
                catch (myException67& e)
                {
                    ok = 1;
                    cout << e.what() << endl;
                    cout << "Varianta ta este:";
                }
            }
        }

        return in;
    }
    friend ostream& operator<<(ostream& out, masina_hibrid& m);
    virtual ostream& afisare(ostream& out) const
    {
        this->masina_benzina::afisare(out);
        out << "Tip hibrid:";
        out << tip_hibrid << endl;
        out << "Putere motor electrica:" << putere_totala << endl;


        return out;
    }

};
istream& operator>>(istream& in, masina_hibrid& m)
{
    return m.citire(in);
}
ostream& operator<<(ostream& out, masina_hibrid& m)
{
    return m.afisare(out);
}

template<class T>
void afisarea_p(vector<T> clasament, T MEU)
{
    int numarare = 0;
    for (int i = 0; i < clasament.size(); i++)
        cout << clasament[i] << endl;
}
template<>
void afisarea_p(vector<Pilot> clasament, Pilot MEU)
{
    int numarare = 0;
    for (int i = 0; i < clasament.size(); i++)
        cout << clasament[i].get_Nume_Prenume() << endl;
}
template<class T>
int poz(vector<T> clasament, T MEU)
{
    int numarare = 0;
    for (int i = 0; i < clasament.size(); i++)
        if (clasament[i] == MEU)
            break;
        else
            numarare++;
    return numarare + 1;
    //verificare numarare, acu compileaza ,in mod normal ar trb sa ruleze cum trebuie
}
class Circuit
{
private:
    string Nume_circuit;
    Pilot A[20];
    int kilometri;
    string Tara;
public:
    Circuit()
    {
        Nume_circuit = "Necunoscut";
        kilometri = 0;
        Tara = "Necunoscut";
    }
    Circuit(string Nume_circuit, Pilot A[20], int kilometri, string Tara)
    {
        this->Nume_circuit = Nume_circuit;
        for (int i = 0; i < 20; i++)
            this->A[i] = A[i];
        this->kilometri = kilometri;
        this->Tara = Tara;
    }
    Circuit(Pilot A[20])
    {
        this->Nume_circuit = "necunoscut";
        for (int i = 0; i < 20; i++)
            this->A[i] = A[i];
        this->kilometri = 0;
        this->Tara = "necunoscut";
    }
    Circuit(const Circuit& nou)
    {
        this->Nume_circuit = nou.Nume_circuit;
        for (int i = 0; i < 20; i++)
            this->A[i] = nou.A[i];
        this->kilometri = nou.kilometri;
        this->Tara = nou.Tara;
    }
    Circuit& operator=(const Circuit& nou)
    {
        this->Nume_circuit = nou.Nume_circuit;
        for (int i = 0; i < 20; i++)
            this->A[i] = nou.A[i];
        this->kilometri = nou.kilometri;
        this->Tara = nou.Tara;
        return *this;
    }
    void set_piloti(vector<Pilot> dsa)
    {
        for (int i = 0; i < dsa.size(); i++)
            A[i] = dsa[i];

    }
    friend istream& operator>>(istream& in, Circuit& nou);
    friend ostream& operator<<(ostream& out, const Circuit& nou);

};
istream& operator>>(istream& in, Circuit& nou)
{
    int ok = 1;
    while (ok == 1)
    {
        cout << "Nume Circuit:";
        try
        {
            getline(in, nou.Nume_circuit);
            if (nou.Nume_circuit != "")
            {
                ok = 0;
                for (int i = 0; i < nou.Nume_circuit.length(); i++)
                    if (!(nou.Nume_circuit[i] >= 'a' and nou.Nume_circuit[i] <= 'z') and !(nou.Nume_circuit[i] >= 'A' and nou.Nume_circuit[i] <= 'Z') or nou.Nume_circuit[i] == ' ')
                        ok = 1;
                if (ok == 0)
                {
                    cout << "Inregistrare cu succes" << endl;
                    ok = 0;
                }
                else
                    throw ex;

            }
            else
                throw ex;
        }
        catch (myException& e)
        {
            ok = 1;
            cout << e.what();
        }


    }
    //for (int i = 0; i < 5; i++)
       // in >> nou.A[i];
    ok = 0;
    cout << endl;
    char c;
    while (ok == 0) {
        cout << "Kilometrii circuit : ";
        in >> nou.kilometri;
        in.get(c);
        if (cin.fail()) {
            ok = 0;
            cin.clear(); // Reseteaza starea fluxului
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
        }
        else {

            if (c == 10)
                ok = 1;
            else
            {
                cout << "Introdu din nou valoarae";
                ok = 0;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
            }
        }
        if (ok == 1)
        {
            try
            {

                if (nou.kilometri >= 0)
                {
                    cout << "Inregistrare cu succes" << endl;
                    ok = 1;
                }
                else
                    throw error;
            }
            catch (myException6& e)
            {
                ok = 0;
                cout << e.what();
            }
        }
    }
    ok = 1;
    while (ok == 1)
    {
        cout << "Nume Tara:";
        try
        {
            in >> nou.Tara;
            if (nou.Tara != "-")
            {
                ok = 0;
                for (int i = 0; i < nou.Tara.length(); i++)
                    if (!(nou.Tara[i] >= 'a' and nou.Tara[i] <= 'z') and !(nou.Tara[i] >= 'A' and nou.Tara[i] <= 'Z'))
                        ok = 1;
                if (ok == 0)
                {
                    cout << "Inregistrare cu succes" << endl;
                    ok = 0;
                }
                else
                    throw error;

            }
            else
                throw error;
        }
        catch (myException6& e)
        {
            ok = 1;
            cout << e.what();
        }


    }
}
ostream& operator<<(ostream& out, const Circuit& nou)
{
    out << "Circuitul  este:" << nou.Nume_circuit << endl;
    out << "Pilotii care participa la concururs sunt" << endl;
    for (int i = 0; i < 5; i++)
        out << nou.A[i] << endl;
    out << "Campionatul are numarul de kilometrii:" << nou.kilometri << endl;
    out << "Tara in care se desfasuara este" << nou.Tara << endl;
    return out;
}
template<class T>
class CEVA {
private:
    vector<T> altceva; // Atribute de tip T
    int size;

public:
    CEVA()
    {

        size = 0;
    }
    void pushBack(T t) {
        size++;
        altceva.push_back(t);

    }
    void stergere()
    {
        size = 0;
        altceva.clear();
    }
    void sortare()
    {
        int ok = 1;
        while (ok == 1)
        {
            ok = 0;
            for (int i = 0; i < size - 1; i++)
                if (altceva[i] < altceva[i + 1])
                {
                    swap(altceva[i], altceva[i + 1]);
                    ok = 1;
                }
        }


    }
    void afisare()
    {
        for (int i = 0; i < size; i++)
            cout << altceva[i] << endl;

    }
    void primii3()
    {
        sortare();
        for (int i = 0; i < size; i++)
            if (i <= 2)
                cout << altceva[i] << " ";
    }


    // Metodă pentru afișarea elementelor

};
class Singleton
{

private:

    static Singleton* instance;
    string data, proiect;
    Singleton()
    {
        data = "29/04/2022";
        proiect = "Made by Diaconu Horia";
    }
    Singleton(const Singleton& t) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:

    static Singleton* getInstance()
    {
        if (Singleton::instance != NULL)
        {
            return Singleton::instance;
        }
        else
        {
            instance = new Singleton();
            return instance;
        }
    }

    string getData() { return this->data; }
    void setData(string data) { this->data = data; }
    string get() { return this->proiect; }
    void main()
    {
        Pilot A, EU;
        string echipa;
        map<Pilot, string> Piloti_echipa;
        vector<Pilot> clasament;
        set<Pilot> Piloti_introdusi;
        list<Circuit> Circuite_introduse;
        CEVA<Pilot> elemente;

        cout << "LOADING";
        for (int j = 0; j < 4; j++)
        {
            f >> A;
            f.get();
            cout << "Echipa";
            getline(f, echipa);
            Piloti_introdusi.insert(A);
            Piloti_echipa[A] = echipa;
            clasament.push_back(A);

        }
        cout << "Jocul a fost incarcat,putem sa incepem" << endl;
        cout << "=========================================" << endl;
        cout << "Creaza-ti un cont:" << endl;
        int anotok = 1;
        while (anotok == 1)
        {

            cin >> EU;

            set<Pilot>::iterator Ire = Piloti_introdusi.find(EU);
            if (Ire == Piloti_introdusi.end())
                anotok = 0;
            else
                cout << "Un pilot deja este aici";
        }
        clasament.push_back(EU);
        cout << "Echipa din care vei face parte" << endl;
        cin >> echipa;
        cout << "Bine ai venit in lumea curselor, locul unde orice este posibil " << EU.get_Nume_Prenume() << endl;
        cout << "Mai ai putin pana a intra aici , te rog configureaza-ti masina" << endl;
        cout << "Pentru ce tip de masina iti doresti apasa tasta din dreapta" << endl;
        cout << "Pentru masina pe benzina apasa tasta 1" << endl;
        cout << "Pentru masina hibrida apasa tasta 2" << endl;
        cout << "Varianta ta este:";
        int varianta = 0, ok = 0;
        char c;
        while (ok == 0) {

            cin >> varianta;
            cin.get(c);
            if (cin.fail()) {
                ok = 0;
                cin.clear(); // Reseteaza starea fluxului
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                cout << "Varianta ta este:";
            }
            else {

                if (c == 10)
                    ok = 1;
                else
                {
                    cout << "Introdu din nou valoarae";
                    ok = 0;
                    cin.clear(); // Reseteaza starea fluxului
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                }
            }
            if (ok == 1)
            {
                try
                {

                    if (varianta == 1 or varianta == 2 or varianta == 3)
                    {
                        cout << "Inregistrare cu succes" << endl;
                        ok = 1;
                    }
                    else
                    {
                        throw GRESIT;
                        ok = 0;
                    }
                }
                catch (myException67& e)
                {
                    ok = 0;
                    cout << e.what() << endl;
                    cout << "Varianta ta este:";
                }
            }
        }
        //variantele pentru configurarea masinii 
        Masina* masina_mea = nullptr;

        int masina_h = 0, masina_b = 0;
        if (varianta == 1)
        {
            cout << "Ai ales masina pe benzina" << endl;
            masina_mea = new masina_benzina();
            cin >> dynamic_cast<masina_benzina&>(*masina_mea);
            cout << "Acestea sunt datele masinii tale" << endl;
            cout << *masina_mea;
            cout << endl;
            masina_b = 1;
        }
        if (varianta == 2)
        {
            cout << "Ai ales masina hibrid" << endl;
            masina_mea = new masina_hibrid();
            cin >> dynamic_cast<masina_hibrid&>(*masina_mea);
            cout << "Acestea sunt datele masinii tale" << endl;
            cout << *masina_mea;
            cout << endl;
            masina_h = 1;

        }

        cout << "Felicitari , acum bucara-te de joc" << endl;
        Pilot P[20];
        for (int i = 0; i < clasament.size(); i++)
            P[i] = clasament[i];
        Circuit circuitul(P);
        int ok1 = 1;
        int start = 0;
        int lt = 1;
        while (ok1 == 1 and lt == 1)
        {

            cout << "Main Menu" << endl;
            cout << "Apasa tasta in care vrei sa faci o cursa" << endl;
            cout << "1.Fa o cursa" << endl;
            cout << "2.Modifica masina parte vizuala" << endl;
            cout << "3.Da-mi rezultatul campionatului" << endl;
            cout << "4.Da share contului tau ca sa vada si prietenii" << endl;
            cout << "5.Circuitele in care s-a concurat pana acum" << endl;
            cout << "6.Inchide jocul" << endl;
            cout << "Varianta ta este:" << endl;
            ok = 1;
            while (ok == 1) {

                cin >> varianta;
                cin.get(c);
                if (cin.fail()) {
                    ok = 1;
                    cin.clear(); // Reseteaza starea fluxului
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                    cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                    cout << "Varianta ta este:";
                }
                else {

                    if (c == 10)
                        ok = 0;
                    else
                    {
                        cout << "Introdu din nou valoarae";
                        ok = 1;
                        cin.clear(); // Reseteaza starea fluxului
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                    }
                }
                if (ok == 0)
                {
                    try
                    {

                        if (varianta >= 1 and varianta <= 6)
                        {
                            cout << "Inregistrare cu succes" << endl;
                            ok = 0;
                        }
                        else
                            throw GRESIT;
                    }
                    catch (myException67& e)
                    {
                        ok = 1;
                        cout << e.what() << endl;
                        cout << "Varianta ta este:";
                    }
                }
            }


            switch (varianta)
            {
            case 1:
            {


                srand(time(0));
                int randommy;
                cout << "Zi mai multe date despre circuit" << endl;

                cin >> circuitul;
                Circuite_introduse.push_back(circuitul);
                cout << "Cursa incepe in 3,2,1 staart" << endl;
                int ture = 1;

                //vector ,sa adaug pilotul pe ultimul rand 
                int alegere = 0;
                while (ture <= 6)
                {
                    cout << "Suntem in turul " << ture << endl;
                    randommy = rand() % 10;
                    switch (randommy)
                    {
                    case 0:
                    {
                        if (poz(clasament, EU) >= 3)
                        {
                            cout << "In fata ta se bat 2 pentru locul 1 , ce o sa faci ?" << endl;
                            cout << "Pentru depasire apasa 1,pentru frana apas 2";
                            int ok2 = 1;


                            while (ok2 == 1) {

                                cin >> alegere;
                                cin.get(c);
                                if (cin.fail()) {
                                    ok2 = 1;
                                    cin.clear(); // Reseteaza starea fluxului
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                                    cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                                    cout << "Varianta ta este:";
                                }
                                else {

                                    if (c == 10)
                                        ok2 = 0;
                                    else
                                    {
                                        cout << "Introdu din nou valoarae";
                                        ok2 = 1;
                                        cin.clear(); // Reseteaza starea fluxului
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                                    }
                                }
                                if (ok2 == 0)
                                {
                                    try
                                    {

                                        if (alegere == 1 or alegere == 2)
                                        {
                                            cout << "Inregistrare cu succes" << endl;
                                            ok2 = 0;
                                        }
                                        else
                                            throw eroare;
                                    }
                                    catch (myException5& e)
                                    {
                                        ok = 1;
                                        cout << e.what() << endl;
                                        cout << "Varianta ta este:";
                                    }
                                }
                            }
                            int anotr = rand() % 2;
                            if (alegere == 1 and anotr == 0 and poz(clasament, EU) <= 4)
                            {
                                cout << "Ai esuat,ai iesit cu masina in decor,ai redresat-o dar ai fost depasit de cel din spate" << endl;
                                swap(clasament[poz(clasament, EU) - 1], clasament[poz(clasament, EU)]);
                            }
                            else
                            {
                                if (alegere == 1 and anotr == 1 and poz(clasament, EU) > 1)
                                {
                                    cout << "Cei doi in fata duceau o lupta grea, si in 2 curbe succesive stanga dreapta ai intrat pe interior ai reusit totusi sa urci o pozitie" << endl;
                                    swap(clasament[poz(clasament, EU) - 2], clasament[poz(clasament, EU) - 1]);
                                }
                                else
                                    cout << "Ai ramas pe aceeasi pozitie" << endl;
                            }
                        }
                        else
                            cout << "Nu s-a intamplat nimic" << endl;

                        break;
                    }
                    case 1:
                    {
                        if ((poz(clasament, EU) != 5))
                        {
                            cout << "Din spate vine tare un pilot si ajungeti in paralele la intrarea in curba " << endl;
                            cout << "1.Tii interiorul-------------2.Tii exteriorul";
                            int ok2 = 1;
                            while (ok2 == 1) {

                                cin >> alegere;
                                cin.get(c);
                                if (cin.fail()) {
                                    ok2 = 1;
                                    cin.clear(); // Reseteaza starea fluxului
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                                    cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                                    cout << "Varianta ta este:";
                                }
                                else {

                                    if (c == 10)
                                        ok2 = 0;
                                    else
                                    {
                                        cout << "Introdu din nou valoarae";
                                        ok2 = 1;
                                        cin.clear(); // Reseteaza starea fluxului
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                                    }
                                }
                                if (ok2 == 0)
                                {
                                    try
                                    {

                                        if (alegere == 1 or alegere == 2)
                                        {
                                            cout << "Inregistrare cu succes" << endl;
                                            ok2 = 0;
                                        }
                                        else
                                            throw eroare;
                                    }
                                    catch (myException5& e)
                                    {
                                        ok2 = 1;
                                        cout << e.what() << endl;
                                        cout << "Varianta ta este:";
                                    }
                                }
                            }
                            int adf = rand() % 2;
                            if (alegere == 1 and adf == 1)
                                cout << "Ai reusit sa tii interiorul" << endl;
                            else
                            {
                                cout << "Ai pierdut o pozitie" << endl;
                                swap(clasament[poz(clasament, EU) - 1], clasament[poz(clasament, EU)]);

                            }
                        }
                        break;
                    }
                    case 2:
                    {
                        cout << "Ai avut probleme si ai iesit din cursa" << endl;
                        for (int i = poz(clasament, EU) - 1; i < clasament.size() - 1; i++)
                            swap(clasament[i], clasament[i + 1]);
                        ture = 7;
                        break;
                    }
                    case 3:
                    {
                        if (poz(clasament, EU) >= 2)
                        {
                            cout << "Ai iesti din curba cu viteza mult mai mare decat oponentul tau si ai reusit sa iei pozitia fara efort" << endl;
                            swap(clasament[poz(clasament, EU) - 2], clasament[poz(clasament, EU) - 1]);
                        }
                        else
                            cout << "Nu s-a intamplat nimic in acest lap";

                        break;
                    }
                    case 4:
                    {
                        if (poz(clasament, EU) < 5)
                        {
                            cout << "Ai fost depasit ...";
                            swap(clasament[poz(clasament, EU) - 1], clasament[poz(clasament, EU)]);

                        }
                        else cout << "Nu s a intamplat nimic" << endl;
                        break;
                    }
                    case 5:
                    {
                        if (poz(clasament, EU) >= 3)
                        {
                            cout << "In fata ta se bat 2 pentru locul 1 , ce o sa faci ?" << endl;
                            cout << "Pentru depasire apasa 1,pentru frana apas 2";
                            int ok2 = 1;


                            while (ok2 == 1) {

                                cin >> alegere;
                                cin.get(c);
                                if (cin.fail()) {
                                    ok2 = 1;
                                    cin.clear(); // Reseteaza starea fluxului
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                                    cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                                    cout << "Varianta ta este:";
                                }
                                else {

                                    if (c == 10)
                                        ok2 = 0;
                                    else
                                    {
                                        cout << "Introdu din nou valoarae";
                                        ok2 = 1;
                                        cin.clear(); // Reseteaza starea fluxului
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                                    }
                                }
                                if (ok2 == 0)
                                {
                                    try
                                    {

                                        if (alegere == 1 or alegere == 2)
                                        {
                                            cout << "Inregistrare cu succes" << endl;
                                            ok2 = 0;
                                        }
                                        else
                                            throw eroare;
                                    }
                                    catch (myException5& e)
                                    {
                                        ok = 1;
                                        cout << e.what() << endl;
                                        cout << "Varianta ta este:";
                                    }
                                }
                            }
                            int anotr = rand() % 2;
                            if (alegere == 1 and anotr == 0 and poz(clasament, EU) <= 4)
                            {
                                cout << "Ai esuat,ai iesit cu masina in decor,ai redresat-o dar ai fost depasit de cel din spate" << endl;
                                swap(clasament[poz(clasament, EU) - 1], clasament[poz(clasament, EU)]);
                            }
                            else
                            {
                                if (alegere == 1 and anotr == 1 and poz(clasament, EU) > 1)
                                {
                                    cout << "Cei doi in fata duceau o lupta grea, si in 2 curbe succesive stanga dreapta ai intrat pe interior ai reusit totusi sa urci o pozitie" << endl;
                                    swap(clasament[poz(clasament, EU) - 2], clasament[poz(clasament, EU) - 1]);
                                }
                                else
                                    cout << "Ai ramas pe aceeasi pozitie" << endl;
                            }
                        }
                        else
                            cout << "Nu s-a intamplat nimic" << endl;

                        break;
                    }
                    case 6:
                    {
                        if ((poz(clasament, EU) != 5))
                        {
                            cout << "Din spate vine tare un pilot si ajungeti in paralele la intrarea in curba " << endl;
                            cout << "1.Tii interiorul-------------2.Tii exteriorul";
                            int ok2 = 1;
                            while (ok2 == 1) {

                                cin >> alegere;
                                cin.get(c);
                                if (cin.fail()) {
                                    ok2 = 1;
                                    cin.clear(); // Reseteaza starea fluxului
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                                    cout << "Valoarea introdusa nu este un numar intreg. Va rugam sa incercati din nou." << endl;
                                    cout << "Varianta ta este:";
                                }
                                else {

                                    if (c == 10)
                                        ok2 = 0;
                                    else
                                    {
                                        cout << "Introdu din nou valoarae";
                                        ok2 = 1;
                                        cin.clear(); // Reseteaza starea fluxului
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Curata buffer-ul
                                    }
                                }
                                if (ok2 == 0)
                                {
                                    try
                                    {

                                        if (alegere == 1 or alegere == 2)
                                        {
                                            cout << "Inregistrare cu succes" << endl;
                                            ok2 = 0;
                                        }
                                        else
                                            throw eroare;
                                    }
                                    catch (myException5& e)
                                    {
                                        ok2 = 1;
                                        cout << e.what() << endl;
                                        cout << "Varianta ta este:";
                                    }
                                }
                            }
                            int adf = rand() % 2;
                            if (alegere == 1 and adf == 1)
                                cout << "Ai reusit sa tii interiorul" << endl;
                            else
                            {
                                cout << "Ai pierdut o pozitie" << endl;
                                swap(clasament[poz(clasament, EU) - 1], clasament[poz(clasament, EU)]);

                            }
                        }
                        break;
                    }
                    case 7:
                    {
                        if (poz(clasament, EU) >= 2)
                        {
                            cout << "Ai iesti din curba cu viteza mult mai mare decat oponentul tau si ai reusit sa iei pozitia fara efort" << endl;
                            swap(clasament[poz(clasament, EU) - 2], clasament[poz(clasament, EU) - 1]);
                        }
                        else
                            cout << "Nu s-a intamplat nimic in acest lap" << endl;

                        break;
                    }
                    case 8:
                    {
                        if (poz(clasament, EU) >= 2)
                        {
                            cout << "Ai iesti din curba cu viteza mult mai mare decat oponentul tau si ai reusit sa iei pozitia fara efort" << endl;
                            swap(clasament[poz(clasament, EU) - 2], clasament[poz(clasament, EU) - 1]);
                        }
                        else
                            cout << "Nu s-a intamplat nimic in acest lap" << endl;

                        break;
                    }
                    case 9:
                    {
                        if (poz(clasament, EU) < 5)
                        {
                            cout << "Ai fost depasit ..." << endl;
                            swap(clasament[poz(clasament, EU) - 1], clasament[poz(clasament, EU)]);

                        }
                        else cout << "Nu s a intamplat nimic" << endl;
                        break;
                    }


                    }
                    afisarea_p(clasament, EU);
                    ture++;
                }
                for (int i = 0; i < clasament.size(); i++)
                {


                    if (i == 0)
                        clasament[i].set_campionat(20);
                    if (i == 1)
                        clasament[i].set_campionat(10);
                    if (i == 2)
                        clasament[i].set_campionat(5);
                    elemente.pushBack(clasament[i]);
                }

                elemente.sortare();
                elemente.afisare();
                elemente.stergere();
                cout << endl;
                cout << "Acestea sunt rezultatele finale" << endl;
                afisarea_p(clasament, EU);
                circuitul.set_piloti(clasament);
                cout << "Cursa s-a terminat, acestea sunt rezultatele " << endl;
                cout << circuitul << endl;




                break;

            }
            case 2:
            {
                masina_mea->set_modificare();
                cout << *masina_mea;

                break;
            }
            case 3:
            {
                map<Pilot, string>::iterator i = Piloti_echipa.begin();
                while (i != Piloti_echipa.end()) {
                    cout << "Pilot: " << i->first << endl;
                    cout << "  Echipa: " << i->second << endl;
                    ++i;
                }
                break;
            }
            case 4:
            {
                g << "Uite ce rezultate am";
                g << EU;
                break;
            }
            case 5:
            {

                for (list<Circuit>::iterator it = Circuite_introduse.begin(); it != Circuite_introduse.end(); it++) {
                    cout << *it << endl;
                }
                cout << endl;
                break;
            }
            case 6:
            {

                lt = 63;
                break;

            }
            }
        }

        //set pentru curse, vector pentru campionat
    }
};

Singleton* Singleton::instance = NULL;

///pentru clasa template ar putea sa fie clasa campionat, care sa contina o clasa T , si  sa tot adaug puncte la campionat, prin asta.sau ceva cu care sa modific , mai mai gandesc
int main()
{
    system("color 40");

    Singleton* a = Singleton::getInstance();

    a->main();
    cout << a->get();


}