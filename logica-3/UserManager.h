using namespace std;

#include "NameGenerator.h"
#include "MergeSort.h"

namespace RiskyWorks
{
  struct User
  {
    string name;
    string surname;

    bool operator<=(const User &other) const
    {
      if (surname == other.surname)
      {
        return name <= other.name;
      }

      return surname <= other.surname;
    }

    bool operator<(const User &other) const
    {
      if (surname == other.surname)
      {
        return name < other.name;
      }

      return surname < other.surname;
    }
  };

  struct UserManager
  {
    vector<User> users;

    void initDb(bool verbose = false)
    {
      NameGenerator nameGenerator;

      for (int i = 0; i < 20; i++)
      {
        addUser(nameGenerator.generateName(), nameGenerator.generateSurname(), verbose);
      }
    }

    void sortUsers()
    {
      MergeSort<User>::sort(users, 0, users.size() - 1);
    }

    void addUser(const string &name, const string &surname, bool verbose = false)
    {
      if (users.size() < 20)
      {
        users.push_back(User{name, surname});

        if (verbose)
        {
          cout << "User added successfully: " << surname << ", " << name << endl;
        }
      }
    }

    void printUsers()
    {
      for (auto user : users)
      {
        cout << "User: " << user.surname << ", " << user.name << endl;
      }
    }
  };
}