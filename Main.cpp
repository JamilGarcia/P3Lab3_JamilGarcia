#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
class Biblioteca
{
private:
    char *b_nombre;
    char *b_ubicacion;
    int b_pisos;
    int b_estantes;
    int b_secciones;

public:
    Biblioteca(const char *nombre, const char *ubicacion, int pisos, int estantes, int secciones)
    {
        b_nombre = new char[strlen(nombre)];
        b_ubicacion = new char[strlen(ubicacion)];
        b_pisos = pisos;
        b_estantes = estantes;
        b_secciones = secciones;
        strcpy(b_nombre, nombre);
        strcpy(b_ubicacion, ubicacion);
    }

    ~Biblioteca()
    {
        if (b_nombre)
        {
            delete b_nombre;
        }
        if (b_ubicacion)
        {
            delete b_ubicacion;
        }
        
    }
    void setSecciones(int secciones)
    {
        b_secciones = secciones;
    }
    int getSecciones()
    {
        return b_secciones;
    }
    void setEstantes(int estantes)
    {
        b_estantes = estantes;
    }
    int getEstantes()
    {
        return b_estantes;
    }

    void setPisos(int pisos)
    {
        b_pisos = pisos;
    }
    int getPisos()
    {
        return b_pisos;
    }

    char *getNombre()
    {
        return b_nombre;
    }

    void setNombre(char *nombre)
    {
        b_nombre = nombre;
    }

    char *getUbicacion()
    {
        return b_ubicacion;
    }

    void setUbicacion(char *ubicacion)
    {
        b_ubicacion = ubicacion;
    }
};

class Libro
{
private:
    char *l_titulo;
    char *l_autor;
    int l_anioLanzamiento;
    int l_piso;
    int l_estante;
    int l_seccion;
    Biblioteca *l_biblio;

public:
    Libro(const char *titulo, const char *autor, int anio, Biblioteca *biblio, int piso, int estante, int seccion)
    {
        l_titulo = new char[strlen(titulo)];
        l_autor = new char[strlen(autor)];
        l_biblio = biblio;
        l_piso = piso;
        l_estante = estante;
        l_seccion = seccion;
        strcpy(l_titulo, titulo);
        strcpy(l_autor, autor);
        l_anioLanzamiento = anio;
    }

    ~Libro()
    {
        if (l_biblio)
        {
            delete l_biblio;
        }
        if (l_titulo)
        {
            delete l_titulo;
        }
        if (l_autor)
        {
            delete l_autor;
        }
    }
    void setSeccion(int seccion)
    {
        l_seccion = seccion;
    }
    int getSeccion()
    {
        return l_seccion;
    }
    void setEstante(int estante)
    {
        l_estante = estante;
    }
    int getEstante()
    {
        return l_estante;
    }

    void setPiso(int piso)
    {
        l_piso = piso;
    }
    int getPiso()
    {
        return l_piso;
    }
    void setBiblio(Biblioteca *biblio)
    {
        l_biblio = biblio;
    }
    Biblioteca *getBiblio() const
    {
        return l_biblio;
    }
    char *getTitulo() const
    {
        return l_titulo;
    }

    void setTitulo(char *titulo)
    {
        l_titulo = titulo;
    }

    char *getAutor() const
    {
        return l_autor;
    }

    void setAutor(char *autor)
    {
        l_autor = autor;
    }

    int getAnio() const
    {
        return l_anioLanzamiento;
    }

    void setAnio(int anio)
    {
        l_anioLanzamiento = anio;
    }
};

void ListadoDeBiblio(char *nombre, char *ubicacion, int pisos, int estantes, int secciones)
{
    cout << "Nombre : " << nombre << endl
         << "Ubicacion: " << ubicacion << endl
         << "No. Pisos: " << pisos << endl
         << "No. Estantes: " << estantes << endl
         << "No. Secciones: " << secciones << endl; 
}

void ListadoDeItems(char *titulo, char *autor, int anio, char *biblioteca, int piso, int estante, int seccion)
{
    cout << "Titulo: " << titulo << endl
         << "Autor: " << autor << endl
         << "Anio: " << anio << endl
         << "Biblioteca: " << *biblioteca << endl
         << "Ubicado en el piso " << piso << " del estante " << estante << " de la seccion " << seccion << endl;
}

vector<Biblioteca *> lista;
vector<Libro *> listaLibros;
int main()
{

    int respuestaMenu = 1;
    int *temporal;
    while (respuestaMenu == 1)
    {
        int OpcionMenu = NULL;
        cout << "Menu \n"
             << "1) Crear Biblioteca\n"
             << "2) Agregar Libro\n"
             << "3) Buscar Por Titulo\n"
             << "4) Buscar Por Autor\n"
             << "5) Explorar Biblioteca\n"
             << "0) Salir\n";
        cin >> OpcionMenu;
        switch (OpcionMenu)
        {
        case 1:
        {
            char nombr[80], ubicacion[80];
            int pisos, estantes, secciones, flag = 0;

            cout << "Crear biblioteca: " << endl;
            cout << "Ingrese el nombre de la biblioteca: ";
            cin.getline(nombr, 80);
            cin.getline(nombr, 80);
            cout << endl;
            cout << "Ingrese la ubicacion de la biblioteca: " << endl;
            cin.getline(ubicacion, 80);
            cout << "Ingrese el numero de pisos: " << endl;
            cin >> pisos;
            cout << "Ingrese el numero de estantes: " << endl;
            cin >> estantes;
            cout << "Ingrese el numero de secciones: " << endl;
            cin >> secciones;
            lista.push_back(new Biblioteca(nombr, ubicacion, pisos, estantes, secciones));
            
            
        }
        break;

        case 2:
        {
            char titulo[80], autor[80];
            int anio;
            cout << "Agregar Libro: \n";
            cout << "Ingrese el titulo del libro: \n";
            cin.getline(titulo, 80);
            cin.getline(titulo, 80);
            cout << "Ingrese el autor del libro: \n";
            cin.getline(autor, 80);
            cout << "Ingrese el anio de lanzamiento del libro: \n";
            cin >> anio;
            for (int i = 0; i < lista.size(); i++)
            {
                cout << i << ") Nombre: " << lista.at(i)->getNombre() << "\nUbicacion: " << lista.at(i)->getUbicacion() << endl;
                //lista.at(i)->~Biblioteca();
            }
            int num_biblio;
            cout << "Ingrese el numero de biblioteca: ";
            cin >> num_biblio;
            int tempPisos = 0, tempEstant = 0, tempSeccion = 0;
            cout << "Pisos: " << lista.at(num_biblio)->getPisos() << "\n Ingrese el numero de piso: ";
            cin >> tempPisos;
            cout << "Estantes: " << lista.at(num_biblio)->getEstantes() << "\n Ingrese el numero de estante: ";
            cin >> tempEstant;
            cout << "Secciones: " << lista.at(num_biblio)->getSecciones() << "\n Ingrese el numero de seccion: ";
            cin >> tempSeccion;
            listaLibros.push_back(new Libro(titulo, autor, anio, lista.at(num_biblio), tempPisos, tempEstant, tempSeccion));
        }
        break;
        case 3:
        {
            char busquedaTit[80];
            cout << "Buscar Por Titulo: \n";
            cout << "Ingrese el titulo a buscar: \n";
            cin.getline(busquedaTit, 80);
            cin.getline(busquedaTit, 80);
            bool encontrado = false;
            for (int i = 0; i < listaLibros.size(); i++)
            {
                
                if (busquedaTit == listaLibros.at(i)->getTitulo())
                {
                    ListadoDeItems(listaLibros.at(i)->getTitulo(),
                                   listaLibros.at(i)->getAutor(),
                                   listaLibros.at(i)->getAnio(),
                                   listaLibros.at(i)->getBiblio()->getNombre(),
                                   listaLibros.at(i)->getPiso(),
                                   listaLibros.at(i)->getEstante(),
                                   listaLibros.at(i)->getSeccion());
                    encontrado = true;
                }
            }
            if (encontrado == false)
            {
                cout << "no se ha encontrado ningun libro\n";
            }
        }
        break;
        case 4:
        {
            cout << "Buscar Por Autor: " << endl;
            char busquedaAut[80];
            cout << "Ingrese el autor a buscar: \n";
            cin.getline(busquedaAut, 80);
            cin.getline(busquedaAut, 80);
            bool encontrado = false;
            for (int i = 0; i < listaLibros.size(); i++)
            {
                if (busquedaAut == listaLibros.at(i)->getAutor())
                {
                    ListadoDeItems(listaLibros.at(i)->getTitulo(),
                                   listaLibros.at(i)->getAutor(),
                                   listaLibros.at(i)->getAnio(),
                                   listaLibros.at(i)->getBiblio()->getNombre(),
                                   listaLibros.at(i)->getPiso(),
                                   listaLibros.at(i)->getEstante(),
                                   listaLibros.at(i)->getSeccion());
                    encontrado = true;
                }
            }
            if (encontrado == false)
            {
                cout << "no se ha encontrado ningun libro\n";
            }
        }
        break;
        case 5:
        {
            int tempNumBiblio, tempNumPiso, tempNumEstante, tempNumSeccion;
            cout << "Explorar Biblioteca: " << endl;
            for (int i = 0; i < lista.size(); i++)
            {
                cout << i << ") ";
                ListadoDeBiblio(lista.at(i)->getNombre(),
                                lista.at(i)->getUbicacion(), 
                                lista.at(i)->getPisos(), 
                                lista.at(i)->getEstantes(), 
                                lista.at(i)->getSecciones());
                cout << endl; 
            }
            cout << "Ingrese el numero de biblioteca: ";
            cin >> tempNumBiblio;
            cout << "Ingrese el piso a explorar: ";
            cin >> tempNumPiso;
            cout << "Ingrese el estante a explorar: ";
            cin >> tempNumEstante;
            cout << "Ingrese la seccion a explorar: ";
            cin >> tempNumSeccion;
            cout << "Estos son los libros disponibles: \n";

            for (int i = 0; i < listaLibros.size(); i++)
            {
                if (listaLibros.at(i)->getBiblio() == listaLibros.at(tempNumBiblio)->getBiblio()){
                    if (listaLibros.at(i)->getPiso() == listaLibros.at(tempNumBiblio)->getPiso()){
                        if (listaLibros.at(i)->getEstante() == listaLibros.at(tempNumBiblio)->getEstante()){
                            if (listaLibros.at(i)->getSeccion() == listaLibros.at(tempNumBiblio)->getSeccion()){
                                ListadoDeItems(listaLibros.at(i)->getTitulo(),
                                   listaLibros.at(i)->getAutor(),
                                   listaLibros.at(i)->getAnio(),
                                   listaLibros.at(i)->getBiblio()->getNombre(),
                                   listaLibros.at(i)->getPiso(),
                                   listaLibros.at(i)->getEstante(),
                                   listaLibros.at(i)->getSeccion());
                            }
                        }
                    }
                }
            }
            
            
        }
        break;
        case 0:
        {
            cout << "Gracias por utilizar el programa " << endl;
            respuestaMenu = 0;
            return 0;
        }
        break;

        default:
            cout << "Ingrese un valor valida!!";
            break;
        }
    }
    return 0;
}