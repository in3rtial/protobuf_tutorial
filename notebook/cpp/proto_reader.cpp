#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
using namespace std;

tutorial::AddressBook create_address_book() {
  // create an address book with simple orders we'll verify in python
  auto book = tutorial::AddressBook();
}

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  tutorial::AddressBook address_book = create_address_book();

  // Write the new address book back to disk.
  fstream output("addresses.out", ios::out | ios::trunc | ios::binary);
  if (!address_book.SerializeToOstream(&output)) {
    cerr << "Failed to write address book." << endl;
    return -1;
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
