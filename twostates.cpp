#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int main()
{
    fstream p,d;
    p.open("data.txt",ios::out|ios::trunc);
    d.open("data2.txt",ios::out|ios::trunc);
    srand(time(NULL));
    int counter = 1, s=1;
    int N = 5000;
    double alpha = 0.5, beta = 1;
    for(int i = 2;i<N;i++)
    {
        if(s>0)
        {
            double u = (double)rand()/((double)RAND_MAX+1.0);
            if(u<alpha)
                s=-1;
        }
        else
        {
            double u = (double)rand()/((double)RAND_MAX+1.0);
            if(u<beta)
                s=1;
        }
        if(s>0)
        {
            counter++;
        }
        p<<i<<"\t"<<(double)counter/(double)i<<"\t"<<1.0-(double)counter/(double)i<<endl;
        d<<i<<"\t"<<s<<endl;
    }
    p.close();
    return 0;
}
