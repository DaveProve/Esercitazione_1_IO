#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>
int function(int a)
{
    int square = a*a;
    return square;
}

int main()
{
    int a = -5;
    double d = M_PI; //M_PI è il pigreco;
    bool b = false;
    char c = ';';
    unsigned int i = 1;
    std::string s = "Hello world!";
    int a1 = 1;
    int a2 = 2;
    int sum = a1+a2;
    std::string s1 = "Hello ";
    std::string s2 =  "world";
    std::string conc = s1+s2;

    std::cout << "conc:" << conc << std::endl;

    std::cout << "size of int: " << sizeof(int) << std::endl;
    std::cout << "size of unsigned int: " << sizeof(unsigned int) << std::endl;
    std::cout << std::fixed << std::setprecision(0) << "interval for int: ["<< -pow(2,31) <<","<< pow(2,31)-1 << "]" << std::endl;
    std::cout << "interval for unsigned int: [" << std::numeric_limits<unsigned int>::min() << ","<< std::numeric_limits<unsigned int>::max() << "]" << std::endl;


    std::cout << "a before" << a << std::endl;
    for(unsigned int a = 0; a<3 ; a++)
    {

        std::cout << "a in: " << a << std::endl;

    }

    std::cout << std::defaultfloat << std::setprecision(6)<< "a after: " << a << std::endl;


    std::string nameFile = "data.csv";
    std::ifstream fstr(nameFile); //fstr.open(nameFile)

    if(fstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }
    int val;
    //char separator;
    int sumValues = 0;
    std::string header;
    fstr >> header;
    unsigned int N = 0;
    while (fstr >> val)
    {
        sumValues += val*val;
        N++;
    }
    fstr.close();
    //std::cin >> val;
    //std::cout << val1 << " "<< val2<<std:endl
    std::cout << "sumValues: " << sumValues << std::endl;
    std::cout << "N: " << N << std::endl;
    int j = 9;
    int k = function(j);
    std::cout << "k: " << k;
    return 0;
}

