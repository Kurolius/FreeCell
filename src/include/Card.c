#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <string.h>
typedef struct{
    SDL_Surface *asset;
    SDL_Rect rect;
    SDL_Texture * txture;
    int num;
    char type;
}card;

typedef struct elementC{

    card *c;
    struct elementC *next;

}Element;


Element *createElement(card* c)
{
    Element *element = (Element*)malloc(sizeof(Element));
    element->c = c;
    element->next = NULL;
    return element;
}

void push(card* card, Element **pile)
{
    Element *e = createElement(card);
    e->next = *pile;
    *pile = e;
}

int pop(Element **pile)
{
    if(*pile == NULL)return 0;
    Element *temp;
    temp = *pile;
    *pile = (*pile)->next;
    free(temp);
    return 1;
}

card* peek(Element *pile)
{
    if(pile == NULL)return 0;
    return pile->c;
}

Element *lastAdressC(Element *L){
    Element *p;
    if(L==NULL) return NULL;
    for(p=L;p->next!=NULL;p=p->next);
    return p;
}
card* pop_back(Element** head) {
      if(*head != NULL) {
        if((*head)->next == NULL) {
            Element* temp = *head;
            *head = NULL;
          return (temp->c);
        } else {
          Element* temp = *head;
          while(temp->next->next != NULL)
            temp = temp->next;
          Element* lastNode = temp->next;
          temp->next = NULL;
          return(lastNode->c); 
        }
      }
    }

card* creatcard(SDL_Surface *asset,SDL_Rect rect,SDL_Texture * txture){
    card *c=(card*)malloc(sizeof(card));
    c->asset=asset;
    c->rect=rect;
    c->txture=txture;
    return c;
}


Element *createElementC(card *c){
    Element *elem;
    elem=(Element*)malloc(sizeof(Element));
    elem->c=c;
    elem->next=NULL;
    return elem;
}


void addcard(card *c, Element **L){
    Element *e;
    e=createElementC(c);
        if(*L==NULL){
            *L=e;return;
        }
    lastAdressC(*L)->next=e;
}

int isempty(Element *pile)
{
    if(pile == NULL)return 1;
    return 0;
}

 Element* GenerateDek(SDL_Renderer* render){
    Element* dek = NULL;

    for(int i=1;i<=13;i++){
        char trefle[20];
        sprintf(trefle,"textures/cards/%dA.bmp",i);
        card* cA=(card*)malloc(sizeof(card));
        cA->asset =  SDL_LoadBMP(trefle);
        cA->txture = SDL_CreateTextureFromSurface(render,cA->asset);
        cA->num = i;
        cA->type = 't';
        push(cA,&dek);

        char heart[20];
        sprintf(heart,"textures/cards/%dB.bmp",i);
        card* cB=(card*)malloc(sizeof(card));
        cB->asset =  SDL_LoadBMP(heart);
        cB->txture = SDL_CreateTextureFromSurface(render,cB->asset);
        cB->num = i;
        cB->type = 'h';
        push(cB,&dek);

        char Pick[20];
        sprintf(Pick,"textures/cards/%dC.bmp",i);
        card* cC=(card*)malloc(sizeof(card));
        cC->asset =  SDL_LoadBMP(Pick);
        cC->txture = SDL_CreateTextureFromSurface(render,cC->asset);
        cC->num = i;
        cC->type = 'p';
        push(cC,&dek);

        char diam[20];
        sprintf(diam,"textures/cards/%dD.bmp",i);
        card* cD=(card*)malloc(sizeof(card));
        cD->asset =  SDL_LoadBMP(diam);
        cD->txture = SDL_CreateTextureFromSurface(render,cD->asset);
        cD->num = i;
        cD->type = 'd';
        push(cD,&dek);
    }
    card* T[52];
    int cpt=0;
    while(!isempty(dek)){
        card* tempCard=peek(dek);
        pop(&dek);
        T[cpt]=tempCard;
        cpt++;
    }

    srand(time(0));
  
    for (int i=0; i<52 ;i++)
    {
        // Random for remaining positions.
        int r = i + (rand() % (52 -i));
        card* temp = T[i];
        T[i] = T[r];
        T[r]=temp;
    }
    for (int i=0; i<52 ;i++)
    {
        push(T[i],&dek);
    }

    return dek;
 }