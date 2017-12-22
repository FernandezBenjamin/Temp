//
//  structureStudent.c
//  
//
//  Created by Benjamin Fernandez on 22/12/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;

struct Student{
    int id;
    char name[255];
    double avg;
};

typedef struct Item Item;


struct Item{
    Student *s;
    Item *next;
};


typedef struct List List;


struct List{
    Item *first;
};


List *initialisation(){
    List *liste = malloc(sizeof(List));
    
    if (liste == NULL){
        exit(EXIT_FAILURE);
    }
    
    liste->first = NULL;
    
    
    return liste;
    
}





void addStudent(List *list, Student student){
    
    
    Item *newStudent = malloc(sizeof(Item));
    
    if(newStudent == NULL){
        exit(EXIT_FAILURE);
    }
    
    
    newStudent->s = malloc(sizeof(Student));
    newStudent->s->id = student.id;
    strcpy(newStudent->s->name,student.name);
    newStudent->s->avg = student.avg;
    newStudent->next = NULL;
    
    Item *temp = malloc(sizeof(Item));
    
    if(temp == NULL){
        exit(EXIT_FAILURE);
    }
    temp = list->first;
    
    while (temp != NULL){
        temp->next;
    }
    temp->next = newStudent;
    
    
    
    
    
}
/*
void displayList(List *liste){
    if(liste == NULL){
        exit(EXIT_FAILURE);
    }
    List *actual = liste->first;
    
    while (actual != NULL){
        printf("Student id : %d \nNom : %s \nMoyenne : %lf -> ",actual->s.id, actual->s.name, actual->s.avg);
        actual = actual->next;
    }
    printf("NULL\n");
}

*/


int main(int argc, char **argv){
    
    Student s;
    
    
    strcpy(s.name,"Benjamin");
    s.id = 1;
    s.avg = 8.4;
    
    
    List *liste = initialisation();
    
    addStudent(liste,s);
    
    //displayList(liste);
    
    
    
    
    
    return 0;
}
