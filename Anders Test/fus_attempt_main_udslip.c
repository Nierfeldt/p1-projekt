#include <stdio.h>
#include <stdlib.h>

#define NUM_POINTS_ROOM 6
#define NUM_COMMANDS_ROOM 14

#define NUM_POINTS_EMISSION 24
#define NUM_COMMANDS_EMISSION 7
#define NUM_LINES_EMISSION 24


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


void average(rum data[], int linjer);

void skriv_alle_udslip_til_fil(FILE *fil, int xvals[], carbon ba[], int laengde);
void skriv_udslip_for_time_til_fil(FILE *fil, carbon b);
int udslip_time_dag(void);
int rum_el_brug(void);
void reminder(float samlet_gns, float *valg_bolig_energi);


void plot_grafer_both(void); /* nok FILE *noget, FILE *noget bum bum.*/

/*det eller også skal der returneres nogle værdier til main */

int main(void){
  
  udslip_time_dag();
  rum_el_brug();

  return 0;
}

int udslip_time_dag(void)
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
  
  char * commandsForGnuplot[] = {"set title \"CO_2 udslip pr. time for forskellige dage\"", "set xlabel \"Tid paa dagen\"",
  "set ylabel \"CO_2 udslip i gram pr kwh.\"", "set xrange [1:24]", "set xtics 1", "set yrange [0:300]", 
  "plot 'udslip.temp' using 1:2 w l lw 2 title 'dag 1', \
     '' using 1:3 w l lw 2 title 'dag 2', \
     '' using 1:4 w l lw 2 title 'dag 3', \
     '' using 1:5 w l lw 2 title 'dag 4', \
     '' using 1:6 w l lw 2 title 'dag 5', \
     '' using 1:7 w l lw 2 title 'dag 6', \
     '' using 1:8 w l lw 2 title 'dag 7' \
     "};
  int xvals[NUM_POINTS_EMISSION] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
  //FILE *temp = tmpfile();
  FILE *temp_emission = fopen("udslip.temp", "w");
  /*Opens an interface that one can use to send commands as if they were typing into the
    *     gnuplot command line.  "The -persistent" keeps the plot open even after your
    *     C program terminates.
    */
  FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
  int i, days;
  
  skriv_alle_udslip_til_fil(temp_emission, xvals, emission, NUM_LINES_EMISSION);
  /* nu er punkterne skrevet ind i en fil som:
   x y1 y2 y3 y4 y5 y6 y7 y8 y9 y10 y11 y12     altså: tid dag1 dag2 da3 dag4 dag5 dag6 dag7 dag8 dag9 dag10 dag11 dag12
   */

  for (i=0; i < NUM_COMMANDS_EMISSION; i++){
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
  }
  fclose(temp_emission);
  
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


int rum_el_brug(void)
{  // opretter fil til dage, og læser data fra fil.
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
 
}

void average(rum data[], int linjer){
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
  
  double xvals[NUM_POINTS_ROOM] = {0.6 , 2, 3, 4, 5, 6};
  double xvals2[NUM_POINTS_ROOM] = {1.0 ,2.4, 3.4, 4.4, 5.4, 6.4};
  double xvals3[NUM_POINTS_ROOM] = {1.4 ,2.4, 3.4, 4.4, 5.4, 6.4};
  double yvals[NUM_POINTS_ROOM] = {day1_samlet, day1_bad, day1_koekken, day1_sovevaerelse, day1_stue, day1_vaerelse};
  double yvals2[NUM_POINTS_ROOM] = {gns_samlet, gns_bad, gns_koekken, gns_sovevaerelse, gns_stue, gns_vaerelse};
  double yvals3[NUM_POINTS_ROOM] = {gns_husstand_2pers, 0, 0, 0, 0, 0};
  FILE * temp_kwh = fopen("data.temp", "w");
  FILE * temp_kwh2 = fopen("data2.temp", "w");
  FILE * temp_kwh3 = fopen("data3.temp", "w");
  /*Opens an interface that one can use to send commands as if they were typing into the
    *     gnuplot command line.  "The -persistent" keeps the plot open even after your
    *     C program terminates.
    */
  
  FILE * gnuplotPipe2 = popen ("gnuplot -persistent", "w");

  for (int i=0; i < NUM_POINTS_ROOM; i++){
  fprintf(temp_kwh, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file
  }
  for (int i=0; i < NUM_POINTS_ROOM; i++){
  fprintf(temp_kwh2, "%lf %lf \n", xvals2[i], yvals2[i]); //Write the data to a temporary file
  }
  for (int i=0; i < NUM_POINTS_ROOM; i++){
  fprintf(temp_kwh3, "%lf %lf \n", xvals3[i], yvals3[i]); //Write the data to a temporary file
  }

  for (int i=0; i < NUM_COMMANDS_ROOM; i++){
  fprintf(gnuplotPipe2, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
  }


}

void reminder(float samlet_gns, float *valg_bolig_energi){
  int bolig_type = 0;
  int bolig_stoerelse = 0;
  int beboer = 0;
  float valgt_bolig_energi = 0;

  printf("Bor du i hus eller lejlighed? (1/2): ");
  scanf("%d", &bolig_type);
  printf("Hvor stor er din bolig? (1: 60-99 kvm / 2: 100-129 kvm / 3: 130-160 kvm): ");
  scanf("%d", &bolig_stoerelse);
  printf("Hvor mange personer bor i din bolig? (1/2/3/4/5): ");
  scanf("%d", &beboer);

  if (bolig_type == 1){
    if (bolig_stoerelse == 1){
      switch (beboer){
      case 1:
        valgt_bolig_energi = 5.980822;
        break;
      case 2:
        valgt_bolig_energi = 8.030137;
        break;
      case 3:
        valgt_bolig_energi = 10.079452;
        break;
      case 4:
        valgt_bolig_energi = 12.128767;
        break;
      case 5:
        valgt_bolig_energi = 14.178082;
        break;
      }
    }else if (bolig_stoerelse == 2){
      switch (beboer){
      case 1:
        valgt_bolig_energi = 7.084932;
        break;
      case 2:
        valgt_bolig_energi = 9.134247;
        break;
      case 3:
        valgt_bolig_energi = 11.183562;
        break;
      case 4:
        valgt_bolig_energi = 13.232877;
        break;
      case 5:
        valgt_bolig_energi = 15.282192;
        break;
      }
    }else if (bolig_stoerelse == 3){
      switch (beboer){
      case 1:
        valgt_bolig_energi = 8.030137;
        break;
      case 2:
        valgt_bolig_energi = 10.079452;
        break;
      case 3:
        valgt_bolig_energi = 12.128767;
        break;
      case 4:
        valgt_bolig_energi = 14.178082;
        break;
      case 5:
        valgt_bolig_energi = 16.227397;
        break;
      }
    } 
  }

  if (bolig_type == 2){
    if (bolig_stoerelse == 1){
      switch (beboer){
      case 1:
        valgt_bolig_energi = 5.145205;
        break;
      case 2:
        valgt_bolig_energi = 5.808219;
        break;
      case 3:
        valgt_bolig_energi = 6.471233;
        break;
      case 4:
        valgt_bolig_energi = 7.134246;
        break;
      case 5:
        valgt_bolig_energi = 7.797260;
        break;
      }
    }else if (bolig_stoerelse == 2){
      switch (beboer){
      case 1:
        valgt_bolig_energi = 5.961644;
        break;
      case 2:
        valgt_bolig_energi = 6.624658;
        break;
      case 3:
        valgt_bolig_energi = 7.287671;
        break;
      case 4:
        valgt_bolig_energi = 7.950685;
        break;
      case 5:
        valgt_bolig_energi = 8.613698;
        break;
      }
    }else if (bolig_stoerelse == 3){
      switch (beboer){
      case 1:
        valgt_bolig_energi = 6.660274;
        break;
      case 2:
        valgt_bolig_energi = 7.323288;
        break;
      case 3:
        valgt_bolig_energi = 7.986301;
        break;
      case 4:
        valgt_bolig_energi = 8.649315;
        break;
      case 5:
        valgt_bolig_energi = 9.312329;
        break;
      }
    }
  }

  if (valgt_bolig_energi < samlet_gns){
    printf("\n\n***ADVARSEL***\n");
    printf("Dit daglige stroemforbrug er over gennemsnittet for en tilsvarende husstand\n");
    printf("Dit forbrug: %lf\nTilsvarende husstand: %lf\n", samlet_gns, valgt_bolig_energi);
    printf("***ADVARSEL***\n");
  }
  
  
}

void multiplot(FILE *fil_co2, FILE *fil_kwh){
    /* eksempel paa brug af multiplot fra:
    https://stackoverflow.com/questions/56477986/double-column-plot-in-gnuplot-multiplot
    ### Multiplot layout
reset session
set multiplot title "These are five plots"
set ytics 0.5

set margins 5,5,2,8 # l,r,b,t

set size 1,0.5
set origin 0,0.6
set title "top plot"
plot sin(x) title "this should be a single plot"

set size 0.5,0.5

set origin 0,0.3
set title "A!"
plot sin(x)

set origin 0.5,0.3
set title "B!"
plot cos(x)

set origin 0,0
set title "C!"
plot sin(2*x)

set origin 0.5,0
set title "D"
plot cos(2*x)

unset multiplot
### end of code*/
}
/*
lav fil pointers i main og kald funktionerne med parametre.
saa kan de kaldes i multiplotfunktionen
*/

void co2_per_rum(void){
    /*emission struct / array til gennemsnit af co2 ud i gram/kwh
    derefter rum med de forskellige kwh over 24 timer.*/

    /* for(i = 0 ; i < NOGET; i++){
        sum = sum + emission [i];
       }
       gns_co2 = sum / 24;
       (det burde så give et gennemsnits estimat af (gram co2)/kwh for dagen [??] som kan bruges til søjlediagram)
       (hvis man tager de individuelle khw over 24 timer og påfører det tidligere gns, vil man få en tilnærmelse af co2 for de forskellige rum)
       (dog med den tilfoejelse at co2 udledning svinger fra dag til dag og hen over dagen)
       */
}