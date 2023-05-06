#include <iostream>
#include <filesystem>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

void crear_archivos(int cantidad_archivos) {
    if (cantidad_archivos % 2 == 0) {
        // Si la cantidad de archivos es par, los almacenamos en "Mis Documentos/par"
        fs::path par_path = fs::path(getenv("rexyr")) / "C:\\Users\\rexyr\\OneDrive\\Documents\\par";
        fs::create_directories(par_path);

        for (int i = 2; i <= cantidad_archivos; i += 2) {
            fs::path file_path = par_path / ("file" + to_string(i) + ".txt");
            ofstream file(file_path);
            file << "Contenido del archivo " << i << endl;
            file.close();
        }
    } else {
        // Si la cantidad de archivos es impar, los almacenamos en "Escritorio/impar"
        fs::path impar_path = fs::path(getenv("rexyr")) / "C:\\Users\\rexyr\\OneDrive\\Escritorio\\Parcial2archivohernandez\\impar";
        fs::create_directories(impar_path);

        for (int i = 2; i <= cantidad_archivos; i += 2) {
            fs::path file_path = impar_path / ("file" + to_string(i) + ".txt");
            ofstream file(file_path);
            file << "Contenido del archivo " << i << endl;
            file.close();
        }
    }
}

int main() {
    int cantidad_archivos;
    cout << "Ingrese la cantidad de archivos a crear: ";
    cin >> cantidad_archivos;

    crear_archivos(cantidad_archivos);

    return 0;
}