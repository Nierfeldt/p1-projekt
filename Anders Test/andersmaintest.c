#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS 6
#define NUM_COMMANDS 14

typedef struct // Koekken,stue,bad,værelse,soveværelse.
{
  float bad;
  float koekken;
  float sovevaerelse;
  float stue;
  float vaerelse;
} rum;

// array af structs til dataen.
rum data[200];

int average(rum data[], int linjer);


int main(void){
  // opretter fil til dage, og læser data fra fil.
    FILE *file = fopen("data.csv", "r");

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
    read = fscanf(file,"%f;%f;%f;%f;%f\n",
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

  float gns_husstand_2pers = 9.449315068;

  // udregning af sum, for at få gennemsnit.
  for (int i = 0; i < linjer; i++){
    sum_bad = sum_bad + data[i].bad;
    sum_koekken = sum_koekken + data[i].koekken;
    sum_sovevaerelse = sum_sovevaerelse + data[i].sovevaerelse;
    sum_stue = sum_stue + data[i].stue;
    sum_vaerelse = sum_vaerelse + data[i].vaerelse;
  }

  float gns_bad = 0;
  float gns_koekken = 0;
  float gns_sovevaerelse = 0;
  float gns_stue = 0;
  float gns_vaerelse = 0;

  // udregning af sum, for at få gennemsnit.
  for (int i = 0; i < linjer; i++){
    gns_bad = (sum_bad + data[i].bad)/7;
    gns_koekken = (sum_koekken + data[i].koekken)/7;
    gns_sovevaerelse = (sum_sovevaerelse + data[i].sovevaerelse)/7;
    gns_stue = (sum_stue + data[i].stue)/7;
    gns_vaerelse = (sum_vaerelse + data[i].vaerelse)/7;
  }
  float gns_samlet = (gns_bad + gns_koekken + gns_sovevaerelse + gns_stue + gns_vaerelse);

  float day1_bad = 0;
  float day1_koekken = 0;
  float day1_sovevaerelse = 0;
  float day1_stue = 0;
  float day1_vaerelse = 0;

  // divider summen med antal elementer, som er linjer, for  at få gennemsnit.
  for (int i = 0; i < 23; i++){
    day1_bad = day1_bad + data[i].bad;
    day1_koekken = day1_koekken + data[i].koekken;
    day1_sovevaerelse = day1_sovevaerelse + data[i].sovevaerelse;
    day1_stue = day1_stue + data[i].stue;
    day1_vaerelse = day1_vaerelse + data[i].vaerelse;
  }
  float day1_samlet = (day1_bad + day1_koekken + day1_sovevaerelse + day1_stue + day1_vaerelse);
  
  char * commandsForGnuplot[] = {
    "set title \"Dit stroemforbrug\"", 
    "set xlabel \"Rum\"", 
    "set ylabel \"kWh over 24 timer\"", 
    "set boxwidth 0.4", 
    "set style fill   solid 1.00 border lt -1",
    "set yrange [0:12]", 
    "set xtics   (\"Samlet\" 1.00000, \"Bad\" 2.20000, \"Koekken\" 3.2000, \"Sovevaerelse\" 4.2000, \"Stue\" 5.2000, \"Vaerelse\" 6.2000)", 
    "set xtic rotate by -45 scale 0",
    "set grid y",
    "set tics scale 0", 
    "set xzeroaxis", 
    "plot 'data.temp' smooth freq w boxes title \"kWh seneste dag\"",
    "replot 'data2.temp' smooth freq w boxes title \"kWh uge gennemsnit\"",
    "replot 'data3.temp' smooth freq w boxes title \"kWh gennemsnitlig husstand\""
    };
  
  double xvals[NUM_POINTS] = {0.6 , 2, 3, 4, 5, 6};
  double xvals2[NUM_POINTS] = {1.0 ,2.4, 3.4, 4.4, 5.4, 6.4};
  double xvals3[NUM_POINTS] = {1.4 ,2.4, 3.4, 4.4, 5.4, 6.4};
  double yvals[NUM_POINTS] = {day1_samlet, day1_bad, day1_koekken, day1_sovevaerelse, day1_stue, day1_vaerelse};
  double yvals2[NUM_POINTS] = {gns_samlet, gns_bad, gns_koekken, gns_sovevaerelse, gns_stue, gns_vaerelse};
  double yvals3[NUM_POINTS] = {gns_husstand_2pers, 0, 0, 0, 0, 0};
  FILE * temp = fopen("data.temp", "w");
  FILE * temp2 = fopen("data2.temp", "w");
  FILE * temp3 = fopen("data3.temp", "w");
  /*Opens an interface that one can use to send commands as if they were typing into the
    *     gnuplot command line.  "The -persistent" keeps the plot open even after your
    *     C program terminates.
    */
  
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");

  for (int i=0; i < NUM_POINTS; i++){
  fprintf(temp, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file
  }
  for (int i=0; i < NUM_POINTS; i++){
  fprintf(temp2, "%lf %lf \n", xvals2[i], yvals2[i]); //Write the data to a temporary file
  }
  for (int i=0; i < NUM_POINTS; i++){
  fprintf(temp3, "%lf %lf \n", xvals3[i], yvals3[i]); //Write the data to a temporary file
  }

  for (int i=0; i < NUM_COMMANDS; i++){
  fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
  }
  return 0;

}


