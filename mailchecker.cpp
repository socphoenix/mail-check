/* released by socphoenix under the MIT license.
MIT License

Copyright (c) 2022 socphoenix

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include<iostream>
#include<fstream>
#include<unistd.h>
#include<regex>
#include<string>
using namespace std;
int old_file=0;
int main() {
   string Username = getlogin();
   Username = "/var/mail/" + Username;
   string command = "notify-send -i dialog-warning -a mail '";
   string str, str2, str3;
   while(true) {
      ifstream in_file(Username, ios::binary);
   in_file.seekg(0, ios::end);
   int file_size = in_file.tellg();
   if(file_size > 0 && file_size > old_file) {
      ifstream file(Username);
      while(getline(file, str)){
         regex reg("Subject");
         if(regex_search(str, reg)) {
            str2 = str;
         }
      }
      str3 = command + str2 + "'";
      system(str3.c_str());
      old_file = file_size;
      sleep(1);
   }
   if(file_size == 0) {
      old_file = file_size;
   }
   }
}
