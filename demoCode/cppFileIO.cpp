#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

int main(int argc, char** argv)
{

    std::ofstream outfile;
    std::ifstream infile;
    int input;

    outfile.open("info.dat");

    for (int i = 0; i < 100; i++)
    {

        outfile << i << endl;

    }
    outfile.close();

    infile.open("info.dat");

    for (int i = 0; i < 100; i++ )
    {

        infile >> input;
        cout << "Read: " << input << endl;

    }
    infile.close();

    return 0;
    
}