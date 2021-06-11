#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "include/Card.c"
#include <SDL2/SDL.h>
#include <math.h>

// Get a random number between 0 and 255
void renderScreen(SDL_Renderer* rendrer){
    SDL_RenderPresent(rendrer);
}

void moveCard(card* c,Element** listsrc,Element** listdist,card** LeftCol){

    if(c != NULL){
        if(LeftCol == NULL && listdist != NULL){
            if(*listdist != NULL){
                card* temp = pop_back(listdist);
                if(temp->num + 1 == c->num && temp->type == c->type ){
                    addcard(temp,listdist);
                    addcard(c,listdist);
                    

                }
                else{
                    addcard(temp,listdist);
                    addcard(c,listsrc);
                }
            }else{
                if(c->num == 1)
                    addcard(c,listdist);
                else{
                    addcard(c,listsrc);
                }


            }

        }
        if(LeftCol != NULL && listdist == NULL){
            if(*LeftCol == NULL)
                *LeftCol=c;
        }
    }
}

void setStackFromDek(Element** dek,Element** listCol){
        card* c = peek(*dek);
        pop(dek);
        addcard(c,listCol);
}


void DisplayCol(SDL_Renderer* renderer,Element** listcol,SDL_Rect* colcopy,SDL_Rect* rect){
     Element* temp;
    // Check for stack underflow
    if (*listcol == NULL)
    {
        return;
    }
    else
    {
        temp = *listcol;
        while (temp != NULL)
        {
            temp->c->rect = *colcopy;
            SDL_RenderCopy(renderer, temp->c->txture, rect,&(temp->c->rect));
            colcopy->y+=20;
            temp = temp->next;
        }
        
    }
}
void DisplayRightCol(SDL_Renderer* renderer,Element** listcol,SDL_Rect* colcopy,SDL_Rect* rect){
     Element* temp;
    // Check for stack underflow
    if (*listcol == NULL)
    {
        return;
    }
    else
    {
        temp = *listcol;
        while (temp != NULL)
        {
            temp->c->rect = *colcopy;
            SDL_RenderCopy(renderer, temp->c->txture, rect,&(temp->c->rect));
            temp = temp->next;
        }
        
    }
}
void displayCard(SDL_Renderer* renderer,card* c,SDL_Rect* colcopy,SDL_Rect* rect){
            c->rect = *colcopy;
            SDL_RenderCopy(renderer, c->txture, rect,&(c->rect));
}
void resetPlacementVar(SDL_Rect* col1copy,SDL_Rect* col2copy,SDL_Rect* col3copy,SDL_Rect* col4copy,SDL_Rect* col5copy,SDL_Rect* col6copy,SDL_Rect* col7copy,SDL_Rect* col8copy,SDL_Rect*  colRight1copy,SDL_Rect* colRight2copy,SDL_Rect* colRight3copy,SDL_Rect* colRight4copy,SDL_Rect* colLeft1copy,SDL_Rect* colLeft2copy,SDL_Rect* colLeft3copy,SDL_Rect* colLeft4copy,SDL_Rect col1,SDL_Rect col2,SDL_Rect col3,SDL_Rect col4,SDL_Rect col5,SDL_Rect col6,SDL_Rect col7,SDL_Rect col8,SDL_Rect colRight1,SDL_Rect colRight2,SDL_Rect colRight3,SDL_Rect colRight4,SDL_Rect colLeft1,SDL_Rect colLeft2,SDL_Rect colLeft3,SDL_Rect colLeft4){

    *col1copy=col1;
    *col2copy=col2;
    *col3copy=col3;
    *col4copy=col4;
    *col5copy=col5;
    *col6copy=col6;
    *col7copy=col7;
    *col8copy=col8;

    *colLeft1copy = colLeft1;
    *colLeft2copy = colLeft2;
    *colLeft3copy = colLeft3;
    *colLeft4copy = colLeft4;

    *colRight1copy = colRight1;
    *colRight2copy = colRight2;
    *colRight3copy = colRight3;
    *colRight4copy = colRight4;



}
void displayallscreen(SDL_Renderer* renderer,SDL_Texture* texture,Element** listcol1,SDL_Rect col1,SDL_Rect* col1copy,Element** listcol2,SDL_Rect col2,SDL_Rect* col2copy,Element** listcol3,SDL_Rect col3,SDL_Rect* col3copy,Element** listcol4,SDL_Rect col4,SDL_Rect* col4copy,Element** listcol5,SDL_Rect col5,SDL_Rect* col5copy,Element** listcol6,SDL_Rect col6,SDL_Rect* col6copy,Element** listcol7,SDL_Rect col7,SDL_Rect* col7copy,Element** listcol8,SDL_Rect col8,SDL_Rect* col8copy,Element** listRightcol1,SDL_Rect colRight1,SDL_Rect* colRight1copy,Element** listRightcol2,SDL_Rect colRight2,SDL_Rect* colRight2copy,Element** listRightcol3,SDL_Rect colRight3,SDL_Rect* colRight3copy,Element** listRightcol4,SDL_Rect colRight4,SDL_Rect* colRight4copy,Element* LeftCol1,SDL_Rect colLeft1,SDL_Rect* colLeft1copy,Element* LeftCol2,SDL_Rect colLeft2,SDL_Rect* colLeft2copy,Element* LeftCol3,SDL_Rect colLeft3,SDL_Rect* colLeft3copy,Element* LeftCol4,SDL_Rect colLeft4,SDL_Rect* colLeft4copy,SDL_Rect* rect){
        
        resetPlacementVar(col1copy,col2copy,col3copy,col4copy,col5copy,col6copy,col7copy,col8copy,colRight1copy,colRight2copy,colRight3copy,colRight4copy,colLeft1copy,colLeft2copy,colLeft3copy,colLeft4copy, col1, col2, col3, col4, col5, col6, col7, col8, colRight1, colRight2, colRight3, colRight4,colLeft1, colLeft2, colLeft3, colLeft4);
        SDL_RenderClear(renderer);
        SDL_SetRenderTarget(renderer, texture);
	    SDL_RenderCopy(renderer, texture, NULL, NULL);

        if(listcol1 != NULL) DisplayCol(renderer,listcol1,col1copy,rect);

        if(listcol2 != NULL) DisplayCol(renderer,listcol2,col2copy,rect);

        if(listcol3 != NULL) DisplayCol(renderer,listcol3,col3copy,rect);

        if(listcol4 != NULL) DisplayCol(renderer,listcol4,col4copy,rect);

        if(listcol5 != NULL) DisplayCol(renderer,listcol5,col5copy,rect);

        if(listcol6 != NULL) DisplayCol(renderer,listcol6,col6copy,rect);

        if(listcol7 != NULL) DisplayCol(renderer,listcol7,col7copy,rect);

        if(listcol8 != NULL) DisplayCol(renderer,listcol8,col8copy,rect);

        if(listRightcol1 != NULL) DisplayRightCol(renderer,listRightcol1,colRight1copy,rect);

        if(listRightcol2 != NULL) DisplayRightCol(renderer,listRightcol2,colRight2copy,rect);

        if(listRightcol3 != NULL) DisplayRightCol(renderer,listRightcol3,colRight3copy,rect);

        if(listRightcol4 != NULL) DisplayRightCol(renderer,listRightcol4,colRight4copy,rect);

        if(LeftCol1 != NULL) displayCard(renderer,LeftCol1,colLeft1copy,rect);

        if(LeftCol2 != NULL) displayCard(renderer,LeftCol2,colLeft2copy,rect);

        if(LeftCol3 != NULL) displayCard(renderer,LeftCol3,colLeft3copy,rect);

        if(LeftCol4 != NULL) displayCard(renderer,LeftCol4,colLeft4copy,rect);

        SDL_SetRenderTarget(renderer, NULL);
        renderScreen(renderer);
}

SDL_Rect* getTarget(int mouse_x,int mouse_y,SDL_Rect col1,SDL_Rect col2,SDL_Rect col3,SDL_Rect col4,SDL_Rect col5,SDL_Rect col6,SDL_Rect col7,SDL_Rect col8,SDL_Rect colLeft1,SDL_Rect colLeft2,SDL_Rect colLeft3,SDL_Rect colLeft4,SDL_Rect colRight1,SDL_Rect colRight2,SDL_Rect colRight3,SDL_Rect colRight4){
    SDL_Rect mouse={mouse_x,mouse_y};
    SDL_Rect T[16]={col1,col2,col3,col4,col5,col6,col7,col8,colLeft1,colLeft2,colLeft3,colLeft4,colRight1,colRight2,colRight3,colRight4};
    float temp=999999;
    float tempcurrent=0;
    SDL_Rect* ret = (SDL_Rect*) malloc(sizeof(SDL_Rect));
    ret->x = 2000;ret->y = 2000; 
    for(int i=0;i<16;i++){
        tempcurrent = sqrt((pow((mouse.x-T[i].x),2))+(pow((mouse.y-T[i].y),2)));
        if( (mouse.x - T[i].x < 80)&& (mouse.x - T[i].x > 0) && (mouse.y - T[i].y < 400) && (tempcurrent < temp)){
            temp = tempcurrent;
            *ret = T[i];
        }
    }
    return ret;
}

int main(int argc, char** argv)
{
	

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Open a 800x600 window and define an accelerated renderer
    // Build screen with background
    SDL_Window* window = SDL_CreateWindow("FREECELL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Surface *background = SDL_LoadBMP("textures/bk.bmp");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,background);
	SDL_SetRenderTarget(renderer, texture);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	//----------------------------------------------------------------------------------------------------
    SDL_Rect col1 = {44, 330, 80, 140};
    SDL_Rect col1copy = col1;
    SDL_Rect col2 = {134, 330, 80, 140};
    SDL_Rect col2copy = col2;
    SDL_Rect col3 = {224, 330, 80, 140};
    SDL_Rect col3copy = col3;
    SDL_Rect col4 = {310, 330, 80, 140};
    SDL_Rect col4copy = col4;
    SDL_Rect col5 = {400, 330, 80, 140};
    SDL_Rect col5copy = col5;
    SDL_Rect col6 = {488, 330, 80, 140};
    SDL_Rect col6copy = col6;
    SDL_Rect col7 = {578, 330, 80, 140};
    SDL_Rect col7copy = col7;
    SDL_Rect col8 = {665, 330, 80, 140};
    SDL_Rect col8copy = col8;

    SDL_Rect colLeft1 = {15, 74, 80, 140};
    SDL_Rect colLeft1copy = colLeft1;
    SDL_Rect colLeft2 = {105, 74, 80, 140};
    SDL_Rect colLeft2copy = colLeft2;
    SDL_Rect colLeft3 = {193, 74, 80, 140};
    SDL_Rect colLeft3copy = colLeft3;
    SDL_Rect colLeft4 = {282, 74, 80, 140};
    SDL_Rect colLeft4copy = colLeft4;

    SDL_Rect colRight1 = {441, 75, 80, 140};
    SDL_Rect colRight1copy = colRight1;
    SDL_Rect colRight2 = {531, 75, 80, 140};
    SDL_Rect colRight2copy = colRight2;
    SDL_Rect colRight3 = {620, 75, 80, 140};
    SDL_Rect colRight3copy = colRight3;
    SDL_Rect colRight4 = {707, 75, 80, 140};
    SDL_Rect colRight4copy = colRight4;

    SDL_Rect rect = {0, 0, 800, 600};
    Element* dek = GenerateDek(renderer);
    Element* listcol1 = NULL;
    Element* listcol2 = NULL;
    Element* listcol3 = NULL;
    Element* listcol4 = NULL;
    Element* listcol5 = NULL;
    Element* listcol6 = NULL;
    Element* listcol7 = NULL;
    Element* listcol8 = NULL;

    card* LeftCol1 = NULL;
    card* LeftCol2 = NULL;
    card* LeftCol3 = NULL;
    card* LeftCol4 = NULL;
    int mouse_x = 0;
    int mouse_y = 0;

    Element* listRightcol1 = NULL;
    Element* listRightcol2 = NULL;
    Element* listRightcol3 = NULL;
    Element* listRightcol4 = NULL;
   
    for(int i=0;i<7;i++){

        setStackFromDek(&dek,&listcol1);
        setStackFromDek(&dek,&listcol2);
        setStackFromDek(&dek,&listcol3);
        setStackFromDek(&dek,&listcol4);
        
        if(i != 6){
            setStackFromDek(&dek,&listcol5);
            setStackFromDek(&dek,&listcol6);
            setStackFromDek(&dek,&listcol7);
            setStackFromDek(&dek,&listcol8);
        }
    }
        displayallscreen(renderer,texture,&listcol1,col1,&col1copy,&listcol2,col2,&col2copy,&listcol3,col3,&col3copy,&listcol4,col4,&col4copy,&listcol5,col5,&col5copy,&listcol6,col6,&col6copy,&listcol7,col7,&col7copy,&listcol8,col8,&col8copy,&listRightcol1,colRight1,&colRight1copy,&listRightcol2,colRight2,&colRight2copy,&listRightcol3,colRight3,&colRight3copy,&listRightcol4,colRight4,&colRight4copy,LeftCol1,colLeft1,&colLeft1copy,LeftCol2,colLeft2,&colLeft2copy,LeftCol3,colLeft3,&colLeft3copy,LeftCol4,colLeft4,&colLeft4copy,&rect);
        
        
        

    bool running = true;
    bool flag = false;
    SDL_Event event;
    Element** srcList = NULL;
    card** srcCard = NULL;
    Element** distList = NULL;
    card** distCard = NULL;
    while (running)
    {
        // Check for various events (keyboard, mouse, touch, close)
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {  
                if(flag == false){
                    srcList = NULL;
                    srcCard = NULL;
                    mouse_x = event.motion.x;
                    mouse_y = event.motion.y;
                    SDL_Rect* pos = getTarget(mouse_x,mouse_y,col1,col2,col3,col4,col5,col6,col7,col8,colLeft1,colLeft2,colLeft3,colLeft4,colRight1,colRight2,colRight3,colRight4);
                    
                    if(pos->x == col1.x && pos->y == col1.y){
                        srcList = &listcol1;
                        flag = true;
                        }else if(pos->x == col2.x && pos->y == col2.y){
                        srcList = &listcol2;
                        flag = true;
                        }else if(pos->x == col3.x && pos->y == col3.y){
                        srcList = &listcol3;
                        flag = true;
                        }else if(pos->x == col4.x && pos->y == col4.y){
                        srcList = &listcol4;
                        flag = true;
                        }else if(pos->x == col5.x && pos->y == col5.y){
                        srcList = &listcol5;
                        flag = true;
                        }else if(pos->x == col6.x && pos->y == col6.y){
                        srcList = &listcol6;
                        flag = true;
                        }else if(pos->x == col7.x && pos->y == col7.y){
                        srcList = &listcol7;
                        flag = true;
                        }else if(pos->x == col8.x && pos->y == col8.y){
                        srcList = &listcol8;
                        flag = true;
                        }else if(pos->x == colLeft1.x && pos->y == colLeft1.y){
                        srcCard= &LeftCol1;
                        flag = true;
                        }else if(pos->x == colLeft2.x && pos->y == colLeft2.y){
                        srcCard = &LeftCol2;
                        flag = true;
                        }else if(pos->x == colLeft3.x && pos->y == colLeft3.y){
                        srcCard = &LeftCol3;
                        flag = true;
                        }else if(pos->x == colLeft4.x && pos->y == colLeft4.y){
                        srcCard = &LeftCol4;
                        flag = true;
                        }else if(pos->x == colRight1.x && pos->y == colRight1.y){
                        srcList = &listRightcol1;
                        flag = true;
                        }else if(pos->x == colRight2.x && pos->y == colRight2.y){
                        srcList = &listRightcol2;
                        flag = true;
                        }else if(pos->x == colRight3.x && pos->y == colRight3.y){
                        srcList = &listRightcol3;
                        flag = true;
                        }else if(pos->x == colRight4.x && pos->y == colRight4.y){
                        srcList = &listRightcol4;
                        flag = true;
                        }else{
                        srcList = NULL;
                        srcCard = NULL;
                    }
                    
                }else{
                    distList = NULL;
                    distCard = NULL;
                    mouse_x = event.motion.x;
                    mouse_y = event.motion.y;
                    SDL_Rect* pos = getTarget(mouse_x,mouse_y,col1,col2,col3,col4,col5,col6,col7,col8,colLeft1,colLeft2,colLeft3,colLeft4,colRight1,colRight2,colRight3,colRight4);
                    if(pos->x == col1.x && pos->y == col1.y){
                        distList = &listcol1;
                        }else if(pos->x == col2.x && pos->y == col2.y){
                        distList = &listcol2;
                        }else if(pos->x == col3.x && pos->y == col3.y){
                        distList = &listcol3;
                        }else if(pos->x == col4.x && pos->y == col4.y){
                        distList = &listcol4;
                        }else if(pos->x == col5.x && pos->y == col5.y){
                        distList = &listcol5;
                        }else if(pos->x == col6.x && pos->y == col6.y){
                        distList = &listcol6;
                        }else if(pos->x == col7.x && pos->y == col7.y){
                        distList = &listcol7;
                        }else if(pos->x == col8.x && pos->y == col8.y){
                        distList = &listcol8;
                        }else if(pos->x == colLeft1.x && pos->y == colLeft1.y){
                        distCard = &LeftCol1;
                        }else if(pos->x == colLeft2.x && pos->y == colLeft2.y){
                        distCard = &LeftCol2;
                        }else if(pos->x == colLeft3.x && pos->y == colLeft3.y){
                        distCard = &LeftCol3;
                        }else if(pos->x == colLeft4.x && pos->y == colLeft4.y){
                        distCard = &LeftCol4;
                        }else if(pos->x == colRight1.x && pos->y == colRight1.y){
                        distList = &listRightcol1;
                        }else if(pos->x == colRight2.x && pos->y == colRight2.y){
                        distList = &listRightcol2;
                        }else if(pos->x == colRight3.x && pos->y == colRight3.y){
                        distList = &listRightcol3;
                        }else if(pos->x == colRight4.x && pos->y == colRight4.y){
                        distList = &listRightcol4;
                        }else{
                        distList = NULL;
                        distCard = NULL;
                    }
                    if(distList != NULL || distCard != NULL){
                        if(srcList != NULL && distList != NULL  ){

                            moveCard(pop_back(srcList),srcList,distList,NULL);}

                        if(srcList != NULL && distCard != NULL && *distCard == NULL)
                            moveCard(pop_back(srcList),NULL,NULL,distCard);

                        if(srcCard != NULL && distList != NULL){
                            card* tempcard = *srcCard;
                            *srcCard = NULL;
                            moveCard(tempcard,srcCard,distList,NULL);
                            
                        }
                            

                        if(srcCard != NULL && distCard != NULL && *distCard == NULL){
                            card* tempcard = *srcCard;
                            *srcCard = NULL;
                            moveCard(tempcard,NULL,NULL,distCard);
                            
                            }
                    }       
                    flag = false;
                }
                displayallscreen(renderer,texture,&listcol1,col1,&col1copy,&listcol2,col2,&col2copy,&listcol3,col3,&col3copy,&listcol4,col4,&col4copy,&listcol5,col5,&col5copy,&listcol6,col6,&col6copy,&listcol7,col7,&col7copy,&listcol8,col8,&col8copy,&listRightcol1,colRight1,&colRight1copy,&listRightcol2,colRight2,&colRight2copy,&listRightcol3,colRight3,&colRight3copy,&listRightcol4,colRight4,&colRight4copy,LeftCol1,colLeft1,&colLeft1copy,LeftCol2,colLeft2,&colLeft2copy,LeftCol3,colLeft3,&colLeft3copy,LeftCol4,colLeft4,&colLeft4copy,&rect);
  
            }
            else if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

    }

    // Release any of the allocated resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}