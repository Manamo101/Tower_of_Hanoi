#include <iostream>

using namespace std;


int main()
{
    string najmn_krazek, najmn_krazek2;
    int n;
    bool parzystosc, skonczony=true;
    cout<<"Podaj liczbe krazkow: ";
    cin>>n;
    if (n%2==1) parzystosc=false;
    else parzystosc=true;
    int A[n], B[n], C[n];
    for (int x=0; x<n; x++) A[x]=x+1;
    for (int x=0; x<n; x++) {B[x]=0; C[x]=0;}

    cout<<endl<<"A\tB\tC\t"<<endl;
    for (int x=0; x<n; x++) cout<<A[x]<<"\t"<<B[x]<<"\t"<<C[x]<<endl;

    do
    {
        for (int y=n-1; y>=0; y--)
        {
            if (A[y]==1) {najmn_krazek="A"; break;}
            if (B[y]==1) {najmn_krazek="B"; break;}
            if (C[y]==1) {najmn_krazek="C"; break;}
        }
        if (parzystosc==false)
        {
            if (najmn_krazek=="A")
            {
                int x, y;
                for (x=n-1; x>=0; x--) if (A[x]==1) break;
                for (y=n-1; y>=0; y--) if (B[y]==0) {swap(A[x],B[y]); break;}
                najmn_krazek2="B";
            }
            if (najmn_krazek=="B")
            {
                int x, y;
                for (x=n-1; x>=0; x--) if (B[x]==1) break;
                for (y=n-1; y>=0; y--) if (C[y]==0) {swap(B[x],C[y]); break;}
                najmn_krazek2="C";
            }
            if (najmn_krazek=="C")
            {
                int x, y;
                for (x=n-1; x>=0; x--) if (C[x]==1) break;
                for (y=n-1; y>=0; y--) if (A[y]==0) {swap(C[x],A[y]); break;}
                najmn_krazek2="A";
            }
        }
        else
        {
            if (najmn_krazek=="A")
            {
                int x, y;
                for (x=n-1; x>=0; x--) if (A[x]==1) break;
                for (y=n-1; y>=0; y--) if (C[y]==0) {swap(A[x],C[y]); break;}
                najmn_krazek2="C";
            }
            if (najmn_krazek=="B")
            {
                    int x, y;
                    for (x=n-1; x>=0; x--) if (B[x]==1) break;
                    for (y=n-1; y>=0; y--) if (A[y]==0) {swap(B[x],A[y]); break;}
                    najmn_krazek2="A";
            }
            if (najmn_krazek=="C")
            {
                    int x, y;
                    for (x=n-1; x>=0; x--) if (C[x]==1) break;
                    for (y=n-1; y>=0; y--) if (B[y]==0) {swap(C[x],B[y]); break;}
                    najmn_krazek2="B";
            }
        }
        cout<<endl<<"A\tB\tC\t"<<endl;
        
        for (int x=0; x<n; x++) cout<<A[x]<<"\t"<<B[x]<<"\t"<<C[x]<<endl;

//////////////////////////////////////////////////////////////
        int czy_skonczony=0;
        for (int x=0; x<n; x++)
        {
            if (B[x]!=0) czy_skonczony++;
        }
        if (czy_skonczony==n) {skonczony=0; break;}

////////////////////////////////////////////////////////////////////
        if (najmn_krazek2=="A")
        {
            int i,j, czy_pusty=0;
            string pusty_palik;
            for (i=0; i<n; i++)
            {
                if (B[i]!=0) break;
                else czy_pusty++;
            }
            if (czy_pusty==n) pusty_palik="B";

            czy_pusty=0;
            for (j=0; j<n; j++)
            {
                if (C[j]!=0) break;
                else czy_pusty++;
            }
            if (czy_pusty==n) pusty_palik="C";

            if (B[i]<C[j] && pusty_palik!="B" && pusty_palik!="C") swap(B[i],C[j-1]);
            if (B[i]>C[j] && pusty_palik!="B" && pusty_palik!="C") swap(C[j],B[i-1]);
            if (pusty_palik=="B") swap(B[n-1],C[j]);
            if (pusty_palik=="C") swap(C[n-1],B[i]);
        }

        if (najmn_krazek2=="B")
        {
            int i,j,czy_pusty=0;
            string pusty_palik;
            for (i=0; i<n; i++)
            {
                if (A[i]!=0) break;
                else czy_pusty++;
            }
            if (czy_pusty==n) pusty_palik="A";

            czy_pusty=0;
            for (j=0; j<n; j++)
            {
                if (C[j]!=0) break;
                else czy_pusty++;
            }
            if (czy_pusty==n) pusty_palik="C";

            if (A[i]<C[j] && pusty_palik!="A" && pusty_palik!="C") swap(A[i],C[j-1]);
            if (A[i]>C[j] && pusty_palik!="A" && pusty_palik!="C") swap(C[j],A[i-1]);
            if (pusty_palik=="A") swap(A[n-1],C[j]);
            if (pusty_palik=="C") swap(C[n-1],A[i]);
        }

        if (najmn_krazek2=="C")
        {
            int i,j, czy_pusty=0;
            string pusty_palik;
            for (i=0; i<n; i++)
            {
                if (A[i]!=0) break;
                else czy_pusty++;
            }
            if (czy_pusty==n) pusty_palik="A";

            czy_pusty=0;
            for (j=0; j<n; j++)
            {
                if (B[j]!=0) break;
                else czy_pusty++;
            }
            if (czy_pusty==n) pusty_palik="B";

            if (B[j]<A[i] && pusty_palik!="A" && pusty_palik!="B") swap(B[j],A[i-1]);
            if (B[j]>A[i] && pusty_palik!="A" && pusty_palik!="B") swap(A[i],B[j-1]);
            if (pusty_palik=="B") swap(B[n-1],A[i]);
            if (pusty_palik=="A") swap(A[n-1],B[j]);
        }

        cout<<endl<<"A\tB\tC\t"<<endl;
        for (int x=0; x<n; x++) cout<<A[x]<<"\t"<<B[x]<<"\t"<<C[x]<<endl;
    }
    while (skonczony);
    return 0;
}
