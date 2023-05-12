#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> palabrasEsp;
vector<string> palabrasIngles;

const int maxErrores = 7;

string obtenerPalabraAleatoria(vector<string>& palabras)
{
    int indice = rand() % palabras.size();
    return palabras[indice];
}

string obtenerPalabraUsuario()
{
    string palabra;
    cout << "Ingresa una palabra: ";
    cin >> palabra;
    system("cls");
    return palabra;
}

string obtenerPalabraUsuarioIngles()
{
    string palabra;
    cout << "Enter a word: ";
    cin >> palabra;
    system("cls");
    return palabra;
}

void agregarPalabra(vector<string>& palabras)
{
    if (palabras.size() < 10)
    {
        string palabra;
        cout << "Ingresa una palabra: ";
        cin >> palabra;
        palabras.push_back(palabra);
        cout << "Palabra agregada exitosamente." << endl;
    }
    else
    {
        cout << "No es posible agregar más palabras. La base de datos está llena." << endl;
    }
}

void agregarPalabraingles(vector<string>& palabras)
{
    if (palabras.size() < 10)
    {
        string palabra;
        cout << "Add a word: ";
        cin >> palabra;
        palabras.push_back(palabra);
        cout << "Word added" << endl;
    }
    else
    {
        cout << "It is not possible to add more words. the database is full" << endl;
    }
}

void inicializarPalabraOculta(string& palabra, string& palabraOculta)
{
    palabraOculta = "";
    for (int i = 0; i < palabra.length(); i++)
    {
        palabraOculta += "_";
    }
}

void mostrarPalabraOculta(string& palabraOculta)
{
    for (char c : palabraOculta)
    {
        cout << c << " ";
    }
    cout << endl;
}

bool adivinarLetra(char letra, string& palabra, string& palabraOculta)
{
    bool adivinada = false;
    for (int i = 0; i < palabra.length(); i++)
    {
        if (palabra[i] == letra)
        {
            palabraOculta[i] = letra;
            adivinada = true;
        }
    }
    return adivinada;
}

bool juegoTerminado(string& palabra, string& palabraOculta)
{
    return palabra == palabraOculta;
}

int main()
{
    srand(time(0));
    string palabra;
    string palabraOculta;
    char letra;
    int opcion;
    bool jugar = true;

    while (jugar)
    {
        cout << "Bienvenido al juego del ahorcado!\n" << endl;
        cout << "Welcome to the hangman game!\n" << endl;
        cout << "Selecciona el idioma:\n" << endl;
        cout << "Choose the language:\n" << endl;
        cout << "1. Espanol\n" << endl;
        cout << "2. English\n" << endl;
        cout << "Opcion / Option: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
            case 1:
{
    vector<string>& palabras = palabrasEsp;

    cout << "Selecciona el modo de juego:" << endl;
    cout << "1. Jugar solo contra la maquina" << endl;
    cout << "2. Jugar contra otro jugador" << endl;
    cout << "3. Agregar palabras a la base de datos" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    system("cls");

    if (opcion == 3)
    {
        agregarPalabra(palabras);
        continue;
    }

    if (opcion == 1)
    {
        palabra = obtenerPalabraAleatoria(palabras);
    }
    else if (opcion == 2)
    {
        palabra = obtenerPalabraUsuario();
    }
    else
    {
        cout << "Opcion invalida. Saliendo del juego." << endl;
        return 0;
    }

    inicializarPalabraOculta(palabra, palabraOculta);

    int errores = 0;

    while (!juegoTerminado(palabra, palabraOculta) && errores < maxErrores)
    {
        cout << "Palabra oculta: ";
        mostrarPalabraOculta(palabraOculta);
        cout << "Ingresa una letra: ";
        cin >> letra;

        if (letra == '/')
        {
            string intento;
            cout << "Ingresa la palabra completa: ";
            cin >> intento;

            if (intento == palabra)
            {
                palabraOculta = palabra;
                break;
            }
            else
            {
                cout << "Palabra incorrecta. Pierdes el juego." << endl;
                errores = maxErrores;
            }
        }
        else
        {
            if (adivinarLetra(letra, palabra, palabraOculta))
            {
                cout << "¡Letra correcta!" << endl;
            }
            else
            {
                cout << "Letra incorrecta. Pierdes una vida." << endl;
                errores++;
            }
        }
    }

    if (juegoTerminado(palabra, palabraOculta))
    {
        cout << "¡Felicidades! Has adivinado la palabra: " << palabra << endl;
    }
    else
    {
        cout << "¡Oh no! Has perdido. La palabra era: " << palabra << endl;
    }

    cout << "¿Deseas jugar nuevamente? (S/N): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's')
    {
        jugar = true;
    }
    else
    {
        jugar = false;
    }

    cout << endl;
}
break;
case 2:
{
    vector<string>& palabras = palabrasIngles;

    cout << "Selecc the game mode" << endl;
    cout << "1. Play alone" << endl;
    cout << "2. Player vs Player" << endl;
    cout << "3. Add words to database" << endl;
    cout << "Option: ";
    cin >> opcion;
    system("cls");

    if (opcion == 3)
    {
        agregarPalabraingles(palabras);
        continue;
    }

    if (opcion == 1)
    {
        palabra = obtenerPalabraAleatoria(palabras);
    }
    else if (opcion == 2)
    {
        palabra = obtenerPalabraUsuarioIngles();
    }
    else
    {
        cout << "Invalid option, Leaving the game" << endl;
        return 0;
    }

    inicializarPalabraOculta(palabra, palabraOculta);

    int errores = 0;

    while (!juegoTerminado(palabra, palabraOculta) && errores < maxErrores)
    {
        cout << "Hidden word: ";
        mostrarPalabraOculta(palabraOculta);
        cout << "Choose a letter: ";
        cin >> letra;

        if (letra == '/')
        {
            string intento;
            cout << "Enter the whole word: ";
            cin >> intento;

            if (intento == palabra)
            {
                palabraOculta = palabra;
                break;
            }
            else
            {
                cout << "Wrong word. You lose the game." << endl;
                errores = maxErrores;
            }
        }
        else
        {
            if (adivinarLetra(letra, palabra, palabraOculta))
            {
                cout << "¡Right letter!" << endl;
            }
            else
            {
                cout << "Wrong letter, you lose one life" << endl;
                errores++;
            }
        }
    }

    if (juegoTerminado(palabra, palabraOculta))
    {
        cout << "Congratulations! You guessed the word: " << palabra << endl;
    }
    else
    {
        cout << "Oh no! You lose. the word was: " << palabra << endl;
    }

    cout << "You wanna play again? (Y/N): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta == 'Y' || respuesta == 'y')
    {
        jugar = true;
    }
    else
    {
        jugar = false;
    }

    cout << endl;
}
default:
            cout<< "invalid option. Leaving the game\n" << endl;
            cout<< "Opcion invalida. Saliendo del juego\n"<<endl;
        }
        system("cls");
    }
    cout << "Gracias por jugar. Hasta luego!\n" << endl;
    cout << "Thanks for playing. See you next time!" << endl;
    return 0;
}
