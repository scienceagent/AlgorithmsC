#include <bits/stdc++.h>
using namespace std;

ifstream in("rucsac.in");
ofstream out("rucsac.out");
struct obiect{ float gr;
                int numar;
                int cost;
              };
obiect a[100];
int m,n;

void citire(obiect a[],int &n)
  {
    in>>n;
    in>>m;
   for(int i=1;i<=n;i++)
     {in>>a[i].gr;
      in>>a[i].cost;
      a[i].numar=i;
     }
  }

void afisare(obiect a[],int n)
  {
    std::cout<<"Lista : "<<endl;
    for(int i=1;i<=n;i++)
      out<<"Obiectul "<<a[i].numar<<" are greutatea "<<a[i].gr<<" costul de: "<<a[i].cost<<endl;
     cout<<endl;
  }

void sortare(obiect a[],int n)
  { int cont;
    obiect aux;
    do{
       cont=1;
       for(int i=1;i<=n-1;i++)
         if(a[i].cost<a[i+1].cost)
           {
             aux=a[i];
             a[i]=a[i+1];
             a[i+1]=aux;
             cont=0;}
         else
           if(a[i].cost==a[i+1].cost)
             if(a[i].gr>a[i+1].gr)
                 { aux=a[i];
                   a[i]=a[i+1];
                   a[i+1]=aux;
                   cont=0;}
      }while(cont==0);
}
void greedy(obiect a[],int n)
  {
    for(int i=1;i<=n;i++)
     if(a[i].gr<=m)
       {
         cout<<a[i].numar<<" ";
         m=m-a[i].gr;
        }
  }
int main(int argc, char const *argv[]) {
    citire(a,n);
   afisare(a,n);
   sortare(a,n);
   cout<<endl;
   afisare(a,n);
   cout<<"Greedy:";
   greedy(a,n);
   return 0;
}
