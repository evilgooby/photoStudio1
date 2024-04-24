#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string gender;

public:
    Person(string name, int age, string gender) : name(name), age(age), gender(gender) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getGender() const {
        return gender;
    }
};

class Photographer : public Person {
private:
    string specialty;

public:
    Photographer(string name, int age, string gender, string specialty) : Person(name, age, gender), specialty(specialty) {}

    void takePhoto() const {
        cout << name << " is taking a photo." << endl;
    }
};

class Client : public Person {
private:
    string email;

public:
    Client(string name, int age, string gender, string email) : Person(name, age, gender), email(email) {}

    string getEmail() const {
        return email;
    }
};

class PhotoStudio {
private:
    string name;
    string location;
    vector<Photographer> photographers;
    vector<Client> clients;

public:
    PhotoStudio(string name, string location) : name(name), location(location) {}

    void hirePhotographer(const Photographer& photographer) {
        photographers.push_back(photographer);
        cout << photographer.getName() << " has been hired as a photographer at " << name << "." << endl;
    }

    void registerClient(const Client& client) {
        clients.push_back(client);
        cout << client.getName() << " has been registered as a client of " << name << "." << endl;
    }
};

int main() {
    // Creating objects
    Photographer john_doe("John Doe", 30, "Male", "Portrait");
    Client jane_smith("Jane Smith", 25, "Female", "jane@example.com");
    PhotoStudio studio("Capture Moments", "123 Main St");

    // We hire a photographer
    studio.hirePhotographer(john_doe);

    // Registering a client
    studio.registerClient(jane_smith);

    // take photo
    john_doe.takePhoto();

    return 0;
}
