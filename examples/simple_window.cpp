#include <unistd.h>
#include <milch.h>
using namespace milch;

int main() {
    window win(400,200, "my window");
    win.show_window();
    sleep(200);
    return 0;
}