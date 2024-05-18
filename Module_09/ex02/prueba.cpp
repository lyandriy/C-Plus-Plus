#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Función para verificar si un vector está ordenado
bool estaOrdenado(const vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(nullptr)); // Inicializar la semilla para generar números aleatorios

    ofstream outFile("resultados.txt"); // Archivo para guardar los resultados

    // Generar y procesar números aleatorios en múltiples rangos
    for (int range = 2; range <= 3000; range += 2) {
        // Generar números aleatorios
        vector<int> numerosAleatorios;
        for (int i = 0; i < range; ++i) {
            numerosAleatorios.push_back(rand());
        }

        // Guardar los números aleatorios en el archivo de entrada
        ofstream inFile("input.txt");
        for (const auto& num : numerosAleatorios) {
            inFile << num << " ";
        }
        inFile.close();

        // Ejecutar el programa PmergeMe con los números generados y redirigir la salida al archivo output.txt
        stringstream cmd;
        cmd << "./PmergeMe < input.txt > output.txt 2>&1"; // 2>&1 redirige tanto stdout como stderr al archivo
        system(cmd.str().c_str());

        // Leer los números ordenados devueltos por PmergeMe
        vector<int> numerosOrdenados;
        ifstream inFile2("output.txt");
        int num;
        while (inFile2 >> num) {
            numerosOrdenados.push_back(num);
        }
        inFile2.close();

        // Verificar si los números devueltos están ordenados
        bool ordenCorrecto = estaOrdenado(numerosOrdenados);
        cout << "Rango: " << range << ", Ordenado correctamente: " << (ordenCorrecto ? "Si" : "No") << endl;

        // Guardar el resultado en el archivo de resultados
        outFile << "Rango: " << range << ", Ordenado correctamente: " << (ordenCorrecto ? "Si" : "No") << endl;
    }

    outFile.close();

    return 0;
}