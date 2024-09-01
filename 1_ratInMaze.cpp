#include<iostream>
using namespace std;
bool ratinmaze(char maze[][5], int i , int j, int n , int m , int sol[][10]){
    // base cas
if (i == n-1 and j == m-1){
    sol[i][j]= 1;
    for(int i= 0; i<n; i++){
        for(int j= 0; j<m ; j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
        cout << endl;
        return false;
    
}
    // recursive case
    sol[i][j] =1;
    if(j+1 <m and maze[i][j+1]!= 'x'){
        bool kyrightsemila = ratinmaze(maze, i, j+1,n,m ,sol);
        if(kyrightsemila) return true;
    }
    if(i+1 <n and maze[i+1][j] !='x'){
        bool kyadownsemila = ratinmaze(maze, i+1, j,n,m ,sol);
        if(kyadownsemila) return true;
    }
    sol[i][j]= 0;
    return false;
}
int main(){
    char maze[][5] ={
        "0000",
        "00xx",
        "0000",
        "xx00", 
    };
    int sol[10][10] = {0};
    ratinmaze(maze, 0 , 0, 4, 5, sol) ;
    return 0;
}