#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include <sys/stat.h>
#include <fstream>
using namespace std;

// List for Patients
list<Patient> totalPatients;
int getRandom(int low, int high) {
    return (rand() % (high - low + 1)) + low;
}

// Add Patient to the Doctors
void addPatient(Doctor *doctor) {
    if (totalPatients.empty())
        return;
    Patient p = totalPatients.front();
    totalPatients.pop_front();
    doctor->addPatient(p);
}

// Print Details to the Text Files
void printDetails(Doctor *d, ofstream &outputFile) {
    list<Patient> patients = d->getPatients();
    for (auto & patient : patients) {
        if (patient.getNumDays()>0) {
            outputFile<<patient.print() <<"\n";
        }
    }
}

// Assign patients again to the Doctors
void reAssignPatient(Doctor *doctor1,Doctor *doctor2) {
    Patient p1 = doctor1->removePatient();
    doctor2->addPatient(p1);
}

// Function for Discharge Patients
void dischargePatients(Doctor *doctor, int days) {
    list<Patient> patients = doctor->getPatients();
    list<Patient> newPatients;
    for (auto & patient : patients) {
        if (patient.getNumDays() != 0) {
            newPatients.push_back(patient);
        }
        else {
            double expense = patient.getTotalDays() * patient.getDailyCharge();
            cout<<"Patient " <<patient.getName() <<" leaving hospital with total expense "
                << to_string(expense) <<"\n";
        }
    }
    doctor->setPatients(newPatients);
}

// Function for reducing count of days
void reduceDayCount(Doctor *doctor) {

    list<Patient> patients = doctor->getPatients();
    list<Patient> newPatients;
    for (auto patient = patients.begin(); patient !=
                                          patients.end(); ++patient) {
        int numDays = patient->getNumDays();
        numDays--;
        patient->setNumDays(numDays);
        newPatients.push_back(*patient);
    }
    doctor->setPatients(newPatients);
}

// Generating Patients
void generatePatients() {

    Patient p1("Burak",21,getRandom(1, 10),3350,getRandom(500, 2000));
    Patient p2("Ahmet",23,getRandom(1, 10),3351,getRandom(500, 2000));
    Patient p3("Hakan",35,getRandom(1, 10),3352,getRandom(500, 2000));
    Patient p4("Sude",49,getRandom(1, 10),3353,getRandom(500, 2000));
    Patient p5("Nil",65,getRandom(1, 10),3354,getRandom(500, 2000));
    Patient p6("Seda",43,getRandom(1, 10),3355,getRandom(500, 2000));
    Patient p7("Nazif",30,getRandom(1, 10),3356,getRandom(500, 2000));
    Patient p8("İbrahim",23,getRandom(1, 10),3357,getRandom(500, 2000));
    Patient p9("Kemal",47,getRandom(1, 10),3358,getRandom(500, 2000));
    Patient p10("Eda",68,getRandom(1, 10),3359,getRandom(500, 2000));


    totalPatients.push_back(p1);totalPatients.push_back(p2);
    totalPatients.push_back(p3);totalPatients.push_back(p4);
    totalPatients.push_back(p5);totalPatients.push_back(p6);
    totalPatients.push_back(p7);totalPatients.push_back(p8);
    totalPatients.push_back(p9);totalPatients.push_back(p10);
}


int main() {

    srand(time(0));
    generatePatients();

    // Creating Doctors
    auto *doctor1 = new Doctor("Mustafa", 48, 2234, 778589);
    auto *doctor2 = new Doctor ("Nurullah", 37, 2235, 374989);
    auto *doctor3 = new Doctor("Mahmut", 60, 2236, 684655);

    // Creating Patients
    Patient p1("Burak",21,getRandom(1, 10),3350,getRandom(500, 2000));
    Patient p2("Ahmet",23,getRandom(1, 10),3351,getRandom(500, 2000));
    Patient p3("Hakan",35,getRandom(1, 10),3352,getRandom(500, 2000));
    Patient p4("Sude",49,getRandom(1, 10),3353,getRandom(500, 2000));
    Patient p5("Nil",65,getRandom(1, 10),3354,getRandom(500, 2000));
    Patient p6("Seda",43,getRandom(1, 10),3355,getRandom(500, 2000));

    // Add patients to the Doctors
    doctor1->addPatient(p1);doctor1->addPatient(p2);
    doctor2->addPatient(p3);doctor2->addPatient(p4);
    doctor3->addPatient(p5);doctor3->addPatient(p6);

    for (int i =1; i <=10;i++) {
        if (i<=3)
            addPatient(doctor1);
        else if(i>=4 && i<=6)
            addPatient(doctor2);
        else
            addPatient(doctor3);
        dischargePatients(doctor1,i);
        dischargePatients(doctor2,i);
        dischargePatients(doctor3,i);
        reAssignPatient(doctor1, doctor2);
        reAssignPatient(doctor2, doctor3);
        reAssignPatient(doctor3, doctor1);
        reduceDayCount(doctor1);
        reduceDayCount(doctor2);
        reduceDayCount(doctor3);

        string day = "Day";
        string fileName = "";

        // Creating info txt files
        day = day + to_string(i);
        fileName = day + "/" + "info.txt";


        int check = mkdir(day.c_str(),0777);
        if (check) {
            cout<< "Unable to create folder " << fileName <<"\n";
            exit(1);
        }

        // We are calling Print Details Function for printing to the Output files
        ofstream outputFile(fileName.c_str());
        outputFile<<"Patient Information\n";
        printDetails(doctor1,outputFile);
        printDetails(doctor2,outputFile);
        printDetails(doctor3,outputFile);
        outputFile.close();
    }
    return 0;
}
