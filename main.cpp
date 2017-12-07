#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

void RegLineaire(vector<float> x, vector<float>y, int n, double& a, double& b)

{
int i;
double xsomme, ysomme, xysomme, xxsomme;

double ai,bi;

xsomme = 0.0; ysomme = 0.0;

xysomme = 0.0; xxsomme = 0.0;

for (i=0;i<n;i++)
{
    xsomme = xsomme + x.at(i);
    ysomme = ysomme + y.at(i);
    xysomme = xysomme + x.at(i)*y.at(i);
    xxsomme = xxsomme + x.at(i)*x.at(i);
    }
ai = (n*xysomme - xsomme*ysomme)/(n*xxsomme - xsomme*xsomme);
bi = (ysomme - ai*xsomme)/n;
a = ai;
b = bi;
}
int main()
{
    ifstream f("C:\\Users\\Zied\\Desktop\\input.txt",ios::in);
    string ligne ;
    string d=" ";
    vector<float> abs;
    vector<float> cor;
    if(f==NULL)
    {
        cout<<"Fichier introuvable"<<endl;
    }
    else
    {
        while (getline(f,ligne))
        {
            string x1 = ligne.substr(0,ligne.find(d));
            string y1 = ligne.substr(ligne.find(d)+1);
            float x = atof(x1.c_str());
            abs.push_back(x);
            float y = atof(y1.c_str());
            cor.push_back(y);
        }
        f.close();
        double a,b;
        RegLineaire(abs,cor,abs.size(),a,b);
        cout<<"l'equation de la droite y="<<a<<"x+"<<b<<endl;
    }
    return 0;
}
