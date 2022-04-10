#ifndef HOSPITAL_DOCTOR_H
#define HOSPITAL_DOCTOR_H

#include <iostream>
#include "Person.h"
#include "Patient.h"

#include <list>
#include <iterator>
#include <string.h>

using namespace std;

// class for Doctor
class Doctor:public Person{
private:

    string name;
    int age;
    int ssn;
    int officeNumber;
    list<Patient> patients;

public:

    Doctor();
    Doctor(string, int, int, int);
    virtual ~Doctor();
    string print();

    // Set functions for Doctor
    void setName(string name);
    void setAge(int age);
    void setSSN(int ssn);
    void setOfficeNumber(int officeNumber);
    void setPatients(list<Patient>);

    // Get functions for Doctor
    int getAge();
    string getName();
    int getSSN();
    int getOfficeNumber();

    // List of patients

    list<Patient> getPatients();

    // Function for add Patient
    void addPatient(Patient p);

    // Function for remove Patient
    Patient removePatient();
};

#endif //HOSPITAL_DOCTOR_H
