#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    std::string _email;
    std::string _phone;

public:
    Person();
    Person(std::string name, std::string _email, std::string _phone);

    std::string getName() const;
    void setName(std::string name);

    std::string getEmail() const;
    void setEmail(std::string _email);

    std::string getPhone() const;
    void setPhone(std::string _phone);
};

#endif  // PERSON_H

