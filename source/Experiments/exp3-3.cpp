
#include "../ClientProg/fileObject.h"

#include <iostream>
#include <string>
#include <cstdio>
#include <chrono>

using namespace std;


int main(int argc, char** argv){
  string ip = argv[1];
  FileObject* new_object = new FileObject(ip);
  int32_t filehandler;
  char* foo = new char[1048576];
  int counter = 0;
  auto start = chrono::steady_clock::now();

  filehandler= new_object->dfs_open("foo3-1", "w");
  for(int j = 0; j < 47; j++){
    for (int i =0; i < 1048576; i++){
      foo[i]= counter;
      counter = (counter+1) % 47;
    }
    new_object->dfs_write(filehandler, foo, 1048576);
  }
  new_object->dfs_close(filehandler);

  counter =0;
  filehandler= new_object->dfs_open("foo3-2", "w");
  for(int j = 0; j < 13; j++){
    for (int i =0; i < 1048576; i++){
      foo[i]= counter;
      counter = (counter+1) % 13;
    }
    new_object->dfs_write(filehandler, foo, 1048576);
  }
  new_object->dfs_close(filehandler);

  counter =0;
  filehandler= new_object->dfs_open("foo3-3", "w");
  for(int j = 0; j < 31; j++){
    for (int i =0; i < 1048576; i++){
      foo[i]= counter;
      counter = (counter+1) % 31;
    }
    new_object->dfs_write(filehandler, foo, 1048576);
  }
  new_object->dfs_close(filehandler);

  counter =0;
  filehandler= new_object->dfs_open("foo3-4", "w");
  for(int j = 0; j < 83; j++){
    for (int i =0; i < 1048576; i++){
      foo[i]= counter;
      counter = (counter+1) % 83;
    }
    new_object->dfs_write(filehandler, foo, 1048576);
  }
  new_object->dfs_close(filehandler);

  counter =0;
  filehandler= new_object->dfs_open("foo3-5", "w");
  for(int j = 0; j < 13; j++){
    for (int i =0; i < 1048576; i++){
      foo[i]= counter;
      counter = (counter+1) % 13;
    }
    new_object->dfs_write(filehandler, foo, 1048576);
  }
  new_object->dfs_close(filehandler);

  filehandler= new_object->dfs_open("foo3-6", "w");
  for(int j = 0; j < 59; j++){
    for (int i =0; i < 1048576; i++){
      foo[i]= counter;
      counter = (counter+1) % 59;
    }
    new_object->dfs_write(filehandler, foo, 1048576);
  }
  new_object->dfs_close(filehandler);


  auto end = chrono::steady_clock::now();

  cout << "foo write time in milliseconds : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;


  start = chrono::steady_clock::now();

  filehandler= new_object->dfs_open("foo3-1", "r");
  for (int j = 0; j < 47; j++){
    new_object->dfs_read(filehandler, foo, 1048576);
  }

  filehandler= new_object->dfs_open("foo3-2", "r");
  for (int j = 0; j < 13; j++){
    new_object->dfs_read(filehandler, foo, 1048576);
  }

  filehandler= new_object->dfs_open("foo3-3", "r");
  for (int j = 0; j < 31; j++){
    new_object->dfs_read(filehandler, foo, 1048576);
  }

  filehandler= new_object->dfs_open("foo3-4", "r");
  for (int j = 0; j < 83; j++){
    new_object->dfs_read(filehandler, foo, 1048576);
  }

  filehandler= new_object->dfs_open("foo3-5", "r");
  for (int j = 0; j < 13; j++){
    new_object->dfs_read(filehandler, foo, 1048576);
  }
  filehandler= new_object->dfs_open("foo3-6", "r");
  for (int j = 0; j < 59; j++){
    new_object->dfs_read(filehandler, foo, 1048576);
  }
  end = chrono::steady_clock::now();

  cout << "foo read time in milliseconds : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

  new_object->dfs_close(filehandler);
  delete new_object;
  delete[] foo;
  return 0;
}
