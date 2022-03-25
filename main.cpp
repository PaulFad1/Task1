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
        float dist = (O[i].x - P1.x) * (O[i].x - P1.x) + (O[i].y - P1.y) * (O[i].y - P1.y) - R[i] * R[i]; // расстояние от манипулятора до цели минус радиус(sqrt не считал)
        if(dist < 0 && dist < min_dist) // если dist отрицательный значит манипулятор может захватить цель и если dist < min_dist значит данный манипулятор ближе к цели
        {
            min_dist = dist;
            num_man = i;
        }
    }
    if(min_dist == 0) // если min_dist == 0, то оба манипулятора не могут захватить цель
    {
         cout << "Out Range";
    }
    else
    {
        cout << "Manipulator" << num_man + 1;
    }

}
