#include <iostream>
#include <vector>
using namespace std;
struct Coord{
    float x,y;
};

int main()
{
    vector<Coord> O(2);
    vector<float> R(2);
    Coord P1;
    cout << "Enter coordinates of Manipulator1:";
    cin >> O[0].x >> O[0].y;
    cout << "Enter radius of Manipulator1:";
    cin >> R[0];
    cout << "Enter coordinates of Manipulator2:";
    cin >> O[1].x >> O[1].y;
    cout << "Enter radius of Manipulator2:";
    cin >> R[1];
    cout << "Enter coordinates of Target:";
    cin >> P1.x >> P1.y;
    float min_dist = 0;
    int num_man;
    for(int i = 0; i < O.size();  i++)
    {
        float dist = (O[i].x - P1.x) * (O[i].x - P1.x) + (O[i].y - P1.y) * (O[i].y - P1.y) - R[i] * R[i];
        if(dist < 0 && dist < min_dist)
        {
            min_dist = dist;
            num_man = i;
        }
    }
    if(min_dist == 0)
    {
         cout << "Out Range";
    }
    else
    {
        cout << "Manipulator" << num_man + 1;
    }

}
