#include "iostream"
#include "string"
#include "vector"

void DNA()
{
    int m = 0, n = 0;
    std::vector<std::string> dna;
    std::cin >> m;
    std::cin >> n;
    std::string str;
    for (int i = 0; i < m; i++)
    {
        std::cin >> str;
        dna.push_back(str);
    }

    str.clear();
    int length = dna.size();
    char dist = 0;
    int d = 0;
    int mindist = 0;
    int A = 0, C = 0, G = 0, T = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < length; j++)
        {
            switch (dna[j][i])
            {
            case 'A':
            {
                A++;
                break;
            }
            case 'C':
            {
                C++;
                break;
            }
            case 'G':
            {
                G++;
                break;
            }
            case 'T':
            {
                T++;
                break;
            }
            }
        }
        d = A;
        dist = 'A';
        if (C > d)
        {
            d = C;
            dist = 'C';
        }
        else if (G > d)
        {
            d = G;
            dist = 'G';
        }
        else if (T > d)
        {
            d = T;
            dist = 'T';
        }
        str += dist;
        mindist += m - d;
        A = 0, C = 0, G = 0, T = 0;
    }
    std::cout << str << '\t' << mindist << std::endl;
}

int main()
{
    DNA();

    return 0;
}