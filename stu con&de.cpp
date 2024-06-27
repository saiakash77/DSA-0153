#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        string name;
        int age;

    public:
        // Constructor
        Student(string n, int a) {
            name = n;
            age = a;
            cout << "Student " << name << " created with age " << age << "." << endl;
        }

        // Destructor
        ~Student() {
            cout << "Student " << name << " is being destroyed." << endl;
        }

        // Function to display student details
        void display() const {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
};

int main() {
    // Creating a student object
    Student student1("John Doe", 20);

  
    student1.display();
    return 0;
}

