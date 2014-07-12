// login.cpp
//
#include <stdio.h>
#include <stdlib.h>
#include <iup.h>

int main(int argc, char* argv[])
{
    IupOpen(&argc, &argv);

    Ihandle* username = IupText("username");
    IupSetAttribute(username, "FONT", "Cambria, 10");
    IupSetAttribute(username, "SIZE", "100x");

    Ihandle* password = IupText("password");
    IupSetAttribute(password, "PASSWORD", "YES");
    IupSetAttribute(password, "FONT", "Cambria, 10");
    IupSetAttribute(password, "SIZE", "100x");

    Ihandle* login_btn = IupButton("Login", NULL);
    IupSetAttribute(login_btn, "FONT", "Comic Sans MS, 10");

    Ihandle* dlg = IupDialog(
        IupVbox(
            username,
            password,
            IupHbox(
                IupFill(),
                login_btn,
                IupFill(),
                NULL
            ),
            NULL
        )
    );
    IupSetAttributes(dlg, "TITLE=IupLogin");

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

    IupMainLoop();

    IupClose();

    return 0;
}

