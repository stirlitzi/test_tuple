#include <string>
#include <iostream>
#include <tuple>
#include <cassert>

using namespace std;

auto getPerson() {
    const std::string name = "Petia";
    const std::string secondName = "Ivanoff";
    const std::size_t age = 23;
    const std::string department = "Sale";
    return std::make_tuple(
            name, secondName, age, department
    );
}


class custom_tuple {
public:

};

class custom_tie {
public:
    custom_tie(string &name, string &secondName, size_t &age, string &department) : name(&name),
                                                                                    secondname(&secondName),
                                                                                    age(&age), department(&department) {

    }

    void operator=(const tuple<string, string, size_t, string> t) {
        *this->name = get<0>(t);
        *this->secondname = get<1>(t);
        *this->age = get<2>(t);
        *this->department = get<3>(t);

    }

private:
    string *name;
    string *secondname;
    string *department;
    size_t *age;
};

int main(int argc, char *argv[]) {
    std::string name, secondName, department;
    std::size_t age;
    custom_tie(name, secondName, age, department) = getPerson();
    assert(name == "Petia");
    assert(secondName == "Ivanoff");
    assert(age == 23);
    assert(department == "Sale");
    return 0;
}
