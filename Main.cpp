#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
class Biblioteca
{
private:
    char *b_nombre;
    char *b_ubicacion;

public:
    Biblioteca(const char *nombre, const char *ubicacion)
    {
        b_nombre = new char[strlen(nombre)];
        b_ubicacion = new char[strlen(ubicacion)];
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

public:
    Libro(const char *titulo, const char *autor, int anio)
    {
        l_titulo = new char[strlen(titulo)];
        l_autor = new char[strlen(autor)];
        strcpy(l_titulo, titulo);
        strcpy(l_autor, autor);
        l_anioLanzamiento = anio;
    }

    ~Libro()
    {
        if (l_titulo)
        {
            delete l_titulo;
        }
        if (l_autor)
        {
            delete l_autor;
        }
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

void ListadoDeItems(char *titulo, char *autor, int anio, char *biblioteca, int piso, int estante, int seccion)
{
    cout << "Titulo: " << titulo << endl
         << "Autor: " << autor << endl
         << "Anio: " << anio << endl
         << "Biblioteca: " << biblioteca << endl
         << "Ubicado en el piso " << piso << " del estante " << estante << " de la seccion " << seccion << endl;
}

int main()
{
    int BaseDeDatos[50];
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
            Biblioteca temp = Biblioteca(nombr, ubicacion);
            temporal = &temp;
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
            Libro(titulo, autor, anio);
        }
        break;
        case 3:
        {
            char busquedaTit[80];
            cout << "Buscar Por Titulo: \n";
            cout << "Ingrese el titulo a buscar: \n";
            cin.getline(busquedaTit, 80);
        }
        break;
        case 4:
        {
            cout << "Buscar Por Autor: " << endl;
            char busquedaAut[80];
            cout << "Buscar Por Titulo: \n";
            cout << "Ingrese el autor a buscar: \n";
            cin.getline(busquedaAut, 80);
        }
        break;
        case 5:
        {
            cout << "Explorar Biblioteca: " << endl;
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
            break;
        }
    }
    return 0;
}