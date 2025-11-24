#include "../../../database/Database.h"
#include <stdio.h>

void GetProfessors(Database database){
    printf("\n---- LISTA DE PROFESORES ----\n\n");

    ProfessorList professorList = database.professors.findAll();

    if (professorList.count == 0){
        printf("No hay profesores registrados. \n");
        return;
    }
    
    for (int i = 0; i < professorList.count; i++){
        Professor p = professorList.items[i];

        printf("Codigo: %d\n", p.code);
        printf("Nombre; %s %s %s\n", p.name, p.firstLastName, p.secondLastName);
        printf("Departamento: %s\n", p.department);
        printf("--------------------\n");
        }
    
}