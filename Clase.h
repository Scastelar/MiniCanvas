#ifndef CLASE_H
#define CLASE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Maestro.h"
#include "Alumno.h"
#include "Examen.h"
#include "Tarea.h"

class Clase {
private:
    int id;
    std::string nombre;
    std::string hora;
    int unidadesValorativas;
    int semestre;
    std::string periodo;
    int anio;
    Maestro maestro;
    std::vector<Alumno> alumnos;
    std::vector<Examen> examenes;
    std::vector<Tarea> tareas;
    int puntosTotales;
    bool estado;

public:
    // Constructor
    Clase(int id, const std::string& nombre, const Maestro& maestro);

    // Métodos
    int getId() const;
    std::string getNombre() const;
    std::string getHora() const;
    int getUnidadesValorativas() const;
    int getSemestre() const;
    std::string getPeriodo() const;
    int getAnio() const;
    const Maestro& getMaestro() const;
    std::vector<Alumno> getAlumnos();
    int getPuntos();

    void asignarAlumno(const Alumno& alumno);
    void asignarMaestro(const Maestro& docente);
    void agregarTarea(const Tarea& ta);
    void agregarExamen(Examen& ex);
    void guardarCursoEnArchivo();
};

#endif

