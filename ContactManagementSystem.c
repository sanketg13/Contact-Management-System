#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50
#define ADDRESS_LENGTH 100

// Define a structure to store contact information
struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
    char address[ADDRESS_LENGTH];
};

// Function prototypes
void addContact(struct Contact contacts[], int *contactCount);
void searchContact(struct Contact contacts[], int contactCount);
void editContact(struct Contact contacts[], int contactCount);
void deleteContact(struct Contact contacts[], int *contactCount);
void displayContacts(struct Contact contacts[], int contactCount);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. View All Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                searchContact(contacts, contactCount);
                break;
            case 3:
                editContact(contacts, contactCount);
                break;
            case 4:
                deleteContact(contacts, &contactCount);
                break;
            case 5:
                displayContacts(contacts, contactCount);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add a new contact
void addContact(struct Contact contacts[], int *contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", contacts[*contactCount].name);
    printf("Enter Phone: ");
    scanf(" %[^\n]", contacts[*contactCount].phone);
    printf("Enter Email: ");
    scanf(" %[^\n]", contacts[*contactCount].email);
    printf("Enter Address: ");
    scanf(" %[^\n]", contacts[*contactCount].address);

    (*contactCount)++;
    printf("Contact added successfully!\n");
}

// Function to search for a contact by name or phone number
void searchContact(struct Contact contacts[], int contactCount) {
    char searchQuery[NAME_LENGTH];
    printf("Enter Name or Phone to search: ");
    scanf(" %[^\n]", searchQuery);

    for (int i = 0; i < contactCount; i++) {
        if (strstr(contacts[i].name, searchQuery) != NULL || strstr(contacts[i].phone, searchQuery) != NULL) {
            printf("Contact found: %s, %s, %s, %s\n", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].address);
            return;
        }
    }
    printf("Contact not found!\n");
}

// Function to edit an existing contact
void editContact(struct Contact contacts[], int contactCount) {
    char searchQuery[NAME_LENGTH];
    printf("Enter Name or Phone to edit: ");
    scanf(" %[^\n]", searchQuery);

    for (int i = 0; i < contactCount; i++) {
        if (strstr(contacts[i].name, searchQuery) != NULL || strstr(contacts[i].phone, searchQuery) != NULL) {
            printf("Editing contact: %s, %s, %s, %s\n", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].address);

            printf("Enter new Name: ");
            scanf(" %[^\n]", contacts[i].name);
            printf("Enter new Phone: ");
            scanf(" %[^\n]", contacts[i].phone);
            printf("Enter new Email: ");
            scanf(" %[^\n]", contacts[i].email);
            printf("Enter new Address: ");
            scanf(" %[^\n]", contacts[i].address);

            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

// Function to delete a contact
void deleteContact(struct Contact contacts[], int *contactCount) {
    char searchQuery[NAME_LENGTH];
    printf("Enter Name or Phone to delete: ");
    scanf(" %[^\n]", searchQuery);

    for (int i = 0; i < *contactCount; i++) {
        if (strstr(contacts[i].name, searchQuery) != NULL || strstr(contacts[i].phone, searchQuery) != NULL) {
            for (int j = i; j < *contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*contactCount)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

// Function to display all contacts
void displayContacts(struct Contact contacts[], int contactCount) {
    if (contactCount == 0) {
        printf("No contacts to display!\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d: %s, %s, %s, %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].address);
    }
}
