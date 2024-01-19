#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void oyuntahtasi(char harita[5][5]){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ",harita[i][j]);
        }
        printf("\n");
        
    }
    

}
void gemibatir(char harita[5][5],int satir,int sutun,int randsatir,int randsutun){
    if (satir == randsatir && sutun == randsutun)
    {
        harita[satir-1][sutun-1] = '+';
    }
    else{
        harita[satir-1][sutun-1] = 'O';
    }
    


}

int main(){
    char harita[5][5];
    int can = 5;
    int satir,sutun;
    srand(time(NULL));
    int randsat = rand()%5+1;
    int randsut = rand()%5+1;

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++)
        {
            harita[i][j] = '*';
        }
        
    }
    while (can>=0)
    {
        oyuntahtasi(harita);
        can--;
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
            if (satir == randsat && sutun == randsut)
            {
                oyuntahtasi(harita);
                printf("WIN");
                break;
            }
            
        }
        


    }
    

    

    return 0;
}