#include <iostream>
#include "LicenseManager.h"
#include "UserManager.h"

using namespace std;
using namespace RiskyWorks;

int main()
{
  cout << "Welcome to LicenseManager. Here are the licenses:" << endl;
  LicenseManager licenseManager;
  licenseManager.printLicenses();

  cout << "Sorting licenses..." << endl;
  licenseManager.sortLicenses();
  cout << "Licenses sorted!" << endl;
  licenseManager.printLicenses();

  cout << "Welcome to UserManager. Generating 20 random users..." << endl;
  UserManager userManager;
  userManager.initDb(true);
  cout << "Sorting users..." << endl;
  userManager.sortUsers();
  cout << "Users sorted!" << endl;
  userManager.printUsers();
}