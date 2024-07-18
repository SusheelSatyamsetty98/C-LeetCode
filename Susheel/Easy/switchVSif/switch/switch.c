#include <stdio.h>

int main() 
{
  int choice;

  // Displaying the menu options
  printf("Enter a number between 1 and 20: ");
  scanf("%d", &choice);

  // Switch-case statement with 20 cases
  switch(choice) {
    case 1:
      printf("You selected option 1.\n");
      break;
    case 2:
      printf("You selected option 2.\n");
      break;
    case 3:
      printf("You selected option 3.\n");
      break;
    case 4:
      printf("You selected option 4.\n");
      break;
    case 5:
      printf("You selected option 5.\n");
      break;
    case 6:
      printf("You selected option 6.\n");
      break;
    case 7:
      printf("You selected option 7.\n");
      break;
    case 8:
      printf("You selected option 8.\n");
      break;
    case 9:
      printf("You selected option 9.\n");
      break;
    case 10:
      printf("You selected option 10.\n");
      break;
    case 11:
      printf("You selected option 11.\n");
      break;
    case 12:
      printf("You selected option 12.\n");
      break;
    case 13:
      printf("You selected option 13.\n");
      break;
    case 14:
      printf("You selected option 14.\n");
      break;
    case 15:
      printf("You selected option 15.\n");
      break;
    case 16:
      printf("You selected option 16.\n");
      break;
    case 17:
      printf("You selected option 17.\n");
      break;
    case 18:
      printf("You selected option 18.\n");
      break;
    case 19:
      printf("You selected option 19.\n");
      break;
    case 20:
      printf("You selected option 20.\n");
      break;
    default:
      printf("Invalid option. Please select a number between 1 and 20.\n");
      break;
  }

  return 0;
} 
