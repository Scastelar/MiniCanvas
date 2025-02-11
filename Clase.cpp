#include "Clase.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

Clase::Clase(const string& _nombre, const Maestro& _maestro)
    : nombre(_nombre), maestro(_maestro) {
}

string Clase::getNombre() const {
    return nombre;
}

const Maestro& Clase::getMaestro() const {
    return maestro;
}

vector<Alumno> Clase::getAlumnos() {
    return alumnos;
}

int Clase::getPuntos()  {
    return puntosTotales;
}

void Clase::asignarAlumno(const Alumno& alumno) {

    alumnos.push_back(alumno);
}

void Clase::asignarMaestro(const Maestro& docente) {
    maestro = docente; 
}

void Clase::agregarTarea(const Tarea& ta) {
    tareas.push_back(ta);
}

void Clase::agregarExamen(Examen& ex) {
    if (puntosTotales + ex.getPuntos() <= 100) {
        examenes.push_back(ex);
        puntosTotales += ex.getPuntos();
    } else {
        cout << "No se puede agregar el examen, superaría los 100 puntos del curso.\n";
    }
}

void Clase::guardarCursoEnArchivo() {
    ofstream archivo("clases.txt", ios::app);
    if (!archivo) {
        cerr << "Error al abrir el archivo para guardar el curso.\n";
        return;
    }
    archivo << nombre << "," << maestro.getUser () << "\n";
    archivo.close();
}
