#include<stdio.h>
#include<cstdlib>
#include<vector>

using namespace std;

struct chromosome
{
    int a, b;
    double fitness ;

} temp, dvalue[6], par[6];

int binary[6][8];
int f(int a, int b){
    return 2*a*a + 3*b - 38 ;
}
void calculateFitness()
{
        for(int i = 0 ; i < 6 ; i++){
        int fVal = abs(f(dvalue[i].a, dvalue[i].b)) ;
        dvalue[i].fitness = 1.00/fVal ;


    }
}
void copyToPar(int x, int y){
    par[y].a = dvalue[x].a ;
    par[y].b = dvalue[y].b ;

    printf("parent : %d : %d \n",par[y].a,par[y].b);

}
void chooseParent(){
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0 ; j < 6 ; j++){
            if(dvalue[i].fitness < dvalue[j].fitness){
                temp = dvalue[i] ;
                dvalue[i] = dvalue[j] ;
                dvalue[j] = temp ;
            }
        }
    }

    int cur = 0 ;
    for(int i = 0 ; i < 6 ; i++){
        int randVal = rand() % 9 ;
        if(randVal == 0 || randVal == 6 || randVal == 7){
         copyToPar(0, i) ;
        }
        else if(randVal == 1 || randVal == 8)
            copyToPar(1, i) ;
        else if(randVal == 2)
            copyToPar(2, i) ;
        else if(randVal == 3)
            copyToPar(3, i) ;
        else if(randVal == 4)
            copyToPar(4, i) ;
        else if(randVal == 5)
            copyToPar(5, i) ;
    }
}
void crossOver(){

    for(int j=0;j<6;j++){
            int  a[5] = {};
            int i,h=0;
           int n =  par[j].a;
           int m =  par[j].b;
        printf("perent value : %d : %d \n",par[j].a, par[j].b);

            for(i=0; n>0; i++){
            a[i]=n%2;
            n= n/2;
            }
            for(i=4-1 ;i>=0 ;i--)
                {


                        binary[j][h]=a[i];
                        a[i] = 0;
                        h++;
                }
                    h=4;
             for(i=0; m>0; i++){
            a[i]=m%2;
            m= m/2;
            }
            for(i=4-1 ;i>=0 ;i--)
                {

                        binary[j][h]=a[i];
                        a[i] = 0;
                        h++;

                }
                    h=0;

    }
    for(int i=0;i< 6;i++){
            printf(" Before: ");
        for(int j =0;j< 8;j++){
            printf("%d\t",binary[i][j]);
        }
    printf("\n");
    }

    for(int i=0;i< 6;i= i +2 ){
        int y = rand()% 8;
        for(int j = y; j < 8; j++){
           int temp =  binary[i][j];
            int temp1 = binary[i+1][j];
            binary[i][j]= temp1;
            binary[i+1][j] = temp;
        }
    }
    for(int i=0;i< 6;i++){
            printf("After: ");
        for(int j =0;j< 8;j++){
            printf("%d\t",binary[i][j]);
        }
    printf("\n");
    }

}
void mutation(){
    for(int i =0;i<6;i++){
    int x = rand() % 6;
    int y = rand() % 7;

        if(binary[x][y] == 1 ){
            binary[x][y]=0;
        }
        else{
            binary[x][y]=1;
        }

    }
}
void binaryToDecimal(){

    int b=1;
    for(int j=0;j<6;j++){
            int dec_valueX = 0;
            int dec_valueY=0;
        for(int i =3;i>=0;i--){
            int last_digit = binary[j][i];

            dec_valueX += last_digit *b;
            b =b*2;
        }
        b=1;


        for(int i =7;i>=4;i--){
            int last_digit = binary[j][i];

            dec_valueY += last_digit *b;
            b = b*2;
        }
        b=1;
        if(f(dec_valueX , dec_valueY) == 0){
            printf("Solution %d %d\n", dec_valueX, dec_valueY) ;
           exit(0);
        }
    }
}
int main()
{
   int i, j ;
   for(i = 0 ; i < 6 ; i++){

    int x = rand() % 10 ;
    int y = rand() % 10 ;
    dvalue[i].a = x ;
    dvalue[i].b = y ;
    dvalue[i].fitness = 0 ;
   }

   for(i = 0 ; i < 300 ; i++){
    printf("Iteration: %d\n\n \n", i) ;
    for(j = 0 ; j < 6 ; j++){
        if(f(dvalue[j].a , dvalue[j].b) == 0){
            printf("Solution %d %d\n", dvalue[j].a, dvalue[j].b) ;
            return 0;
        }
    calculateFitness() ;
    chooseParent() ;
    crossOver() ;
    mutation() ;
     binaryToDecimal();
    }

   }

}
