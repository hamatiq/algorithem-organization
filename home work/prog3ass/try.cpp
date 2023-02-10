#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

// vector<vector<int>> populateVec( int x){
//     vector<vector<int>> vec;
//     vec.resize(x);
//     for (int i =0; i < x ; i++){
//         vec.at(i).resize(2);
//         vec.at(i).at(0) = i;
//     }
//     return vec;
// }

using namespace std;

int main(){

    int floorcount =0;
    cout << "enter number of floors:";
    cin >> floorcount;
    int upcount = 0, downcount = 0 , curfloor =0, goal = 0 , upmoves = 0, downmoves = 0;
    vector< vector <int> > floors ;
    for (int i = 0; i < floorcount; i++){
        floors.at(i).resize(2);
        floors.at(i).at(0) = i;
    }
    // floors= populateVec(floorcount);
    cout << "what floor are you at: ";
    cin >> curfloor;
    cout << "what floor do u want to go to: ";
    cin >> goal;
    cout << "up floors#: ";
    cin>> upcount;
    cout <<"down floors#: ";
    cin>> downcount;

    while (floors.at(curfloor).at(0) != goal){
        if (floors.at(curfloor).at(1) < 2){
            if (curfloor < goal){
                // move up
                curfloor += upcount;
                cout<< curfloor << "=>";
            }
            else if (curfloor > goal){
                // move down
                curfloor += downcount;
                cout<< curfloor << "=>";
            }
            else {
                break;
            }
            floors.at(curfloor).at(1) ++;
        }
        else{
            cout << "use the stares" << endl;
        }

    }

    return 0;
}