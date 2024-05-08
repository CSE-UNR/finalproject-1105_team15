// Jack Smith & Ryleigh Romero
#include <stdio.h>

#define IMAGE_SIZE 25
#define character_map_size 5

//char character_map[character_map_size] = {' ', '.', 'o', 'O', '0'};
int current_image[IMAGE_SIZE][IMAGE_SIZE] = {0}; // Current data for the image

// Forward declarations
void crop_image();
void dim_image();
void brighten_image();
void rotate_image();
void save_image();

char print_menu() {
   char c;
    printf("\nMenu:\n");
    printf("1. Load a new image\n2. Display the current image\n3. Edit the current image\n4. Exit the program\n");
    printf("Enter your choice: ");
    scanf(" %c", &c);
    return c;
}
    void load_image(int image[][IMAGE_SIZE]) {
    char filename[50];
    FILE *file;
   printf("Enter the filename of the image: ");
    scanf("%s", filename);
   printf("\n");
   file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;}
// Read the image data into the matrix
//add an if function
  //  if (rows != '\n'); {
        //cols++;
       // if (cols == IMAGE_SIZE) {
          //  rows++;
        //    cols = 0;
        //} }
          for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            fscanf(file, " %c", &image[i][j]); 
        }
    }
    //for (int i = 0; i < IMAGE_SIZE; i++) {
        //for (int j = 0; j < IMAGE_SIZE; j++) {
           // if (fscanf(file, "%d", &current_image[i][j]) != 1) {
              //  printf("Invalid format in file.\n");
               // fclose(file);
               // return;
            //}
        
      fclose(file); 
      printf("Image loaded!\n");
      }

void display_image(int image[][IMAGE_SIZE]) {
    printf("Displaying image:\n");
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
        if (image[i][j] == 0) {
        printf(" ");
        }
        else if (image[i][j] == '1') {
        printf(".");
        }
        else if (image[i][j] == '2') {
        printf("o");
        }
        else if (image[i][j] == '3') {
        printf("O");
        }
        else if(image[i][j] == '4') {
        printf("0");
        }
        else{
        printf(" ");
       }
      // char index = image[i][j]; 
           // switch (index) {
            //    case 0:
               //     image[i][j] = ' ';  
               //     break;
            //    case 1:
               //     image[i][j] = '.';  
               //     break;
               // case 2:
              //      image[i][j] = 'o';  
               //     break;
              //  case 3:
               //     image[i][j] = 'O';  
                 //   break;
              //  case 4:
                //    image[i][j] = '0';  
                 //   break;
           //    default:
                  //  image[i][j] = '?';  
                   // break;
          }
         printf("\n"); }     
    }
void edit_menu() {
    while (1) {
        printf("\nEdit Menu:\n1. Crop\n2. Dim\n3. Brighten\n4. Rotate 90 Degrees\n5. Save image\n6. Return to main menu\n");
        printf("Enter your choice: ");
        char edit_choice;
        scanf(" %c", &edit_choice);
        switch (edit_choice) {
            case '1':
                crop_image();
                break;
            case '2':
                dim_image();
                break;
            case '3':
                brighten_image();
                break;
            case '4':
                rotate_image();
                break;
            case '5':
                save_image();
                break;
            case '6':
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void crop_image() {
   int start_row, end_row, start_col, end_col;
    
    printf("Enter starting row for cropping: ");
    scanf("%d", &start_row);
    printf("Enter ending row for cropping: ");
    scanf("%d", &end_row);
    printf("Enter starting column for cropping: ");
    scanf("%d", &start_col);
    printf("Enter ending column for cropping: ");
    scanf("%d", &end_col);
    
    // Validate input coordinates
    if (start_row < 0 || start_row >= IMAGE_SIZE || end_row < 0 || end_row >= IMAGE_SIZE ||
        start_col < 0 || start_col >= IMAGE_SIZE || end_col < 0 || end_col >= IMAGE_SIZE ||
        start_row > end_row || start_col > end_col) {
        printf("Invalid cropping coordinates.\n");
        return;
    }
    
    // Calculate dimensions of cropped_image array
    int cropped_rows = end_row - start_row + 1;
    int cropped_cols = end_col - start_col + 1;
    
    // Create a temporary array to store the cropped image
    int cropped_image[cropped_rows][cropped_cols];
    
    // Copy pixels from the specified region to the temporary array
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_col; j <= end_col; j++) {
            cropped_image[i - start_row][j - start_col] = current_image[i][j];
        }
    }
    
    // Copy the cropped image back to the current_image array
    for (int i = 0; i < cropped_rows; i++) {
        for (int j = 0; j < cropped_cols; j++) {
            current_image[i + start_row][j + start_col] = cropped_image[i][j];
        }
    }
    printf("Image cropped!\n");
}
void dim_image() {
    // Iterate over each pixel in the current_image array
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            // Decrease the brightness of each pixel by one step
            if (current_image[i][j] > 0) {
                current_image[i][j]--; // Decrease brightness by one step
            }
        }
    }
    printf("Image dimmed!\n");
}

void brighten_image() {
    // Iterate over each pixel in the current_image array
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            // Increase the brightness of each pixel by one step
            if (current_image[i][j] < 4) {
                current_image[i][j]++; // Increase brightness by one step
            }
        }
    }
    printf("Image brightened!\n");
}

void rotate_image() {
    int rotated_image[IMAGE_SIZE][IMAGE_SIZE]; // Temporary array to store rotated image
    // Iterate over each pixel in the current_image array
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            // Rotate the pixel to its new position
            rotated_image[j][IMAGE_SIZE - 1 - i] = current_image[i][j];
        }
    }

    // Copy the rotated image back to the current_image array
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            current_image[i][j] = rotated_image[i][j];
        }
    }
    printf("Image rotated!\n");
}

void save_image() {
    char filename[50];
    printf("Enter the filename to save the image: ");
    scanf("%s", filename);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            fprintf(file, "%d ", current_image[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Image saved to %s successfully!\n", filename);
}

//int exit_program() {
  //  printf("Exiting the program.\n");
   // return 0;
    // Terminate the program
//}

int main() {
	char choice; 
	int image[IMAGE_SIZE][IMAGE_SIZE]={0};
    do {choice = print_menu();
        switch (choice) {
            case '1':
   		load_image(image);
                break;
            case '2':
                display_image(image);
                break;
            case '3':
                edit_menu();
                break;
            case '4':
            printf("Ending program \n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        } 
    }  while (choice != '4');
    return 0;
}
