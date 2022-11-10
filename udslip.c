#include <stdio.h>


typedef struct
{
  float dag_1;
  float dag_2;
  float dag_3;
  float dag_4;
  float dag_5;
  float dag_6;
  float dag_7;
  float dag_8;
  float dag_9;
  float dag_10;
  float dag_11;
  float dag_12; 
}carbon;

carbon emission[300];


int main(void)
{
  // opretter variablen fil, for at kunne læse data.
  FILE *file;

  file = fopen("co2udledning.txt", "r");

  // Kommer med besked hvis filen ikke åbner.
  if (file == NULL)
  {
    printf("error opening file\n");
    return 1;
  }
  // array af structs til dataen.
   

  // bliver brugt til at tjekke om filen bliver læst ordenligt
  int read = 0;
  // variablen skal bruges til at kigge på hvor mange linjer der er i programmet, som kan bruges i koden længere nede.
  int linjer = 0;

  do // læs alle linjer af data og sæt dem ind i array af structs, som der passer til.
  {
    read = fscanf(file,
                  "%f ,%f ,%f ,%f ,%f ,%f ,%f ,%f ,%f ,%f ,%f ,%f",
                  &emission[linjer].dag_1,
                  &emission[linjer].dag_2,
                  &emission[linjer].dag_3,
                  &emission[linjer].dag_4,
                  &emission[linjer].dag_5,
                  &emission[linjer].dag_6,
                  &emission[linjer].dag_7,
                  &emission[linjer].dag_8,
                  &emission[linjer].dag_9,
                  &emission[linjer].dag_10,
                  &emission[linjer].dag_11,
                  &emission[linjer].dag_12);

    // hvis den kan læse alle 5 værdier, så betyder det at der er en linje.
    if (read == 12)
      linjer++;

    // hvis den ikke kan læse 5 værdier, og den ikke er nået til slutningen af filen, så print en fejlbesked.
    if (read != 12 && !feof(file))
    {
      printf("File format is incorrect.\n");
      return 1;
    }

  } while (!feof(file));

  fclose(file);

  printf("\n %d lines read.\n", linjer);


  int location = 0;int location_2 = 0;int location_3 = 0;int location_4 = 0;int location_5 = 0;int location_6 = 0;int location_7 = 0;
  int location_8 = 0;int location_9 = 0;int location_10 = 0;int location_11 = 0;int location_12 = 0;

  for (int i = 1; i < linjer; i++)
  {
    if (emission[i].dag_1 < emission[location].dag_1)
    {
      location = i;
    }

    if (emission[i].dag_2 < emission[location_2].dag_2)
    {
      location_2 = i;
    }

    if (emission[i].dag_3 < emission[location_3].dag_3)
    {
      location_3 = i;
    }

    if (emission[i].dag_4 < emission[location_4].dag_4)
    {
      location_4 = i;
    }

    if (emission[i].dag_5 < emission[location_5].dag_5)
    {
      location_5 = i;
    }

    if (emission[i].dag_6 < emission[location_6].dag_6)
    {
      location_6 = i;
    }

    if (emission[i].dag_7 < emission[location_7].dag_7)
    {
      location_7 = i;
    }

    if (emission[i].dag_8 < emission[location_8].dag_8)
    {
      location_8 = i;
    }

    if (emission[i].dag_9 < emission[location_9].dag_9)
    {
      location_9 = i;
    }

    if (emission[i].dag_10 < emission[location_10].dag_10)
    {
      location_10 = i;
    }

    if (emission[i].dag_11 < emission[location_11].dag_11)
    {
      location_11 = i;
    }

    if (emission[i].dag_12 < emission[location_12].dag_12)
    {
      location_12 = i;
    }

    
  }

  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 1 er kl: %d og udslippet er : %lf\n",location,emission[location].dag_1);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 2 er kl: %d og udslippet er : %lf\n",location_2,emission[location_2].dag_2);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 3 er kl: %d og udslippet er : %lf\n",location_3,emission[location_3].dag_3);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 4 er kl: %d og udslippet er : %lf\n",location_4,emission[location_4].dag_4);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 5 er kl: %d og udslippet er : %lf\n",location_5,emission[location_5].dag_5);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 6 er kl: %d og udslippet er : %lf\n",location_6,emission[location_6].dag_6);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 7 er kl: %d og udslippet er : %lf\n",location_7,emission[location_7].dag_7);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 8 er kl: %d og udslippet er : %lf\n",location_8,emission[location_8].dag_8);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 9 er kl: %d og udslippet er : %lf\n",location_9,emission[location_9].dag_9);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 10 er kl: %d og udslippet er : %lf\n",location_10,emission[location_10].dag_10);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 11 er kl: %d og udslippet er : %lf\n",location_11,emission[location_11].dag_11);
  printf("\nTidspunktet hvor der bliver udslippet mindst co2 paa dag 12 er kl: %d og udslippet er : %lf\n",location_12,emission[location_12].dag_12);








  return 0;
}



