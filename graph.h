#include <bits/stdc++.h>
#include "airport.h"
using namespace std;
class Graph
{
    int nov; // number of vertices
    map<int, vector<int>> adj;

    map<pair<int, int>, pair<int, int>> cost; // pair 0-weight 1-time
public:
    Graph()
    {
        nov = 0;
    }
    Graph(int n)
    {
        nov = n;
    }
    void addedge(int u, int v, int wt, int tim)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // since it is undirected graph
        cost[{u, v}] = {wt, tim};
        cost[{v, u}] = {wt, tim};
    }
    friend void create_graph(Graph &);
    void display()
    {
        for (int i = 0; i < nov; i++)
        {
            cout << "vertex : " << i << " -- ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }

        cout << "cost\n";
        for (auto it : cost)
        {
            cout << it.first.first << "--" << it.first.second << "==" << it.second.first << " " << it.second.second << endl;
        }
    }
    void printQueue(priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q){
        while(!q.empty()){
            cout<<q.top().first<<" "<<q.top().second<<endl; 
            q.pop(); 
        }
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl; 
    }
    void djisktra(int src, int dest, int flag)
    {
        // flag 0-dist 1-time
        vector<int> distance(nov, INT_MAX);
        distance[src] = 0;
        vector<int> path(nov, -1);
        //deque<pair<int, int>> q;
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q ; 
        //q.push({src, 0});
        q.push({ 0 ,src })  ;
        while (!q.empty())
        {
           // printQueue(q) ; 
            // int node = q.front().first;
            // int dist = q.front().second;
            // q.pop_front();
            int node = q.top().second; 
            int dist = q.top().first ; 
            q.pop() ; 
            for (int i = 0; i < adj[node].size(); i++)
            {
                int adjnode = adj[node][i];

                int wt = (flag == 0) ? cost[{node, adjnode}].first : cost[{node, adjnode}].second;
                //cout<<adjnode<<" "<<wt<<endl; 
                if (dist + wt < distance[adjnode])
                {
                    //if(adjnode == dest) cout<<dist+wt<<endl; 
                    distance[adjnode] = dist + wt;
                    path[adjnode] = node;
                    //q.push({ adjnode , dist + wt });
                    q.push({distance[adjnode] , adjnode}) ; 
                }
            }
        }
        if (flag == 0)
        {
            cout << "\t\t\t*** Cheapest way to reach " << airport[dest].city_name() << " is " << distance[dest] << " rupees *** " << endl;
            cout << "\n";
        }
        else
        {
            cout << "\t\t\t*** Fatest way to reach " << airport[dest].city_name() << " is " << distance[dest] << " hrs *** " << endl;
            cout << "\n";
        }
        // for(int i=0;i<path.size();i++)
        // {
        //     cout<<path[i]<<"--";
        // }
        vector<int> route;
        int backtrack = dest;
        while (path[backtrack] != -1)
        {
            route.push_back(backtrack);
            backtrack = path[backtrack];
        }
        route.push_back(backtrack);
        cout << "\t\t\t\t\t\t**** Route ****" << endl;
        cout << endl;
        cout << "\t\t";
        for (int i = route.size() - 1; i >= 0; i--)
        {

            if (i != 0)
                cout << "[" << airport[route[i]].airport_name() << "] " << airport[route[i]].city_name() << " ---> ";
            else
                cout << "[" << airport[route[i]].airport_name() << "] " << airport[route[i]].city_name() << endl;
        }
        cout << endl;
    }
    void besttimeroute(int src, int dest)
    {
        deque<pair<int, int>> dq;
        dq.push_back({src, 0});
        vector<int> distance(nov, INT_MAX);
        distance[src] = 0;
        vector<int> path(nov, -1);
        dq.push_back({src, 0});
        while (!dq.empty())
        {
            int node = dq.front().first;
            int dist = dq.front().second;
            dq.pop_front();
            for (int i = 0; i < adj[node].size(); i++)
            {
                int adjnode = adj[node][i];
                int wt = 1;
                if (dist + wt < distance[adjnode])
                {
                    distance[adjnode] = dist + wt;
                    path[adjnode] = node;
                    if (wt == 1)
                    {
                        dq.push_back({adjnode, dist + wt});
                    }
                    else
                    {
                        dq.push_front({adjnode, dist + wt});
                    }
                }
            }
        }
        cout << "\t\t\t*** Best time to reach " << airport[dest].city_name() << " is " << distance[dest] << " stops ***" << endl; //////
        cout << endl;

        // this piece of code is reponsible for backtracking and finding the route
        // through which the user has to travel
        vector<int> route;
        int backtrack = dest;
        while (path[backtrack] != -1)
        {
            route.push_back(backtrack);
            backtrack = path[backtrack];
        }
        route.push_back(backtrack);

        cout << "\t\t\t\t\t\t**** Route ****" << endl;
        cout << endl;
        cout << "\t\t";
        for (int i = route.size() - 1; i >= 0; i--)
        {

            if (i != 0)
                cout << "[" << airport[route[i]].airport_name() << "] " << airport[route[i]].city_name() << " ---> "; //
            else
                cout << "[" << airport[route[i]].airport_name() << "] " << airport[route[i]].city_name() << endl; ///
        }
    }
};
void create_graph(Graph &g)
{
    int u[] = {0, 1, 1, 0, 1, 0, 2, 0, 0, 7, 7,
               3, 9, 10, 3, 14, 8, 8, 14, 15, 8, 5, 11, 12, 4, 4, 5, 7, 5};
    int v[] = {1, 2, 3, 2, 8, 6, 6, 3, 7, 9, 10,
               10, 15, 15, 14, 4, 4, 11, 5, 11, 10, 12, 12, 13, 13, 6, 4, 3, 11};
    int wt[] = {5145, 5211, 68938, 5680, 69450, 83175, 60175, 63599, 23794, 91580, 42741,
                13318, 95589, 101855, 459144, 91890, 15549, 97315, 186799, 196377, 15407, 16645, 138591, 47512, 53433,
                111824, 70999, 51591, 90150};
    int hrs[] = {2, 2, 9, 3, 11, 13, 13, 11, 5, 6, 7, 2, 15, 12, 14, 13, 2, 14, 21, 28, 2, 2, 14, 6, 11,23, 
                 7, 7, 13};
    for (int i = 0; i < sizeof(u) / sizeof(u[0]); i++)
    {
        g.addedge(u[i], v[i], wt[i], hrs[i]);
    }
}
