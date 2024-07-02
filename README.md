<h2>Road Management System</h2>
<h3>Overview</h3>
<p>This Road Management System is a console-based application written in C. It allows users to create accounts, log in, and manage records of roads, including adding, viewing, modifying, and deleting records. The application uses file operations to store and retrieve user account information and road records.</p>
<h3>Features</h3>
<ol>
<li><strong>Account Management</strong>:</li>
</ol>
<ul>
<li><strong>Sign Up</strong>: Create a new user account.</li>
<li><strong>Sign In</strong>: Log in to an existing user account using a username and password.</li>
</ul>
<ol start="2">
<li><strong>Road Records Management</strong> (accessible after login):</li>
</ol>
<ul>
<li><strong>Add Record</strong>: Add a new road record.</li>
<li><strong>View Records</strong>: View all existing road records.</li>
<li><strong>Modify Record</strong>: Modify an existing road record.</li>
<li><strong>Delete Record</strong>: Delete an existing road record.</li>
</ul>
<ol start="3">
<li><strong>Administration Menu</strong>:</li>
</ol>
<ul>
<li>Only accessible after logging in.</li>
<li>Options to add, view, modify, or delete road records.</li>
<li>Option to log out.</li>
</ul>
<h3>File Structure</h3>
<ul>
<li>account.txt: Stores user account information.</li>
<li>record.txt: Stores road records.</li>
<li>temp.txt: Temporary file used during the delete operation to store intermediate records.</li>
</ul>
<h3>How to Use</h3>
<h4>1. Initial Menu</h4>
<p>When the program starts, it presents the user with the initial menu:
&lt;--:Menu:--&gt;
1 : Sign In.
2 : Sign Up.
Enter your choice:</p>
<ul>
<li><strong>Sign In</strong>: Prompts the user to enter their username and password to log in.</li>
<li><strong>Sign Up</strong>: Allows the user to create a new account by entering their username, phone number, user ID, and password.</li>
</ul>
<h4>2. Post Login Menu</h4>
<p>After logging in, the menu changes to:
&lt;--:Menu:--&gt;
1 : Administration.
2 : Logout.
Enter your choice:</p>
<ul>
<li><strong>Administration</strong>: Access the administration menu to manage road records.</li>
<li><strong>Logout</strong>: Logs the user out and returns to the initial menu.</li>
</ul>
<h4>3. Administration Menu</h4>
<p>The administration menu allows the logged-in user to manage road records:
&lt;--:Administration Menu:--&gt;
1 : Add.
2 : View.
3 : Modify.
4 : Delete.
5 : Back to Main Menu.
Enter your choice:</p>
<ul>
<li><strong>Add</strong>: Add a new road record by entering the starting point, ending point, and bus name.</li>
<li><strong>View</strong>: View all existing road records.</li>
<li><strong>Modify</strong>: Modify an existing road record by specifying the starting and ending points of the record to be modified.</li>
<li><strong>Delete</strong>: Delete an existing road record by specifying the starting and ending points of the record to be deleted.</li>
<li><strong>Back to Main Menu</strong>: Return to the main menu.</li>
</ul>
<h3>Code Documentation</h3>
<h4>Main Functions</h4>
<ul>
<li>main(): Entry point of the program. Displays the initial road title and menu.</li>
<li>road_title(): Displays the road management system title.</li>
<li>draw_box(int a, int b, int c, int d): Draws a box in the console for UI layout.</li>
<li>clear_screen(): Clears the console screen (platform-independent).</li>
<li>get_input(const char *prompt, char *input, int size): Gets user input safely.</li>
<li>sign_up(): Allows a new user to create an account.</li>
<li>sign_in(): Allows an existing user to log in using their username and password.</li>
<li>display_menu(int is_logged_in): Displays the appropriate menu based on the login status.</li>
<li>add_record(): Adds a new road record to the file.</li>
<li>search_record(): Searches for a road record based on the starting and ending points.</li>
<li>modify_record(): Modifies an existing road record.</li>
<li>delete_record(): Deletes an existing road record.</li>
<li>view_records(): Displays all road records.</li>
<li>administration_menu(): Displays the administration menu for managing road records.</li>
</ul>
<h3>File Operations</h3>
<ul>
<li>fopen(): Opens a file.</li>
<li>fclose(): Closes a file.</li>
<li>fread(): Reads from a file.</li>
<li>fwrite(): Writes to a file.</li>
<li>remove(): Deletes a file.</li>
<li>rename(): Renames a file.</li>
</ul>
