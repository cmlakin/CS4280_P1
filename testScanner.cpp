// call scanner and  print  token until scaner returns EOF


void testScanner(istream& in) {
  string element;
  in >> element;
  if (in.eof()) {
    cout << "Error: Empty file, no content.\n";
    cout << "Exiting program.\n";
  }
  while(!in.eof()) {

    char first = element.front();
    in >> userWord;
  }
}
