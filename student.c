/*Natalie Brooks - 116009829 - Project 3*/
/*Project 4 s a project the implements structure use with simple string maniupulation. Moreover, string library functions are also implemented in this project.*/

#include <stdio.h>
#include "student.h"
#include <string.h>
#include <stdlib.h>


Student new_student(const char name[], unsigned int id, float shoe_size);

void init_student(Student *const student, const char name[], unsigned int id, float shoe_size);


unsigned int has_id(Student student, unsigned int id);

unsigned int has_name(Student student, const char name[]);

unsigned int get_id(Student student);

float get_shoe_size(Student student);

Student change_shoe_size(Student student, float new_shoe_size);

void change_name(Student *const student, const char new_name[]);

/*This function returns a Student structure with the values of its parameters stored in its fields*/

Student new_student(const char name[], unsigned int id, float shoe_size){
  Student s;
  s.id = id;
  s.shoe_size = shoe_size;

  if (name) {
    strcpy(s.name, name);
    /*manually adds null byte to end of char array*/
    s.name[strlen(name) + 1] = '\0';
  }else{
    strcpy(s.name,"");
  }
   
  return s;
}

/*This function stores the last 3 values to the student structure passed in*/
void init_student(Student *const student, const char name[], unsigned int id, float shoe_size){

  if (student) {
    student -> id = id;
    student -> shoe_size = shoe_size;
    if (name) {
    strcpy(student -> name, name);
    student -> name[strlen(name) + 1] = '\0';
    } else {
      student -> name[0] = '\0';
    }

  }
}

/*This function will return 0 is the student's id does not equal the given  parameter*/

unsigned int has_id(Student student, unsigned int id){
 
  if (student.id == id) {
    return 1;
  } 
    return 0;
  
}


/*This function will return 0 is the student's name does not equal the given parameter with the use of string libraries*/

unsigned int has_name(Student student, const char name[]){
  
  char real_name[40];
  
  strcpy(real_name,student.name);

  if (name) {
    if (strcmp(real_name, name) != 0) {
      return 0;
    } else {
      return 1;
    }

  }
  return 0;
}

/*This function will return the id of the student parameter*/

unsigned int get_id(Student student){
  return(student.id);
}

/*This function will return the shoe_size of the student parameter*/

float get_shoe_size(Student student){
  return(student.shoe_size);

}

/*This function will modify the student's shoe_size via a pointer and change the size*/

Student change_shoe_size(Student student, float new_shoe_size){
  
  student.shoe_size = new_shoe_size;

  return student;
}

/*This function will access the student structure and modify the name to a new name set by the parameter.*/

void change_name(Student *const student, const char new_name[]){

  if (student) {

    if (new_name && new_name != '\0') {
      strcpy(student->name, new_name);
      /*manually adds null byte to end of char array*/
      student->name[strlen(new_name) + 1] = '\0';

    } else {
      student->name[0] = '\0';
    }

  }

}
