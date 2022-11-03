#include <stdio.h>


typedef struct 
{
  char Enhed;
  char rum[50];
  int tal;
  double tidspunkt;
} Data;

int main(void)
{
  //file pointer variabel fil. 
  FILE *file;
  
  file = fopen("data.txt", "r"); 
  

  //Til hvis filen ikke åbner, så kom med en fejl besked. 
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // array af structs til at gemme data i
  Data Datas[100];
  
  // read bliver brugt til at være sikker på vær linje bliver læst ordenligt 
  int read = 0;
  
  // linjer holder øje med hvor mange linjer data, som der er i filen 
  int linjer = 0;

 
  //læs alle linjer fra filen og sæt den ind i datas array 
  do 
  {
 
    read = fscanf(file,
                  "%c,%49[^,],%d,%lf\n",
                  &Datas[linjer].Enhed, 
                  Datas[linjer].rum, 
                  &Datas[linjer].tal, 
                  &Datas[linjer].tidspunkt); 
    
    
    //hvis fscanf læser 4 værdier fra filen, så er den succesfuld.
    if (read == 4) linjer++;
    
    
    if (read != 4 && !feof(file))
    {
      printf("File format incorrect.\n");
      return 1;
    }
    
    if (ferror(file))
    {
      printf("Error reading file.\n");
      return 1;
    }

  } while (!feof(file));

  //luk filen, der er blevet brugt færdigt. 
  fclose(file);
  
  
  //printer nummeret af linjer læst ud. 
  printf("\n%d linjer read.\n\n", linjer);
  
  
  // print hver linje ud i konsolen
  for (int i = 0; i < linjer; i++)
    printf("%c %s %d %.2f\n", 
           Datas[i].Enhed, 
           Datas[i].rum,
           Datas[i].tal,
           Datas[i].tidspunkt);
  printf("\n");

  return 0;
}