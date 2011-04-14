#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/time.h>


void fragTime(struct timeval first,struct timeval second){

  double t2=first.tv_sec+(first.tv_usec/1000000.0); 
  double t3=second.tv_sec+(second.tv_usec/1000000.0); 

  FILE * pFile;
  pFile = fopen("fragTime.dat", "a"); /*arquivo com tempos de leitura sequcial do*/

  if (pFile == NULL) 
    return ;
  
  /* if (first.tv_usec > second.tv_usec) { 
    second.tv_usec += 1000000; 
    second.tv_sec--; 
  } */
 
  fseek(pFile, 0, SEEK_END);
  fprintf(pFile,"%f \n" ,t3-t2);
  fclose(pFile);

  return;
}


void seqTime(struct timeval first,struct timeval second){

  double t2=first.tv_sec+(first.tv_usec/1000000.0); 
  double t3=second.tv_sec+(second.tv_usec/1000000.0); 

  FILE * pFile;
  pFile = fopen("seqTime.dat", "a"); /*arquivo com tempos de leitura sequcial do*/

  if (pFile == NULL) 
    return ;
  
  /* if (first.tv_usec > second.tv_usec) { 
    second.tv_usec += 1000000; 
    second.tv_sec--; 
  } */
 
  fseek(pFile, 0, SEEK_END);
  fprintf(pFile,"%f \n" ,t3-t2);
  fclose(pFile);

  return;
}


/*Le toda a agenda do usuario em arquivo e passa para memoria*/
void leSeq()
{
  FILE * pFile0,* pFile1,* pFile2,* pFile3,* pFile4;
  char line[10]="";

  /* Estrutura para analise de tempo em microsegundos */
  struct timeval  first, second, lapsed;
  struct timezone tzp; 

  pFile0 = fopen("/tmp/0", "r"); /*arquivo com nome de usuarios*/
  pFile1 = fopen("/tmp/1", "r"); /*arquivo com nome de usuarios*/
  pFile2 = fopen("/tmp/2", "r"); /*arquivo com nome de usuarios*/
  pFile3 = fopen("/tmp/3", "r"); /*arquivo com nome de usuarios*/
  pFile4 = fopen("/tmp/4", "r"); /*arquivo com nome de usuarios*/

  if (pFile0  == NULL || pFile1  == NULL || pFile2  == NULL || pFile3  == NULL || pFile4  == NULL ){
    return ;
  }
  else
  {

    gettimeofday (&first, &tzp); 

    while (fscanf(pFile0, "%[^\n]", line) != EOF)
    {/*evento*/
      fgetc(pFile0);
    }
    while (fscanf(pFile1, "%[^\n]", line) != EOF)
    {/*evento*/
      fgetc(pFile1);
    }
    while (fscanf(pFile2, "%[^\n]", line) != EOF)
    {/*evento*/
      fgetc(pFile2);
    }
    while (fscanf(pFile3, "%[^\n]", line) != EOF)
    {/*evento*/
      fgetc(pFile3);
    }
    while (fscanf(pFile4, "%[^\n]", line) != EOF)
    {/*evento*/
      fgetc(pFile4);
    }


    gettimeofday (&second, &tzp);
    seqTime(first,second);  
    fclose(pFile0);
    fclose(pFile1);
    fclose(pFile2);
    fclose(pFile3);
    fclose(pFile4);
    return ;
  }

  return ;
}

/*Le toda a agenda do usuario em arquivo e passa para memoria*/
void leFrag(int num)
{
  FILE * pFile0,* pFile1,* pFile2,* pFile3,* pFile4;
  char line[10]="";

  /* Estrutura para analise de tempo em microsegundos */
  struct timeval  first, second, lapsed;
  struct timezone tzp; 

  pFile0 = fopen("/tmp/0", "r"); /*arquivo com nome de usuarios*/
  pFile1 = fopen("/tmp/1", "r"); /*arquivo com nome de usuarios*/
  pFile2 = fopen("/tmp/2", "r"); /*arquivo com nome de usuarios*/
  pFile3 = fopen("/tmp/3", "r"); /*arquivo com nome de usuarios*/
  pFile4 = fopen("/tmp/4", "r"); /*arquivo com nome de usuarios*/

  if (pFile0  == NULL || pFile1  == NULL || pFile2  == NULL || pFile3  == NULL || pFile4  == NULL ){
    return ;
  }
  else
  {

    gettimeofday (&first, &tzp); 
    /*Vamos ler 1000 linhas de cada arquivo*/
    /*Primeiro evento*/
    while (fscanf(pFile4, "%[^\n]", line) != EOF)
    {/*evento*/

      fscanf(pFile0, "%[^\n]", line);
      fgetc(pFile0);

      fscanf(pFile1, "%[^\n]", line);
      fgetc(pFile1);

      fscanf(pFile2, "%[^\n]", line);
      fgetc(pFile2);

      fscanf(pFile3, "%[^\n]", line);
      fgetc(pFile3);

      fgetc(pFile4);

    }


    gettimeofday (&second, &tzp);
    fragTime(first,second);  
    fclose(pFile0);
    fclose(pFile1);
    fclose(pFile2);
    fclose(pFile3);
    fclose(pFile4);

    return ;
  }

  return ;
}


void createFile(char nome[])
{
  FILE * pFile;
  int i;
  /*Cria novo arquivo de 100MB*/
  pFile = fopen(nome, "w"); /*arquivo com nome de usuarios*/
  if (pFile == NULL)
    perror("Error opening file");
  else
    {
      for(i=0;i*10<100000000;i++){
	fputs("123456789\n", pFile); /* 10 bytes */
      }
      fclose(pFile);
    }
      
  return;
}



void createManyFile(int num)
{
  int i=0;
  char numChar[10];
  char path[10]="/tmp/";
  for(i=0;i<num;i++){
    strcpy(path,"/tmp/");
    snprintf(numChar, sizeof(numChar)-1, "%d",i);
    strcat(path,numChar);
    //    printf("%s",path);
    createFile(path);
  }
  return;
}
int main(){
  /*Cria arquivo de 100MB*/
  // createFile("file.dat");
  createManyFile(5);
 
  /*Le sequencialmente um arquivo*/
  leSeq();
  createManyFile(5);
  leFrag(5);


  return 0;
}
