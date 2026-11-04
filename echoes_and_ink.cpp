#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <windows.h>
#include <stdexcept>

using namespace std;
string currentPassword = "";

class Entry {
private:
    string date;
    string title;
    string category;
    string mood;
    string text;
    bool favorite;
    bool secret;

public:
    Entry() {
        favorite = false;
        secret = false;
    }

    Entry(string d, string t, string c, string m, string txt, bool fav, bool sec) {
        date = d;
        title = t;
        category = c;
        mood = m;
        text = txt;
        favorite = fav;
        secret = sec;
    }

    void createEntry() {
        cin.ignore();

        time_t now = time(0);
        date = ctime(&now);

        cout << "\nEnter Title: ";
        getline(cin, title);

        cout << "Enter Category: ";
        getline(cin, category);

        int choice;

cout << "\nSelect Mood\n";
cout << "1. Happy\n";
cout << "2. Sad\n";
cout << "3. Angry\n";
cout << "4. Excited\n";

do
{
    cout << "Choice: ";
    cin >> choice;

    if(choice < 1 || choice > 4)
    {
        cout << "\nInvalid Choice! Please enter 1 to 4.\n";
    }

} while(choice < 1 || choice > 4);

cin.ignore();

if(choice == 1)
    mood = "Happy";
else if(choice == 2)
    mood = "Sad";
else if(choice == 3)
    mood = "Angry";
else
    mood = "Excited";

        cout << "\nWrite Your Entry: ";
        getline(cin, text);

        char fav;
        cout << "Mark as Favorite? (y/n): ";
        cin >> fav;
        if (fav == 'y' || fav == 'Y') favorite = true;

        char sec;
        cout << "Save in Secret Vault? (y/n): ";
        cin >> sec;
        if (sec == 'y' || sec == 'Y') secret = true;
    }

    void displayEntry() {
        cout << "\n====================================\n";
        cout << "Date: " << date;
        cout << "Title: " << title << endl;
        cout << "Category: " << category << endl;
        cout << "Mood: " << mood << endl;
        cout << "Entry: " << text << endl;

        if (favorite) cout << " Favorite Entry\n";
        if (secret) cout << "Secret Entry\n";

        cout << "====================================\n";
    }

    string getMood() { return mood; }
    string getTitle() { return title; }
    string getText() { return text; }
    string getCategory() { return category; }

    bool isFavorite() { return favorite; }
    bool isSecret() { return secret; }

    void save(ofstream &file) {
        file << date;
        file << title << endl;
        file << category << endl;
        file << mood << endl;
        file << text << endl;
        file << favorite << endl;
        file << secret << endl;
        file << "---" << endl;
    }

    void editEntry() {
        cin.ignore();

        cout << "\nEnter New Title: ";
        getline(cin, title);

        cout << "Enter New Entry: ";
        getline(cin, text);

        cout << "\nEntry Updated Successfully\n";
    }
};

class Diary {
private:
    vector<Entry> entries;

public:
    void quoteOfDay() {
        string quotes[] = {
            "Every day is a fresh start.",
            "Write your own story.",
            "Your thoughts matter.",
            "Believe in yourself.",
            "Small progress is still progress."
        };

        srand(time(0));

        cout << "\n === Quote of the Day === \n";
        cout << quotes[rand() % 5] << endl;
    }

    void addEntry() {
        Entry e;
        e.createEntry();
        entries.push_back(e);
        saveFile();

        cout << "\nEntry Added Successfully\n";
    }

    void viewEntries() {
        if (entries.empty()) {
            cout << "\nNo Entries Found\n";
            return;
        }

        for (int i = 0; i < entries.size(); i++) {
            cout << "\nEntry Number: " << i + 1 << endl;
            entries[i].displayEntry();
        }
    }

    void viewSavedEntries() {
        ifstream file("diary.txt");

        if (!file) {
            cout << "\nNo Saved Entries Found\n";
            return;
        }

        string line;

        cout << "\n========== SAVED ENTRIES ==========\n";

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    void favoriteEntries() {
        bool found = false;

        for (int i = 0; i < entries.size(); i++) {
            if (entries[i].isFavorite()) {
                entries[i].displayEntry();
                found = true;
            }
        }

        if (!found)
            cout << "\nNo Favorite Entries\n";
    }

    void secretVault() {

    string password;

    cout << "\nEnter Password to Access Secret Vault (same as login password): ";
    cin >> password;

    if (password != currentPassword) {
        cout << "\nIncorrect Password!\n";
        return;
    }

    bool found = false;

    for (int i = 0; i < entries.size(); i++) {

        if (entries[i].isSecret()) {

            entries[i].displayEntry();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo Secret Entries\n";
}

    void searchKeyword() {
        cin.ignore();
        string key;

        cout << "\nEnter Keyword: ";
        getline(cin, key);

        bool found = false;

        for (int i = 0; i < entries.size(); i++) {
            if (entries[i].getTitle().find(key) != string::npos ||
                entries[i].getText().find(key) != string::npos ||
                entries[i].getCategory().find(key) != string::npos) {

                entries[i].displayEntry();
                found = true;
            }
        }

        if (!found)
            cout << "\nNo Matching Entry Found\n";
    }

    void statistics() {
        int happy = 0, sad = 0, angry = 0, excited = 0;

        for (int i = 0; i < entries.size(); i++) {
            if (entries[i].getMood() == "Happy") happy++;
            else if (entries[i].getMood() == "Sad") sad++;
            else if (entries[i].getMood() == "Angry") angry++;
            else excited++;
        }

        cout << "\n========= STATISTICS =========\n";
        cout << "Total Entries: " << entries.size() << endl;
        cout << "Happy: " << happy << endl;
        cout << "Sad: " << sad << endl;
        cout << "Angry: " << angry << endl;
        cout << "Excited: " << excited << endl;
    }

    void editEntry() {
        int num;
        viewEntries();

        cout << "\nEnter Entry Number to Edit: ";
        cin >> num;

        if (num > 0 && num <= entries.size()) {
            entries[num - 1].editEntry();
            saveFile();
        } else {
            cout << "\nInvalid Entry Number\n";
        }
    }

    void deleteEntry() {
        int num;
        viewEntries();

        cout << "\nEnter Entry Number to Delete: ";
        cin >> num;

        if (num > 0 && num <= entries.size()) {
            entries.erase(entries.begin() + num - 1);
            saveFile();
            cout << "\nEntry Deleted Successfully\n";
        } else {
            cout << "\nInvalid Entry Number\n";
        }
    }

    void saveFile() {
        ofstream file("diary.txt");

        for (int i = 0; i < entries.size(); i++) {
            entries[i].save(file);
        }

        file.close();
    }

    void loadFile() {
        ifstream file("diary.txt");

        if (!file) return;

        string date, title, category, mood, text, line;
        bool fav, sec;

        while (getline(file, date)) {
            getline(file, title);
            getline(file, category);
            getline(file, mood);
            getline(file, text);

            file >> fav >> sec;
            file.ignore();
            getline(file, line);

            Entry e(date, title, category, mood, text, fav, sec);
            entries.push_back(e);
        }

        file.close();
    }
};

class User {
public:
    virtual bool login() = 0;
    virtual void signup() = 0;
    virtual ~User() {}
};

class DiaryUser : public User {
public:

    void signup() override {

        string username, password, u, p;

        cin.ignore();

        cout << "\nCreate Username: ";
        getline(cin, username);

        ifstream check("users.txt");

        while (getline(check, u)) {
            getline(check, p);

            if (u == username) {
                cout<<"Username already exists!"<<endl;
            }
        }

        check.close();

        cout << "Create Password: ";
        getline(cin, password);

        ofstream file("users.txt", ios::app);

        file << username << endl;
        file << password << endl;

        file.close();

        cout << "\nAccount Created Successfully\n";
    }

    bool login() override {

        string username, password, u, p;
        int attempts = 3;

        while (attempts > 0) {

            cin.ignore();

            cout << "\nEnter Username: ";
            getline(cin, username);

            cout << "Enter Password: ";
            getline(cin, password);

            ifstream file("users.txt");
            bool found = false;

            while (getline(file, u)) {

                getline(file, p);

                if (username == u && password == p) {
    currentPassword = password;
    found = true;
    break;
}
            }

            file.close();

            if (found) {
                cout << "\nLogin Successful\n";
                return true;
            }
            else {
                attempts--;

                cout << "\nInvalid Credentials\nAttempts Left: "
                     << attempts << endl;
            }
        }

        return false;
    }
};

int main() {
    system("color 0B");

    DiaryUser diaryUser;

User& user = diaryUser;
    Diary diary;

    diary.loadFile();

    cout << "========================================\n";
    cout << "             ECHOES & INK\n";
    cout << "        Your Personal Digital Diary\n";
    cout << "========================================\n";

    int option;

    cout << "\n1. Signup\n2. Login\nEnter Choice: ";
    cin >> option;

    if (option == 1) user.signup();

    if (!user.login()) return 0;

    diary.quoteOfDay();

    int choice;

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Add Entry\n";
        cout << "2. View All Entries\n";
        cout << "3. Favorite Entries\n";
        cout << "4. Search by Keyword\n";
        cout << "5. Edit Entry\n";
        cout << "6. Delete Entry\n";
        cout << "7. Statistics\n";
        cout << "8. Secret Vault\n";
        cout << "9. View Saved Entries (File)\n";
        cout << "10. Hidden Message\n";
        cout << "11. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: diary.addEntry(); break;
        case 2: diary.viewEntries(); break;
        case 3: diary.favoriteEntries(); break;
        case 4: diary.searchKeyword(); break;
        case 5: diary.editEntry(); break;
        case 6: diary.deleteEntry(); break;
        case 7: diary.statistics(); break;
        case 8: diary.secretVault(); break;

        case 9:
            diary.viewSavedEntries();
            break;

        case 10:
            cout << "\n You are stronger than yesterday.\nKeep writing your story.\n";
            break;

        case 11:
            cout << "\nThank you for using Echoes & Ink\n";
            break;

        default:
            cout << "\nInvalid Choice\n";
        }

    } while (choice != 11);

    return 0;
}

