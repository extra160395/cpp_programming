// https://www.geeksforgeeks.org/find-the-minimum-cost-to-reach-a-destination-where-every-station-is-connected-in-one-direction/
#include<iostream> 
#include<climits> 
using namespace std; 
  
#define INF INT_MAX 
#define N 4 
  
int minCost(int cost[][N]) 
{  
    int dist[N]; 
    for (int i=0; i<N; i++) 
       dist[i] = INT_MAX; 
    dist[0]=0;
    dist[1]= cost[0][1]; 

    for (int i=2; i<N; i++) 
       for (int j=0; j<i; j++) 
             dist[i] = min(dist[j] + cost[j][i],dist[i]); 
  
    return dist[N-1]; 
} 
int main() 
{ 
    int cost[N][N] = { {0, 15, 80, 90}, 
                      {INF, 0, 40, 50}, 
                      {INF, INF, 0, 70}, 
                      {INF, INF, INF, 0} 
                    }; 
    cout << "The Minimum cost to reach station "
          << N << " is " << minCost(cost); 
    return 0; 
} 
