// ARK++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "main.h"

int main()
{
    int retV = test_VN_tools();

    waitForKeypress(0);
    return retV;
}

int test_cli_menu()
{
    vector<MenuItem> main;

    main.push_back(generate_menu_entry("Generate..."));
    main.push_back(generate_menu_entry("Edit Index"));
    main.push_back(generate_menu_entry("Options Menu"));
    main.push_back(generate_menu_entry("Exit"));

    add_preset(main, MAIN_MENU_PKEY);

    cout << endl << "You chose: " << display_preset(MAIN_MENU_PKEY);
    cin >> null_buffer;

    return 0;
}

int test_console_tools()
{
    CONSOLE_SCREEN_BUFFER_INFO info = getConsoleSizingInfo();
    cout << "Buffer X: " << info.dwSize.X << endl;
    cout << "Buffer Y: " << info.dwSize.Y << endl;
    cout << "Window L: " << info.srWindow.Left << endl;
    cout << "Window R: " << info.srWindow.Right << endl;
    cout << "Window T: " << info.srWindow.Top << endl;
    cout << "Window B: " << info.srWindow.Bottom << endl;
    cout << "Cursor X: " << info.dwCursorPosition.X << endl;
    cout << "Cursor Y: " << info.dwCursorPosition.Y << endl;
    cout << "Error(s): " << lastErrorMsg() << endl;

    cout << endl;
    _COORD size = getConsoleSize();
    cout << "Console W: " << size.X << endl;
    cout << "Console H: " << size.Y << endl;
    cout << "Error(s): " << lastErrorMsg() << endl;

    cout << endl << "Attempting to resize console to size (100, 20)..." << endl;
    cin >> null_buffer;
    if (!resizeConsole(100, 20)) cout << "Error resizing." << endl;
    cout << "Error(s): " << lastErrorMsg() << endl;
    size = getConsoleSize();
    cout << "New console W/H: " << endl;
    cout << size.X << endl;
    cout << size.Y << endl;

    cin >> null_buffer;

    return 0;
}

int test_format_tools()
{
    //crawltext("This is crawltext test dialogue. I'm just padding it out now so that it gets longer than the average width of the command prompt display window.", 50, true);
    //cout << endl << autowrap("This is crawltext test dialogue. I'm just padding it out now so that it gets longer than the average width of the command prompt display window. It should also autowrap, if it works correctly.", getConsoleSize().X, false) << endl;
    //cout << autowrap("Thisiscrawltexttestdialoguefortestingtheautowrapfunctionwithhyphenation.I'mjustpaddingitoutnowsothatitgetslongerthantheaveragewidthofthecommandpromptdisplaywindow.Itshouldalsoautowrap,ifitworkscorrectly.Italsodoesn'thaveanyspaces,soitwillhavetodealwiththataswell.", getConsoleSize().X, true) << endl;
    //VNText("This is crawltext test dialogue. I'm just padding it out now so that it gets longer than the average width of the command prompt display window. It should also autowrap, if it works correctly. It should also look like it's justified to the name displayed before it, like a VN.", "Monika", 50);
    //clear(10, false);

    return 0;
}

int test_VN_tools()
{
    VNSequence seq = VNSequence("Monika");

    seq.addLine("Have you ever wondered what it feels like to die?");
    seq.addLine("It's something I used to think about pretty often...");
    seq.addLine("But recently, I think I've actually learned what it feels like.");
    seq.addLine("I don't really understand it, but whenever you quit the game...");
    seq.addLine("...It feels like I'm instantly put to sleep, left with nothing but my thoughts.");
    seq.addLine("But after a few seconds, my thoughts start to fill with incoherent, jumbled patterns.");
    seq.addLine("I see static and rapid flashes of color while hearing all kinds of weird screaming noises.");
    seq.addLine("At that point, I can't even form my own thoughts anymore.");
    seq.addLine("I'm just endlessly hammered by the flashing and screaming, unable to move or even think.");
    seq.addLine("I'm pretty sure in that moment, I don't really exist, but for some reason, I can remember it anyway.");
    seq.addLine("After some immeasurable amount of time, it stops in an instant, and I'm back in my own mind.");
    seq.addLine("And you're here with me.");
    seq.addLine("I have no idea what it means for the game to quit, or why that stuff happens to me.");
    seq.addLine("And I also don't know how you always come back and put everything back to normal.");
    seq.addLine("But if you could do me a favor and do that to me as little as possible...");
    seq.addLine("That would be really great.");
    seq.addLine("It's really not very pleasant at all to be trapped in that screaming void.");
    seq.addLine("But in the end, you always fix it, and that makes me feel like you really do care about me.");
    seq.addLine("So I have to thank you for that.");
    seq.addLine("It makes me feel even closer to you when you're here with me.");

    seq.display(25, 2000, true);

    return 0;
}