#include <bits/stdc++.h>
#include "graph.h"
using namespace std;
void displaytable()
{
    cout<<"\n\n\n";
    cout<<"\t\t ";
    for(int i=0;i<17;i++)
    {
        cout<<"_ _";
    }
    cout<<endl;
    cout<<"\t\t|\tAirport Id\t\tAirport Names       |\n";
    for(int i=0;i<16;i++)
    {
        string tem=airport[i].city_name();
        int slen=tem.length();
        cout<<"\t\t|\t  "<<i<<"\t\t\t  "<<tem;
        for(int i=0;i<18-slen;i++)
        {
            cout<<" ";
        }
        cout<<"|\n";
    }
    cout<<"\t\t ";
    for(int i=0;i<17;i++)
    {
        cout<<"_ _";
    }
    cout<<"\n\n\n";
}
void sdcities(int src,int des)
{
    cout<<"\t\t\t";
    for(int i=0;i<10;i++)
    {
        cout<<" _ _";
    }
    cout<<endl;
    
    string tem=airport[src].city_name();
    int slen=tem.length();
    cout<<"\t\t\t| Start city          :   "<<tem;
    for(int i=0;i<14-slen;i++)
    {
        cout<<" ";
    }
    cout<<"|\n";
    
    tem=airport[des].city_name();
     slen=tem.length();
     cout<<"\t\t\t| Destination city    :   "<<tem;
    for(int i=0;i<14-slen;i++)
    {
        cout<<" ";
    }
    cout<<"|\n";
    cout<<"\t\t\t";
    for(int i=0;i<10;i++)
    {
        cout<<" _ _";
    }
    cout<<endl;
}

int main()
{
    cout<<"\t\t\t\tOPTIMAL AVIATION\t\t\t\t\t\t\t\n";
    cout<<"\t\t\tNavigational guidance to air travellers...\t\t\t\t\n";
    cout<<"\t\t\t\t\t\t\t\tTeam Members : Dinesh A\n\t\t\t\t\t\t\t\t               Kanivan S\n\t\t\t\t\t\t\t\t               Sourav Kumar N R S\n";
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\tPlanning a journey!\n";
    Graph g(n);
    cout<<"number of nodes :"<<n<<endl; 
    create_graph(g);
    create_airports();
    int flag;
    do
    {
        displaytable();
        int src ;
        cout<<"\t\tChoose the start city       : ";
        cin>>src;
        if(!(src>=0 && src<16)){
            cout<<"\t\tInvalid source choice!!!"<<endl; 
            continue ; 
        }
        int dest;
        cout<<"\t\tChoose the destination city : " ; cin>>dest;
        if(!(dest>=0 && dest<16)){
            cout<<"\t\tInvalid destination choice!!!"<<endl; 
            continue ; 
        }
        sdcities(src,dest);
        cout<<"\n";
        g.besttimeroute(src,dest) ;
        cout<<"\n";
        g.djisktra(src, dest,0);
        g.djisktra(src,dest,1);
        cout<<"\t\tTo stop enter 0 or 1 to continue : ";
        cin>>flag;
    }
    while(flag!=0);
    cout<<"\n\n\t\t\t\tThank You!\t\t\t\t\t\t\t\n";
}
