#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
    int a,b,n,node;
    int A[100][100],D[100][100],L[100][100];
    float DD[100][100],LN[100][100];
    string const file("graph.txt");
    ofstream flow(file.c_str());
    cout<<"Entrer le nombre de sommets(noeuds): ";
    cin>>node;
    cout<<endl;
    cout<<"Entrer le nombre d'arcs(arretes): ";
    cin>>n;

    /***J'ecris les input dans un fichier et representation algebrique du graphe***/
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        flow<<a<<" "<<b<<endl;
    }

    /***Traitement pour trouver la matrice d'adjacence***/
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            A[i][j]=0;
        }
    }
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            ifstream find("graph.txt");
            while(!find.eof())
            {
                find>>a>>b;
                if((i==a && j==b) || (i==b && j==a)) {A[i][j]=1; break;}
            }
        }
    }
    cout<<endl;
    /***Affichage de la matrice d'adjacence***/
    cout<<"La MaTrIcE D'AdJaCeNcE: "<<endl;
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    /***Traitement pour trouver la matrice des degres***/
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            D[i][j]=0;
        }
    }
    for(int i=1;i<=node;i++)
    {
        int nb=0;
        ifstream find("graph.txt");
        while(!find.eof())
        {
            find>>a>>b;
            if(find.eof()) break;
            if(i==a || i==b) nb++;
        }
        D[i][i]=nb;
    }
    cout<<endl;
    /***Affichage de la matrice des degres***/
    cout<<"La MaTrIcE DeS DeGrEs: "<<endl;
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    /***Traitement de la matrice Laplacienne Non normalise***/
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            L[i][j]=D[i][j]-A[i][j];
        }
    }
    /***Affichage de la matrice Laplacienne Non normalise***/
    cout<<"La MaTrIcE LaPlAcIeNnE NoN NoRmAlIsE: "<<endl;
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    /***Traitement de la matrice Laplacienne normalise***/
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(D[i][j])
            DD[i][j]=pow(D[i][j],(-0.5));
        }
    }
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            LN[i][j]=0;
            for(int k=1;k<=node;k++)
                LN[i][j]+=L[i][k]*DD[k][j];
        }
    }

    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            for(int k=1;k<=node;k++)
                LN[i][j]+=DD[i][k]*LN[k][j];
        }
    }
    cout<<endl;
    /***Affichage de la matrice Laplacienne normalise***/
    cout<<"La MaTrIcE LaPlAcIeNnE NoRmAlIsE: "<<endl;
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
        {
            cout<<LN[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    return 0;
}
