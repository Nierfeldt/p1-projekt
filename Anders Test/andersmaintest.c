#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS 6
#define NUM_COMMANDS 12

typedef struct // Koekken,stue,bad,værelse,soveværelse.
{
  float bad;
  float koekken;
  float sovevaerelse;
  float stue;
  float vaerelse;
} rum;

// array af structs til dataen.
rum day1_data[100];

int average(rum data[], int linjer);


int main(void){
  // opretter fil til dage, og læser data fra fil.
  FILE *day1; 
  day1 = fopen("Day2.csv", "r");
  /*
  FILE *day2 = fopen("Day2.csv", "r");
  FILE *day3 = fopen("Day3.csv", "r");
  FILE *day4 = fopen("Day4.csv", "r");
  FILE *day5 = fopen("Day5.csv", "r");
  FILE *day6 = fopen("Day6.csv", "r");
  FILE *day7 = fopen("Day7.csv", "r");
  */
 

  // Kommer med besked hvis filen ikke åbner.
  if (day1 == NULL){
    printf("error opening file\n");
    return 1;
  }
  
  // bliver brugt til at tjekke om filen bliver læst ordenligt
  int read = 0;
  // variablen skal bruges til at kigge på hvor mange linjer der er i programmet, som kan bruges i koden længere nede.
  int linjer = 0;

// læs alle linjer af data og sæt dem ind i array af structs, som der passer til.
  do{
    read = fscanf(day1,
                  "%f; %f; %f; %f; %f \n",
                  &day1_data[linjer].bad,
                  &day1_data[linjer].koekken,
                  &day1_data[linjer].sovevaerelse,
                  &day1_data[linjer].stue,
                  &day1_data[linjer].vaerelse);

    // hvis den kan læse alle 5 værdier, så betyder det at der er en linje.
    if (read == 5)
      linjer++;

    // hvis den ikke kan læse 5 værdier, og den ikke er nået til slutningen af filen, så print en fejlbesked.
    if (read != 5 && !feof(day1)){
      printf("File format is incorrect.\n");
      return 1;
    }

  } while (!feof(day1));

  fclose(day1);

  printf("\n %d lines read.\n", linjer);

  // print hver linje data ud i konsolen.
  for (int i = 0; i < linjer; i++)
  {
    printf("%lf %lf %lf %lf %lf",
           day1_data[i].bad,
           day1_data[i].koekken,
           day1_data[i].sovevaerelse,
           day1_data[i].stue,
           day1_data[i].vaerelse);
    printf("\n");
  }


  average(day1_data, linjer);
  return 0;
}

int average(rum data[], int linjer){
  float sum_bad = 0;
  float sum_koekken = 0;
  float sum_sovevaerelse = 0;
  float sum_stue = 0;
  float sum_vaerelse = 0;

  // udregning af sum, for at få gennemsnit.
  for (int i = 0; i < linjer; i++){
    sum_bad = sum_bad + data[i].bad;
    sum_koekken = sum_koekken + data[i].koekken;
    sum_sovevaerelse = sum_sovevaerelse + data[i].sovevaerelse;
    sum_stue = sum_stue + data[i].stue;
    sum_vaerelse = sum_vaerelse + data[i].vaerelse;
  }

  float gns_bad_24 = 0;
  float gns_koekken_24 = 0;
  float gns_sovevaerelse_24 = 0;
  float gns_stue_24 = 0;
  float gns_vaerelse_24 = 0;

  float samlet_24 = (sum_bad+sum_koekken+sum_sovevaerelse+sum_stue+sum_vaerelse);

  // divider summen med antal elementer, som er linjer, for  at få gennemsnit.
  gns_bad_24 = sum_bad / linjer;
  gns_koekken_24 = sum_koekken / linjer;
  gns_sovevaerelse_24 = sum_sovevaerelse / linjer;
  gns_stue_24 = sum_stue / linjer;
  gns_vaerelse_24 = sum_vaerelse / linjer;

/*
  printf("\nGennemsnit kW paa bad brugt over %d antal timer er %lfkW\n", linjer, gns_bad_24);
  printf("\nGennemsnit kW paa koekken brugt over %d antal timer er %lfkW\n", linjer, gns_koekken_24);
  printf("\nGennemsnit kW paa sovevaerelse brugt over %d antal timer er %lfkW\n", linjer, gns_sovevaerelse_24);
  printf("\nGennemsnit kW paa stue brugt over %d antal timer er %lfkW\n", linjer, gns_stue_24);
  printf("\nGennemsnit kW paa vaerelset brugt over %d antal timer er %lfkW\n", linjer, gns_vaerelse_24);
*/
  
  char * commandsForGnuplot[] = {
    "set title \"Dit stroemforbrug\"", 
    "set xlabel \"Rum\"", 
    "set ylabel \"kWh over 24 timer\"", 
    "set boxwidth 0.8", 
    "set style fill   solid 1.00 border lt -1",
    "set yrange [0:15]", 
    "set xtics   (\"Samlet\" 1.00000, \"Bad\" 2.00000, \"Koekken\" 3.0000, \"Sovevaerelse\" 4.0000, \"Stue\" 5.0000, \"Vaerelse\" 6.0000)", 
    "set xtic rotate by -45 scale 0",
    "unset border", 
    "set tics scale 0", 
    "set xzeroaxis", 
    "plot 'data.temp' smooth freq w boxes"
    };
  
  double xvals[NUM_POINTS] = {1.0 ,2.0, 3.0, 4.0, 5.0, 6.0};
  double yvals[NUM_POINTS] = {samlet_24, sum_bad, sum_koekken, sum_sovevaerelse, sum_stue, sum_vaerelse};
  FILE * temp = fopen("data.temp", "w");
  /*Opens an interface that one can use to send commands as if they were typing into the
    *     gnuplot command line.  "The -persistent" keeps the plot open even after your
    *     C program terminates.
    */
  
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  int i;

  for (i=0; i < NUM_POINTS; i++){
  fprintf(temp, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file
  }

  for (i=0; i < NUM_COMMANDS; i++){
  fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
  }
  return 0;

}


