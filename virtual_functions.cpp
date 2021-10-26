# question link = https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true
################## provided includes ########################

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
    protected:
        string name;
        int age;
            
    public:
        Person(): name(""), age(0) {};
        
        virtual void getdata() = 0;
        virtual void putdata() const = 0;
};

class Professor: public Person {
    private:
        int publications;
        static int cur_id;
    
    public:
        Professor(): Person(), publications(0) {};
        
        void getdata();
        void putdata() const;    
};

int Professor::cur_id = 0;

void Professor::getdata() {
    cin >> name >> age >> publications;    
}

void Professor::putdata() const{
    cur_id += 1;
    
    cout << name << " " << age << " " << publications << " " << cur_id << endl;
}

class Student: public Person {
    private:
        int marks[6];
        static int cur_id;
        
    public:
        Student(): Person() {
            for (auto& mark: marks){
                mark = 0;
            }
        };
        
        void getdata();
        void putdata() const;

};

int Student::cur_id = 0;

void Student::getdata() {
    cin >> name >> age;
    
    for (auto& mark: marks) {
        cin >> mark;
    }    
}

void Student::putdata() const{
    int sum = 0;
    cur_id += 1;
    
    for (auto const& mark: marks) {
        sum += mark;
    }
    
    cout << name << " " << age << " " << sum << " " << cur_id << endl;
}

####################### provided code below ###############################

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
