#include "Doctor.h"

// Doctor Class

Doctor::Doctor() {
    name = "";
    age = 0;
    officeNumber = 0;
    ssn = 0;
}

Doctor::Doctor(string n, int a, int on, int SSN) {
    name = n;
    age = a;
    officeNumber = on;
    ssn = SSN;
}

Doctor::~Doctor() {
}

// Print of Doctor
string Doctor::print() {
    return "Name: " + name + ", Age: " + to_string(age) +
           ", OfficeNumber: " + to_string(officeNumber) + ", SSN: " + to_string(ssn);
}

// Set function for Doctors name
void Doctor::setName(string n) {
    name = n;
}

// Set function for Doctors age
void Doctor::setAge(int a) {
    age = a;
}

// Set function for DoctorS SSN
void Doctor::setSSN(int SSN) {
    ssn = SSN;
}

// Set function for Doctors OfficeNumber
void Doctor::setOfficeNumber(int on) {
    officeNumber = on;
}

// Set function for Doctors Patients
void Doctor::setPatients(list<Patient> pts) {
    patients = pts;
}

// Get function for Doctors age
int Doctor::getAge() {
    return age;
}

// Get function for Doctors name
string Doctor::getName() {
    return name;
}

// Get function for Doctors SSN
int Doctor::getSSN() {
    return ssn;
}

// Get function for Doctors OfficeNumber
int Doctor::getOfficeNumber() {
    return officeNumber;
}

// Get function for Doctors patients from list of Patients
list<Patient> Doctor::getPatients() {
    return patients;
}

// Get function for Doctors patients from list of Patients
void Doctor::addPatient(Patient p) {
    patients.push_back(p);
}

// Remove patient from Doctor
Patient Doctor::removePatient() {
    Patient p = patients.front();
    patients.pop_front();
    return p;
}