#include <iostream>
#include <sstream>
#include "LicenseManager.h"
#include "UserManager.h"

using namespace std;
using namespace RiskyWorks;

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x)                                                              \
  {                                                                             \
    if (!(x))                                                                   \
      std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; \
  }

// Test for function1()
// You would need to write these even when using a framework
void test_licenseManager(LicenseManager licenseManager)
{
  licenseManager.sortLicenses();
  int lc = licenseManager.licenses.size();

  // Should sort correctly
  IS_TRUE(licenseManager.licenses[0].code < licenseManager.licenses[1].code);
  IS_TRUE(licenseManager.licenses[lc - 2].code < licenseManager.licenses[lc - 1].code);
}

void test_userManager(UserManager userManager)
{
  userManager.initDb();
  userManager.sortUsers();

  int uc = userManager.users.size();
  // Should sort correctly
  IS_TRUE(userManager.users[0].surname <= userManager.users[1].surname);
  IS_TRUE(userManager.users[uc - 2].surname <= userManager.users[uc - 1].surname);
}

int main(void)
{
  LicenseManager licenseManager;
  test_licenseManager(licenseManager);

  UserManager userManager;
  test_userManager(userManager);
}