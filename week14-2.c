#include <stdio.h>
int main()
{
    FILE * fout = fopen("file2.txt","w+");
    fprintf(fout,"angle %d\n",999);
    fclose(fout);

    char line[200];
    int a;
    FILE * fin = fopen("file2.txt","r");
    fscanf(fin,"%s %d",line ,&a);
    printf("Ū��F�r��:%s �ξ��%d\n",line,a);
    fclose(fin);
}
