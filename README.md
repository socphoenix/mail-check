# mail-check
simple mail checker for FreeBSD system mail
This program runs in the background and can be set up to run on user login. it will issue a popup notification with the message subject using "notify-send". Some code was found on stack-overflow: https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-c

Released as is under the MIT license.

Compilation:
as user run "g++ mailchecker.cpp -o mail-check"
as root (in directory of compilation): "cp mail-check /usr/local/bin/mail-check".
Application requires notify-send which works under KDE (and should under other desktop environments but is not tested on them). Otherwise there are no dependencies that shouldn't be included by default with g++. This should also compile under Linux and work the same for system mail (sendmail) but also has not been tested for it.
