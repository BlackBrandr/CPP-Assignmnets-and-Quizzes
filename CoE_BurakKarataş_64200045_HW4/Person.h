#ifndef HOSPITAL_PERSON_H
#define HOSPITAL_PERSON_H

#include <iostream>
#include "string.h"
using namespace std;

class Person {
public:
    Person();
    virtual ~Person();
    virtual string print() = 0;
};

#endif //HOSPITAL_PERSON_H
