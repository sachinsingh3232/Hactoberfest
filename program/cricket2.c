#include<stdio.h>
#include<stdlib.h>

void get_players(char[15][20]);
void show_team(char[15][20] , int);
void select_player(short int* , char*);

int main()
{

    short int team11 = 0; 
    char count_selected = 0;
    /*  0 0000000000000000000000 to represent playing XI in 16bits
    0000000000000000000000 11 bits for setting player is playing or not
    */

    char players15[15][20];

    get_players(players15);
    while(count_selected < 11){
        show_team(players15 , team11);
        select_player(&team11, &count_selected);
    }

    show_team(players15 , team11);
    select_player(&team11, &count_selected);
    scanf("%d" , &team11);
    return 0;
}

void get_players(char player[15][20]){
    
    short int i = 0;
    printf("\t ========enter the name of players followed by enter ==== \n");
    for(i = 0; i<15 ; i++){
        printf("%d. ", i+1);
        scanf("%s", player[i]);
    }


}

void show_team(char players15[15][20], int team11)
{
    short int i;
    system("cls");
    printf("\n\t\t ======= Here is your team on left of 15 players and playing XI on right======== \n");
    printf("%-40s %4s| %-40s\n" , "Non Selected" ," ", "Playing XI");
    printf("%-40s %5s %-40s\n" , "------------" ," ", "----------");

    for(i = 0; i<15 ; i++){
        if(!(team11 & (1 << i))){
            printf("%2d. %-20s %20s|\n" , i+1 , players15[i] , " ");
        }else{
            printf("%44s |%2d. %-20s %20s\n" ," ", i+1 , players15[i] , " ");
        }
    }
   
}

void select_player(short int *team11 , char *count){
    int selected = 0;
    printf("\n\t No of selected players = %d , select %d more players \n" , *count , 11-*count);
    if(*count < 11){
        printf("Pls select players by typing number followed by enter");
        scanf("%d", &selected);
        if(selected >=1 && selected <= 15){
            if(!(*team11 & (1<<(selected-1)))){
            *team11 |= (1 << (selected-1));
            *count = *count + 1;
            }else{
                printf("already selected");
            }
        }
    }else{
        printf("\n\t You have selected 11 players no more you can select \n");
    }
}