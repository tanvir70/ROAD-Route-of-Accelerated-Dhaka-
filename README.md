## Road Management System

### Overview

This Road Management System is a console-based application written in C. It allows users to create accounts, log in, and manage records of roads, including adding, viewing, modifying, and deleting records. The application uses file operations to store and retrieve user account information and road records.

### Features

1. **Account Management**:

   - **Sign Up**: Create a new user account.
   - **Sign In**: Log in to an existing user account using a username and password.

2. **Road Records Management** (accessible after login):

   - **Add Record**: Add a new road record.
   - **View Records**: View all existing road records.

3. **Administration Menu**:

   - Only accessible after logging in.
   - Options to add, view, modify, or delete road records.
   - Option to log out.

### File Structure

- `account.txt`: Stores user account information.
- `record.txt`: Stores road records.

### How to Use

#### 1. Initial Menu

When the program starts, it presents the user with the initial menu:

```
<--:Menu:-->
1 : Sign In.
2 : Sign Up.
Enter your choice:
```

- **Sign In**: Prompts the user to enter their username and password to log in.
- **Sign Up**: Allows the user to create a new account by entering their username, phone number, user ID, and password.

#### 2. Post Login Menu

After logging in, the menu changes to:

```
<--:Menu:-->
1 : Administration.
2 : Logout.
Enter your choice:
```

- **Administration**: Access the administration menu to manage road records.
- **Logout**: Logs the user out and returns to the initial menu.

#### 3. Administration Menu

The administration menu allows the logged-in user to manage road records:

```
<--:Administration Menu:-->
1 : Add.
2 : View.
3 : Modify.
4 : Delete.
5 : Back to Main Menu.
Enter your choice:
```

- **Add**: Add a new road record by entering the starting point, ending point, and bus name.
- **View**: View all existing road records.
- **Modify**: Modify an existing road record by specifying the starting and ending points of the record to be modified.
- **Delete**: Delete an existing road record by specifying the starting and ending points of the record to be deleted.
- **Back to Main Menu**: Return to the main menu.

### Code Documentation

#### Main Functions

- `main()`: Entry point of the program. Displays the initial road title and menu.
- `road_title()`: Displays the road management system title.
- `draw_box(int a, int b, int c, int d)`: Draws a box in the console for UI layout.
- `clear_screen()`: Clears the console screen (platform-independent).
- `get_input(const char *prompt, char *input, int size)`: Gets user input safely.
- `sign_up()`: Allows a new user to create an account.
- `sign_in()`: Allows an existing user to log in using their username and password.
- `display_menu(int is_logged_in)`: Displays the appropriate menu based on the login status.
- `add_record()`: Adds a new road record to the file.
- `search_record()`: Searches for a road record based on the starting and ending points.
- `modify_record()`: Modifies an existing road record.
- `delete_record()`: Deletes an existing road record.
- `view_records()`: Displays all road records.
- `administration_menu()`: Displays the administration menu for managing road records.

### File Operations

- `fopen()`: Opens a file.
- `fclose()`: Closes a file.
- `fread()`: Reads from a file.
- `fwrite()`: Writes to a file.
- `remove()`: Deletes a file.


