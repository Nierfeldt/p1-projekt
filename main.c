#include <stdio.h>

typedef struct // Koekken,stue,bad,værelse,soveværelse.
{
  float bad;
  float koekken;
  float sovevaerelse;
  float stue;
  float vaerelse;
} rum;

// array af structs til dataen.
rum data[100];


int average(rum data[], int linjer);

int main(void)
{
  // opretter variablen fil, for at kunne læse data.
  FILE *file;

  file = fopen("data.csv", "r");

  // Kommer med besked hvis filen ikke åbner.
  if (file == NULL)
  {
    printf("error opening file\n");
    return 1;
  }
  
  // bliver brugt til at tjekke om filen bliver læst ordenligt
  int read = 0;
  // variablen skal bruges til at kigge på hvor mange linjer der er i programmet, som kan bruges i koden længere nede.
  int linjer = 0;

  do // læs alle linjer af data og sæt dem ind i array af structs, som der passer til.
  {
    read = fscanf(file,
                  "%f ,%f ,%f ,%f ,%f \n",
                  &data[linjer].bad,
                  &data[linjer].koekken,
                  &data[linjer].sovevaerelse,
                  &data[linjer].stue,
                  &data[linjer].vaerelse);

    // hvis den kan læse alle 5 værdier, så betyder det at der er en linje.
    if (read == 5)
      linjer++;

    // hvis den ikke kan læse 5 værdier, og den ikke er nået til slutningen af filen, så print en fejlbesked.
    if (read != 5 && !feof(file))
    {
      printf("File format is incorrect.\n");
      return 1;
    }

  } while (!feof(file));

  fclose(file);

  printf("\n %d lines read.\n", linjer);

  // print hver linje data ud i konsolen.
  for (int i = 0; i < linjer; i++)
  {
    printf("%lf %lf %lf %lf %lf",
           data[i].bad,
           data[i].koekken,
           data[i].sovevaerelse,
           data[i].stue,
           data[i].vaerelse);
    printf("\n");
  }


  average(data, linjer);
  return 0;
}

int average(rum data[], int linjer){
  float sum_bad = 0;
  float sum_koekken = 0;
  float sum_sovevaerelse = 0;
  float sum_stue = 0;
  float sum_vaerelse = 0;

  // udregning af sum, for at få gennemsnit.
  for (int i = 0; i < linjer; i++)
  {
    sum_bad = sum_bad + data[i].bad;
    sum_koekken = sum_koekken + data[i].koekken;
    sum_sovevaerelse = sum_sovevaerelse + data[i].sovevaerelse;
    sum_stue = sum_stue + data[i].stue;
    sum_vaerelse = sum_vaerelse + data[i].vaerelse;
  }

  float gennemsnit_af_bad = 0;
  float gennemsnit_koekken = 0;
  float gennemsnit_sovevaerelse = 0;
  float gennemsnit_stue = 0;
  float gennemsnit_vaerelse = 0;

  // divider summen med antal elementer, som er linjer, for  at få gennemsnit.
  gennemsnit_af_bad = sum_bad / linjer;
  gennemsnit_koekken = sum_koekken / linjer;
  gennemsnit_sovevaerelse = sum_sovevaerelse / linjer;
  gennemsnit_stue = sum_stue / linjer;
  gennemsnit_vaerelse = sum_vaerelse / linjer;

  printf("\nGennemsnit kW paa bad brugt over %d antal timer er %lfkW\n", linjer, gennemsnit_af_bad);
  printf("\nGennemsnit kW paa koekken brugt over %d antal timer er %lfkW\n", linjer, gennemsnit_koekken);
  printf("\nGennemsnit kW paa sovevaerelse brugt over %d antal timer er %lfkW\n", linjer, gennemsnit_sovevaerelse);
  printf("\nGennemsnit kW paa stue brugt over %d antal timer er %lfkW\n", linjer, gennemsnit_stue);
  printf("\nGennemsnit kW paa vaerelset brugt over %d antal timer er %lfkW\n", linjer, gennemsnit_vaerelse);
  
  return 0;
}
