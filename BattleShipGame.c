//SOURCE CODE:-

/*------------PROGRAM FOR BATTLESHIP GAME---------------*/

#include <stdio.h>
#include <stdlib.h>

void display()
{
    printf("\n -----------WELCOME TO THE BATTLESHIP GAME-------------\n");

}

void startBoard(int board[][5])
{
    int line, column;
        for(line=0 ; line < 5 ; line++ )
            for(column=0 ; column < 5 ; column++ )
                board[line][column]=-1;
}

void showBoard(int board[][5])    //to show the display screen
{

    int line, column;

        printf("\t1 \t2 \t3 \t4 \t5");
        printf("\n");

        for(line=0 ; line <5 ; line++ ){
            printf("%d",line+1);
            for(column=0 ; column < 5 ; column++ ){
                if(board[line][column]==-1)
                    printf("\t-");
                else if(board[line][column]==0)  // IF IT DOESNOT HITS THE SHIP
                    printf("\tX");
                else if(board[line][column]==1)      //IF IT HITS THE SHIP
                    printf("\tH");
            }
            printf("\n");
        }

}

/* to check whether it is a hit or not by using srand() function*/

void startShips(int ships[][2])
   {
        srand(time(NULL));
        int ship, last;

        for(ship=0 ; ship < 3 ; ship++){
            ships[ship][0]= rand()%5;
            ships[ship][1]= rand()%5;
            
            //let's check if this shot was not tried
            //if it was, just get out of the 'do while' loop when draws a pair that was not tried
            for(last=0 ; last < ship ; last++) {
                  if( (ships[ship][0] == ships[last][0])&&(ships[ship][1] == ships[last][1]) )
                    do
                    {
                        ships[ship][0]= rand()%5;
                        ships[ship][1]= rand()%5;
                    }while( (ships[ship][0] == ships[last][0])&&(ships[ship][1] == ships[last][1]) );
        }
    }
}
// To display the line,column and hits(H)
void giveShot(int shot[2])
 {

        printf(" Enter Line No: ");
        scanf("%d",&shot[0]);
        shot[0]--;

        printf("Enter Column No: ");
        scanf("%d",&shot[1]);
        shot[1]--;

}

int hitship(int shot[2], int ships[][2])
{
    int ship;

        for(ship=0 ; ship < 3 ; ship++)
        {
            if( shot[0]==ships[ship][0] && shot[1]==ships[ship][1])
            {
                printf("Woah! You hit a ship with a shot. (%d,%d)\n",shot[0]+1,shot[1]+1);
                return 1;
            }
        }
        return 0;
}

//  count the no of ships and attempts
void tip(int shot[2], int ships[][2], int attempt)
{
        int line=0,
            column=0,
            i;

        //count how many ships there is line/column
        for(i=0 ; i< 3 ; i++)
        {
            if(ships[i][0]==shot[0])
                line++;
            if(ships[i][1]==shot[1])
                column++;
        }

        printf("DICA %d: \n",attempt);
}


// function to display board again
void changeBoard(int shot[2], int ships[][2], int board[][5])
     {
        if(hitship(shot,ships))
            board[shot[0]][shot[1]]=1;
      else
            board[shot[0]][shot[1]]=0;
    }


int main()
{
        int board[5][5];
        int ships[3][2];
        int shot[2];
        int attempts=0,
            hits=0;

        display();
        startBoard(board);
        startShips(ships);

        printf("\n");

        do
        {
            showBoard(board);
            giveShot(shot);
            attempts++;

            if(hitship(shot,ships))
            {
                tip(shot,ships,attempts);
                hits++;
            }
            else
                tip(shot,ships,attempts);
            
            changeBoard(shot,ships,board);


        }while(hits!=3);

        printf("\n\n\n\n\n\n\n ----------!!!GAME FINISHED!!!-------------\n");
         printf("\n\nYou hit the three ships in %d attempts\n", attempts);
        showBoard(board);
        
}
