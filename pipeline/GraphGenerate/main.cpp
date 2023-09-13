#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include <omp.h>
#include <bits/stdc++.h>


using namespace std;

int igual_s(char texto1[100], char texto2[100]){
    for(int i=2;i<98;i++){
        if(texto1[i]!=texto2[i]) return 0;
        if(texto1[i]=='\0' and texto2[i]=='\0') return 1;
    }
    return 1;
}

int igual_s_i(char texto1[100], char texto2[100]){
    for(int i=2;i<98;i++){
        if(texto1[i]!=texto2[i]) return 0;
        if(texto1[i]=='.' and texto2[i]=='.') return 1;
    }
    return 1;
}


class vertice{

    public:

    char nome1[100];
    char nome2[100];
    char vizinhos[500][100];
    float score[500];
    vertice * prox;

    vertice(){
        prox=NULL;
        for(int iaux=0;iaux<500;iaux++){
            vizinhos[iaux][0]='x';
            score[iaux]=0.0;
        }
    }

    void set_name1(char n1[100]){
        for(int iaux=0;iaux<100;iaux++){
            nome1[iaux]=n1[iaux];
            if(n1[iaux]=='\0') break;
        }
    }

    void set_name2(char n2[100]){
        for(int iaux=0;iaux<100;iaux++){
            nome2[iaux]=n2[iaux];
            if(n2[iaux]=='\0') break;
        }
    }

};


float verifica_s(char p1[100], char p2[100]){


    char link[100];


	for(int i=0;i<45;i++){
	    link[i+4]=p1[i];
	}
	link[0]='b';
	link[1]='d';
	link[2]='s';
	link[3]='/';

    int i=0;

    FILE *fha;

//    cout<<link<<endl;
//    cout<<p1<<endl;
//    cout<<p2<<endl;

    if((fha = fopen(link, "r")) == NULL) {
        //printf("Arquivo nao encontrado E!\n");
        return 0.0;
    }


    char t1[100];
    char t2[100];
    float pont=0;
    int it=0;
    int cont=0;

    int ifinal=0;

    while (!feof(fha)){
        char x;
        fscanf(fha, "%c", &x);

        if(x!=' ' and x!='\n'){
            if(cont==0){
                t1[it]=x;
                t1[it+1]='\0';
                it++;
            }
            if(cont==1){
                t2[it]=x;
                t2[it+1]='\0';
                it++;
            }
        }
        if(x==' '){
            if(cont==1){
                cont=0;
                it=0;
                fscanf(fha, "%f", &pont);
                fscanf(fha, "%c", &x);
//                cout<<p2<<" "<<t2<<" "<<pont<<endl;

                if(pont>0.0){

                    //if(igual_s(p1, t1)==1){
                        if(igual_s(p2, t2)==1){
  //                          cout<<p2<<" "<<t2<<" "<<pont<<endl;
                            fclose(fha);
                            return pont;
                        }
                    //}
                }
            }else{
                if(cont==0){
                    cont++;
                    it=0;
                }
            }
        }
    }
    fclose(fha);
    return 0.0;

}



int imprime(vertice * vert){

    vertice * v;
    v = new vertice();
    v=vert;
    int contl=0;
    while(v!=NULL){
        cout<<contl<<" "<<v->nome1<<" "<<v->nome2;
        for (int aux=0;aux<500;aux++){
            cout<<" "<<v->vizinhos[aux];
        }
        cout<<endl;
        v=v->prox;
        contl++;
    }
    return 1;
}


int main(int argc, char *argv[])
{


//    cout<<argv[1]<<endl;
//    cout<<argv[2]<<endl;


    vertice * raiz1;
    raiz1 = new vertice();

    vertice * raiz2;
    raiz2 = new vertice();


    //conta linhas do primeiro arquivo
//    cout<<"conta linhas do primeiro arquivo"<<endl;

    int maxlinha1=0;

    FILE *fh;

    if((fh = fopen(argv[1], "r")) == NULL) {
        printf("Arquivo nao encontrado!\n");
    }
    while (!feof(fh)){
        char x;
        fscanf(fh, "%c", &x);
        if(x=='\n')maxlinha1++;
    }
//    cout<<maxlinha1<<endl;

    fclose(fh);





    //conta linhas do segundo arquivo
//    cout<<"conta linhas do segundo arquivo"<<endl;

    int maxlinha2=0;

    FILE *fh2;

    if((fh2 = fopen(argv[2], "r")) == NULL) {
        printf("Arquivo nao encontrado!\n");
    }
    while (!feof(fh2)){
        char x;
        fscanf(fh2, "%c", &x);
        if(x=='\n')maxlinha2++;
    }
//    cout<<maxlinha2<<endl;


    int maxlinha21=0;
    int maxlinha22=0;


    //le primeiro arquivo
//    cout<<"le primeiro arquivo"<<endl;


    if((fh = fopen(argv[1], "r")) == NULL) {
        printf("Arquivo nao encontrado!1\n");
    }

    int linha=0;

    while (!feof(fh)){

        char texto1[100];
        char textob[100];

        char x;
        int i=0;

        //le e grava o primeiro e o segundo termo

        while (!feof(fh)){
            fscanf(fh, "%c", &x);

            if(x!=' ' and x!='	'){
                texto1[i]=x;
                texto1[i+1]='\0';
            }

            i++;

            if(x==' ' or x=='	'){
                break;
             }
         }

         i=0;

        while (!feof(fh)){
            fscanf(fh, "%c", &x);

            if(x!=' ' and x!='	'){
                textob[i]=x;
                textob[i+1]='\0';
            }

            i++;

            if(x==' ' or x=='	'){
                break;
            }
        }



        //le os valotes
        int val1, val2;
        int val4, val5;
        float val3;
        char val6;
        char x2;
        char x3;
        char x4;
        int x5;
        fscanf(fh, "%d %d %f %d %d %c", &val1, &val2, &val3, &val4, &val5, &val6);
        int nao=0;
        if(val6!='0'){
            fscanf(fh, "%c", &x2);
            fscanf(fh, "%c", &x3);
            fscanf(fh, "%c", &x4);
            fscanf(fh, "%c", &x);
            fscanf(fh, "%c", &x);
            fscanf(fh, "%d", &x5);

            float f1=val3;
            float f2=val2;
            float f3=val1;
            float f4=val4;
            float f5=(f2-f3)/f4;

            if(f5<0.50)nao=1;
            if(f1<50.0)nao=1;
            //if(x5>250)nao=1;

        }else{//score=0
            nao=1;

            fscanf(fh, "%c", &x);
            fscanf(fh, "%c", &x2);
        }

        fscanf(fh, "%d %d", &val1, &val2);

        char xa='b';
        fscanf(fh, "%c", &xa);
        fscanf(fh, "%c", &xa);
        while(xa!='	'){
            fscanf(fh, "%c", &xa);
        }

        int valn;
        fscanf(fh, "%d", &valn);

        fscanf(fh, "%c", &xa);
        linha++;
        if(linha==maxlinha1-1){
            fclose(fh);
            break;
        }


        if(nao==0){

            vertice * ver;
            ver = new vertice();

            ver->set_name1(texto1);
            ver->set_name2(textob);












            char link[100];


            for(int i=0;i<45;i++){
                link[i+4]=ver->nome2[i];
            }

            link[0]='b';
            link[1]='d';
            link[2]='s';
            link[3]='/';

            FILE *fhaaux;

           // cout<<link<<endl;

            if((fhaaux = fopen(link, "r")) == NULL) {

            }
            else{

                char t1aux[100];
                char t2aux[100];
                float pontaux=0;
                int itaux=0;
                int contaux=0;
                int cont2aux=0;


                while (!feof(fhaaux)){
                    char x;
                    fscanf(fhaaux, "%c", &x);

                    if(x==' ')contaux++;
                    if(x==' ')itaux=0;

                    if(x!=' ' and x!='\n'){
                        if(contaux==0){
                            t1aux[itaux]=x;
                            t1aux[itaux+1]='\0';
                            itaux++;
                        }
                        if(contaux==1){
                            t2aux[itaux]=x;
                            t2aux[itaux+1]='\0';
                            itaux++;
                        }
                    }

                    if(contaux==2){

                        fscanf(fhaaux, "%f", &pontaux);
                        fscanf(fhaaux, "%c", &x);

                        itaux=0;

                        contaux=0;

                        if(pontaux>0.0){
                            if(cont2aux<=500){
                                for (int linhaaux=0;linhaaux<=40;linhaaux++){
                                    ver->vizinhos[cont2aux][linhaaux]=t2aux[linhaaux];
                                }
                                ver->score[cont2aux]=pontaux;
                            }
                            cont2aux++;
                        }
                    }
                }

            }




            if(linha==0){
                raiz1=ver;
            }
            if(linha>0){
                ver->prox=raiz1;
                raiz1=ver;
            }

            maxlinha21++;
        }
    }



//    cout<<maxlinha21<<endl;
   // imprime(raiz1);




    fclose(fh2);


    //le segundo arquivo
//    cout<<"le segundo arquivo"<<endl;

    if((fh2 = fopen(argv[2], "r")) == NULL) {
        printf("Arquivo nao encontrado!2\n");
    }

    for (int linha2=0;linha2<=maxlinha2-2;linha2++){

        char texto2[100];
        char texto2b[100];

        int i=0;

        //le e grava o primeiro e o segundo termo
        while (!feof(fh2)){

            char x;
            fscanf(fh2, "%c", &x);

            if(x!=' ' and x!='	'){
                texto2[i]=x;
                texto2[i+1]='\0';
            }

            i++;

            if(x==' ' or x=='	'){
                break;
             }
         }

         i=0;

        while (!feof(fh2)){
            char x;
            fscanf(fh2, "%c", &x);

            if(x!=' ' and x!='	'){
                texto2b[i]=x;
                texto2b[i+1]='\0';
            }

            i++;

            if(x==' ' or x=='	'){
                break;
            }
        }

        //le os valotes
        int val1, val2;
        int val4, val5;
        float val3;
        char val6;
        char x2;
        char x3;
        char x4;
        int x5;
        fscanf(fh2, "%d %d %f %d %d %c", &val1, &val2, &val3, &val4, &val5, &val6);
        int nao2=0;
        if(val6!='0'){
            char x;
            fscanf(fh2, "%c", &x2);
            fscanf(fh2, "%c", &x3);
            fscanf(fh2, "%c", &x3);
            fscanf(fh2, "%c", &x4);
            fscanf(fh2, "%c", &x);
            fscanf(fh2, "%c", &x);
            fscanf(fh2, "%d", &x5);

            float f1=val3;
            float f2=val2;
            float f3=val1;
            float f4=val4;
            float f5=(f2-f3)/f4;

            if(f5<0.50)nao2=1;
            if(f1<50.0)nao2=1;
            //if(x5>250)nao2=1;

        }else{//score=0
            nao2=1;
            char x;

            fscanf(fh2, "%c", &x);
            fscanf(fh2, "%c", &x2);
        }

        fscanf(fh2, "%d %d", &val1, &val2);

        char xa='b';
        fscanf(fh2, "%c", &xa);
        fscanf(fh2, "%c", &xa);
        while(xa!='	'){
            fscanf(fh2, "%c", &xa);
        }

        int valn;
        fscanf(fh2, "%d", &valn);


        fscanf(fh2, "%c", &xa);

        if(linha2==maxlinha2-1){
            fclose(fh2);
            //break;
        }

        if(nao2==0){
            vertice * ver;
            ver = new vertice();

            ver->set_name1(texto2);
            ver->set_name2(texto2b);

            if(linha2==0){
                raiz2=ver;
            }
            if(linha2>0){
                ver->prox=raiz2;
                raiz2=ver;
            }

            maxlinha22++;
        }

    }


    //cout<<maxlinha22<<endl;
    //imprime(raiz2);












clock_t tInicio, tFim, tDecorrido;


tInicio = clock();




    //processo
    //cout<<"processo"<<endl;



    vertice * v1 = raiz1;

    int nao1=0;
    int nao2=0;

    int nao3=0;
    int nao4=0;
    int nao5=0;
    int nao6=0;


    for (int linha1=0;linha1<maxlinha1-1;linha1++){
    if(v1->prox==NULL)nao1=0;
    if(v1->prox!=NULL)nao1=1;

    if(nao1==1){

        vertice * v2 = raiz2;

//    cout<<v1->nome1<<endl;
        //#pragma omp parallel for
        for (int linha2=0;linha2<maxlinha2-1;linha2++){
        if(v2->prox==NULL)nao2=0;
        if(v2->prox!=NULL)nao2=1;


        if(nao2==1){

            if(igual_s(v1->nome1,v2->nome1)==0){
//cout<<v1->nome2<<" "<<v2->nome2<<endl;
                if(igual_s(v1->nome2,v2->nome2)==1){

                    nao3=0;
                    for(int ite=0;ite<100;ite++){
                        if(v1->nome1[ite]=='\0')nao3=1;
                        //if(nao3==0)fprintf (arq2, "%c", v1->nome1[ite]);
                    }
                    //fprintf (arq2, " ");
                    nao4=0;
                    for(int ite=0;ite<100;ite++){
                        if(v2->nome1[ite]=='\0')nao4=1;
                        //if(nao4==0)fprintf (arq2, "%c", v2->nome1[ite]);
                    }
                    //fprintf (arq2, " 1.0 \n");
                    //cout<<v1->nome1<<" "<<v1->nome2<<" "<<v2->nome2<<" "<<v2->nome1<<" 1.0"<<endl;
                    cout<<v1->nome1<<" "<<v2->nome1<<" 1.0"<<endl;
                }


                if(igual_s(v1->nome2,v2->nome2)==0){

                    for(int iteaux=0;iteaux<500;iteaux++){
                        //cout<<v2->nome2<<endl;

                        float vpont=v1->score[iteaux];

                        if(igual_s(v1->vizinhos[iteaux],v2->nome2)==1){
                            nao5=0;
                            for(int ite=0;ite<100;ite++){
                                if(v1->nome1[ite]=='\0')nao5=1;
                                //if(nao5==0)fprintf (arq2, "%c", v1->nome1[ite]);
                            }
                            //fprintf (arq2, " ");
                            nao6=0;
                            for(int ite=0;ite<100;ite++){
                                if(v2->nome1[ite]=='\0')nao6=1;
                                //if(nao6==0)fprintf (arq2, "%c", v2->nome1[ite]);
                            }
                            //fprintf (arq2, " %f \n", vpont);
                            //cout<<v1->nome1<<" "<<v1->nome2<<" "<<v2->nome2<<" "<<v2->nome1<<" "<<vpont<<endl;
                            cout<<v1->nome1<<" "<<v2->nome1<<" "<<vpont<<endl;

                        }
                    }


                }
            }
            v2=v2->prox;
        }
        }
        v1=v1->prox;
        //cout<<"+ "<<linha1<<" "<<maxlinha21<<endl;
    }
    }



   // fclose(arq2);




    return 0;

}


