// map in STL
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> age;
    age["Prathamesh"] = 25;
    age["Manoj"] = 30;

    cout << "Map contents:\n";
    for (auto& p : age) {
        cout << p.first << " is " << p.second << " years old.\n";
    }

    if (age.count("Manoj")){
        cout << "Manoj exists in the map.\n";
    }
        
    age.erase("Prathamesh");
}
