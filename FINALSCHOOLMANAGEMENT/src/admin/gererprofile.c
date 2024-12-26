#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "/home/wiem/Desktop/mei/uni/projects/C/FINALSCHOOLMANAGEMENT/header/admin/admin.h"

#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50
#define CREDENTIALS_FILE "admin_credentials.txt"

// Function to generate a random phrase for password confirmation
void generate_random_phrase(char *phrase, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=<>?";
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int key = rand() % (sizeof(charset) - 1);
        phrase[i] = charset[key];
    }
    phrase[length] = '\0'; // Null-terminate the string
}

// Function to validate password (uppercase, lowercase, number, symbol)
int is_valid_password(const char *password) {
    int has_upper = 0, has_lower = 0, has_digit = 0, has_symbol = 0;

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (strchr("!@#$%^&*()_-+=<>?", password[i])) has_symbol = 1;
    }

    return has_upper && has_lower && has_digit && has_symbol;
}

// Function to prompt for password input with masking
void prompt_password(char *password) {
    char ch;
    int i = 0;
    while (1) {
        ch = getchar();
        if (ch == '\n') {
            password[i] = '\0';
            break;
        } else if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    printf("\n");
}

// Function to read the admin credentials from the file
void read_credentials(char *username, char *password) {
    FILE *file = fopen(CREDENTIALS_FILE, "r");
    if (file == NULL) {
        printf("Error reading credentials file!\n");
        exit(1);
    }

    fgets(username, MAX_USERNAME_LENGTH, file);
    username[strcspn(username, "\n")] = 0; // Remove newline character
    fgets(password, MAX_PASSWORD_LENGTH, file);
    password[strcspn(password, "\n")] = 0; // Remove newline character

    fclose(file);
}

// Function to write the admin credentials to the file
void write_credentials(const char *username, const char *password) {
    FILE *file = fopen(CREDENTIALS_FILE, "w");
    if (file == NULL) {
        printf("Error writing credentials to file!\n");
        exit(1);
    }

    fprintf(file, "%s\n%s\n", username, password);
    fclose(file);
}

// Function to handle changing the admin profile (username and password)

void gererprofileadmin() {
    char admin_username[MAX_USERNAME_LENGTH];
    char admin_password[MAX_PASSWORD_LENGTH];
    char current_password[MAX_PASSWORD_LENGTH];
    char new_password[MAX_PASSWORD_LENGTH];
    char confirm_password[MAX_PASSWORD_LENGTH];
    char new_username[MAX_USERNAME_LENGTH];
    char random_phrase[11];

    // Read current credentials from file
    read_credentials(admin_username, admin_password);

    // Flush the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Prompt for current password
    printf("Enter your current password: ");
    fgets(current_password, MAX_PASSWORD_LENGTH, stdin);
    current_password[strcspn(current_password, "\n")] = 0; // Remove newline character

    // Check if the current password is correct
    if (strcmp(current_password, admin_password) != 0) {
        printf("Incorrect password. Exiting profile management.\n");
        return;
    }

    // Give admin the option to change username or password
    printf("Would you like to change the username or password? (Enter 'username' or 'password'): ");
    char choice[20];
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0; // Remove newline character

    if (strcmp(choice, "password") == 0) {
        // Prompt for new password
        printf("Enter your new password: ");
        fgets(new_password, MAX_PASSWORD_LENGTH, stdin);
        new_password[strcspn(new_password, "\n")] = 0; // Remove newline character

        // Validate the new password
        while (!is_valid_password(new_password)) {
            printf("Password must contain at least one uppercase letter, one lowercase letter, one number, and one symbol.\n");
            printf("Enter a valid new password: ");
            fgets(new_password, MAX_PASSWORD_LENGTH, stdin);
            new_password[strcspn(new_password, "\n")] = 0; // Remove newline character
        }

        // Prompt to confirm the new password
        printf("Confirm your new password: ");
        fgets(confirm_password, MAX_PASSWORD_LENGTH, stdin);
        confirm_password[strcspn(confirm_password, "\n")] = 0; // Remove newline character

        // Check if both passwords match
        if (strcmp(new_password, confirm_password) != 0) {
            printf("Passwords do not match. Exiting profile management.\n");
            return;
        }

        // Ask for a random confirmation phrase
        generate_random_phrase(random_phrase, 10);
        printf("For added security, please confirm the change by entering this phrase: %s\n", random_phrase);
        char confirm_phrase[11];
        fgets(confirm_phrase, sizeof(confirm_phrase), stdin);
        confirm_phrase[strcspn(confirm_phrase, "\n")] = 0; // Remove newline character

        if (strcmp(confirm_phrase, random_phrase) != 0) {
            printf("Incorrect confirmation phrase. Exiting profile management.\n");
            return;
        }

        // Update the password
        strcpy(admin_password, new_password);
        write_credentials(admin_username, admin_password);  // Save to file
        printf("Password changed successfully!\n");

    } else if (strcmp(choice, "username") == 0) {
        // Prompt for new username
        printf("Enter your new username: ");
        fgets(new_username, MAX_USERNAME_LENGTH, stdin);
        new_username[strcspn(new_username, "\n")] = 0; // Remove newline character

        // Update the username
        strcpy(admin_username, new_username);
        write_credentials(admin_username, admin_password);  // Save to file
        printf("Username changed successfully!\n");

    } else {
        printf("Invalid choice. Exiting profile management.\n");
    }
}

