#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include <omp.h>
#include <bits/stdc++.h>


using namespace std;



int igual_s(char texto1[500],char texto2[500]){
    for(int i=2;i<499;i++){
        if(texto1[i]!=texto2[i]) return 0;
        if(texto1[i]=='\0' and texto2[i]=='\0') return 1;
    }
    return 1;
}


class vertice{

    public:

    char name[100];
    vertice * vs[500];
    float scores[500];
    int qts;
    float acumulado;

    vertice(char lname[500]){
        for(int i=0;i<500;i++){
            name[i]=lname[i];
        }
        qts=0;
    }

    void adiciona(vertice *aux, float s){
        int aju=0;
        for(int i=0;i<qts;i++){
            if(igual_s(aux->name,vs[i]->name)==1){
                aju=1;
                scores[i]=s*scores[i];
            }
        }
        if(aju==0){
            vs[qts]=aux;
            scores[qts]=s;
            qts++;
        }
    }

    void printg(){
        cout<<name<<endl;
        for(int i=0;i<qts;i++){
            cout<<i<<" "<<vs[i]->name<<" "<<scores[i]<<endl;
        }
    }

    void facumulado(){
        acumulado=0;
        for(int i=0;i<qts;i++){
            acumulado+=scores[i];
        }
    }

};


void coutscore(vertice * aux, int lim, float s){

    if(lim>3)return;

    for(int i=0;i<aux->qts;i++){
        float scoref=1.0-(s*aux->scores[i]);
        if(scoref>=0.7 and scoref<=1.0)cout<<aux->name<<" "<<aux->vs[i]->name<<" "<<scoref<<endl;
        coutscore(aux->vs[i], lim+1, s*aux->scores[i]);
    }

}


int main()
{

    int maxlinha=0;

    //le as conexoes

    FILE *fh;

    if((fh = fopen("output.txt", "r")) == NULL) {
        printf("Arquivo nao encontrado!\n");
    }

    while (!feof(fh)){
        char x;
        fscanf(fh, "%c", &x);

        if(x=='\n')maxlinha++;

    }


    if((fh = fopen("output.txt", "r")) == NULL) {
        printf("Arquivo nao encontrado!\n");
    }


    //proteinas do texto
    char texto1[500];
    char texto2[500];

    //pontuacoes do texto
    float scoreaux=0;
    float score=0.0;

    //auxiliar
    int estado=0;

    int iaux=0;

    int lala=0;

    int linha=-1;

    vertice * grafo[maxlinha];

    int qual=-1;
    int qual2=-1;

    while (!feof(fh)){
        char x;
        fscanf(fh, "%c", &x);

        if(x==' ') {
            estado++;
            iaux=0;
            if(estado==1){iaux=-1;}
        }

        //le o score
        if(estado==2){
            fscanf(fh, "%f", &scoreaux);
            score=scoreaux;
            score=1.0-score;
        }

        if(x=='\n') {
            estado=0;
            iaux=-1;

            //if(texto1[0]=='G' and texto2[0]=='G')
                //cout<<texto1<<" "<<texto2<<" "<<score1<<" "<<score2<<" "<<score3<<endl;

            //se nao for igual, nao faz sentido se forem
            if(igual_s(texto1,texto2)==0){

                //procure se ja existe na lista
                for(int i=0;i<linha;i++){
                    if(igual_s(grafo[i]->name,texto1)==1){
                        qual=i;//e coloca sua id nessa var
                    }
                }

                //se nao existe cria ele
                if(qual==-1){
                    qual=linha+1;
                    linha++;
                    grafo[qual]=new vertice(texto1);
                }

                //mesma coisa para a outra entrada
                for(int i=0;i<linha;i++){
                    if(igual_s(grafo[i]->name,texto2)==1){
                        qual2=i;
                    }
                }

                if(qual2==-1){
                    qual2=linha+1;
                    linha++;
                    grafo[qual2]=new vertice(texto2);
                }

                //sabendo quais arestas sao e seu score adiciona a aresta ao vertice
                grafo[qual]->adiciona(grafo[qual2], score);

            }

            qual=-1;
            qual2=-1;
        }


        //le os nomes
        if(estado==0 and x!=' ' and x!='\n'){
            texto1[iaux]=x;
            texto1[iaux+1]='\0';
        }
        //le os nomes
        if(estado==1 and x!=' ' and x!='\n'){
            texto2[iaux]=x;
            texto2[iaux+1]='\0';
        }

        iaux++;

    }



    for(int i=0;i<linha-1;i++){
     //   grafo[i]->printg();
    }


    //calcula score
    for(int i=0;i<linha-1;i++){
        coutscore(grafo[i], 0, 1.0);
    }

    //calcula maior
    float maior=0;
    int idmaior=0;

    //calcula score
    for(int i=0;i<linha-1;i++){
        grafo[i]->facumulado();
        if(grafo[i]->acumulado>maior){
            maior=grafo[i]->acumulado;
            idmaior=i;
        }
    }
    //cout<<"maior:"<<endl;
    //grafo[idmaior]->printg();

    return 0;

}
