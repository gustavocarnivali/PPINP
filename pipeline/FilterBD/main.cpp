#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include <omp.h>

using namespace std;

int igual_s(char texto1[100],char texto2[100]){

    for(int i=2;i<98;i++){
        if(texto1[i]!=texto2[i]) return 0;
        if(texto1[i]=='\0' and texto2[i]=='\0') return 1;
    }

    return 1;
}


int main(int argc, char *argv[])
{
    int maxlinha=0;
    char x;
    int linha=0;

    FILE *fha;
    if((fha = fopen(argv[1], "r")) == NULL) {
        printf("Arquivo nao encontrado1!\n");
    }

    char t1[100];
    char t2[100];
    float pont=0;
    int it=0;
    int cont=0;

    while (!feof(fha)){

        fscanf(fha, "%c", &x);
        if(x!=' '){
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
                pont=pont/1000.0;
                if(pont>=0.8 and pont<=1.0 and t1[5]!='\0'){
                    char link[100];

                    link[0]='.';
                    link[1]='.';
                    link[2]='/';
                    link[3]='G';
                    link[4]='r';
                    link[5]='a';
                    link[6]='p';
                    link[7]='h';
                    link[8]='G';
                    link[9]='e';
                    link[10]='n';
                    link[11]='e';
                    link[12]='r';
                    link[13]='a';
                    link[14]='t';
                    link[15]='e';
                    link[16]='/';
                    link[17]='b';
                    link[18]='d';
                    link[19]='s';
                    link[20]='/';

                    for(int i=0;i<100;i++){
                        link[i+21]=t1[i];
                        if(t1[i]=='\0') break;
                    }
                    FILE *arq;
                    arq = fopen(link, "a");
                    fprintf (arq, "%s %s %f \n", t1, t2, pont);
                    fclose(arq);
                }
                linha++;
            }else{
                if(cont==0){
                    cont++;
                    it=0;
                }
            }
        }

    }



    return 0;

}


