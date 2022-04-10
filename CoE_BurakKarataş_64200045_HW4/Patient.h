#ifndef HOSPITAL_PATIENT_H
#define HOSPITAL_PATIENT_H

#include <iostream>
#include "Person.h"
#include <string.h>
using namespace std;

// Patient class that inherits Person class
class Patient: public Person {
private:
    string name;
    int age;
    int ssn;
    int numDays;
    double dailyCharge;
    bool discharged;
    int totalDays;

public:
    static int counter;

    Patient();
    Patient(string,int,int,int,double);

    // Virtual function for Patient
    virtual ~Patient();
    string print();

    // Set functions
    void setName(string name);
    void setAge(int age);
    void setSSN(int ssn);
    void setNumDays(int numDays);
    void setDailyCharge(double);

    // Get functions
    int getAge();
    string getName();
    int getSSN();
    double getDailyCharge();
    int getNumDays();
    int getTotalDays();

    // Discharged functions
    void setDischarged();
    bool getDischarged();

    // Calculate functions
    friend double calculateExpenses(Patient p);
};

#endif //HOSPITAL_PATIENT_H
