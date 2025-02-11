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
    std::string nombre;
    Maestro maestro;
    std::vector<Alumno> alumnos;
    std::vector<Examen> examenes;
    std::vector<Tarea> tareas;
    int puntosTotales;
    bool estado;

public:
    // Constructor
    Clase(const std::string& nombre, const Maestro& maestro);

    //metodos
    std::string getNombre() const;
    const Maestro& getMaestro() const;
    std::vector<Alumno> getAlumnos() ;
    int getPuntos();

    void asignarAlumno(const Alumno& alumno); 
    void asignarMaestro(const Maestro& docente);
    void agregarTarea(const Tarea& ta); 
    void agregarExamen(Examen& ex); 
    void guardarCursoEnArchivo();
};

#endif
