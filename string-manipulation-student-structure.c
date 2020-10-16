/*The program implements structure use with simple string maniupulation and
memory allocation methods for the student structure*/

#include <stdio.h>
#include "student.h"
#include <string.h>
#include <stdlib.h>

Student *new_student(const char name[], unsigned int id, float shoe_size);
unsigned int has_id(const Student *const student, unsigned int id);
unsigned int has_name(const Student *const student, const char name[]);
unsigned int get_id(const Student *const student);
float get_shoe_size(const Student *const student);
void change_shoe_size(Student *const student, float new_shoe_size);
void change_name(Student *const student, const char new_name[]);
void copy_student(Student *const student1, const Student *const student2);


/*This function returns a Student structure with the values of its parameters stored in its fields*/

Student *new_student(const char name[], unsigned int id, float shoe_size){
  Student *s;
  s = malloc(sizeof(*s));
  s->id = id;
  s->shoe_size = shoe_size;

  if (name) {
    s -> name = calloc((strlen(name)+1),sizeof(char));
    strcpy(s->name, name);

  } else {
    /*if name NULL*/
    s -> name = malloc(sizeof('\0'));
    strcpy(s->name,"");
  }
   
  return s;
}

/*Checks if the id matches the id in the student structure*/

unsigned int has_id(const Student *const student, unsigned int id){
  if (student) {
    if(student->id == id) {
      return 1;

    } else {
      return 0;

    }

  }

  return 0;

}

/*Checks if the name matches the name  in the student structure*/

unsigned int has_name(const Student *const student, const char name[]){

  if (student != NULL && name != NULL){
    if (strcmp(student -> name, name) == 0){
      return 1;
    } 

  } 
    return 0;

  

}
/*returns id*/

unsigned int get_id(const Student *const student){
  if (student) {
    return(student -> id);

  }
  return 0;

}

/*returns shoe_size*/

float get_shoe_size(const Student *const student){
    if (student) {
      return(student -> shoe_size);

  }
  return 0.0;
}

/*change shoe_size to be new parameter*/

void change_shoe_size(Student *const student, float new_shoe_size){

  if (student) {
    student -> shoe_size = new_shoe_size;

  }

}

/*change name to be new parameter*/

void change_name(Student *const student, const char new_name[]){
  
  if (student) {
    /*if not null*/
    if (new_name != NULL && new_name != '\0') {
      free(student->name);
      student -> name = (malloc(sizeof(char) * 
				(strlen(new_name)+1)));
      strcpy(student -> name, new_name);
      
    } else {
      
      /*if NULL or empty string*/
      free(student->name);

      student -> name = (malloc(sizeof('\0')));
      
      strcpy(student -> name, "");
    }
  }
  
}


/*copies student structure 2  into new structure 1*/

void copy_student(Student *const student1, const Student *const student2){
  if(student1 != NULL && student2 != NULL){
 
  student1 -> id = student2 -> id;
  change_shoe_size(student1,student2 -> shoe_size);
  
  free(student1 -> name);

  student1 -> name = (malloc(sizeof(strlen(student2 -> name)+1)));
  strcpy(student1 -> name, student2 -> name);
  }


}

