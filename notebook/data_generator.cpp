#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <limits>

#include "addressbook.pb.h"

using namespace tutorial;

void add_person(AddressBook& book, int id, double data) {
  Person* person = book.add_people();
  person->set_name("name_" + std::to_string(id));
  person->set_id(id);
  person->set_data(data);
}

int main(int argc, char* argv[]) {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  // create test data
  AddressBook book;
  add_person(book, 0, std::numeric_limits<double>::quiet_NaN());
  add_person(book, 1, std::numeric_limits<double>::infinity());
  add_person(book, 2, std::numeric_limits<double>::lowest());

  // write data to disk
  std::fstream output(argv[1],
		      std::ios::out | std::ios::trunc | std::ios::binary);
  assert(book.SerializeToOstream(&output));
}
