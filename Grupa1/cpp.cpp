#include <windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#define ID_TEXTBOX 101
#define ID_ADDBUTTON 102
#define ID_DELETEBUTTON 103
#define ID_SORTBUTTON 104
#define ID_LISTBOX 105

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void LoadTasks(HWND);
void SaveTasks(HWND);

const char g_szClassName[] = "ToDoListApp";
std::string filename = "tasks.txt";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc = {0};
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.lpfnWndProc   = WindowProcedure;
    wc.hInstance     = hInstance;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = g_szClassName;
    RegisterClassEx(&wc);

    hwnd = CreateWindowEx(0, g_szClassName, "To-Do List",
                          WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                          400, 400, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

void AddTask(HWND hwnd) {
    char buffer[256];
    GetWindowText(GetDlgItem(hwnd, ID_TEXTBOX), buffer, 256);
    if (strlen(buffer) > 0) {
        SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_ADDSTRING, 0, (LPARAM)buffer);
        SetWindowText(GetDlgItem(hwnd, ID_TEXTBOX), "");
    }
}

void DeleteTask(HWND hwnd) {
    HWND hList = GetDlgItem(hwnd, ID_LISTBOX);
    int index = SendMessage(hList, LB_GETCURSEL, 0, 0);
    if (index != LB_ERR) {
        SendMessage(hList, LB_DELETESTRING, index, 0);
    }
}

void SortTasks(HWND hwnd) {
    HWND hList = GetDlgItem(hwnd, ID_LISTBOX);
    int count = SendMessage(hList, LB_GETCOUNT, 0, 0);
    std::vector<std::string> tasks;

    for (int i = 0; i < count; ++i) {
        char buffer[256];
        SendMessage(hList, LB_GETTEXT, i, (LPARAM)buffer);
        tasks.push_back(buffer);
    }

    std::sort(tasks.begin(), tasks.end());

    SendMessage(hList, LB_RESETCONTENT, 0, 0);
    for (const auto& task : tasks) {
        SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)task.c_str());
    }
}

void LoadTasks(HWND hwnd) {
    std::ifstream in(filename);
    std::string line;
    HWND hList = GetDlgItem(hwnd, ID_LISTBOX);

    while (std::getline(in, line)) {
        SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)line.c_str());
    }
    in.close();
}

void SaveTasks(HWND hwnd) {
    std::ofstream out(filename);
    HWND hList = GetDlgItem(hwnd, ID_LISTBOX);
    int count = SendMessage(hList, LB_GETCOUNT, 0, 0);

    for (int i = 0; i < count; ++i) {
        char buffer[256];
        SendMessage(hList, LB_GETTEXT, i, (LPARAM)buffer);
        out << buffer << std::endl;
    }
    out.close();
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_CREATE:
            CreateWindow("STATIC", "Task:", WS_VISIBLE | WS_CHILD, 10, 10, 40, 20, hwnd, NULL, NULL, NULL);
            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                         60, 10, 200, 20, hwnd, (HMENU)ID_TEXTBOX, NULL, NULL);
            CreateWindow("BUTTON", "Add", WS_VISIBLE | WS_CHILD,
                         270, 10, 100, 25, hwnd, (HMENU)ID_ADDBUTTON, NULL, NULL);
            CreateWindow("BUTTON", "Delete", WS_VISIBLE | WS_CHILD,
                         270, 45, 100, 25, hwnd, (HMENU)ID_DELETEBUTTON, NULL, NULL);
            CreateWindow("BUTTON", "Sort", WS_VISIBLE | WS_CHILD,
                         270, 80, 100, 25, hwnd, (HMENU)ID_SORTBUTTON, NULL, NULL);
            CreateWindow("LISTBOX", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | LBS_NOTIFY,
                         10, 45, 250, 300, hwnd, (HMENU)ID_LISTBOX, NULL, NULL);
            LoadTasks(hwnd);
            break;
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case ID_ADDBUTTON:
                    AddTask(hwnd);
                    break;
                case ID_DELETEBUTTON:
                    DeleteTask(hwnd);
                    break;
                case ID_SORTBUTTON:
                    SortTasks(hwnd);
                    break;
            }
            break;
        case WM_DESTROY:
            SaveTasks(hwnd);
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
