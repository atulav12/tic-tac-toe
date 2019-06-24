#include<bits/stdc++.h>
using namespace std;

map<int, pair<int,int> > m;
char board[3][3];

void f()
{
   int i,j,k=1;
   
   for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
           //pair<int,int> p[1];
          m[k].first=i;m[k].second=j;
           k++;
       }
   }
}



void showBoard() 
{ 
    printf("\n\n"); 
      
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0], 
                             board[0][1], board[0][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0], 
                             board[1][1], board[1][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0], 
                             board[2][1], board[2][2]); 
   
    return; 
} 
  
// A function to show the instructions 
void showInstructions() 
{ 
    printf("Tic-Tac-Toe\n\n"); 
    printf("Choose a cell numbered from 1 to 9 as below"
            " and play\n\n"); 
      
    printf("\t\t\t  1 | 2  | 3  \n"); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  4 | 5  | 6  \n"); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  7 | 8  | 9  \n\n"); 
      
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"); 
  
    return; 
} 

void initialise()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        board[i][j]=' ';
    }
    
}

bool rowcross(int n)
{
    int i,c=0;
    char ch;
    
    if(n%2==0)
    ch='0';
    else
    ch='*';
    
    for(i=0;i<3;i++)
    {
        if(board[0][i]==ch&&board[1][i]==ch&&board[2][i]==ch)
        {
            c++;
            break;
        }
    }
    if(c>0)
    return true;
    
    return false;
}

bool columncross(int n)
{
    int i,c=0;
    char ch;
    
    if(n%2==0)
    ch='0';
    else
    ch='*';
    
    for(i=0;i<3;i++)
    {
        if(board[i][0]==ch&&board[i][1]==ch&&board[i][2]==ch)
        {
            c++;
            break;
        }
    }
    if(c>0)
    return true;
    
    return false;
}

bool diagonalcross(int n)
{
    int i,c=0;
    char ch;
    
    if(n%2==0)
    ch='0';
    else
    ch='*';
    i=0;
    if(board[i][i]==ch&&board[i+1][i+1]==ch&&board[i+2][i+2]==ch)
    {
        c++;
        
    }
    
    if(board[0][2]==ch&&board[1][1]==ch&&board[2][0]==ch)
    c++;
    
    if(c>0)
    return true;
    
    return false;
}
bool CheckForWinner(int n)
{
    bool p= rowcross(n) | columncross(n) |  diagonalcross(n);
    return p;
}

int main()
{
    f();
    initialise();
    int i,j,k,n=0,p=0,c=0;
    cout<<"\n\nC'mon guyz lets play tic tac toe on this fantastic platform !!!\n\nFirst lets just go through the rules and regulations of the game.\n\n";
    showInstructions();
    cout<<"\n\nNow lets start playing.";
    char confirm;
    while(n<9)
    {
        if(n%2==0)
        {
            cout<<"\n\nPlayer 1 enter your choice.\n";
            cin>>k;
            cout<<"\nPlayer 1 you have entered-"<<k<<". \n\nAre you sure to continue with this ?(Y/N)";
        }
        else
        {
            cout<<"\n\nPlayer 2 enter your choice.\n";
            cin>>k;
            cout<<"\nPlayer 2 you have entered-"<<k<<".\n\nAre you sure to continue with this ?(Y/N)";
        }
        cin>>confirm;
        if(confirm=='N')
        continue;
        
        if(n%2==0)
        board[m[k].first][m[k].second]='0';
        else
        board[m[k].first][m[k].second]='*';
        
        showBoard();
        
        bool t=CheckForWinner(n);
        if(t)
        {
            cout<<" \n\n\n\n\n\n\n\n\n                                                           Congratulations !!!!\n  \n\n\nThe winner is Player ";
            if(n%2==0)
            cout<<"1.";
            else
            cout<<"2 ";
            cout<<endl;
            break;
        }
        n++;
    }
    if(n>=9)
    cout<<"\n\nMatch is tied !!!.";
    
}

