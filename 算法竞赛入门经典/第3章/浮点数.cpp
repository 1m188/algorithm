#include "iostream"
#include "cmath"
#include "string"
#include "vector"
#include "sstream"
int main() //打表匹配，通过事先算好所有可能性储存在表中，之后通过输入的某些特征在表中匹配相应的结果
{
    double A[10][31]{};
    long long B[10][31]{};

    for (int M = 0; M <= 9; M++)
    {
        for (int E = 1; E <= 30; E++)
        {
            double m = 1 - pow(2, -1 - M), e = pow(2, E) - 1;
            double t = log10(m) + e * log10(2);
            B[M][E] = t;
            A[M][E] = pow(10, t - B[M][E]);
        }
    }

    std::vector<std::string> in{};
    std::string temp = "";
    while (std::cin >> temp && temp != "0e0")
    {
        in.push_back(temp);
    }
    for (int i = 0; i < in.size(); i++)
    {
        for (std::string::iterator it = in [i].begin(); it != in[i].end(); it++)
        {
            if (*it == 'e')
            {
                *it = ' ';
            }
        }

        std::istringstream ss(in[i]);
        double a = 0.0;
        int b = 0;
        ss >> a >> b;
        while (a < 1)
        {
            a *= 10;
            b--;
        }
        for (int M = 0; M <= 9; M++)
        {
            for (int E = 1; E <= 30; E++)
            {
                if (b == B[M][E] && (fabs(a - A[M][E]) < 1e-4 || fabs(a / 10 - A[M][E]) < 1e-4))
                {
                    std::cout << M << ' ' << E << std::endl;
                }
            }
        }
    }

    return 0;
}