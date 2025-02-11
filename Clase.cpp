#include "Clase.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Constructor
Clase::Clase(int _id, const string& _nombre, const Maestro& _maestro)
    : id(_id), nombre(_nombre), maestro(_maestro), 
      unidadesValorativas(0), semestre(0), periodo(""), 
      anio(0), puntosTotales(0), estado(true) { // Inicializa los atributos
}

// Métodos
int Clase::getId() const {
    return id;
}

string Clase::getNombre() const {
    return nombre;
}

string Clase::getHora() const {
    return hora; // Asegúrate de que 'hora' se inicialice en algún lugar
}

int Clase::getUnidadesValorativas() const {
    return unidadesValorativas; // Asegúrate de que se inicialice correctamente
}

int Clase::getSemestre() const {
    return semestre; // Asegúrate de que se inicialice correctamente
}

string Clase::getPeriodo() const {
    return periodo; // Asegúrate de que se inicialice correctamente
}

int Clase::getAnio() const {
    return anio; // Asegúrate de que se inicialice correctamente
}

const Maestro& Clase::getMaestro() const {
    return maestro;
}

vector<Alumno> Clase::getAlumnos() {
    return alumnos;
}

int Clase::getPuntos() {
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
    archivo << id << "," << nombre << "," << maestro.getUser () << "\n"; // Incluye el ID
    archivo.close();
}
