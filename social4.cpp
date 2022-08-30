#include <iostream> 
#include <cctype>
using namespace std; 

/* Name : tanisha mahmud 
class: cs 135 
lab 11 */ 

struct Post{
    
    string username; 
    string message; 
};

class Profile {
    private:
        string username; 
        string displayname;
    public: 
        Profile(string dspn, string usrn); 
        Profile(); //omg
        string getUsername(); 
        string getFullName();  // self expln
        void setDisplayName(string dspn);
};

Profile::Profile()
{
    
}
Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
    
}
string Profile::getUsername()
{
    return username; 
}
string Profile::getFullName()
{
    string FullName; 
    FullName = displayname + " (@" + username +")"; // yij 
    return FullName; 
}
void Profile::setDisplayName(string dspn)
{
    displayname = dspn; 
}

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
  bool following[MAX_USERS][MAX_USERS]; 
  static const int MAX_POSTS = 100;
  int numPosts; 
  Post posts[MAX_POSTS];// mapping integer ID -> Profile
// check friendships
  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(string usrn, string dspn);
  bool follow(string usrn1, string usrn2); 
  void printDot(); 
  bool writePost(string usrn, string msg);
  bool printTimeline(string usrn); 
};
Network::Network()
{
    numUsers = 0; 
    numPosts = 0; 
    for (int i = 0; i <MAX_USERS; i++)
    {
        for (int j = 0; j < MAX_USERS; j++)
        {
            following[i][j] = false; 
        }
    }
}

int Network::findID(string usrn)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (profiles[i].getUsername()==usrn)
        {
            return i; 
        }
    }
    return -1;
}
bool Network::addUser(string usrn, string dspn)
{
    if (numUsers < MAX_USERS && findID(usrn) == -1) // check usrn doesnt already exist and not max users 
    { //cout << "usrn doesn't already exist" << endl;
        for (int i = 0 ; i < usrn.length() ;  i++)
        {
            if (isdigit(usrn[i])== false && isalpha(usrn[i])==false) // check alpha numeric
            {
                //cout << "alpha numeric false" << endl;
                return false; 
            }
        }
        //cout << "profile being created" << endl;
        Profile itsdone(usrn, dspn);
        profiles[numUsers] = itsdone; 
        numUsers++;
        return true; 
    }
    //cout << "user exists" << endl;
    return false; 
}
bool Network::follow(string usrn1, string usrn2)
{
    if (findID(usrn1) == -1 || findID(usrn2) == -1) // check both users exists
    {
        return false; 
    }
    else 
    {
        int user1 = findID(usrn1);
        int user2 = findID(usrn2);
        following[user1][user2] = true; 
        return true; 
    }
    
}

void Network::printDot()
{
    cout << "digraph {" << endl; 
    for (int i=0; i < numUsers;i++) // print all users
    {
        cout << " " << "\"@" << profiles[i].getUsername()<< "\"" << endl; 
    }
    
    for (int i=0; i < numUsers; i++) // nested loop for 2d array
    {
        for (int j=0; j < numUsers; j++)
        {
            if (following[i][j]==true)
            {
                cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@"
                << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }
    cout << "}"<< endl; 
}

bool Network::writePost(string usrn, string msg)
{
    if (findID(usrn)==-1 || numPosts >= MAX_POSTS)
    { // if user doesnt exist or reached max posts 
        return false; 
    }
    else 
    {
        posts[numPosts].username = usrn; 
        posts[numPosts].message = msg; 
        numPosts++; 
        return true; 
    }
}
bool Network::printTimeline(string usrn)
{
    int userindex = findID(usrn); 
    if (findID(usrn)==-1)// check user exists 
    {
        return false; 
    }
    for (int i = numPosts; i >= 0; i--) // reverse chrono
    {
        if (posts[i].username == usrn) // own posts 
        {
            cout << profiles[userindex].getFullName() << ": " 
            << posts[i].message << endl; 
        }
        int otherid = findID(posts[i].username);
        if (following[userindex][otherid]==true) // if following
        {
            cout << profiles[otherid].getFullName() << ": "
            << posts[i].message << endl; 
        }
    }
    return true; 
}
int main() {
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}