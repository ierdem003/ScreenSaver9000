#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void bruh(void);
void initializeGrid(int gridX, int gridY, char grid[gridY][gridX], char bg);
void printGrid(int gridX, int gridY, char grid[gridY][gridX]);
void moveSymbol(int gridX, int gridY, int* posX, int* posY, int* directionX, int* directionY);


int main(void){

    int gridX=40, gridY=17, posX=5, posY=6, directionX =1, directionY =1;
    char grid[gridY][gridX], bg ='.', symbol ='*';
    initializeGrid(gridX,gridY,grid,bg);
    //printGrid(gridX,gridY,grid);
    

    //bruh();

    while(1){
        grid[posY][posX]=symbol;
        printf("\033[H");
        printGrid(gridX,gridY,grid);
        fflush(stdout);
        usleep(100000);
        grid[posY][posX]=bg; 
        moveSymbol(gridX,gridY,&posX,&posY,&directionX,&directionY);
        


    }

}

void bruh(){
    printf("bruh");
}
void initializeGrid(int gridX, int gridY, char grid[gridY][gridX], char bg){

    for(int i = 0 ; i < gridY ; i++){
        for(int j = 0 ; j < gridX ; j++){
            grid[i][j]= bg;
        }
        
    }
    
}
void printGrid(int gridX, int gridY, char grid[gridY][gridX]){

    for(int i = 0 ; i < gridY ; i++){
        for(int j = 0 ; j < gridX ; j++){
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
    
}

void moveSymbol(int gridX, int gridY, int* posX, int* posY, int* directionX, int* directionY){

    //check collisons then move

 if( *posX + *directionX == gridX || *posX + *directionX == -1 ){
    *directionX*=-1;
 }
  if( *posY + *directionY == gridY || *posY + *directionY == -1 ){
    *directionY*=-1;
 }

    *posX += *directionX ;
    *posY += *directionY ;


}