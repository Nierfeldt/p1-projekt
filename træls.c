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
  // file pointer variable for accessing the file
  FILE *file;
  
  file = fopen("data.txt", "r"); 
  
  // if the file failed to open, exit with an error message and status
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  
  // array of structs for storing the Student data from the file
  Data Datas[100];
  
  // read will be used to ensure each line/record is read correctly
  int read = 0;
  
  // records will keep track of the number of Student records read from the file
  int records = 0;

  // read all records from the file and store them into the students array
  do 
  {
 
    read = fscanf(file,
                  "%c,%49[^,],%d,%lf\n",
                  &Datas[records].Enhed, 
                  Datas[records].rum, 
                  &Datas[records].tal, 
                  &Datas[records].tidspunkt); 
    
    // if fscanf read 4 values from the file then we've successfully read 
    // in another record
    if (read == 4) records++;
    
    
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

  // close the file as we are done working with it
  fclose(file);
  
  // print out the number of records read
  printf("\n%d records read.\n\n", records);
  
  // print out each of the records that was read 
  for (int i = 0; i < records; i++)
    printf("%c %s %d %.2f\n", 
           Datas[i].Enhed, 
           Datas[i].rum,
           Datas[i].tal,
           Datas[i].tidspunkt);
  printf("\n");

  return 0;
}