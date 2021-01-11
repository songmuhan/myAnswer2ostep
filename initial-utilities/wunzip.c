#include<stdio.h>
#include<stdlib.h>

int main(int argc, char**argv){
    if(argc == 1){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }else{
        int count;
        char ch;
        FILE*fp;
        for(int i = 1; i < argc; i++){
            fp = fopen(argv[i],"r");
            if(fp == NULL){
                printf("wunzip: cannot open file\n");
                exit(1);
            }
            while(fread(&count,sizeof(int),1,fp)){
                fread(&ch,sizeof(char),1,fp);
                while(count >0){
                    printf("%c",ch);
                    count--;
                }
            }
        }
    }
}