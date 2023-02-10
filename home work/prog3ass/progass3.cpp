#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int main(){

    int floorcount =0;
    cout << "enter number of floors:";
    cin >> floorcount;
    int upcount = 0, downcount = 0 , curfloor =0, goal = 0 , upmoves = 0, downmoves = 0;
    vector<int> floors ;
	floors.resize(floorcount);
	for (int i = 0; i < floorcount; i++) {
		floors.at(i) = 0;
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

	for(int i = 0; i < floorcount; i++) {

		if (curfloor == goal) {
			cout << curfloor << "goall!!!";
			break;
		}
		if (floors.at(curfloor) == 1||curfloor < 0 || curfloor > floorcount ) {
			cout << "use the stairs!";
			break;
		}
		if (curfloor + upcount > floorcount && floors.at(curfloor + upcount - downcount) != 1) {
			floors.at(curfloor) = 1;
			cout << curfloor << "=>";
			curfloor -= downcount;
		}
		else if (curfloor - downcount < 0 && floors.at(curfloor) == 0) {
			floors.at(curfloor) = 1;
			cout << curfloor << "=>";
			curfloor += upcount;
		}
		else if (curfloor < goal) {
			// move up
			floors.at(curfloor) = 1;
			cout << curfloor << "=>";
			curfloor += upcount;
		}
		else if (curfloor > goal) {
			// move down
			floors.at(curfloor) = 1;
			cout << curfloor << "=>";
			curfloor -= downcount;
		}

	}

    return 0;
}