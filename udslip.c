#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS 24
#define NUM_COMMANDS 7
#define NUM_LINES 24


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


void skriv_alle_udslip_til_fil(FILE *fil, int xvals[], carbon ba[], int laengde);
void skriv_udslip_for_time_til_fil(FILE *fil, carbon b);

int main(void)
{
  // opretter variablen fil, for at kunne læse data.
  FILE *file;

  file = fopen("co2udledning.csv", "r");

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


  /*forslag til gnuplot flere grafer:  */
  
  char * commandsForGnuplot[] = {"set title \"Noget med CO2\"", "set xlabel \"Tid paa dagen\"",
  "set ylabel \"CO2-udslip i hvad\"", "set xrange [1:24]", "set yrange [0:300]", "set multiplot",
  "plot 'udslip.temp' using 1:2 w l title 'dag 1', \
     '' using 1:3 w l title 'dag 2', \
     '' using 1:4 w l title 'dag 3', \
     '' using 1:5 w l title 'dag 4', \
     '' using 1:6 w l title 'dag 5', \
     '' using 1:7 w l title 'dag 6', \
     '' using 1:8 w l title 'dag 7', \
     '' using 1:9 w l title 'dag 8', \
     '' using 1:10 w l title 'dag 9', \
     '' using 1:11 w l title 'dag 10', \
     '' using 1:12 w l title 'dag 11', \
     '' using 1:13 w l title 'dag 12' \
     "};
  int xvals[NUM_POINTS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
  //FILE *temp = tmpfile();
  FILE *temp = fopen("udslip.temp", "w");
  /*Opens an interface that one can use to send commands as if they were typing into the
    *     gnuplot command line.  "The -persistent" keeps the plot open even after your
    *     C program terminates.
    */
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  int i, days;
  
  skriv_alle_udslip_til_fil(temp, xvals, emission, NUM_LINES);
  /* nu er punkterne skrevet ind i en fil som:
   x y1 y2 y3 y4 y5 y6 y7 y8 y9 y10 y11 y12     altså: tid dag1 dag2 da3 dag4 dag5 dag6 dag7 dag8 dag9 dag10 dag11 dag12
   */

  for (i=0; i < NUM_COMMANDS; i++){
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
  }
  fclose(temp);
  
  return 0;
}




void skriv_alle_udslip_til_fil(FILE *fil, int xvals[], carbon ba[], int laengde){
  int i;
  for(i = 0; i < laengde; i++){
    fprintf(fil, "%d ", xvals[i]);
    skriv_udslip_for_time_til_fil(fil, ba[i]);
    fprintf(fil, "\n");
  }
}

void skriv_udslip_for_time_til_fil(FILE *fil, carbon b){
  fprintf(fil, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", 
    b.dag_1, b.dag_2, b.dag_3, b.dag_4, b.dag_5, b.dag_6, 
    b.dag_7, b.dag_8, b.dag_9, b.dag_10, b.dag_11, b.dag_12
  );
}

/*
# Set the output file type
set terminal postscript eps enhanced color solid colortext 9
# Set the output file name
set output 'multiple_plots.eps'

# Now plot the data with lines and points
plot 'data.txt' using 1:2 w l title 'y1', \
     '' using 1:3 w l title 'y2', \
     '' using 1:4 w l title 'y3', \
     '' using 1:4 w l title 'y4'
     */

/*"set xtics (1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24)",*/