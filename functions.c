#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


//#1
char* ReverseWords(char* str)
{
   int len = strlen(str);

   char* temp = malloc((len+1) * sizeof(char));

   int first = 0;
   int last = 0;
   int flag = 0;

   for (int i = 0; i < strlen(str); i++)
   {
      if (flag == 0 && str[i] == ' ')
      {
         first = i;
         flag = 1;
      }
      if (str[i] == ' ')
         last = i;
   }

   int final = 0;
   for (int i = last + 1; i < strlen(str); i++) {
      temp[final] = str[i];
      final++;
   }
   temp[final] = ' ';
   final++;
   
   for (int i = first + 1; i < last; i++)
   {
      temp[final] = str[i];
      final++;
   }
   temp[final] = ' ';
   final++;
   
   for (int i = 0; i < first; i++)
   {
      temp[final] = str[i];
      final++;
   }
   temp[final] = '\0';
   str = temp;

   return str;

}

//#2
void people()
{
   setlocale(LC_ALL, "russian");
   struct people
   {
      char lastname[50];
      char firstname[50];
      char patronimic[50];
      char sex[2];
      char job[50];
      int day;
      int month;
      int year;
   };

   int amount = 0;
   printf("Введите количество людей\n");
   scanf_s("%d", &amount);

   struct people* list = (struct people*)malloc(amount * sizeof(struct people));

   printf("Введите данные в следующем порядке: \n-фамилия\n-имя\n-отчество\n-пол(м или ж)\n-профессия\n-дата рождения(день, месяц, год через пробелы)\n");

   for (int i = 0; i < amount; ++i)
   {
      scanf_s("%s", &list[i].lastname, 50);
      scanf_s("%s", &list[i].firstname, 50); 
      scanf_s("%s", &list[i].patronimic, 50); 
      scanf_s("%s", &list[i].sex, 2);
      scanf_s("%s", &list[i].job, 50);
      scanf_s("%d %d %d", &list[i].day, &list[i].month, &list[i].year);
   }

   for (int i = 0; i < amount; i++)
   {
      if (strcmp(list[i].job, "Инженер") == 0)
      {
         if (strcmp(list[i].sex, "м") == 0)
         {
            if (list[i].year <= 2021-65)
            {
               printf("%s %s %s, %s, %s, %d.%d.%d", list[i].firstname, 
                  list[i].firstname, list[i].patronimic, list[i].sex, list[i].job, 
                  list[i].day, list[i].month, list[i].year);
            }
         }
         else
         {
            if (list[i].year <= 2021-60)
            {
               printf("%s %s %s, %s, %s, %d.%d.%d", list[i].firstname,
                  list[i].firstname, list[i].patronimic, list[i].sex, list[i].job,
                  list[i].day, list[i].month, list[i].year);
            }
         }
      }
   }
}



//#3
void CopyCutPaste()
{
   
   
   FILE* f = NULL;
   FILE* g = NULL;

   errno_t err;
   err = fopen_s(&f, "f.txt", "r");
   if (err)
   {
      perror("f.txt opening error");
      return;
   }
   if (!f)
   {
      perror("f.txt opening error");
      return;
   }

   err = fopen_s(&g, "g.txt", "w");
   if (err)
   {
      perror("g.txt opening error");
      return;
   }
   if (!g)
   {
      perror("g.txt opening error");
      return;
   }
   

   int spacecount = 1;

   for (char sym; fscanf_s(f, "%c", &sym,4) != EOF;)
   {
      if (sym == ' ')
         ++spacecount;
      if (sym == 'П' || sym == 'п' || spacecount % 4 == 0)
      {
         while (sym != ' ')
            fscanf_s(f, "%c", &sym,4);
      }
      else
         fprintf_s(g, "%c", sym);
   }


   err = fclose(f);
   if (err)
   {
      perror("f.txt closure error");
      return;
   }
   err = fclose(g);
   if (err)
   {
      perror("g.txt closure error");
      return;
   }
}
