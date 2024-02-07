#include <iostream>
#include <X11/Xlib.h>
#include <unistd.h>

int main()
{
	//init x server
	Display *d = XOpenDisplay(0);
 	if (d) {
		std::cout << "\nX server running! Here, have this window! :D\n";
 		//define window
		Window w = XCreateWindow(d, DefaultRootWindow(d), 0, 0, 1080, 720, 0, CopyFromParent, CopyFromParent, CopyFromParent, 0, 0);
		//actually show it
		XMapWindow(d, w);
		XFlush(d);
		//microsleeps because i don't get good rest
		sleep(1);
	}
	else {
		std::cout << "\nX server could not be opened. Is it running?\n";
		return -1;
	}
	return 0;
}
