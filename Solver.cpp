#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0
#define N 9

bool UsedInRow(int grid[N][N],int row,int num){
    for(int col=0;col<N;col++)
        if(grid[row][col]==num) return true;
    return false;
}

bool UsedInCol(int grid[N][N],int col,int num){
    for(int row=0;row<N;row++)
        if(grid[row][col]==num) return true;
    return false;
}

bool UsedInBox(int grid[N][N],int boxStartRow,int boxStartCol,int num){
    for(int row=0;row<3;row++)
        for(int col=0;col<3;col++)
            if(grid[row+boxStartRow][col+boxStartCol]==num) return true;
    return false;
}

bool FindUnassignedLocation(int grid[N][N],int &row,int &col){
    for(row=0;row<N;row++)
        for(col=0;col<N;col++)
            if(grid[row][col]==UNASSIGNED) return true;
    return false;
}

bool isSafe(int grid[N][N],int row,int col,int num){
    return !UsedInRow(grid,row,num) && !UsedInCol(grid,col,num) && !UsedInBox(grid,row-row%3,col-col%3,num) && grid[row][col]==UNASSIGNED;
}

bool Solve(int grid[N][N]){
    int row,col;
    if(!FindUnassignedLocation(grid,row,col)) return true;
    for(int num=1;num<=9;num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;
            if(Solve(grid)) return true;
            grid[row][col]=UNASSIGNED;
        }
    }
    return false;
}

void printGrid(int grid[N][N]){
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++)
            cout<<grid[row][col]<<" ";
        cout<<endl;
    }
}

int main(){
    system("cls");
    int grid[N][N];
    cout<<"\nEnter the numbers in a Standard 9x9 Sudoku : \n\n";
    for(int i=0;i<N;i++){
        cout<<"Row "<<i+1<<":\n\n";
        for(int j=0;j<N;j++)
            cin>>grid[i][j];
        cout<<"\n";
    }
    cout<<"Sudoku Entered:\n\n";
    printGrid(grid);
    cout<<"\nSolution:\n";
    if(Solve(grid)) printGrid(grid);
    else cout<<"No Solution Exists.\n";
    cout<<endl;
    system("pause");
    return 0;
}