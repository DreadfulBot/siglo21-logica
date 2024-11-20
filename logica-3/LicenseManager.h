#include <iostream>
#include <vector>
using namespace std;

namespace RiskyWorks
{
  struct License
  {
    string code;
  };

  bool compareLicenses(const License &a, const License &b)
  {
    return a.code < b.code;
  };

  struct LicenseManager
  {
    vector<License> licenses = {
        {"LB2362"},
        {"VD2563"},
        {"DS7856"},
        {"GT8569"},
        {"SD4572"},
        {"WF4004"},
        {"TG4565"},
        {"BP0456"},
        {"KL4580"},
        {"DF4587"},
    };

    void sortLicenses()
    {
      // quicksort is used here, from standard lib
      sort(begin(licenses), end(licenses), compareLicenses);
    }

    void printLicenses()
    {
      // Print sorted licenses
      for (const auto &license : licenses)
      {
        std::cout << license.code << std::endl;
      }
    }
  };
}