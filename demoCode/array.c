#include <iostream>
using namespace std;

void wasteMemory();

int main(int argc char** argv)
{

    for(int i = 0; i < 1000; )
    {

        cout << "Wasting memory: " << i << endl;
        wasteMemory();

        system("pause");


    }
    return 0;

}

void wasteMemory()
{

    int* myArray = new int[1000000];

}