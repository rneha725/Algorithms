#include <iostream>
#define SIZE 1

using namespace std;

int arr[SIZE][SIZE];

//================= Functions in Program ========================//
bool place(int row_i, int col_j);
bool checkSafe(int row_i, int col_j);
void putInRow(int i_th);
void display(int arr[][SIZE]);
void initializeArrayToZero(int arr[][SIZE]);

// Main =========================================================//
int main()
{
    initializeArrayToZero(arr);
    //putting of queeens starts from 0-th row.
    putInRow(0);
    display(arr);
}
//===============================================================//

void initializeArrayToZero(int arr[][SIZE])
{
    for(int i = 0; i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            arr[i][j]=0;
        }
    }
}

void  putInRow(int i)
{
    if(i==SIZE) return;
    int flag = 0;
    for(int j=0; j<SIZE;j++)
    {
        if(checkSafe(i,j) && place(i,j))
        {
            //if the current cell is safe as well as placing is new.
            flag=1;
            break;
        }
    }
    if(!flag)
    {
        //unsuccessful placing, backtrack to i-1 th row and reinitialize
        //the current row to have a fresh start from i-1 th row
        for(int j=0;j<SIZE;j++) arr[i][j]=0;
        putInRow(i-1);
    }
    else
    {
        //successfully placed queen in ith row.
        putInRow(i+1);
    }
}

bool checkSafe(int i, int j)
{
    //check if the i-th row or j-th column contains any queen
    for(int k=0;k<SIZE-1; k++)
    {
        if(arr[k][j]==1 && k!=i) return false;
        if(arr[i][k]==1 && k!=j) return false;
    }
    //check the lower part of the diagnol which is like a forward-slash(\)
    for(int k = i+1, l = j+1; k<=(SIZE-1) && l<=(SIZE-1); k++, l++)
    {
        if(arr[k][l]==1) return false;
    }
    // check the upper part of the diagnol seems like a forward-slash(\)
    for(int k = i-1, l = j-1; k>=0 && l>=0; k--, l--)
    {
        if(arr[k][l]==1) return false;
    }
    //checks the upper part of the other diagnol
    for(int k = i-1, l = j+1; k>=0 && l<=(SIZE-1); k--, l++)
    {
        if(arr[k][l]==1) return false;
    }
    //checks the lower part of the other diagnol
    for(int k = i+1, l = j-1; k<=(SIZE-1) && l>=0; k++, l--)
    {
        if(arr[k][l]==1) return false;
    }
    //if everything is fine then state that the current cell is safe for
    // a queen.
    return true;
}

bool place(int i, int j)
{
    //if queen was placed previously.
    if(arr[i][j] == 1)
    {
        arr[i][j] = -1;
        return false;
    }
    //-1: queen cannot be placed, because at some time this place was chosen
    else if(arr[i][j] == -1)
        return false;
    //if current cell value is zero means a fresh cell.
    else
    {
        arr[i][j]=1;
        return true;
    }
}

void display(int arr[][SIZE])
{
    //make all -1's in the matrix to zero
    for(int i=0;i<SIZE;i++)
        for(int j = 0; j<SIZE;j++)
        {
            if(arr[i][j]==1);
            else arr[i][j]=0;
        }
    cout<<"\n";
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j<SIZE; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
