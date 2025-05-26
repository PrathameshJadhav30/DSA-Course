// unordered_map in STL
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> scores;
    scores["Prathamesh"] = 90;
    scores["Manoj"] = 85;

    cout << "Unordered map contents:\n";
    for (auto& p : scores){
        cout << p.first << " => " << p.second << endl;
    }
        

    scores.erase("Manoj");

    if (scores.count("Prathamesh")){
         cout << "Prathamesh is in the map.\n";
    }
       
}
