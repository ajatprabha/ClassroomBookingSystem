//
// Created by ajatprabha on 1/4/18.
//

#ifndef CLASSROOMBOOKINGSYSTEM_FORMS_H
#define CLASSROOMBOOKINGSYSTEM_FORMS_H

#include <vector>
#include <string>
#include <users/models.h>
#include "models.h"

using namespace std;

class Form {
private:
    vector<string> errors;
public:
    bool isValid();

    vector<string> getErrors();

    void addError(const string &error);

    virtual void clean() = 0;
};

template<class T>
class ModelForm : public Form {
public:
    virtual T &save() = 0;
};

class AdminCreateForm : public ModelForm<BaseUser> {
    string firstName, lastName, email, password;
public:
    AdminCreateForm(const string &passedFirstName, const string &passedLastName, const string &passedEmail,
                    const string &passedPassword);

    void clean() override;

    BaseUser &save() override;
};

#endif //CLASSROOMBOOKINGSYSTEM_FORMS_H
