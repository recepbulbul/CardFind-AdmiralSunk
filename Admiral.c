#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void oyuntahtasi(char harita[8][8]){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c ",harita[i][j]);
        }
        printf("\n");
        
    }
    

}
void gemibatir(char harita[8][8],int satir,int sutun,int randsatir,int randsutun){
    if (sutun == randsutun && (satir == randsatir|| satir == randsatir+1 || satir == randsatir-1))
    {
        harita[satir-1][sutun-1] = '+';
    }
    else{
        harita[satir-1][sutun-1] = 'O';
    }
    


}

int main(){
    char harita[8][8];
    int can = 15;
    int satir,sutun;
    srand(time(NULL));
    int randsat = rand()%7+1;
    int randsut = rand()%7+1;

    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++)
        {
            harita[i][j] = '*';
        }
        
    }
    while (can>=0)
    {
        oyuntahtasi(harita);
        can--;
        if (can<0)
        {
            printf("LOSE");
        }
        
        if (can>=0)
        {
            do
            {
                printf("Satir ve Sutun Giriniz(5-5): \n");
                scanf("%d%d",&satir,&sutun);
                if (harita[satir-1][sutun-1]=='O')
                {
                    printf("Ayni yere Ates ettiniz! \n");
                }
                
            } while (harita[satir-1][sutun-1] == 'O');
            
            gemibatir(harita,satir,sutun,randsat,randsut);
            if (harita[randsat-1][randsut-1] == '+' && harita[randsat][randsut-1] == '+' && harita[randsat-2][randsut-1] == '+')
            {
                oyuntahtasi(harita);
                printf("WIN");
                break;
            }
            
        }
        


    }
    

    

    return 0;
}