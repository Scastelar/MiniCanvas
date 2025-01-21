#pragma once
#ifndef REGISTRO_H
#define REGISTRO_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Alumno.h"
#include "Docente.h"

class Registro {
private:
    std::string archivo;

public:
    Registro(const std::string& archivoNombre) : archivo(archivoNombre) {}

    std::string toLowerCase(const std::string& str);
    
    bool isUsuarioUnico(const std::string& user);
    void escribirAlumno(const Alumno& usuario);
    void escribirDocente(const Docente& usuario);

    void leerAlumnos(std::vector<Alumno>& usuarios);
    void leerDocentes(std::vector<Docente>& usuarios);

    void crearUsuario(std::string nombre, std::string contrasena);
    bool iniciarSesion(const std::string nombreUsuario, const std::string contrasena);
};

#endif
