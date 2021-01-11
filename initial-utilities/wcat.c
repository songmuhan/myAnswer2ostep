#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int filePrint(char *filename){
    FILE * fp;
    fp = fopen(filename,"r");
    if(fp == NULL){
        printf("wcat: cannot open file\n");
        exit(1);
    }
    int MaxLineLength = 1024;
    char linebuffer[MaxLineLength];
    while(fgets(linebuffer,MaxLineLength,fp)){
        printf("%s",linebuffer);
    }
    fclose(fp);
    return 0;
}


int main(int argc, char*argv[]){
    int i;
    if(argc == 1){
        return 0;
    }
    for(i = 1; i < argc; i++){
        filePrint(argv[i]);
    }
    return 0;
}
