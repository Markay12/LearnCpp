#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

    FILE* outfile; //file pointer
    outfile = fopen("data.t", "w"); //open data.t for writing

    int i;

    //loop through file to fprinf information
    for (i = 0; i < 100; i++)
    {

        fprintf(outfile, "%d\n", i);

    }

    fclose(outfile);

    return 0;

}